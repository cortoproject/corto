/* src/hyve/lang/_meta.cpp
 *
 *  Generated on Oct 28 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "hyve/lang/_type.hpp"
#include "hyve.hpp"

#include "hyve/lang/Virtual.hpp"
#include "hyve/lang/Uint.hpp"
#include "hyve/lang/Typedef.hpp"
#include "hyve/lang/Text.hpp"
#include "hyve/lang/Primitive.hpp"
#include "hyve/lang/Map.hpp"
#include "hyve/lang/List.hpp"
#include "hyve/lang/Struct.hpp"
#include "hyve/lang/Sequence.hpp"
#include "hyve/lang/Float.hpp"
#include "hyve/lang/Function.hpp"
#include "hyve/lang/Event.hpp"
#include "hyve/lang/ObservableEvent.hpp"
#include "hyve/lang/Interface.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "hyve/lang/Int.hpp"
#include "hyve/lang/Enum.hpp"
#include "hyve/lang/Metaprocedure.hpp"
#include "hyve/lang/Collection.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Delegate.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Character.hpp"
#include "hyve/lang/Procedure.hpp"
#include "hyve/lang/Boolean.hpp"
#include "hyve/lang/Binary.hpp"
#include "hyve/lang/Bitmask.hpp"
#include "hyve/lang/Array.hpp"
#include "hyve/lang/Type.hpp"
#include "hyve/lang/Member.hpp"
#include "hyve/lang/Callback.hpp"
#include "hyve/lang/Class.hpp"
#include "hyve/lang/Alias.hpp"

/* Variable definitions */
namespace hyve {
    ::hyve::lang::object lang_h;
    namespace lang {
        ::hyve::lang::_class alias_h;
        ::hyve::lang::Class (*alias_o);
        ::hyve::lang::callback alias_init_h;
        ::hyve::lang::member alias_typeName_h;
        ::hyve::lang::type any_h;
        ::hyve::lang::_class array_h;
        ::hyve::lang::Class (*array_o);
        ::hyve::lang::callback array_construct_h;
        ::hyve::lang::callback array_destruct_h;
        ::hyve::lang::member array_elementType_h;
        ::hyve::lang::callback array_init_h;
        ::hyve::lang::bitmask attr_h;
        ::hyve::lang::constant *attr_ATTR_OBSERVABLE_h;
        ::hyve::lang::constant *attr_ATTR_SCOPED_h;
        ::hyve::lang::constant *attr_ATTR_WRITABLE_h;
        ::hyve::lang::_class binary_h;
        ::hyve::lang::Class (*binary_o);
        ::hyve::lang::callback binary_init_h;
        ::hyve::lang::_class bitmask_h;
        ::hyve::lang::Class (*bitmask_o);
        ::hyve::lang::callback bitmask_init_h;
        ::hyve::lang::boolean _bool_h;
        ::hyve::lang::_class boolean_h;
        ::hyve::lang::Class (*boolean_o);
        ::hyve::lang::callback boolean_init_h;
        ::hyve::lang::procedure callback_h;
        ::hyve::lang::Procedure (*callback_o);
        ::hyve::lang::callback callback_bind_h;
        ::hyve::lang::member callback_delegate_h;
        ::hyve::lang::callback callback_init_h;
        ::hyve::lang::character _char_h;
        ::hyve::lang::_class character_h;
        ::hyve::lang::Class (*character_o);
        ::hyve::lang::callback character_init_h;
        ::hyve::lang::_class _class_h;
        ::hyve::lang::Class (*_class_o);
        ::hyve::lang::callback _class__construct_h;
        ::hyve::lang::callback _class__destruct_h;
        ::hyve::lang::method _class_allocSize_h;
        ::hyve::lang::method _class_bindMethod_h;
        ::hyve::lang::delegate _class_construct_h;
        ::hyve::lang::delegate _class_destruct_h;
        ::hyve::lang::member _class_implements_h;
        ::hyve::lang::callback _class_init_h;
        ::hyve::lang::method _class_instanceof_h;
        ::hyve::lang::member _class_interfaceVector_h;
        ::hyve::lang::member _class_observers_h;
        ::hyve::lang::method _class_privateObserver_h;
        ::hyve::lang::_class collection_h;
        ::hyve::lang::Class (*collection_o);
        ::hyve::lang::method collection_castable_h;
        ::hyve::lang::member collection_elementType_h;
        ::hyve::lang::callback collection_init_h;
        ::hyve::lang::member collection_kind_h;
        ::hyve::lang::member collection_max_h;
        ::hyve::lang::metaprocedure collection_size_h;
        ::hyve::lang::_enum collectionKind_h;
        ::hyve::lang::constant *collectionKind_ARRAY_h;
        ::hyve::lang::constant *collectionKind_LIST_h;
        ::hyve::lang::constant *collectionKind_MAP_h;
        ::hyve::lang::constant *collectionKind_SEQUENCE_h;
        ::hyve::lang::_enum compositeKind_h;
        ::hyve::lang::constant *compositeKind_CLASS_h;
        ::hyve::lang::constant *compositeKind_INTERFACE_h;
        ::hyve::lang::constant *compositeKind_PROCEDURE_h;
        ::hyve::lang::constant *compositeKind_STRUCT_h;
        ::hyve::lang::_int constant_h;
        ::hyve::lang::callback constant_init_h;
        ::hyve::lang::procedure delegate_h;
        ::hyve::lang::Procedure (*delegate_o);
        ::hyve::lang::member delegate_id_h;
        ::hyve::lang::callback delegate_init_h;
        ::hyve::lang::interface dispatcher_h;
        ::hyve::lang::Interface (*dispatcher_o);
        ::hyve::lang::method dispatcher_getEvent_h;
        ::hyve::lang::method dispatcher_post_h;
        ::hyve::lang::_class _enum_h;
        ::hyve::lang::Class (*_enum_o);
        ::hyve::lang::method _enum_constant_h;
        ::hyve::lang::member _enum_constants_h;
        ::hyve::lang::callback _enum_construct_h;
        ::hyve::lang::callback _enum_destruct_h;
        ::hyve::lang::callback _enum_init_h;
        ::hyve::lang::_enum equalityKind_h;
        ::hyve::lang::constant *equalityKind_EQ_h;
        ::hyve::lang::constant *equalityKind_GT_h;
        ::hyve::lang::constant *equalityKind_LT_h;
        ::hyve::lang::constant *equalityKind_NEQ_h;
        ::hyve::lang::_class event_h;
        ::hyve::lang::Class (*event_o);
        ::hyve::lang::member event_handled_h;
        ::hyve::lang::member event_kind_h;
        ::hyve::lang::method event_processed_h;
        ::hyve::lang::function event_uniqueKind_h;
        ::hyve::lang::bitmask eventMask_h;
        ::hyve::lang::constant *eventMask_ON_DECLARE_h;
        ::hyve::lang::constant *eventMask_ON_DEFINE_h;
        ::hyve::lang::constant *eventMask_ON_DESTRUCT_h;
        ::hyve::lang::constant *eventMask_ON_INVALIDATE_h;
        ::hyve::lang::constant *eventMask_ON_METAVALUE_h;
        ::hyve::lang::constant *eventMask_ON_SCOPE_h;
        ::hyve::lang::constant *eventMask_ON_SELF_h;
        ::hyve::lang::constant *eventMask_ON_UPDATE_h;
        ::hyve::lang::constant *eventMask_ON_VALUE_h;
        ::hyve::lang::_class _float_h;
        ::hyve::lang::Class (*_float_o);
        ::hyve::lang::callback _float_init_h;
        ::hyve::lang::member _float_max_h;
        ::hyve::lang::member _float_min_h;
        ::hyve::lang::_float float32_h;
        ::hyve::lang::_float float64_h;
        ::hyve::lang::procedure function_h;
        ::hyve::lang::Procedure (*function_o);
        ::hyve::lang::callback function_bind_h;
        ::hyve::lang::member function_impl_h;
        ::hyve::lang::member function_impludata_h;
        ::hyve::lang::callback function_init_h;
        ::hyve::lang::member function_kind_h;
        ::hyve::lang::member function_nextParameterId_h;
        ::hyve::lang::member function_overloaded_h;
        ::hyve::lang::member function_parameters_h;
        ::hyve::lang::member function_resource_h;
        ::hyve::lang::member function_returnType_h;
        ::hyve::lang::member function_size_h;
        ::hyve::lang::callback function_unbind_h;
        ::hyve::lang::_class _int_h;
        ::hyve::lang::Class (*_int_o);
        ::hyve::lang::callback _int_init_h;
        ::hyve::lang::member _int_max_h;
        ::hyve::lang::member _int_min_h;
        ::hyve::lang::_int int16_h;
        ::hyve::lang::_int int32_h;
        ::hyve::lang::_int int64_h;
        ::hyve::lang::_int int8_h;
        ::hyve::lang::_class interface_h;
        ::hyve::lang::Class (*interface_o);
        ::hyve::lang::member interface_base_h;
        ::hyve::lang::method interface_bindMethod_h;
        ::hyve::lang::method interface_compatible_h;
        ::hyve::lang::callback interface_construct_h;
        ::hyve::lang::callback interface_destruct_h;
        ::hyve::lang::callback interface_init_h;
        ::hyve::lang::member interface_kind_h;
        ::hyve::lang::member interface_members_h;
        ::hyve::lang::member interface_methods_h;
        ::hyve::lang::member interface_nextMemberId_h;
        ::hyve::lang::method interface_resolveMember_h;
        ::hyve::lang::method interface_resolveMethod_h;
        ::hyve::lang::method interface_resolveMethodById_h;
        ::hyve::lang::method interface_resolveMethodId_h;
        ::hyve::lang::sequence interfaceSeq_h;
        ::hyve::lang::_struct interfaceVector_h;
        ::hyve::lang::member interfaceVector_interface_h;
        ::hyve::lang::member interfaceVector_vector_h;
        ::hyve::lang::sequence interfaceVectorSeq_h;
        ::hyve::lang::_class list_h;
        ::hyve::lang::Class (*list_o);
        ::hyve::lang::metaprocedure list_append__h;
        ::hyve::lang::metaprocedure list_append_langany_h;
        ::hyve::lang::metaprocedure list_clear_h;
        ::hyve::lang::callback list_construct_h;
        ::hyve::lang::callback list_init_h;
        ::hyve::lang::metaprocedure list_insert__h;
        ::hyve::lang::metaprocedure list_insert_langany_h;
        ::hyve::lang::metaprocedure list_reverse_h;
        ::hyve::lang::_class map_h;
        ::hyve::lang::Class (*map_o);
        ::hyve::lang::callback map_construct_h;
        ::hyve::lang::member map_elementType_h;
        ::hyve::lang::callback map_init_h;
        ::hyve::lang::member map_keyType_h;
        ::hyve::lang::member map_max_h;
        ::hyve::lang::_class member_h;
        ::hyve::lang::Class (*member_o);
        ::hyve::lang::callback member_construct_h;
        ::hyve::lang::member member_id_h;
        ::hyve::lang::callback member_init_h;
        ::hyve::lang::member member_modifiers_h;
        ::hyve::lang::member member_offset_h;
        ::hyve::lang::member member_state_h;
        ::hyve::lang::member member_type_h;
        ::hyve::lang::member member_weak_h;
        ::hyve::lang::sequence memberSeq_h;
        ::hyve::lang::procedure metaprocedure_h;
        ::hyve::lang::Procedure (*metaprocedure_o);
        ::hyve::lang::callback metaprocedure_bind_h;
        ::hyve::lang::procedure method_h;
        ::hyve::lang::Procedure (*method_o);
        ::hyve::lang::callback method_bind_h;
        ::hyve::lang::callback method_init_h;
        ::hyve::lang::member method__virtual_h;
        ::hyve::lang::bitmask modifier_h;
        ::hyve::lang::constant *modifier_CONST_h;
        ::hyve::lang::constant *modifier_GLOBAL_h;
        ::hyve::lang::constant *modifier_LOCAL_h;
        ::hyve::lang::constant *modifier_PRIVATE_h;
        ::hyve::lang::constant *modifier_READONLY_h;
        ::hyve::lang::type object_h;
        ::hyve::lang::sequence objectSeq_h;
        ::hyve::lang::_class observableEvent_h;
        ::hyve::lang::Class (*observableEvent_o);
        ::hyve::lang::member observableEvent_me_h;
        ::hyve::lang::member observableEvent_observable_h;
        ::hyve::lang::member observableEvent_observer_h;
        ::hyve::lang::member observableEvent_source_h;
        ::hyve::lang::procedure observer_h;
        ::hyve::lang::Procedure (*observer_o);
        ::hyve::lang::callback observer_bind_h;
        ::hyve::lang::member observer_delayedBinder_h;
        ::hyve::lang::member observer_dispatcher_h;
        ::hyve::lang::member observer_expression_h;
        ::hyve::lang::callback observer_init_h;
        ::hyve::lang::method observer_listen_h;
        ::hyve::lang::member observer_mask_h;
        ::hyve::lang::member observer_me_h;
        ::hyve::lang::member observer_observable_h;
        ::hyve::lang::member observer_observing_h;
        ::hyve::lang::method observer_setDispatcher_h;
        ::hyve::lang::method observer_silence_h;
        ::hyve::lang::member observer__template_h;
        ::hyve::lang::sequence observerSeq_h;
        ::hyve::lang::binary octet_h;
        ::hyve::lang::_enum operatorKind_h;
        ::hyve::lang::constant *operatorKind_ADD_h;
        ::hyve::lang::constant *operatorKind_AND_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_ADD_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_AND_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_DIV_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_MOD_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_MUL_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_OR_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_SUB_h;
        ::hyve::lang::constant *operatorKind_ASSIGN_XOR_h;
        ::hyve::lang::constant *operatorKind_BRACKET_CLOSE_h;
        ::hyve::lang::constant *operatorKind_BRACKET_OPEN_h;
        ::hyve::lang::constant *operatorKind_COMMA_h;
        ::hyve::lang::constant *operatorKind_COND_AND_h;
        ::hyve::lang::constant *operatorKind_COND_EQ_h;
        ::hyve::lang::constant *operatorKind_COND_GT_h;
        ::hyve::lang::constant *operatorKind_COND_GTEQ_h;
        ::hyve::lang::constant *operatorKind_COND_LT_h;
        ::hyve::lang::constant *operatorKind_COND_LTEQ_h;
        ::hyve::lang::constant *operatorKind_COND_NEQ_h;
        ::hyve::lang::constant *operatorKind_COND_NOT_h;
        ::hyve::lang::constant *operatorKind_COND_OR_h;
        ::hyve::lang::constant *operatorKind_DEC_h;
        ::hyve::lang::constant *operatorKind_DIV_h;
        ::hyve::lang::constant *operatorKind_ELEMENT_CLOSE_h;
        ::hyve::lang::constant *operatorKind_ELEMENT_OPEN_h;
        ::hyve::lang::constant *operatorKind_INC_h;
        ::hyve::lang::constant *operatorKind_MEMBER_RESOLVE_h;
        ::hyve::lang::constant *operatorKind_MOD_h;
        ::hyve::lang::constant *operatorKind_MUL_h;
        ::hyve::lang::constant *operatorKind_NOT_h;
        ::hyve::lang::constant *operatorKind_OR_h;
        ::hyve::lang::constant *operatorKind_REF_h;
        ::hyve::lang::constant *operatorKind_SHIFT_LEFT_h;
        ::hyve::lang::constant *operatorKind_SHIFT_RIGHT_h;
        ::hyve::lang::constant *operatorKind_SUB_h;
        ::hyve::lang::constant *operatorKind_XOR_h;
        ::hyve::lang::_struct parameter_h;
        ::hyve::lang::member parameter_name_h;
        ::hyve::lang::member parameter_passByReference_h;
        ::hyve::lang::member parameter_type_h;
        ::hyve::lang::sequence parameterSeq_h;
        ::hyve::lang::_class primitive_h;
        ::hyve::lang::Class (*primitive_o);
        ::hyve::lang::method primitive_castable_h;
        ::hyve::lang::method primitive_compatible_h;
        ::hyve::lang::callback primitive_construct_h;
        ::hyve::lang::member primitive_convertId_h;
        ::hyve::lang::callback primitive_init_h;
        ::hyve::lang::member primitive_kind_h;
        ::hyve::lang::member primitive_width_h;
        ::hyve::lang::_enum primitiveKind_h;
        ::hyve::lang::constant *primitiveKind_ALIAS_h;
        ::hyve::lang::constant *primitiveKind_BINARY_h;
        ::hyve::lang::constant *primitiveKind_BITMASK_h;
        ::hyve::lang::constant *primitiveKind_BOOLEAN_h;
        ::hyve::lang::constant *primitiveKind_CHARACTER_h;
        ::hyve::lang::constant *primitiveKind_ENUM_h;
        ::hyve::lang::constant *primitiveKind_FLOAT_h;
        ::hyve::lang::constant *primitiveKind_INTEGER_h;
        ::hyve::lang::constant *primitiveKind_TEXT_h;
        ::hyve::lang::constant *primitiveKind_UINTEGER_h;
        ::hyve::lang::_class procedure_h;
        ::hyve::lang::Class (*procedure_o);
        ::hyve::lang::delegate procedure_bind_h;
        ::hyve::lang::callback procedure_init_h;
        ::hyve::lang::member procedure_kind_h;
        ::hyve::lang::delegate procedure_unbind_h;
        ::hyve::lang::_enum procedureKind_h;
        ::hyve::lang::constant *procedureKind_CALLBACK_h;
        ::hyve::lang::constant *procedureKind_DELEGATE_h;
        ::hyve::lang::constant *procedureKind_FUNCTION_h;
        ::hyve::lang::constant *procedureKind_METAPROCEDURE_h;
        ::hyve::lang::constant *procedureKind_METHOD_h;
        ::hyve::lang::constant *procedureKind_OBSERVER_h;
        ::hyve::lang::_class sequence_h;
        ::hyve::lang::Class (*sequence_o);
        ::hyve::lang::callback sequence_construct_h;
        ::hyve::lang::callback sequence_init_h;
        ::hyve::lang::metaprocedure sequence_size_h;
        ::hyve::lang::bitmask state_h;
        ::hyve::lang::constant *state_DECLARED_h;
        ::hyve::lang::constant *state_DEFINED_h;
        ::hyve::lang::constant *state_VALID_h;
        ::hyve::lang::text string_h;
        ::hyve::lang::_class _struct_h;
        ::hyve::lang::Class (*_struct_o);
        ::hyve::lang::member _struct_baseAccess_h;
        ::hyve::lang::method _struct_castable_h;
        ::hyve::lang::method _struct_compatible_h;
        ::hyve::lang::callback _struct_construct_h;
        ::hyve::lang::member _struct_delegateCount_h;
        ::hyve::lang::callback _struct_init_h;
        ::hyve::lang::method _struct_resolveMember_h;
        ::hyve::lang::_class text_h;
        ::hyve::lang::Class (*text_o);
        ::hyve::lang::member text_charWidth_h;
        ::hyve::lang::callback text_init_h;
        ::hyve::lang::member text_length_h;
        ::hyve::lang::_class type_h;
        ::hyve::lang::Class (*type_o);
        ::hyve::lang::callback type__init_h;
        ::hyve::lang::member type_alignment_h;
        ::hyve::lang::method type_alignmentof_h;
        ::hyve::lang::method type_allocSize_h;
        ::hyve::lang::method type_castable_h;
        ::hyve::lang::metaprocedure type_compare_h;
        ::hyve::lang::method type_compatible_h;
        ::hyve::lang::callback type_construct_h;
        ::hyve::lang::metaprocedure type_copy_h;
        ::hyve::lang::member type_defaultType_h;
        ::hyve::lang::callback type_destruct_h;
        ::hyve::lang::metaprocedure type_fullname_h;
        ::hyve::lang::member type_hasResources_h;
        ::hyve::lang::delegate type_init_h;
        ::hyve::lang::member type_kind_h;
        ::hyve::lang::member type_metaprocedures_h;
        ::hyve::lang::metaprocedure type_nameof_h;
        ::hyve::lang::metaprocedure type_parentof_h;
        ::hyve::lang::member type_parentState_h;
        ::hyve::lang::member type_parentType_h;
        ::hyve::lang::member type_reference_h;
        ::hyve::lang::metaprocedure type_relname_h;
        ::hyve::lang::method type_resolveProcedure_h;
        ::hyve::lang::member type_size_h;
        ::hyve::lang::method type__sizeof_h;
        ::hyve::lang::member type_templateId_h;
        ::hyve::lang::metaprocedure type_toString_h;
        ::hyve::lang::metaprocedure type_typeof_h;
        ::hyve::lang::_class _typedef_h;
        ::hyve::lang::Class (*_typedef_o);
        ::hyve::lang::callback _typedef_construct_h;
        ::hyve::lang::callback _typedef_destruct_h;
        ::hyve::lang::callback _typedef_init_h;
        ::hyve::lang::member _typedef_real_h;
        ::hyve::lang::method _typedef_realType_h;
        ::hyve::lang::member _typedef_type_h;
        ::hyve::lang::_enum typeKind_h;
        ::hyve::lang::constant *typeKind_ANY_h;
        ::hyve::lang::constant *typeKind_COLLECTION_h;
        ::hyve::lang::constant *typeKind_COMPOSITE_h;
        ::hyve::lang::constant *typeKind_PRIMITIVE_h;
        ::hyve::lang::constant *typeKind_VOID_h;
        ::hyve::lang::_class uint_h;
        ::hyve::lang::Class (*uint_o);
        ::hyve::lang::callback uint_init_h;
        ::hyve::lang::member uint_max_h;
        ::hyve::lang::member uint_min_h;
        ::hyve::lang::uint uint16_h;
        ::hyve::lang::uint uint32_h;
        ::hyve::lang::uint uint64_h;
        ::hyve::lang::uint uint8_h;
        ::hyve::lang::procedure _virtual_h;
        ::hyve::lang::Procedure (*_virtual_o);
        ::hyve::lang::callback _virtual_init_h;
        ::hyve::lang::type _void_h;
        ::hyve::lang::sequence vtable_h;
        ::hyve::lang::_enum width_h;
        ::hyve::lang::constant *width_WIDTH_16_h;
        ::hyve::lang::constant *width_WIDTH_32_h;
        ::hyve::lang::constant *width_WIDTH_64_h;
        ::hyve::lang::constant *width_WIDTH_8_h;
        ::hyve::lang::constant *width_WIDTH_WORD_h;
        ::hyve::lang::binary word_h;
        ::hyve::lang::uint32 __cpp__class_allocSize(::hyve::lang::_class _this) {
            ::hyve::lang::Class proxy(_this,FALSE);
            return proxy.allocSize_v();
        }
        ::hyve::lang::int16 __cpp__class_bindMethod(::hyve::lang::_class _this, ::hyve::lang::method method) {
            ::hyve::lang::Class proxy(_this,FALSE);
            ::hyve::lang::Method _method(method,FALSE);
            return proxy.bindMethod_v(_method);
        }
        ::hyve::lang::int16 __cpp__class_construct(::hyve::lang::_class _this, ::hyve::lang::object object) {
            ::hyve::lang::Class proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            return proxy.construct(_object);
        }
        ::hyve::lang::_void __cpp__class_destruct(::hyve::lang::_class _this, ::hyve::lang::object object) {
            ::hyve::lang::Class proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            proxy.destruct(_object);
        }
        ::hyve::lang::_bool __cpp__class_instanceof(::hyve::lang::_class _this, ::hyve::lang::object object) {
            ::hyve::lang::Class proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            return proxy.instanceof(_object);
        }
        ::hyve::lang::observer __cpp__class_privateObserver(::hyve::lang::_class _this, ::hyve::lang::object object, ::hyve::lang::observer observer) {
            ::hyve::lang::Class proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            ::hyve::lang::Observer _observer(observer,FALSE);
            return proxy.privateObserver(_object, _observer)._handle();
        }
        ::hyve::lang::_bool __cpp_collection_castable(::hyve::lang::collection _this, ::hyve::lang::type type) {
            ::hyve::lang::Collection proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.castable_v(_type);
        }
        ::hyve::lang::observableEvent __cpp_dispatcher_getEvent(::hyve::lang::dispatcher _this, ::hyve::lang::observer observer, ::hyve::lang::object me, ::hyve::lang::object observable, ::hyve::lang::object src) {
            ::hyve::lang::Dispatcher proxy(_this,FALSE);
            ::hyve::lang::Observer _observer(observer,FALSE);
            ::hyve::lang::Object _me(me,FALSE);
            ::hyve::lang::Object _observable(observable,FALSE);
            ::hyve::lang::Object _src(src,FALSE);
            return proxy.getEvent_v(_observer, _me, _observable, _src)._handle();
        }
        ::hyve::lang::_void __cpp_dispatcher_post(::hyve::lang::dispatcher _this, ::hyve::lang::event event) {
            ::hyve::lang::Dispatcher proxy(_this,FALSE);
            ::hyve::lang::Event _event(event,FALSE);
            proxy.post_v(_event);
        }
        ::hyve::lang::object __cpp__enum_constant(::hyve::lang::_enum _this, ::hyve::lang::int32 value) {
            ::hyve::lang::Enum proxy(_this,FALSE);
            return proxy.constant(value)._handle();
        }
        ::hyve::lang::_void __cpp_event_processed(::hyve::lang::event _this) {
            ::hyve::lang::Event proxy(_this,FALSE);
            proxy.processed();
        }
        ::hyve::lang::int16 __cpp_event_uniqueKind() {
            return ::hyve::lang::Event::uniqueKind();
        }
        ::hyve::lang::int16 __cpp_interface_bindMethod(::hyve::lang::interface _this, ::hyve::lang::method method) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            ::hyve::lang::Method _method(method,FALSE);
            return proxy.bindMethod_v(_method);
        }
        ::hyve::lang::_bool __cpp_interface_compatible(::hyve::lang::interface _this, ::hyve::lang::type type) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.compatible_v(_type);
        }
        ::hyve::lang::member __cpp_interface_resolveMember(::hyve::lang::interface _this, ::hyve::lang::string name) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            return proxy.resolveMember_v(name)._handle();
        }
        ::hyve::lang::method __cpp_interface_resolveMethod(::hyve::lang::interface _this, ::hyve::lang::string name) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            return proxy.resolveMethod(name)._handle();
        }
        ::hyve::lang::method __cpp_interface_resolveMethodById(::hyve::lang::interface _this, ::hyve::lang::uint32 id) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            return proxy.resolveMethodById(id)._handle();
        }
        ::hyve::lang::uint32 __cpp_interface_resolveMethodId(::hyve::lang::interface _this, ::hyve::lang::string name) {
            ::hyve::lang::Interface proxy(_this,FALSE);
            return proxy.resolveMethodId(name);
        }
        ::hyve::lang::int16 __cpp_observer_listen(::hyve::lang::observer _this, ::hyve::lang::object observable, ::hyve::lang::object me) {
            ::hyve::lang::Observer proxy(_this,FALSE);
            ::hyve::lang::Object _observable(observable,FALSE);
            ::hyve::lang::Object _me(me,FALSE);
            return proxy.listen(_observable, _me);
        }
        ::hyve::lang::_void __cpp_observer_setDispatcher(::hyve::lang::observer _this, ::hyve::lang::dispatcher dispatcher) {
            ::hyve::lang::Observer proxy(_this,FALSE);
            ::hyve::lang::Dispatcher _dispatcher(dispatcher,FALSE);
            proxy.setDispatcher(_dispatcher);
        }
        ::hyve::lang::int16 __cpp_observer_silence(::hyve::lang::observer _this, ::hyve::lang::object me) {
            ::hyve::lang::Observer proxy(_this,FALSE);
            ::hyve::lang::Object _me(me,FALSE);
            return proxy.silence(_me);
        }
        ::hyve::lang::_bool __cpp_primitive_castable(::hyve::lang::primitive _this, ::hyve::lang::type type) {
            ::hyve::lang::Primitive proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.castable_v(_type);
        }
        ::hyve::lang::_bool __cpp_primitive_compatible(::hyve::lang::primitive _this, ::hyve::lang::type type) {
            ::hyve::lang::Primitive proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.compatible_v(_type);
        }
        ::hyve::lang::int16 __cpp_procedure_bind(::hyve::lang::procedure _this, ::hyve::lang::object object) {
            ::hyve::lang::Procedure proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            return proxy.bind(_object);
        }
        ::hyve::lang::_void __cpp_procedure_unbind(::hyve::lang::procedure _this, ::hyve::lang::object object) {
            ::hyve::lang::Procedure proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            proxy.unbind(_object);
        }
        ::hyve::lang::_bool __cpp__struct_castable(::hyve::lang::_struct _this, ::hyve::lang::type type) {
            ::hyve::lang::Struct proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.castable_v(_type);
        }
        ::hyve::lang::_bool __cpp__struct_compatible(::hyve::lang::_struct _this, ::hyve::lang::type type) {
            ::hyve::lang::Struct proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.compatible_v(_type);
        }
        ::hyve::lang::member __cpp__struct_resolveMember(::hyve::lang::_struct _this, ::hyve::lang::string name) {
            ::hyve::lang::Struct proxy(_this,FALSE);
            return proxy.resolveMember_v(name)._handle();
        }
        ::hyve::lang::uint16 __cpp_type_alignmentof(::hyve::lang::type _this) {
            ::hyve::lang::Type proxy(_this,FALSE);
            return proxy.alignmentof();
        }
        ::hyve::lang::uint32 __cpp_type_allocSize(::hyve::lang::type _this) {
            ::hyve::lang::Type proxy(_this,FALSE);
            return proxy.allocSize_v();
        }
        ::hyve::lang::_bool __cpp_type_castable(::hyve::lang::type _this, ::hyve::lang::type type) {
            ::hyve::lang::Type proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.castable_v(_type);
        }
        ::hyve::lang::_bool __cpp_type_compatible(::hyve::lang::type _this, ::hyve::lang::type type) {
            ::hyve::lang::Type proxy(_this,FALSE);
            ::hyve::lang::Type _type(type,FALSE);
            return proxy.compatible_v(_type);
        }
        ::hyve::lang::int16 __cpp_type_init(::hyve::lang::type _this, ::hyve::lang::object object) {
            ::hyve::lang::Type proxy(_this,FALSE);
            ::hyve::lang::Object _object(object,FALSE);
            return proxy.init(_object);
        }
        ::hyve::lang::function __cpp_type_resolveProcedure(::hyve::lang::type _this, ::hyve::lang::string name) {
            ::hyve::lang::Type proxy(_this,FALSE);
            return proxy.resolveProcedure(name)._handle();
        }
        ::hyve::lang::uint32 __cpp_type__sizeof(::hyve::lang::type _this) {
            ::hyve::lang::Type proxy(_this,FALSE);
            return proxy._sizeof();
        }
        ::hyve::lang::type __cpp__typedef_realType(::hyve::lang::_typedef _this) {
            ::hyve::lang::Typedef proxy(_this,FALSE);
            return proxy.realType()._handle();
        }
        
        /* Load objects in database */
        void unload(void* udata) {
            (void)udata;
            delete ::hyve::lang::alias_o;
            delete ::hyve::lang::array_o;
            delete ::hyve::lang::binary_o;
            delete ::hyve::lang::bitmask_o;
            delete ::hyve::lang::boolean_o;
            delete ::hyve::lang::callback_o;
            delete ::hyve::lang::character_o;
            delete ::hyve::lang::_class_o;
            delete ::hyve::lang::collection_o;
            delete ::hyve::lang::delegate_o;
            delete ::hyve::lang::dispatcher_o;
            delete ::hyve::lang::_enum_o;
            delete ::hyve::lang::event_o;
            delete ::hyve::lang::_float_o;
            delete ::hyve::lang::function_o;
            delete ::hyve::lang::_int_o;
            delete ::hyve::lang::interface_o;
            delete ::hyve::lang::list_o;
            delete ::hyve::lang::map_o;
            delete ::hyve::lang::member_o;
            delete ::hyve::lang::metaprocedure_o;
            delete ::hyve::lang::method_o;
            delete ::hyve::lang::observableEvent_o;
            delete ::hyve::lang::observer_o;
            delete ::hyve::lang::primitive_o;
            delete ::hyve::lang::procedure_o;
            delete ::hyve::lang::sequence_o;
            delete ::hyve::lang::_struct_o;
            delete ::hyve::lang::text_o;
            delete ::hyve::lang::type_o;
            delete ::hyve::lang::_typedef_o;
            delete ::hyve::lang::uint_o;
            delete ::hyve::lang::_virtual_o;
        }
        
        /* Load objects in database */
        int load(void) {
            ::hyve::lang::object _a_; /* Used for resolving anonymous objects */
            _a_ = NULL;

            /* Declare ::hyve::lang */
            if (!(::hyve::lang_h = (::hyve::lang::object)::hyve::resolve(NULL, NULL, "::hyve::lang", "load: check if object '::hyve::lang' already exists."))) {
                ::hyve::lang_h = (::hyve::lang::object)::hyve::declare(::hyve_h, "lang", ((::hyve::lang::_typedef)::hyve::lang::object_h));
                if (!::hyve::lang_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang_h);
            }

            /* Declare ::hyve::lang::alias */
            if (!(::hyve::lang::alias_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::alias", "load: check if object '::hyve::lang::alias' already exists."))) {
                ::hyve::lang::alias_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "alias", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::alias_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::alias'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::alias_h);
            }

            /* Declare ::hyve::lang::alias::init(lang::alias object) */
            if (!(::hyve::lang::alias_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::alias::init(lang::alias object)", "load: check if object '::hyve::lang::alias::init(lang::alias object)' already exists."))) {
                ::hyve::lang::alias_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::alias_h, "init(lang::alias object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::alias_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::alias::init(lang::alias object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::alias_init_h);
            }

            /* Declare ::hyve::lang::alias::typeName */
            if (!(::hyve::lang::alias_typeName_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::alias::typeName", "load: check if object '::hyve::lang::alias::typeName' already exists."))) {
                ::hyve::lang::alias_typeName_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::alias_h, "typeName", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::alias_typeName_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::alias::typeName'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::alias_typeName_h);
            }

            /* Declare ::hyve::lang::any */
            if (!(::hyve::lang::any_h = (::hyve::lang::type)::hyve::resolve(NULL, NULL, "::hyve::lang::any", "load: check if object '::hyve::lang::any' already exists."))) {
                ::hyve::lang::any_h = (::hyve::lang::type)::hyve::declare(::hyve::lang_h, "any", ((::hyve::lang::_typedef)::hyve::lang::type_h));
                if (!::hyve::lang::any_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::any'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::any_h);
            }

            /* Declare ::hyve::lang::array */
            if (!(::hyve::lang::array_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::array", "load: check if object '::hyve::lang::array' already exists."))) {
                ::hyve::lang::array_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "array", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::array_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::array'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::array_h);
            }

            /* Declare ::hyve::lang::array::construct(lang::array object) */
            if (!(::hyve::lang::array_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::array::construct(lang::array object)", "load: check if object '::hyve::lang::array::construct(lang::array object)' already exists."))) {
                ::hyve::lang::array_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::array_h, "construct(lang::array object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::array_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::array::construct(lang::array object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::array_construct_h);
            }

            /* Declare ::hyve::lang::array::destruct(lang::array object) */
            if (!(::hyve::lang::array_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::array::destruct(lang::array object)", "load: check if object '::hyve::lang::array::destruct(lang::array object)' already exists."))) {
                ::hyve::lang::array_destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::array_h, "destruct(lang::array object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::array_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::array::destruct(lang::array object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::array_destruct_h);
            }

            /* Declare ::hyve::lang::array::elementType */
            if (!(::hyve::lang::array_elementType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::array::elementType", "load: check if object '::hyve::lang::array::elementType' already exists."))) {
                ::hyve::lang::array_elementType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::array_h, "elementType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::array_elementType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::array::elementType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::array_elementType_h);
            }

            /* Declare ::hyve::lang::array::init(lang::array object) */
            if (!(::hyve::lang::array_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::array::init(lang::array object)", "load: check if object '::hyve::lang::array::init(lang::array object)' already exists."))) {
                ::hyve::lang::array_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::array_h, "init(lang::array object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::array_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::array::init(lang::array object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::array_init_h);
            }

            /* Declare ::hyve::lang::attr */
            if (!(::hyve::lang::attr_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::hyve::lang::attr", "load: check if object '::hyve::lang::attr' already exists."))) {
                ::hyve::lang::attr_h = (::hyve::lang::bitmask)::hyve::declare(::hyve::lang_h, "attr", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
                if (!::hyve::lang::attr_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::attr'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::attr_h);
            }

            /* Declare ::hyve::lang::attr::ATTR_OBSERVABLE */
            if (!(::hyve::lang::attr_ATTR_OBSERVABLE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::attr::ATTR_OBSERVABLE", "load: check if object '::hyve::lang::attr::ATTR_OBSERVABLE' already exists."))) {
                ::hyve::lang::attr_ATTR_OBSERVABLE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::attr_h, "ATTR_OBSERVABLE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::attr_ATTR_OBSERVABLE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::attr::ATTR_OBSERVABLE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::attr_ATTR_OBSERVABLE_h);
            }

            /* Declare ::hyve::lang::attr::ATTR_SCOPED */
            if (!(::hyve::lang::attr_ATTR_SCOPED_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::attr::ATTR_SCOPED", "load: check if object '::hyve::lang::attr::ATTR_SCOPED' already exists."))) {
                ::hyve::lang::attr_ATTR_SCOPED_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::attr_h, "ATTR_SCOPED", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::attr_ATTR_SCOPED_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::attr::ATTR_SCOPED'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::attr_ATTR_SCOPED_h);
            }

            /* Declare ::hyve::lang::attr::ATTR_WRITABLE */
            if (!(::hyve::lang::attr_ATTR_WRITABLE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::attr::ATTR_WRITABLE", "load: check if object '::hyve::lang::attr::ATTR_WRITABLE' already exists."))) {
                ::hyve::lang::attr_ATTR_WRITABLE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::attr_h, "ATTR_WRITABLE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::attr_ATTR_WRITABLE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::attr::ATTR_WRITABLE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::attr_ATTR_WRITABLE_h);
            }

            /* Declare ::hyve::lang::binary */
            if (!(::hyve::lang::binary_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::binary", "load: check if object '::hyve::lang::binary' already exists."))) {
                ::hyve::lang::binary_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "binary", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::binary_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::binary'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::binary_h);
            }

            /* Declare ::hyve::lang::binary::init(lang::binary object) */
            if (!(::hyve::lang::binary_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::binary::init(lang::binary object)", "load: check if object '::hyve::lang::binary::init(lang::binary object)' already exists."))) {
                ::hyve::lang::binary_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::binary_h, "init(lang::binary object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::binary_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::binary::init(lang::binary object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::binary_init_h);
            }

            /* Declare ::hyve::lang::bitmask */
            if (!(::hyve::lang::bitmask_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::bitmask", "load: check if object '::hyve::lang::bitmask' already exists."))) {
                ::hyve::lang::bitmask_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "bitmask", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::bitmask_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::bitmask'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::bitmask_h);
            }

            /* Declare ::hyve::lang::bitmask::init(lang::bitmask object) */
            if (!(::hyve::lang::bitmask_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::bitmask::init(lang::bitmask object)", "load: check if object '::hyve::lang::bitmask::init(lang::bitmask object)' already exists."))) {
                ::hyve::lang::bitmask_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::bitmask_h, "init(lang::bitmask object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::bitmask_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::bitmask::init(lang::bitmask object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::bitmask_init_h);
            }

            /* Declare ::hyve::lang::bool */
            if (!(::hyve::lang::_bool_h = (::hyve::lang::boolean)::hyve::resolve(NULL, NULL, "::hyve::lang::bool", "load: check if object '::hyve::lang::bool' already exists."))) {
                ::hyve::lang::_bool_h = (::hyve::lang::boolean)::hyve::declare(::hyve::lang_h, "bool", ((::hyve::lang::_typedef)::hyve::lang::boolean_h));
                if (!::hyve::lang::_bool_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::bool'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_bool_h);
            }

            /* Declare ::hyve::lang::boolean */
            if (!(::hyve::lang::boolean_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::boolean", "load: check if object '::hyve::lang::boolean' already exists."))) {
                ::hyve::lang::boolean_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "boolean", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::boolean_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::boolean'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::boolean_h);
            }

            /* Declare ::hyve::lang::boolean::init(lang::boolean object) */
            if (!(::hyve::lang::boolean_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::boolean::init(lang::boolean object)", "load: check if object '::hyve::lang::boolean::init(lang::boolean object)' already exists."))) {
                ::hyve::lang::boolean_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::boolean_h, "init(lang::boolean object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::boolean_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::boolean::init(lang::boolean object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::boolean_init_h);
            }

            /* Declare ::hyve::lang::callback */
            if (!(::hyve::lang::callback_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::callback", "load: check if object '::hyve::lang::callback' already exists."))) {
                ::hyve::lang::callback_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "callback", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::callback_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::callback'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::callback_h);
            }

            /* Declare ::hyve::lang::callback::bind(lang::callback object) */
            if (!(::hyve::lang::callback_bind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::callback::bind(lang::callback object)", "load: check if object '::hyve::lang::callback::bind(lang::callback object)' already exists."))) {
                ::hyve::lang::callback_bind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::callback_h, "bind(lang::callback object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::callback_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::callback::bind(lang::callback object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::callback_bind_h);
            }

            /* Declare ::hyve::lang::callback::delegate */
            if (!(::hyve::lang::callback_delegate_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::callback::delegate", "load: check if object '::hyve::lang::callback::delegate' already exists."))) {
                ::hyve::lang::callback_delegate_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::callback_h, "delegate", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::callback_delegate_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::callback::delegate'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::callback_delegate_h);
            }

            /* Declare ::hyve::lang::callback::init(lang::callback object) */
            if (!(::hyve::lang::callback_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::callback::init(lang::callback object)", "load: check if object '::hyve::lang::callback::init(lang::callback object)' already exists."))) {
                ::hyve::lang::callback_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::callback_h, "init(lang::callback object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::callback_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::callback::init(lang::callback object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::callback_init_h);
            }

            /* Declare ::hyve::lang::char */
            if (!(::hyve::lang::_char_h = (::hyve::lang::character)::hyve::resolve(NULL, NULL, "::hyve::lang::char", "load: check if object '::hyve::lang::char' already exists."))) {
                ::hyve::lang::_char_h = (::hyve::lang::character)::hyve::declare(::hyve::lang_h, "char", ((::hyve::lang::_typedef)::hyve::lang::character_h));
                if (!::hyve::lang::_char_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::char'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_char_h);
            }

            /* Declare ::hyve::lang::character */
            if (!(::hyve::lang::character_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::character", "load: check if object '::hyve::lang::character' already exists."))) {
                ::hyve::lang::character_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "character", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::character_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::character'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::character_h);
            }

            /* Declare ::hyve::lang::character::init(lang::character object) */
            if (!(::hyve::lang::character_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::character::init(lang::character object)", "load: check if object '::hyve::lang::character::init(lang::character object)' already exists."))) {
                ::hyve::lang::character_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::character_h, "init(lang::character object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::character_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::character::init(lang::character object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::character_init_h);
            }

            /* Declare ::hyve::lang::class */
            if (!(::hyve::lang::_class_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::class", "load: check if object '::hyve::lang::class' already exists."))) {
                ::hyve::lang::_class_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "class", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_class_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_h);
            }

            /* Declare ::hyve::lang::class::_construct(lang::class object) */
            if (!(::hyve::lang::_class__construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::class::_construct(lang::class object)", "load: check if object '::hyve::lang::class::_construct(lang::class object)' already exists."))) {
                ::hyve::lang::_class__construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_class_h, "_construct(lang::class object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_class__construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::_construct(lang::class object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class__construct_h);
            }

            /* Declare ::hyve::lang::class::_destruct(lang::class object) */
            if (!(::hyve::lang::_class__destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::class::_destruct(lang::class object)", "load: check if object '::hyve::lang::class::_destruct(lang::class object)' already exists."))) {
                ::hyve::lang::_class__destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_class_h, "_destruct(lang::class object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_class__destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::_destruct(lang::class object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class__destruct_h);
            }

            /* Declare ::hyve::lang::class::allocSize() */
            if (!(::hyve::lang::_class_allocSize_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::class::allocSize()", "load: check if object '::hyve::lang::class::allocSize()' already exists."))) {
                ::hyve::lang::_class_allocSize_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_class_h, "allocSize()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_class_allocSize_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::allocSize()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_allocSize_h);
            }

            /* Declare ::hyve::lang::class::bindMethod(lang::method method) */
            if (!(::hyve::lang::_class_bindMethod_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::class::bindMethod(lang::method method)", "load: check if object '::hyve::lang::class::bindMethod(lang::method method)' already exists."))) {
                ::hyve::lang::_class_bindMethod_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_class_h, "bindMethod(lang::method method)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_class_bindMethod_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::bindMethod(lang::method method)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_bindMethod_h);
            }

            /* Declare ::hyve::lang::class::construct(lang::object object) */
            if (!(::hyve::lang::_class_construct_h = (::hyve::lang::delegate)::hyve::resolve(NULL, NULL, "::hyve::lang::class::construct(lang::object object)", "load: check if object '::hyve::lang::class::construct(lang::object object)' already exists."))) {
                ::hyve::lang::_class_construct_h = (::hyve::lang::delegate)::hyve::declare(::hyve::lang::_class_h, "construct(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::delegate_h));
                if (!::hyve::lang::_class_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::construct(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_construct_h);
            }

            /* Declare ::hyve::lang::class::destruct(lang::object object) */
            if (!(::hyve::lang::_class_destruct_h = (::hyve::lang::delegate)::hyve::resolve(NULL, NULL, "::hyve::lang::class::destruct(lang::object object)", "load: check if object '::hyve::lang::class::destruct(lang::object object)' already exists."))) {
                ::hyve::lang::_class_destruct_h = (::hyve::lang::delegate)::hyve::declare(::hyve::lang::_class_h, "destruct(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::delegate_h));
                if (!::hyve::lang::_class_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::destruct(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_destruct_h);
            }

            /* Declare ::hyve::lang::class::implements */
            if (!(::hyve::lang::_class_implements_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::class::implements", "load: check if object '::hyve::lang::class::implements' already exists."))) {
                ::hyve::lang::_class_implements_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_class_h, "implements", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_class_implements_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::implements'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_implements_h);
            }

            /* Declare ::hyve::lang::class::init(lang::class object) */
            if (!(::hyve::lang::_class_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::class::init(lang::class object)", "load: check if object '::hyve::lang::class::init(lang::class object)' already exists."))) {
                ::hyve::lang::_class_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_class_h, "init(lang::class object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_class_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::init(lang::class object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_init_h);
            }

            /* Declare ::hyve::lang::class::instanceof(lang::object object) */
            if (!(::hyve::lang::_class_instanceof_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::class::instanceof(lang::object object)", "load: check if object '::hyve::lang::class::instanceof(lang::object object)' already exists."))) {
                ::hyve::lang::_class_instanceof_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_class_h, "instanceof(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_class_instanceof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::instanceof(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_instanceof_h);
            }

            /* Declare ::hyve::lang::class::interfaceVector */
            if (!(::hyve::lang::_class_interfaceVector_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::class::interfaceVector", "load: check if object '::hyve::lang::class::interfaceVector' already exists."))) {
                ::hyve::lang::_class_interfaceVector_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_class_h, "interfaceVector", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_class_interfaceVector_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::interfaceVector'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_interfaceVector_h);
            }

            /* Declare ::hyve::lang::class::observers */
            if (!(::hyve::lang::_class_observers_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::class::observers", "load: check if object '::hyve::lang::class::observers' already exists."))) {
                ::hyve::lang::_class_observers_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_class_h, "observers", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_class_observers_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::observers'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_observers_h);
            }

            /* Declare ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
            if (!(::hyve::lang::_class_privateObserver_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::class::privateObserver(lang::object object,lang::observer observer)", "load: check if object '::hyve::lang::class::privateObserver(lang::object object,lang::observer observer)' already exists."))) {
                ::hyve::lang::_class_privateObserver_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_class_h, "privateObserver(lang::object object,lang::observer observer)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_class_privateObserver_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::class::privateObserver(lang::object object,lang::observer observer)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_class_privateObserver_h);
            }

            /* Declare ::hyve::lang::collection */
            if (!(::hyve::lang::collection_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::collection", "load: check if object '::hyve::lang::collection' already exists."))) {
                ::hyve::lang::collection_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "collection", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::collection_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_h);
            }

            /* Declare ::hyve::lang::collection::castable(lang::type type) */
            if (!(::hyve::lang::collection_castable_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::castable(lang::type type)", "load: check if object '::hyve::lang::collection::castable(lang::type type)' already exists."))) {
                ::hyve::lang::collection_castable_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::collection_h, "castable(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::collection_castable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::castable(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_castable_h);
            }

            /* Declare ::hyve::lang::collection::elementType */
            if (!(::hyve::lang::collection_elementType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::elementType", "load: check if object '::hyve::lang::collection::elementType' already exists."))) {
                ::hyve::lang::collection_elementType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::collection_h, "elementType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::collection_elementType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::elementType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_elementType_h);
            }

            /* Declare ::hyve::lang::collection::init(lang::collection object) */
            if (!(::hyve::lang::collection_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::init(lang::collection object)", "load: check if object '::hyve::lang::collection::init(lang::collection object)' already exists."))) {
                ::hyve::lang::collection_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::collection_h, "init(lang::collection object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::collection_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::init(lang::collection object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_init_h);
            }

            /* Declare ::hyve::lang::collection::kind */
            if (!(::hyve::lang::collection_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::kind", "load: check if object '::hyve::lang::collection::kind' already exists."))) {
                ::hyve::lang::collection_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::collection_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::collection_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_kind_h);
            }

            /* Declare ::hyve::lang::collection::max */
            if (!(::hyve::lang::collection_max_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::max", "load: check if object '::hyve::lang::collection::max' already exists."))) {
                ::hyve::lang::collection_max_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::collection_h, "max", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::collection_max_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::max'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_max_h);
            }

            /* Declare ::hyve::lang::collection::size() */
            if (!(::hyve::lang::collection_size_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::collection::size()", "load: check if object '::hyve::lang::collection::size()' already exists."))) {
                ::hyve::lang::collection_size_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::collection_h, "size()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::collection_size_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collection::size()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collection_size_h);
            }

            /* Declare ::hyve::lang::collectionKind */
            if (!(::hyve::lang::collectionKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::collectionKind", "load: check if object '::hyve::lang::collectionKind' already exists."))) {
                ::hyve::lang::collectionKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "collectionKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::collectionKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collectionKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collectionKind_h);
            }

            /* Declare ::hyve::lang::collectionKind::ARRAY */
            if (!(::hyve::lang::collectionKind_ARRAY_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::collectionKind::ARRAY", "load: check if object '::hyve::lang::collectionKind::ARRAY' already exists."))) {
                ::hyve::lang::collectionKind_ARRAY_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::collectionKind_h, "ARRAY", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::collectionKind_ARRAY_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collectionKind::ARRAY'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collectionKind_ARRAY_h);
            }

            /* Declare ::hyve::lang::collectionKind::LIST */
            if (!(::hyve::lang::collectionKind_LIST_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::collectionKind::LIST", "load: check if object '::hyve::lang::collectionKind::LIST' already exists."))) {
                ::hyve::lang::collectionKind_LIST_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::collectionKind_h, "LIST", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::collectionKind_LIST_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collectionKind::LIST'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collectionKind_LIST_h);
            }

            /* Declare ::hyve::lang::collectionKind::MAP */
            if (!(::hyve::lang::collectionKind_MAP_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::collectionKind::MAP", "load: check if object '::hyve::lang::collectionKind::MAP' already exists."))) {
                ::hyve::lang::collectionKind_MAP_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::collectionKind_h, "MAP", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::collectionKind_MAP_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collectionKind::MAP'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collectionKind_MAP_h);
            }

            /* Declare ::hyve::lang::collectionKind::SEQUENCE */
            if (!(::hyve::lang::collectionKind_SEQUENCE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::collectionKind::SEQUENCE", "load: check if object '::hyve::lang::collectionKind::SEQUENCE' already exists."))) {
                ::hyve::lang::collectionKind_SEQUENCE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::collectionKind_h, "SEQUENCE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::collectionKind_SEQUENCE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::collectionKind::SEQUENCE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::collectionKind_SEQUENCE_h);
            }

            /* Declare ::hyve::lang::compositeKind */
            if (!(::hyve::lang::compositeKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::compositeKind", "load: check if object '::hyve::lang::compositeKind' already exists."))) {
                ::hyve::lang::compositeKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "compositeKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::compositeKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::compositeKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::compositeKind_h);
            }

            /* Declare ::hyve::lang::compositeKind::CLASS */
            if (!(::hyve::lang::compositeKind_CLASS_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::compositeKind::CLASS", "load: check if object '::hyve::lang::compositeKind::CLASS' already exists."))) {
                ::hyve::lang::compositeKind_CLASS_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::compositeKind_h, "CLASS", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::compositeKind_CLASS_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::compositeKind::CLASS'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::compositeKind_CLASS_h);
            }

            /* Declare ::hyve::lang::compositeKind::INTERFACE */
            if (!(::hyve::lang::compositeKind_INTERFACE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::compositeKind::INTERFACE", "load: check if object '::hyve::lang::compositeKind::INTERFACE' already exists."))) {
                ::hyve::lang::compositeKind_INTERFACE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::compositeKind_h, "INTERFACE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::compositeKind_INTERFACE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::compositeKind::INTERFACE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::compositeKind_INTERFACE_h);
            }

            /* Declare ::hyve::lang::compositeKind::PROCEDURE */
            if (!(::hyve::lang::compositeKind_PROCEDURE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::compositeKind::PROCEDURE", "load: check if object '::hyve::lang::compositeKind::PROCEDURE' already exists."))) {
                ::hyve::lang::compositeKind_PROCEDURE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::compositeKind_h, "PROCEDURE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::compositeKind_PROCEDURE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::compositeKind::PROCEDURE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::compositeKind_PROCEDURE_h);
            }

            /* Declare ::hyve::lang::compositeKind::STRUCT */
            if (!(::hyve::lang::compositeKind_STRUCT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::compositeKind::STRUCT", "load: check if object '::hyve::lang::compositeKind::STRUCT' already exists."))) {
                ::hyve::lang::compositeKind_STRUCT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::compositeKind_h, "STRUCT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::compositeKind_STRUCT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::compositeKind::STRUCT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::compositeKind_STRUCT_h);
            }

            /* Declare ::hyve::lang::constant */
            if (!(::hyve::lang::constant_h = (::hyve::lang::_int)::hyve::resolve(NULL, NULL, "::hyve::lang::constant", "load: check if object '::hyve::lang::constant' already exists."))) {
                ::hyve::lang::constant_h = (::hyve::lang::_int)::hyve::declare(::hyve::lang_h, "constant", ((::hyve::lang::_typedef)::hyve::lang::_int_h));
                if (!::hyve::lang::constant_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::constant'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::constant_h);
            }

            /* Declare ::hyve::lang::constant::init(constant object) */
            if (!(::hyve::lang::constant_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::constant::init(constant object)", "load: check if object '::hyve::lang::constant::init(constant object)' already exists."))) {
                ::hyve::lang::constant_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::constant_h, "init(constant object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::constant_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::constant::init(constant object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::constant_init_h);
            }

            /* Declare ::hyve::lang::delegate */
            if (!(::hyve::lang::delegate_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::delegate", "load: check if object '::hyve::lang::delegate' already exists."))) {
                ::hyve::lang::delegate_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "delegate", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::delegate_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::delegate'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::delegate_h);
            }

            /* Declare ::hyve::lang::delegate::id */
            if (!(::hyve::lang::delegate_id_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::delegate::id", "load: check if object '::hyve::lang::delegate::id' already exists."))) {
                ::hyve::lang::delegate_id_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::delegate_h, "id", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::delegate_id_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::delegate::id'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::delegate_id_h);
            }

            /* Declare ::hyve::lang::delegate::init(lang::delegate object) */
            if (!(::hyve::lang::delegate_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::delegate::init(lang::delegate object)", "load: check if object '::hyve::lang::delegate::init(lang::delegate object)' already exists."))) {
                ::hyve::lang::delegate_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::delegate_h, "init(lang::delegate object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::delegate_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::delegate::init(lang::delegate object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::delegate_init_h);
            }

            /* Declare ::hyve::lang::dispatcher */
            if (!(::hyve::lang::dispatcher_h = (::hyve::lang::interface)::hyve::resolve(NULL, NULL, "::hyve::lang::dispatcher", "load: check if object '::hyve::lang::dispatcher' already exists."))) {
                ::hyve::lang::dispatcher_h = (::hyve::lang::interface)::hyve::declare(::hyve::lang_h, "dispatcher", ((::hyve::lang::_typedef)::hyve::lang::interface_h));
                if (!::hyve::lang::dispatcher_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::dispatcher'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::dispatcher_h);
            }

            /* Declare ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
            if (!(::hyve::lang::dispatcher_getEvent_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)", "load: check if object '::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)' already exists."))) {
                ::hyve::lang::dispatcher_getEvent_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::dispatcher_h, "getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::dispatcher_getEvent_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::dispatcher_getEvent_h);
            }

            /* Declare ::hyve::lang::dispatcher::post(lang::event event) */
            if (!(::hyve::lang::dispatcher_post_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::dispatcher::post(lang::event event)", "load: check if object '::hyve::lang::dispatcher::post(lang::event event)' already exists."))) {
                ::hyve::lang::dispatcher_post_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::dispatcher_h, "post(lang::event event)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::dispatcher_post_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::dispatcher::post(lang::event event)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::dispatcher_post_h);
            }

            /* Declare ::hyve::lang::enum */
            if (!(::hyve::lang::_enum_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::enum", "load: check if object '::hyve::lang::enum' already exists."))) {
                ::hyve::lang::_enum_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "enum", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_enum_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_h);
            }

            /* Declare ::hyve::lang::enum::constant(lang::int32 value) */
            if (!(::hyve::lang::_enum_constant_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::enum::constant(lang::int32 value)", "load: check if object '::hyve::lang::enum::constant(lang::int32 value)' already exists."))) {
                ::hyve::lang::_enum_constant_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_enum_h, "constant(lang::int32 value)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_enum_constant_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum::constant(lang::int32 value)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_constant_h);
            }

            /* Declare ::hyve::lang::enum::constants */
            if (!(::hyve::lang::_enum_constants_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::enum::constants", "load: check if object '::hyve::lang::enum::constants' already exists."))) {
                ::hyve::lang::_enum_constants_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_enum_h, "constants", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_enum_constants_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum::constants'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_constants_h);
            }

            /* Declare ::hyve::lang::enum::construct(lang::enum object) */
            if (!(::hyve::lang::_enum_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::enum::construct(lang::enum object)", "load: check if object '::hyve::lang::enum::construct(lang::enum object)' already exists."))) {
                ::hyve::lang::_enum_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_enum_h, "construct(lang::enum object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_enum_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum::construct(lang::enum object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_construct_h);
            }

            /* Declare ::hyve::lang::enum::destruct(lang::enum object) */
            if (!(::hyve::lang::_enum_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::enum::destruct(lang::enum object)", "load: check if object '::hyve::lang::enum::destruct(lang::enum object)' already exists."))) {
                ::hyve::lang::_enum_destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_enum_h, "destruct(lang::enum object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_enum_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum::destruct(lang::enum object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_destruct_h);
            }

            /* Declare ::hyve::lang::enum::init(lang::enum object) */
            if (!(::hyve::lang::_enum_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::enum::init(lang::enum object)", "load: check if object '::hyve::lang::enum::init(lang::enum object)' already exists."))) {
                ::hyve::lang::_enum_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_enum_h, "init(lang::enum object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_enum_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::enum::init(lang::enum object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_enum_init_h);
            }

            /* Declare ::hyve::lang::equalityKind */
            if (!(::hyve::lang::equalityKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::equalityKind", "load: check if object '::hyve::lang::equalityKind' already exists."))) {
                ::hyve::lang::equalityKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "equalityKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::equalityKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::equalityKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::equalityKind_h);
            }

            /* Declare ::hyve::lang::equalityKind::EQ */
            if (!(::hyve::lang::equalityKind_EQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::equalityKind::EQ", "load: check if object '::hyve::lang::equalityKind::EQ' already exists."))) {
                ::hyve::lang::equalityKind_EQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::equalityKind_h, "EQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::equalityKind_EQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::equalityKind::EQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::equalityKind_EQ_h);
            }

            /* Declare ::hyve::lang::equalityKind::GT */
            if (!(::hyve::lang::equalityKind_GT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::equalityKind::GT", "load: check if object '::hyve::lang::equalityKind::GT' already exists."))) {
                ::hyve::lang::equalityKind_GT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::equalityKind_h, "GT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::equalityKind_GT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::equalityKind::GT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::equalityKind_GT_h);
            }

            /* Declare ::hyve::lang::equalityKind::LT */
            if (!(::hyve::lang::equalityKind_LT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::equalityKind::LT", "load: check if object '::hyve::lang::equalityKind::LT' already exists."))) {
                ::hyve::lang::equalityKind_LT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::equalityKind_h, "LT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::equalityKind_LT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::equalityKind::LT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::equalityKind_LT_h);
            }

            /* Declare ::hyve::lang::equalityKind::NEQ */
            if (!(::hyve::lang::equalityKind_NEQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::equalityKind::NEQ", "load: check if object '::hyve::lang::equalityKind::NEQ' already exists."))) {
                ::hyve::lang::equalityKind_NEQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::equalityKind_h, "NEQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::equalityKind_NEQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::equalityKind::NEQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::equalityKind_NEQ_h);
            }

            /* Declare ::hyve::lang::event */
            if (!(::hyve::lang::event_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::event", "load: check if object '::hyve::lang::event' already exists."))) {
                ::hyve::lang::event_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "event", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::event_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::event'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::event_h);
            }

            /* Declare ::hyve::lang::event::handled */
            if (!(::hyve::lang::event_handled_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::event::handled", "load: check if object '::hyve::lang::event::handled' already exists."))) {
                ::hyve::lang::event_handled_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::event_h, "handled", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::event_handled_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::event::handled'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::event_handled_h);
            }

            /* Declare ::hyve::lang::event::kind */
            if (!(::hyve::lang::event_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::event::kind", "load: check if object '::hyve::lang::event::kind' already exists."))) {
                ::hyve::lang::event_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::event_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::event_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::event::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::event_kind_h);
            }

            /* Declare ::hyve::lang::event::processed() */
            if (!(::hyve::lang::event_processed_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::event::processed()", "load: check if object '::hyve::lang::event::processed()' already exists."))) {
                ::hyve::lang::event_processed_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::event_h, "processed()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::event_processed_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::event::processed()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::event_processed_h);
            }

            /* Declare ::hyve::lang::event::uniqueKind() */
            if (!(::hyve::lang::event_uniqueKind_h = (::hyve::lang::function)::hyve::resolve(NULL, NULL, "::hyve::lang::event::uniqueKind()", "load: check if object '::hyve::lang::event::uniqueKind()' already exists."))) {
                ::hyve::lang::event_uniqueKind_h = (::hyve::lang::function)::hyve::declare(::hyve::lang::event_h, "uniqueKind()", ((::hyve::lang::_typedef)::hyve::lang::function_h));
                if (!::hyve::lang::event_uniqueKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::event::uniqueKind()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::event_uniqueKind_h);
            }

            /* Declare ::hyve::lang::eventMask */
            if (!(::hyve::lang::eventMask_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask", "load: check if object '::hyve::lang::eventMask' already exists."))) {
                ::hyve::lang::eventMask_h = (::hyve::lang::bitmask)::hyve::declare(::hyve::lang_h, "eventMask", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
                if (!::hyve::lang::eventMask_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_DECLARE */
            if (!(::hyve::lang::eventMask_ON_DECLARE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_DECLARE", "load: check if object '::hyve::lang::eventMask::ON_DECLARE' already exists."))) {
                ::hyve::lang::eventMask_ON_DECLARE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_DECLARE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_DECLARE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_DECLARE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_DECLARE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_DEFINE */
            if (!(::hyve::lang::eventMask_ON_DEFINE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_DEFINE", "load: check if object '::hyve::lang::eventMask::ON_DEFINE' already exists."))) {
                ::hyve::lang::eventMask_ON_DEFINE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_DEFINE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_DEFINE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_DEFINE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_DEFINE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_DESTRUCT */
            if (!(::hyve::lang::eventMask_ON_DESTRUCT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_DESTRUCT", "load: check if object '::hyve::lang::eventMask::ON_DESTRUCT' already exists."))) {
                ::hyve::lang::eventMask_ON_DESTRUCT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_DESTRUCT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_DESTRUCT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_DESTRUCT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_DESTRUCT_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_INVALIDATE */
            if (!(::hyve::lang::eventMask_ON_INVALIDATE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_INVALIDATE", "load: check if object '::hyve::lang::eventMask::ON_INVALIDATE' already exists."))) {
                ::hyve::lang::eventMask_ON_INVALIDATE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_INVALIDATE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_INVALIDATE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_INVALIDATE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_INVALIDATE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_METAVALUE */
            if (!(::hyve::lang::eventMask_ON_METAVALUE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_METAVALUE", "load: check if object '::hyve::lang::eventMask::ON_METAVALUE' already exists."))) {
                ::hyve::lang::eventMask_ON_METAVALUE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_METAVALUE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_METAVALUE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_METAVALUE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_METAVALUE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_SCOPE */
            if (!(::hyve::lang::eventMask_ON_SCOPE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_SCOPE", "load: check if object '::hyve::lang::eventMask::ON_SCOPE' already exists."))) {
                ::hyve::lang::eventMask_ON_SCOPE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_SCOPE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_SCOPE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_SCOPE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_SCOPE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_SELF */
            if (!(::hyve::lang::eventMask_ON_SELF_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_SELF", "load: check if object '::hyve::lang::eventMask::ON_SELF' already exists."))) {
                ::hyve::lang::eventMask_ON_SELF_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_SELF", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_SELF_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_SELF'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_SELF_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_UPDATE */
            if (!(::hyve::lang::eventMask_ON_UPDATE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_UPDATE", "load: check if object '::hyve::lang::eventMask::ON_UPDATE' already exists."))) {
                ::hyve::lang::eventMask_ON_UPDATE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_UPDATE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_UPDATE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_UPDATE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_UPDATE_h);
            }

            /* Declare ::hyve::lang::eventMask::ON_VALUE */
            if (!(::hyve::lang::eventMask_ON_VALUE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::eventMask::ON_VALUE", "load: check if object '::hyve::lang::eventMask::ON_VALUE' already exists."))) {
                ::hyve::lang::eventMask_ON_VALUE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::eventMask_h, "ON_VALUE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::eventMask_ON_VALUE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::eventMask::ON_VALUE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::eventMask_ON_VALUE_h);
            }

            /* Declare ::hyve::lang::float */
            if (!(::hyve::lang::_float_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::float", "load: check if object '::hyve::lang::float' already exists."))) {
                ::hyve::lang::_float_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "float", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_float_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_float_h);
            }

            /* Declare ::hyve::lang::float::init(lang::float object) */
            if (!(::hyve::lang::_float_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::float::init(lang::float object)", "load: check if object '::hyve::lang::float::init(lang::float object)' already exists."))) {
                ::hyve::lang::_float_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_float_h, "init(lang::float object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_float_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float::init(lang::float object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_float_init_h);
            }

            /* Declare ::hyve::lang::float::max */
            if (!(::hyve::lang::_float_max_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::float::max", "load: check if object '::hyve::lang::float::max' already exists."))) {
                ::hyve::lang::_float_max_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_float_h, "max", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_float_max_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float::max'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_float_max_h);
            }

            /* Declare ::hyve::lang::float::min */
            if (!(::hyve::lang::_float_min_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::float::min", "load: check if object '::hyve::lang::float::min' already exists."))) {
                ::hyve::lang::_float_min_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_float_h, "min", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_float_min_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float::min'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_float_min_h);
            }

            /* Declare ::hyve::lang::float32 */
            if (!(::hyve::lang::float32_h = (::hyve::lang::_float)::hyve::resolve(NULL, NULL, "::hyve::lang::float32", "load: check if object '::hyve::lang::float32' already exists."))) {
                ::hyve::lang::float32_h = (::hyve::lang::_float)::hyve::declare(::hyve::lang_h, "float32", ((::hyve::lang::_typedef)::hyve::lang::_float_h));
                if (!::hyve::lang::float32_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float32'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::float32_h);
            }

            /* Declare ::hyve::lang::float64 */
            if (!(::hyve::lang::float64_h = (::hyve::lang::_float)::hyve::resolve(NULL, NULL, "::hyve::lang::float64", "load: check if object '::hyve::lang::float64' already exists."))) {
                ::hyve::lang::float64_h = (::hyve::lang::_float)::hyve::declare(::hyve::lang_h, "float64", ((::hyve::lang::_typedef)::hyve::lang::_float_h));
                if (!::hyve::lang::float64_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::float64'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::float64_h);
            }

            /* Declare ::hyve::lang::function */
            if (!(::hyve::lang::function_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::function", "load: check if object '::hyve::lang::function' already exists."))) {
                ::hyve::lang::function_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "function", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::function_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_h);
            }

            /* Declare ::hyve::lang::function::bind(lang::function object) */
            if (!(::hyve::lang::function_bind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::function::bind(lang::function object)", "load: check if object '::hyve::lang::function::bind(lang::function object)' already exists."))) {
                ::hyve::lang::function_bind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::function_h, "bind(lang::function object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::function_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::bind(lang::function object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_bind_h);
            }

            /* Declare ::hyve::lang::function::impl */
            if (!(::hyve::lang::function_impl_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::impl", "load: check if object '::hyve::lang::function::impl' already exists."))) {
                ::hyve::lang::function_impl_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "impl", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_impl_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::impl'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_impl_h);
            }

            /* Declare ::hyve::lang::function::impludata */
            if (!(::hyve::lang::function_impludata_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::impludata", "load: check if object '::hyve::lang::function::impludata' already exists."))) {
                ::hyve::lang::function_impludata_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "impludata", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_impludata_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::impludata'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_impludata_h);
            }

            /* Declare ::hyve::lang::function::init(lang::function object) */
            if (!(::hyve::lang::function_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::function::init(lang::function object)", "load: check if object '::hyve::lang::function::init(lang::function object)' already exists."))) {
                ::hyve::lang::function_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::function_h, "init(lang::function object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::function_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::init(lang::function object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_init_h);
            }

            /* Declare ::hyve::lang::function::kind */
            if (!(::hyve::lang::function_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::kind", "load: check if object '::hyve::lang::function::kind' already exists."))) {
                ::hyve::lang::function_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_kind_h);
            }

            /* Declare ::hyve::lang::function::nextParameterId */
            if (!(::hyve::lang::function_nextParameterId_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::nextParameterId", "load: check if object '::hyve::lang::function::nextParameterId' already exists."))) {
                ::hyve::lang::function_nextParameterId_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "nextParameterId", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_nextParameterId_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::nextParameterId'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_nextParameterId_h);
            }

            /* Declare ::hyve::lang::function::overloaded */
            if (!(::hyve::lang::function_overloaded_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::overloaded", "load: check if object '::hyve::lang::function::overloaded' already exists."))) {
                ::hyve::lang::function_overloaded_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "overloaded", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_overloaded_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::overloaded'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_overloaded_h);
            }

            /* Declare ::hyve::lang::function::parameters */
            if (!(::hyve::lang::function_parameters_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::parameters", "load: check if object '::hyve::lang::function::parameters' already exists."))) {
                ::hyve::lang::function_parameters_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "parameters", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_parameters_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::parameters'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_parameters_h);
            }

            /* Declare ::hyve::lang::function::resource */
            if (!(::hyve::lang::function_resource_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::resource", "load: check if object '::hyve::lang::function::resource' already exists."))) {
                ::hyve::lang::function_resource_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "resource", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_resource_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::resource'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_resource_h);
            }

            /* Declare ::hyve::lang::function::returnType */
            if (!(::hyve::lang::function_returnType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::returnType", "load: check if object '::hyve::lang::function::returnType' already exists."))) {
                ::hyve::lang::function_returnType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "returnType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_returnType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::returnType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_returnType_h);
            }

            /* Declare ::hyve::lang::function::size */
            if (!(::hyve::lang::function_size_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::function::size", "load: check if object '::hyve::lang::function::size' already exists."))) {
                ::hyve::lang::function_size_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::function_h, "size", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::function_size_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::size'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_size_h);
            }

            /* Declare ::hyve::lang::function::unbind(lang::function object) */
            if (!(::hyve::lang::function_unbind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::function::unbind(lang::function object)", "load: check if object '::hyve::lang::function::unbind(lang::function object)' already exists."))) {
                ::hyve::lang::function_unbind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::function_h, "unbind(lang::function object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::function_unbind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::function::unbind(lang::function object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::function_unbind_h);
            }

            /* Declare ::hyve::lang::int */
            if (!(::hyve::lang::_int_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::int", "load: check if object '::hyve::lang::int' already exists."))) {
                ::hyve::lang::_int_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "int", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_int_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_int_h);
            }

            /* Declare ::hyve::lang::int::init(lang::int object) */
            if (!(::hyve::lang::_int_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::int::init(lang::int object)", "load: check if object '::hyve::lang::int::init(lang::int object)' already exists."))) {
                ::hyve::lang::_int_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_int_h, "init(lang::int object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_int_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int::init(lang::int object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_int_init_h);
            }

            /* Declare ::hyve::lang::int::max */
            if (!(::hyve::lang::_int_max_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::int::max", "load: check if object '::hyve::lang::int::max' already exists."))) {
                ::hyve::lang::_int_max_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_int_h, "max", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_int_max_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int::max'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_int_max_h);
            }

            /* Declare ::hyve::lang::int::min */
            if (!(::hyve::lang::_int_min_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::int::min", "load: check if object '::hyve::lang::int::min' already exists."))) {
                ::hyve::lang::_int_min_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_int_h, "min", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_int_min_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int::min'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_int_min_h);
            }

            /* Declare ::hyve::lang::int16 */
            if (!(::hyve::lang::int16_h = (::hyve::lang::_int)::hyve::resolve(NULL, NULL, "::hyve::lang::int16", "load: check if object '::hyve::lang::int16' already exists."))) {
                ::hyve::lang::int16_h = (::hyve::lang::_int)::hyve::declare(::hyve::lang_h, "int16", ((::hyve::lang::_typedef)::hyve::lang::_int_h));
                if (!::hyve::lang::int16_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int16'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::int16_h);
            }

            /* Declare ::hyve::lang::int32 */
            if (!(::hyve::lang::int32_h = (::hyve::lang::_int)::hyve::resolve(NULL, NULL, "::hyve::lang::int32", "load: check if object '::hyve::lang::int32' already exists."))) {
                ::hyve::lang::int32_h = (::hyve::lang::_int)::hyve::declare(::hyve::lang_h, "int32", ((::hyve::lang::_typedef)::hyve::lang::_int_h));
                if (!::hyve::lang::int32_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int32'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::int32_h);
            }

            /* Declare ::hyve::lang::int64 */
            if (!(::hyve::lang::int64_h = (::hyve::lang::_int)::hyve::resolve(NULL, NULL, "::hyve::lang::int64", "load: check if object '::hyve::lang::int64' already exists."))) {
                ::hyve::lang::int64_h = (::hyve::lang::_int)::hyve::declare(::hyve::lang_h, "int64", ((::hyve::lang::_typedef)::hyve::lang::_int_h));
                if (!::hyve::lang::int64_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int64'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::int64_h);
            }

            /* Declare ::hyve::lang::int8 */
            if (!(::hyve::lang::int8_h = (::hyve::lang::_int)::hyve::resolve(NULL, NULL, "::hyve::lang::int8", "load: check if object '::hyve::lang::int8' already exists."))) {
                ::hyve::lang::int8_h = (::hyve::lang::_int)::hyve::declare(::hyve::lang_h, "int8", ((::hyve::lang::_typedef)::hyve::lang::_int_h));
                if (!::hyve::lang::int8_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::int8'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::int8_h);
            }

            /* Declare ::hyve::lang::interface */
            if (!(::hyve::lang::interface_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::interface", "load: check if object '::hyve::lang::interface' already exists."))) {
                ::hyve::lang::interface_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "interface", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::interface_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_h);
            }

            /* Declare ::hyve::lang::interface::base */
            if (!(::hyve::lang::interface_base_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::base", "load: check if object '::hyve::lang::interface::base' already exists."))) {
                ::hyve::lang::interface_base_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interface_h, "base", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interface_base_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::base'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_base_h);
            }

            /* Declare ::hyve::lang::interface::bindMethod(lang::method method) */
            if (!(::hyve::lang::interface_bindMethod_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::bindMethod(lang::method method)", "load: check if object '::hyve::lang::interface::bindMethod(lang::method method)' already exists."))) {
                ::hyve::lang::interface_bindMethod_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "bindMethod(lang::method method)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_bindMethod_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::bindMethod(lang::method method)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_bindMethod_h);
            }

            /* Declare ::hyve::lang::interface::compatible(lang::type type) */
            if (!(::hyve::lang::interface_compatible_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::compatible(lang::type type)", "load: check if object '::hyve::lang::interface::compatible(lang::type type)' already exists."))) {
                ::hyve::lang::interface_compatible_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "compatible(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_compatible_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::compatible(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_compatible_h);
            }

            /* Declare ::hyve::lang::interface::construct(lang::interface object) */
            if (!(::hyve::lang::interface_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::construct(lang::interface object)", "load: check if object '::hyve::lang::interface::construct(lang::interface object)' already exists."))) {
                ::hyve::lang::interface_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::interface_h, "construct(lang::interface object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::interface_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::construct(lang::interface object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_construct_h);
            }

            /* Declare ::hyve::lang::interface::destruct(lang::interface object) */
            if (!(::hyve::lang::interface_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::destruct(lang::interface object)", "load: check if object '::hyve::lang::interface::destruct(lang::interface object)' already exists."))) {
                ::hyve::lang::interface_destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::interface_h, "destruct(lang::interface object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::interface_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::destruct(lang::interface object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_destruct_h);
            }

            /* Declare ::hyve::lang::interface::init(lang::interface object) */
            if (!(::hyve::lang::interface_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::init(lang::interface object)", "load: check if object '::hyve::lang::interface::init(lang::interface object)' already exists."))) {
                ::hyve::lang::interface_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::interface_h, "init(lang::interface object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::interface_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::init(lang::interface object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_init_h);
            }

            /* Declare ::hyve::lang::interface::kind */
            if (!(::hyve::lang::interface_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::kind", "load: check if object '::hyve::lang::interface::kind' already exists."))) {
                ::hyve::lang::interface_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interface_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interface_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_kind_h);
            }

            /* Declare ::hyve::lang::interface::members */
            if (!(::hyve::lang::interface_members_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::members", "load: check if object '::hyve::lang::interface::members' already exists."))) {
                ::hyve::lang::interface_members_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interface_h, "members", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interface_members_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::members'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_members_h);
            }

            /* Declare ::hyve::lang::interface::methods */
            if (!(::hyve::lang::interface_methods_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::methods", "load: check if object '::hyve::lang::interface::methods' already exists."))) {
                ::hyve::lang::interface_methods_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interface_h, "methods", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interface_methods_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::methods'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_methods_h);
            }

            /* Declare ::hyve::lang::interface::nextMemberId */
            if (!(::hyve::lang::interface_nextMemberId_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::nextMemberId", "load: check if object '::hyve::lang::interface::nextMemberId' already exists."))) {
                ::hyve::lang::interface_nextMemberId_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interface_h, "nextMemberId", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interface_nextMemberId_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::nextMemberId'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_nextMemberId_h);
            }

            /* Declare ::hyve::lang::interface::resolveMember(lang::string name) */
            if (!(::hyve::lang::interface_resolveMember_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::resolveMember(lang::string name)", "load: check if object '::hyve::lang::interface::resolveMember(lang::string name)' already exists."))) {
                ::hyve::lang::interface_resolveMember_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "resolveMember(lang::string name)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_resolveMember_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::resolveMember(lang::string name)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_resolveMember_h);
            }

            /* Declare ::hyve::lang::interface::resolveMethod(lang::string name) */
            if (!(::hyve::lang::interface_resolveMethod_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::resolveMethod(lang::string name)", "load: check if object '::hyve::lang::interface::resolveMethod(lang::string name)' already exists."))) {
                ::hyve::lang::interface_resolveMethod_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "resolveMethod(lang::string name)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_resolveMethod_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::resolveMethod(lang::string name)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_resolveMethod_h);
            }

            /* Declare ::hyve::lang::interface::resolveMethodById(lang::uint32 id) */
            if (!(::hyve::lang::interface_resolveMethodById_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::resolveMethodById(lang::uint32 id)", "load: check if object '::hyve::lang::interface::resolveMethodById(lang::uint32 id)' already exists."))) {
                ::hyve::lang::interface_resolveMethodById_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "resolveMethodById(lang::uint32 id)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_resolveMethodById_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::resolveMethodById(lang::uint32 id)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_resolveMethodById_h);
            }

            /* Declare ::hyve::lang::interface::resolveMethodId(lang::string name) */
            if (!(::hyve::lang::interface_resolveMethodId_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::interface::resolveMethodId(lang::string name)", "load: check if object '::hyve::lang::interface::resolveMethodId(lang::string name)' already exists."))) {
                ::hyve::lang::interface_resolveMethodId_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::interface_h, "resolveMethodId(lang::string name)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::interface_resolveMethodId_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interface::resolveMethodId(lang::string name)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interface_resolveMethodId_h);
            }

            /* Declare ::hyve::lang::interfaceSeq */
            if (!(::hyve::lang::interfaceSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::interfaceSeq", "load: check if object '::hyve::lang::interfaceSeq' already exists."))) {
                ::hyve::lang::interfaceSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "interfaceSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::interfaceSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interfaceSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interfaceSeq_h);
            }

            /* Declare ::hyve::lang::interfaceVector */
            if (!(::hyve::lang::interfaceVector_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::hyve::lang::interfaceVector", "load: check if object '::hyve::lang::interfaceVector' already exists."))) {
                ::hyve::lang::interfaceVector_h = (::hyve::lang::_struct)::hyve::declare(::hyve::lang_h, "interfaceVector", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
                if (!::hyve::lang::interfaceVector_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interfaceVector'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interfaceVector_h);
            }

            /* Declare ::hyve::lang::interfaceVector::interface */
            if (!(::hyve::lang::interfaceVector_interface_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interfaceVector::interface", "load: check if object '::hyve::lang::interfaceVector::interface' already exists."))) {
                ::hyve::lang::interfaceVector_interface_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interfaceVector_h, "interface", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interfaceVector_interface_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interfaceVector::interface'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interfaceVector_interface_h);
            }

            /* Declare ::hyve::lang::interfaceVector::vector */
            if (!(::hyve::lang::interfaceVector_vector_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::interfaceVector::vector", "load: check if object '::hyve::lang::interfaceVector::vector' already exists."))) {
                ::hyve::lang::interfaceVector_vector_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::interfaceVector_h, "vector", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::interfaceVector_vector_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interfaceVector::vector'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interfaceVector_vector_h);
            }

            /* Declare ::hyve::lang::interfaceVectorSeq */
            if (!(::hyve::lang::interfaceVectorSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::interfaceVectorSeq", "load: check if object '::hyve::lang::interfaceVectorSeq' already exists."))) {
                ::hyve::lang::interfaceVectorSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "interfaceVectorSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::interfaceVectorSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::interfaceVectorSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::interfaceVectorSeq_h);
            }

            /* Declare ::hyve::lang::list */
            if (!(::hyve::lang::list_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::list", "load: check if object '::hyve::lang::list' already exists."))) {
                ::hyve::lang::list_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "list", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::list_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_h);
            }

            /* Declare ::hyve::lang::list::append() */
            if (!(::hyve::lang::list_append__h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::append()", "load: check if object '::hyve::lang::list::append()' already exists."))) {
                ::hyve::lang::list_append__h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "append()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_append__h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::append()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_append__h);
            }

            /* Declare ::hyve::lang::list::append(lang::any element) */
            if (!(::hyve::lang::list_append_langany_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::append(lang::any element)", "load: check if object '::hyve::lang::list::append(lang::any element)' already exists."))) {
                ::hyve::lang::list_append_langany_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "append(lang::any element)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_append_langany_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::append(lang::any element)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_append_langany_h);
            }

            /* Declare ::hyve::lang::list::clear() */
            if (!(::hyve::lang::list_clear_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::clear()", "load: check if object '::hyve::lang::list::clear()' already exists."))) {
                ::hyve::lang::list_clear_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "clear()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_clear_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::clear()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_clear_h);
            }

            /* Declare ::hyve::lang::list::construct(lang::list object) */
            if (!(::hyve::lang::list_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::list::construct(lang::list object)", "load: check if object '::hyve::lang::list::construct(lang::list object)' already exists."))) {
                ::hyve::lang::list_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::list_h, "construct(lang::list object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::list_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::construct(lang::list object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_construct_h);
            }

            /* Declare ::hyve::lang::list::init(lang::list object) */
            if (!(::hyve::lang::list_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::list::init(lang::list object)", "load: check if object '::hyve::lang::list::init(lang::list object)' already exists."))) {
                ::hyve::lang::list_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::list_h, "init(lang::list object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::list_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::init(lang::list object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_init_h);
            }

            /* Declare ::hyve::lang::list::insert() */
            if (!(::hyve::lang::list_insert__h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::insert()", "load: check if object '::hyve::lang::list::insert()' already exists."))) {
                ::hyve::lang::list_insert__h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "insert()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_insert__h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::insert()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_insert__h);
            }

            /* Declare ::hyve::lang::list::insert(lang::any element) */
            if (!(::hyve::lang::list_insert_langany_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::insert(lang::any element)", "load: check if object '::hyve::lang::list::insert(lang::any element)' already exists."))) {
                ::hyve::lang::list_insert_langany_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "insert(lang::any element)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_insert_langany_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::insert(lang::any element)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_insert_langany_h);
            }

            /* Declare ::hyve::lang::list::reverse() */
            if (!(::hyve::lang::list_reverse_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::list::reverse()", "load: check if object '::hyve::lang::list::reverse()' already exists."))) {
                ::hyve::lang::list_reverse_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::list_h, "reverse()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::list_reverse_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::list::reverse()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::list_reverse_h);
            }

            /* Declare ::hyve::lang::map */
            if (!(::hyve::lang::map_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::map", "load: check if object '::hyve::lang::map' already exists."))) {
                ::hyve::lang::map_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "map", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::map_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_h);
            }

            /* Declare ::hyve::lang::map::construct(lang::map object) */
            if (!(::hyve::lang::map_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::map::construct(lang::map object)", "load: check if object '::hyve::lang::map::construct(lang::map object)' already exists."))) {
                ::hyve::lang::map_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::map_h, "construct(lang::map object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::map_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map::construct(lang::map object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_construct_h);
            }

            /* Declare ::hyve::lang::map::elementType */
            if (!(::hyve::lang::map_elementType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::map::elementType", "load: check if object '::hyve::lang::map::elementType' already exists."))) {
                ::hyve::lang::map_elementType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::map_h, "elementType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::map_elementType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map::elementType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_elementType_h);
            }

            /* Declare ::hyve::lang::map::init(lang::map object) */
            if (!(::hyve::lang::map_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::map::init(lang::map object)", "load: check if object '::hyve::lang::map::init(lang::map object)' already exists."))) {
                ::hyve::lang::map_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::map_h, "init(lang::map object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::map_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map::init(lang::map object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_init_h);
            }

            /* Declare ::hyve::lang::map::keyType */
            if (!(::hyve::lang::map_keyType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::map::keyType", "load: check if object '::hyve::lang::map::keyType' already exists."))) {
                ::hyve::lang::map_keyType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::map_h, "keyType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::map_keyType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map::keyType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_keyType_h);
            }

            /* Declare ::hyve::lang::map::max */
            if (!(::hyve::lang::map_max_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::map::max", "load: check if object '::hyve::lang::map::max' already exists."))) {
                ::hyve::lang::map_max_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::map_h, "max", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::map_max_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::map::max'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::map_max_h);
            }

            /* Declare ::hyve::lang::member */
            if (!(::hyve::lang::member_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::member", "load: check if object '::hyve::lang::member' already exists."))) {
                ::hyve::lang::member_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "member", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::member_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_h);
            }

            /* Declare ::hyve::lang::member::construct(lang::member object) */
            if (!(::hyve::lang::member_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::member::construct(lang::member object)", "load: check if object '::hyve::lang::member::construct(lang::member object)' already exists."))) {
                ::hyve::lang::member_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::member_h, "construct(lang::member object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::member_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::construct(lang::member object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_construct_h);
            }

            /* Declare ::hyve::lang::member::id */
            if (!(::hyve::lang::member_id_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::id", "load: check if object '::hyve::lang::member::id' already exists."))) {
                ::hyve::lang::member_id_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "id", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_id_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::id'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_id_h);
            }

            /* Declare ::hyve::lang::member::init(lang::member object) */
            if (!(::hyve::lang::member_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::member::init(lang::member object)", "load: check if object '::hyve::lang::member::init(lang::member object)' already exists."))) {
                ::hyve::lang::member_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::member_h, "init(lang::member object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::member_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::init(lang::member object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_init_h);
            }

            /* Declare ::hyve::lang::member::modifiers */
            if (!(::hyve::lang::member_modifiers_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::modifiers", "load: check if object '::hyve::lang::member::modifiers' already exists."))) {
                ::hyve::lang::member_modifiers_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "modifiers", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_modifiers_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::modifiers'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_modifiers_h);
            }

            /* Declare ::hyve::lang::member::offset */
            if (!(::hyve::lang::member_offset_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::offset", "load: check if object '::hyve::lang::member::offset' already exists."))) {
                ::hyve::lang::member_offset_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "offset", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_offset_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::offset'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_offset_h);
            }

            /* Declare ::hyve::lang::member::state */
            if (!(::hyve::lang::member_state_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::state", "load: check if object '::hyve::lang::member::state' already exists."))) {
                ::hyve::lang::member_state_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "state", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_state_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::state'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_state_h);
            }

            /* Declare ::hyve::lang::member::type */
            if (!(::hyve::lang::member_type_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::type", "load: check if object '::hyve::lang::member::type' already exists."))) {
                ::hyve::lang::member_type_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "type", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_type_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::type'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_type_h);
            }

            /* Declare ::hyve::lang::member::weak */
            if (!(::hyve::lang::member_weak_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::member::weak", "load: check if object '::hyve::lang::member::weak' already exists."))) {
                ::hyve::lang::member_weak_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::member_h, "weak", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::member_weak_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::member::weak'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::member_weak_h);
            }

            /* Declare ::hyve::lang::memberSeq */
            if (!(::hyve::lang::memberSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::memberSeq", "load: check if object '::hyve::lang::memberSeq' already exists."))) {
                ::hyve::lang::memberSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "memberSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::memberSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::memberSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::memberSeq_h);
            }

            /* Declare ::hyve::lang::metaprocedure */
            if (!(::hyve::lang::metaprocedure_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::metaprocedure", "load: check if object '::hyve::lang::metaprocedure' already exists."))) {
                ::hyve::lang::metaprocedure_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "metaprocedure", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::metaprocedure_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::metaprocedure'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::metaprocedure_h);
            }

            /* Declare ::hyve::lang::metaprocedure::bind(lang::metaprocedure object) */
            if (!(::hyve::lang::metaprocedure_bind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::metaprocedure::bind(lang::metaprocedure object)", "load: check if object '::hyve::lang::metaprocedure::bind(lang::metaprocedure object)' already exists."))) {
                ::hyve::lang::metaprocedure_bind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::metaprocedure_h, "bind(lang::metaprocedure object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::metaprocedure_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::metaprocedure::bind(lang::metaprocedure object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::metaprocedure_bind_h);
            }

            /* Declare ::hyve::lang::method */
            if (!(::hyve::lang::method_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::method", "load: check if object '::hyve::lang::method' already exists."))) {
                ::hyve::lang::method_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "method", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::method_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::method'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::method_h);
            }

            /* Declare ::hyve::lang::method::bind(lang::method object) */
            if (!(::hyve::lang::method_bind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::method::bind(lang::method object)", "load: check if object '::hyve::lang::method::bind(lang::method object)' already exists."))) {
                ::hyve::lang::method_bind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::method_h, "bind(lang::method object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::method_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::method::bind(lang::method object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::method_bind_h);
            }

            /* Declare ::hyve::lang::method::init(lang::method object) */
            if (!(::hyve::lang::method_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::method::init(lang::method object)", "load: check if object '::hyve::lang::method::init(lang::method object)' already exists."))) {
                ::hyve::lang::method_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::method_h, "init(lang::method object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::method_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::method::init(lang::method object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::method_init_h);
            }

            /* Declare ::hyve::lang::method::virtual */
            if (!(::hyve::lang::method__virtual_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::method::virtual", "load: check if object '::hyve::lang::method::virtual' already exists."))) {
                ::hyve::lang::method__virtual_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::method_h, "virtual", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::method__virtual_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::method::virtual'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::method__virtual_h);
            }

            /* Declare ::hyve::lang::modifier */
            if (!(::hyve::lang::modifier_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier", "load: check if object '::hyve::lang::modifier' already exists."))) {
                ::hyve::lang::modifier_h = (::hyve::lang::bitmask)::hyve::declare(::hyve::lang_h, "modifier", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
                if (!::hyve::lang::modifier_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_h);
            }

            /* Declare ::hyve::lang::modifier::CONST */
            if (!(::hyve::lang::modifier_CONST_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier::CONST", "load: check if object '::hyve::lang::modifier::CONST' already exists."))) {
                ::hyve::lang::modifier_CONST_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::modifier_h, "CONST", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::modifier_CONST_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier::CONST'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_CONST_h);
            }

            /* Declare ::hyve::lang::modifier::GLOBAL */
            if (!(::hyve::lang::modifier_GLOBAL_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier::GLOBAL", "load: check if object '::hyve::lang::modifier::GLOBAL' already exists."))) {
                ::hyve::lang::modifier_GLOBAL_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::modifier_h, "GLOBAL", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::modifier_GLOBAL_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier::GLOBAL'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_GLOBAL_h);
            }

            /* Declare ::hyve::lang::modifier::LOCAL */
            if (!(::hyve::lang::modifier_LOCAL_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier::LOCAL", "load: check if object '::hyve::lang::modifier::LOCAL' already exists."))) {
                ::hyve::lang::modifier_LOCAL_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::modifier_h, "LOCAL", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::modifier_LOCAL_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier::LOCAL'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_LOCAL_h);
            }

            /* Declare ::hyve::lang::modifier::PRIVATE */
            if (!(::hyve::lang::modifier_PRIVATE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier::PRIVATE", "load: check if object '::hyve::lang::modifier::PRIVATE' already exists."))) {
                ::hyve::lang::modifier_PRIVATE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::modifier_h, "PRIVATE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::modifier_PRIVATE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier::PRIVATE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_PRIVATE_h);
            }

            /* Declare ::hyve::lang::modifier::READONLY */
            if (!(::hyve::lang::modifier_READONLY_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::modifier::READONLY", "load: check if object '::hyve::lang::modifier::READONLY' already exists."))) {
                ::hyve::lang::modifier_READONLY_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::modifier_h, "READONLY", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::modifier_READONLY_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::modifier::READONLY'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::modifier_READONLY_h);
            }

            /* Declare ::hyve::lang::object */
            if (!(::hyve::lang::object_h = (::hyve::lang::type)::hyve::resolve(NULL, NULL, "::hyve::lang::object", "load: check if object '::hyve::lang::object' already exists."))) {
                ::hyve::lang::object_h = (::hyve::lang::type)::hyve::declare(::hyve::lang_h, "object", ((::hyve::lang::_typedef)::hyve::lang::type_h));
                if (!::hyve::lang::object_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::object'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::object_h);
            }

            /* Declare ::hyve::lang::objectSeq */
            if (!(::hyve::lang::objectSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::objectSeq", "load: check if object '::hyve::lang::objectSeq' already exists."))) {
                ::hyve::lang::objectSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "objectSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::objectSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::objectSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::objectSeq_h);
            }

            /* Declare ::hyve::lang::observableEvent */
            if (!(::hyve::lang::observableEvent_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::observableEvent", "load: check if object '::hyve::lang::observableEvent' already exists."))) {
                ::hyve::lang::observableEvent_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "observableEvent", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::observableEvent_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observableEvent'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observableEvent_h);
            }

            /* Declare ::hyve::lang::observableEvent::me */
            if (!(::hyve::lang::observableEvent_me_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observableEvent::me", "load: check if object '::hyve::lang::observableEvent::me' already exists."))) {
                ::hyve::lang::observableEvent_me_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observableEvent_h, "me", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observableEvent_me_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observableEvent::me'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observableEvent_me_h);
            }

            /* Declare ::hyve::lang::observableEvent::observable */
            if (!(::hyve::lang::observableEvent_observable_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observableEvent::observable", "load: check if object '::hyve::lang::observableEvent::observable' already exists."))) {
                ::hyve::lang::observableEvent_observable_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observableEvent_h, "observable", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observableEvent_observable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observableEvent::observable'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observableEvent_observable_h);
            }

            /* Declare ::hyve::lang::observableEvent::observer */
            if (!(::hyve::lang::observableEvent_observer_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observableEvent::observer", "load: check if object '::hyve::lang::observableEvent::observer' already exists."))) {
                ::hyve::lang::observableEvent_observer_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observableEvent_h, "observer", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observableEvent_observer_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observableEvent::observer'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observableEvent_observer_h);
            }

            /* Declare ::hyve::lang::observableEvent::source */
            if (!(::hyve::lang::observableEvent_source_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observableEvent::source", "load: check if object '::hyve::lang::observableEvent::source' already exists."))) {
                ::hyve::lang::observableEvent_source_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observableEvent_h, "source", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observableEvent_source_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observableEvent::source'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observableEvent_source_h);
            }

            /* Declare ::hyve::lang::observer */
            if (!(::hyve::lang::observer_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::observer", "load: check if object '::hyve::lang::observer' already exists."))) {
                ::hyve::lang::observer_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "observer", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::observer_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_h);
            }

            /* Declare ::hyve::lang::observer::bind(lang::observer object) */
            if (!(::hyve::lang::observer_bind_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::bind(lang::observer object)", "load: check if object '::hyve::lang::observer::bind(lang::observer object)' already exists."))) {
                ::hyve::lang::observer_bind_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::observer_h, "bind(lang::observer object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::observer_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::bind(lang::observer object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_bind_h);
            }

            /* Declare ::hyve::lang::observer::delayedBinder */
            if (!(::hyve::lang::observer_delayedBinder_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::delayedBinder", "load: check if object '::hyve::lang::observer::delayedBinder' already exists."))) {
                ::hyve::lang::observer_delayedBinder_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "delayedBinder", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_delayedBinder_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::delayedBinder'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_delayedBinder_h);
            }

            /* Declare ::hyve::lang::observer::dispatcher */
            if (!(::hyve::lang::observer_dispatcher_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::dispatcher", "load: check if object '::hyve::lang::observer::dispatcher' already exists."))) {
                ::hyve::lang::observer_dispatcher_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "dispatcher", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_dispatcher_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::dispatcher'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_dispatcher_h);
            }

            /* Declare ::hyve::lang::observer::expression */
            if (!(::hyve::lang::observer_expression_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::expression", "load: check if object '::hyve::lang::observer::expression' already exists."))) {
                ::hyve::lang::observer_expression_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "expression", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_expression_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::expression'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_expression_h);
            }

            /* Declare ::hyve::lang::observer::init(lang::observer object) */
            if (!(::hyve::lang::observer_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::init(lang::observer object)", "load: check if object '::hyve::lang::observer::init(lang::observer object)' already exists."))) {
                ::hyve::lang::observer_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::observer_h, "init(lang::observer object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::observer_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::init(lang::observer object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_init_h);
            }

            /* Declare ::hyve::lang::observer::listen(lang::object observable,lang::object me) */
            if (!(::hyve::lang::observer_listen_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::listen(lang::object observable,lang::object me)", "load: check if object '::hyve::lang::observer::listen(lang::object observable,lang::object me)' already exists."))) {
                ::hyve::lang::observer_listen_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::observer_h, "listen(lang::object observable,lang::object me)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::observer_listen_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::listen(lang::object observable,lang::object me)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_listen_h);
            }

            /* Declare ::hyve::lang::observer::mask */
            if (!(::hyve::lang::observer_mask_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::mask", "load: check if object '::hyve::lang::observer::mask' already exists."))) {
                ::hyve::lang::observer_mask_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "mask", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_mask_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::mask'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_mask_h);
            }

            /* Declare ::hyve::lang::observer::me */
            if (!(::hyve::lang::observer_me_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::me", "load: check if object '::hyve::lang::observer::me' already exists."))) {
                ::hyve::lang::observer_me_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "me", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_me_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::me'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_me_h);
            }

            /* Declare ::hyve::lang::observer::observable */
            if (!(::hyve::lang::observer_observable_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::observable", "load: check if object '::hyve::lang::observer::observable' already exists."))) {
                ::hyve::lang::observer_observable_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "observable", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_observable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::observable'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_observable_h);
            }

            /* Declare ::hyve::lang::observer::observing */
            if (!(::hyve::lang::observer_observing_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::observing", "load: check if object '::hyve::lang::observer::observing' already exists."))) {
                ::hyve::lang::observer_observing_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "observing", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer_observing_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::observing'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_observing_h);
            }

            /* Declare ::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
            if (!(::hyve::lang::observer_setDispatcher_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher)", "load: check if object '::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher)' already exists."))) {
                ::hyve::lang::observer_setDispatcher_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::observer_h, "setDispatcher(lang::dispatcher dispatcher)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::observer_setDispatcher_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_setDispatcher_h);
            }

            /* Declare ::hyve::lang::observer::silence(lang::object me) */
            if (!(::hyve::lang::observer_silence_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::silence(lang::object me)", "load: check if object '::hyve::lang::observer::silence(lang::object me)' already exists."))) {
                ::hyve::lang::observer_silence_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::observer_h, "silence(lang::object me)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::observer_silence_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::silence(lang::object me)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer_silence_h);
            }

            /* Declare ::hyve::lang::observer::template */
            if (!(::hyve::lang::observer__template_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::observer::template", "load: check if object '::hyve::lang::observer::template' already exists."))) {
                ::hyve::lang::observer__template_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::observer_h, "template", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::observer__template_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observer::template'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observer__template_h);
            }

            /* Declare ::hyve::lang::observerSeq */
            if (!(::hyve::lang::observerSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::observerSeq", "load: check if object '::hyve::lang::observerSeq' already exists."))) {
                ::hyve::lang::observerSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "observerSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::observerSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::observerSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::observerSeq_h);
            }

            /* Declare ::hyve::lang::octet */
            if (!(::hyve::lang::octet_h = (::hyve::lang::binary)::hyve::resolve(NULL, NULL, "::hyve::lang::octet", "load: check if object '::hyve::lang::octet' already exists."))) {
                ::hyve::lang::octet_h = (::hyve::lang::binary)::hyve::declare(::hyve::lang_h, "octet", ((::hyve::lang::_typedef)::hyve::lang::binary_h));
                if (!::hyve::lang::octet_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::octet'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::octet_h);
            }

            /* Declare ::hyve::lang::operatorKind */
            if (!(::hyve::lang::operatorKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind", "load: check if object '::hyve::lang::operatorKind' already exists."))) {
                ::hyve::lang::operatorKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "operatorKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::operatorKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_h);
            }

            /* Declare ::hyve::lang::operatorKind::ADD */
            if (!(::hyve::lang::operatorKind_ADD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ADD", "load: check if object '::hyve::lang::operatorKind::ADD' already exists."))) {
                ::hyve::lang::operatorKind_ADD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ADD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ADD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ADD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ADD_h);
            }

            /* Declare ::hyve::lang::operatorKind::AND */
            if (!(::hyve::lang::operatorKind_AND_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::AND", "load: check if object '::hyve::lang::operatorKind::AND' already exists."))) {
                ::hyve::lang::operatorKind_AND_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "AND", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_AND_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::AND'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_AND_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN */
            if (!(::hyve::lang::operatorKind_ASSIGN_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN", "load: check if object '::hyve::lang::operatorKind::ASSIGN' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_ADD */
            if (!(::hyve::lang::operatorKind_ASSIGN_ADD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_ADD", "load: check if object '::hyve::lang::operatorKind::ASSIGN_ADD' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_ADD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_ADD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_ADD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_ADD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_ADD_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_AND */
            if (!(::hyve::lang::operatorKind_ASSIGN_AND_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_AND", "load: check if object '::hyve::lang::operatorKind::ASSIGN_AND' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_AND_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_AND", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_AND_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_AND'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_AND_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_DIV */
            if (!(::hyve::lang::operatorKind_ASSIGN_DIV_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_DIV", "load: check if object '::hyve::lang::operatorKind::ASSIGN_DIV' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_DIV_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_DIV", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_DIV_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_DIV'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_DIV_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_MOD */
            if (!(::hyve::lang::operatorKind_ASSIGN_MOD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_MOD", "load: check if object '::hyve::lang::operatorKind::ASSIGN_MOD' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_MOD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_MOD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_MOD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_MOD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_MOD_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_MUL */
            if (!(::hyve::lang::operatorKind_ASSIGN_MUL_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_MUL", "load: check if object '::hyve::lang::operatorKind::ASSIGN_MUL' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_MUL_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_MUL", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_MUL_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_MUL'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_MUL_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_OR */
            if (!(::hyve::lang::operatorKind_ASSIGN_OR_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_OR", "load: check if object '::hyve::lang::operatorKind::ASSIGN_OR' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_OR_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_OR", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_OR_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_OR'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_OR_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_SUB */
            if (!(::hyve::lang::operatorKind_ASSIGN_SUB_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_SUB", "load: check if object '::hyve::lang::operatorKind::ASSIGN_SUB' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_SUB_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_SUB", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_SUB_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_SUB'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_SUB_h);
            }

            /* Declare ::hyve::lang::operatorKind::ASSIGN_XOR */
            if (!(::hyve::lang::operatorKind_ASSIGN_XOR_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ASSIGN_XOR", "load: check if object '::hyve::lang::operatorKind::ASSIGN_XOR' already exists."))) {
                ::hyve::lang::operatorKind_ASSIGN_XOR_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ASSIGN_XOR", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ASSIGN_XOR_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ASSIGN_XOR'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ASSIGN_XOR_h);
            }

            /* Declare ::hyve::lang::operatorKind::BRACKET_CLOSE */
            if (!(::hyve::lang::operatorKind_BRACKET_CLOSE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::BRACKET_CLOSE", "load: check if object '::hyve::lang::operatorKind::BRACKET_CLOSE' already exists."))) {
                ::hyve::lang::operatorKind_BRACKET_CLOSE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "BRACKET_CLOSE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_BRACKET_CLOSE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::BRACKET_CLOSE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_BRACKET_CLOSE_h);
            }

            /* Declare ::hyve::lang::operatorKind::BRACKET_OPEN */
            if (!(::hyve::lang::operatorKind_BRACKET_OPEN_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::BRACKET_OPEN", "load: check if object '::hyve::lang::operatorKind::BRACKET_OPEN' already exists."))) {
                ::hyve::lang::operatorKind_BRACKET_OPEN_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "BRACKET_OPEN", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_BRACKET_OPEN_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::BRACKET_OPEN'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_BRACKET_OPEN_h);
            }

            /* Declare ::hyve::lang::operatorKind::COMMA */
            if (!(::hyve::lang::operatorKind_COMMA_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COMMA", "load: check if object '::hyve::lang::operatorKind::COMMA' already exists."))) {
                ::hyve::lang::operatorKind_COMMA_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COMMA", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COMMA_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COMMA'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COMMA_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_AND */
            if (!(::hyve::lang::operatorKind_COND_AND_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_AND", "load: check if object '::hyve::lang::operatorKind::COND_AND' already exists."))) {
                ::hyve::lang::operatorKind_COND_AND_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_AND", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_AND_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_AND'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_AND_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_EQ */
            if (!(::hyve::lang::operatorKind_COND_EQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_EQ", "load: check if object '::hyve::lang::operatorKind::COND_EQ' already exists."))) {
                ::hyve::lang::operatorKind_COND_EQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_EQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_EQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_EQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_EQ_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_GT */
            if (!(::hyve::lang::operatorKind_COND_GT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_GT", "load: check if object '::hyve::lang::operatorKind::COND_GT' already exists."))) {
                ::hyve::lang::operatorKind_COND_GT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_GT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_GT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_GT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_GT_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_GTEQ */
            if (!(::hyve::lang::operatorKind_COND_GTEQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_GTEQ", "load: check if object '::hyve::lang::operatorKind::COND_GTEQ' already exists."))) {
                ::hyve::lang::operatorKind_COND_GTEQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_GTEQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_GTEQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_GTEQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_GTEQ_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_LT */
            if (!(::hyve::lang::operatorKind_COND_LT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_LT", "load: check if object '::hyve::lang::operatorKind::COND_LT' already exists."))) {
                ::hyve::lang::operatorKind_COND_LT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_LT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_LT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_LT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_LT_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_LTEQ */
            if (!(::hyve::lang::operatorKind_COND_LTEQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_LTEQ", "load: check if object '::hyve::lang::operatorKind::COND_LTEQ' already exists."))) {
                ::hyve::lang::operatorKind_COND_LTEQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_LTEQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_LTEQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_LTEQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_LTEQ_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_NEQ */
            if (!(::hyve::lang::operatorKind_COND_NEQ_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_NEQ", "load: check if object '::hyve::lang::operatorKind::COND_NEQ' already exists."))) {
                ::hyve::lang::operatorKind_COND_NEQ_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_NEQ", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_NEQ_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_NEQ'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_NEQ_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_NOT */
            if (!(::hyve::lang::operatorKind_COND_NOT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_NOT", "load: check if object '::hyve::lang::operatorKind::COND_NOT' already exists."))) {
                ::hyve::lang::operatorKind_COND_NOT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_NOT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_NOT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_NOT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_NOT_h);
            }

            /* Declare ::hyve::lang::operatorKind::COND_OR */
            if (!(::hyve::lang::operatorKind_COND_OR_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::COND_OR", "load: check if object '::hyve::lang::operatorKind::COND_OR' already exists."))) {
                ::hyve::lang::operatorKind_COND_OR_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "COND_OR", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_COND_OR_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::COND_OR'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_COND_OR_h);
            }

            /* Declare ::hyve::lang::operatorKind::DEC */
            if (!(::hyve::lang::operatorKind_DEC_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::DEC", "load: check if object '::hyve::lang::operatorKind::DEC' already exists."))) {
                ::hyve::lang::operatorKind_DEC_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "DEC", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_DEC_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::DEC'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_DEC_h);
            }

            /* Declare ::hyve::lang::operatorKind::DIV */
            if (!(::hyve::lang::operatorKind_DIV_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::DIV", "load: check if object '::hyve::lang::operatorKind::DIV' already exists."))) {
                ::hyve::lang::operatorKind_DIV_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "DIV", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_DIV_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::DIV'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_DIV_h);
            }

            /* Declare ::hyve::lang::operatorKind::ELEMENT_CLOSE */
            if (!(::hyve::lang::operatorKind_ELEMENT_CLOSE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ELEMENT_CLOSE", "load: check if object '::hyve::lang::operatorKind::ELEMENT_CLOSE' already exists."))) {
                ::hyve::lang::operatorKind_ELEMENT_CLOSE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ELEMENT_CLOSE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ELEMENT_CLOSE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ELEMENT_CLOSE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ELEMENT_CLOSE_h);
            }

            /* Declare ::hyve::lang::operatorKind::ELEMENT_OPEN */
            if (!(::hyve::lang::operatorKind_ELEMENT_OPEN_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::ELEMENT_OPEN", "load: check if object '::hyve::lang::operatorKind::ELEMENT_OPEN' already exists."))) {
                ::hyve::lang::operatorKind_ELEMENT_OPEN_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "ELEMENT_OPEN", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_ELEMENT_OPEN_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::ELEMENT_OPEN'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_ELEMENT_OPEN_h);
            }

            /* Declare ::hyve::lang::operatorKind::INC */
            if (!(::hyve::lang::operatorKind_INC_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::INC", "load: check if object '::hyve::lang::operatorKind::INC' already exists."))) {
                ::hyve::lang::operatorKind_INC_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "INC", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_INC_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::INC'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_INC_h);
            }

            /* Declare ::hyve::lang::operatorKind::MEMBER_RESOLVE */
            if (!(::hyve::lang::operatorKind_MEMBER_RESOLVE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::MEMBER_RESOLVE", "load: check if object '::hyve::lang::operatorKind::MEMBER_RESOLVE' already exists."))) {
                ::hyve::lang::operatorKind_MEMBER_RESOLVE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "MEMBER_RESOLVE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_MEMBER_RESOLVE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::MEMBER_RESOLVE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_MEMBER_RESOLVE_h);
            }

            /* Declare ::hyve::lang::operatorKind::MOD */
            if (!(::hyve::lang::operatorKind_MOD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::MOD", "load: check if object '::hyve::lang::operatorKind::MOD' already exists."))) {
                ::hyve::lang::operatorKind_MOD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "MOD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_MOD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::MOD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_MOD_h);
            }

            /* Declare ::hyve::lang::operatorKind::MUL */
            if (!(::hyve::lang::operatorKind_MUL_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::MUL", "load: check if object '::hyve::lang::operatorKind::MUL' already exists."))) {
                ::hyve::lang::operatorKind_MUL_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "MUL", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_MUL_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::MUL'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_MUL_h);
            }

            /* Declare ::hyve::lang::operatorKind::NOT */
            if (!(::hyve::lang::operatorKind_NOT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::NOT", "load: check if object '::hyve::lang::operatorKind::NOT' already exists."))) {
                ::hyve::lang::operatorKind_NOT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "NOT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_NOT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::NOT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_NOT_h);
            }

            /* Declare ::hyve::lang::operatorKind::OR */
            if (!(::hyve::lang::operatorKind_OR_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::OR", "load: check if object '::hyve::lang::operatorKind::OR' already exists."))) {
                ::hyve::lang::operatorKind_OR_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "OR", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_OR_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::OR'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_OR_h);
            }

            /* Declare ::hyve::lang::operatorKind::REF */
            if (!(::hyve::lang::operatorKind_REF_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::REF", "load: check if object '::hyve::lang::operatorKind::REF' already exists."))) {
                ::hyve::lang::operatorKind_REF_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "REF", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_REF_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::REF'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_REF_h);
            }

            /* Declare ::hyve::lang::operatorKind::SHIFT_LEFT */
            if (!(::hyve::lang::operatorKind_SHIFT_LEFT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::SHIFT_LEFT", "load: check if object '::hyve::lang::operatorKind::SHIFT_LEFT' already exists."))) {
                ::hyve::lang::operatorKind_SHIFT_LEFT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "SHIFT_LEFT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_SHIFT_LEFT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::SHIFT_LEFT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_SHIFT_LEFT_h);
            }

            /* Declare ::hyve::lang::operatorKind::SHIFT_RIGHT */
            if (!(::hyve::lang::operatorKind_SHIFT_RIGHT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::SHIFT_RIGHT", "load: check if object '::hyve::lang::operatorKind::SHIFT_RIGHT' already exists."))) {
                ::hyve::lang::operatorKind_SHIFT_RIGHT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "SHIFT_RIGHT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_SHIFT_RIGHT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::SHIFT_RIGHT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_SHIFT_RIGHT_h);
            }

            /* Declare ::hyve::lang::operatorKind::SUB */
            if (!(::hyve::lang::operatorKind_SUB_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::SUB", "load: check if object '::hyve::lang::operatorKind::SUB' already exists."))) {
                ::hyve::lang::operatorKind_SUB_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "SUB", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_SUB_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::SUB'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_SUB_h);
            }

            /* Declare ::hyve::lang::operatorKind::XOR */
            if (!(::hyve::lang::operatorKind_XOR_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::operatorKind::XOR", "load: check if object '::hyve::lang::operatorKind::XOR' already exists."))) {
                ::hyve::lang::operatorKind_XOR_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::operatorKind_h, "XOR", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::operatorKind_XOR_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::operatorKind::XOR'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::operatorKind_XOR_h);
            }

            /* Declare ::hyve::lang::parameter */
            if (!(::hyve::lang::parameter_h = (::hyve::lang::_struct)::hyve::resolve(NULL, NULL, "::hyve::lang::parameter", "load: check if object '::hyve::lang::parameter' already exists."))) {
                ::hyve::lang::parameter_h = (::hyve::lang::_struct)::hyve::declare(::hyve::lang_h, "parameter", ((::hyve::lang::_typedef)::hyve::lang::_struct_h));
                if (!::hyve::lang::parameter_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::parameter'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::parameter_h);
            }

            /* Declare ::hyve::lang::parameter::name */
            if (!(::hyve::lang::parameter_name_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::parameter::name", "load: check if object '::hyve::lang::parameter::name' already exists."))) {
                ::hyve::lang::parameter_name_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::parameter_h, "name", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::parameter_name_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::parameter::name'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::parameter_name_h);
            }

            /* Declare ::hyve::lang::parameter::passByReference */
            if (!(::hyve::lang::parameter_passByReference_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::parameter::passByReference", "load: check if object '::hyve::lang::parameter::passByReference' already exists."))) {
                ::hyve::lang::parameter_passByReference_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::parameter_h, "passByReference", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::parameter_passByReference_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::parameter::passByReference'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::parameter_passByReference_h);
            }

            /* Declare ::hyve::lang::parameter::type */
            if (!(::hyve::lang::parameter_type_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::parameter::type", "load: check if object '::hyve::lang::parameter::type' already exists."))) {
                ::hyve::lang::parameter_type_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::parameter_h, "type", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::parameter_type_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::parameter::type'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::parameter_type_h);
            }

            /* Declare ::hyve::lang::parameterSeq */
            if (!(::hyve::lang::parameterSeq_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::parameterSeq", "load: check if object '::hyve::lang::parameterSeq' already exists."))) {
                ::hyve::lang::parameterSeq_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "parameterSeq", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::parameterSeq_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::parameterSeq'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::parameterSeq_h);
            }

            /* Declare ::hyve::lang::primitive */
            if (!(::hyve::lang::primitive_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive", "load: check if object '::hyve::lang::primitive' already exists."))) {
                ::hyve::lang::primitive_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "primitive", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::primitive_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_h);
            }

            /* Declare ::hyve::lang::primitive::castable(lang::type type) */
            if (!(::hyve::lang::primitive_castable_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::castable(lang::type type)", "load: check if object '::hyve::lang::primitive::castable(lang::type type)' already exists."))) {
                ::hyve::lang::primitive_castable_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::primitive_h, "castable(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::primitive_castable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::castable(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_castable_h);
            }

            /* Declare ::hyve::lang::primitive::compatible(lang::type type) */
            if (!(::hyve::lang::primitive_compatible_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::compatible(lang::type type)", "load: check if object '::hyve::lang::primitive::compatible(lang::type type)' already exists."))) {
                ::hyve::lang::primitive_compatible_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::primitive_h, "compatible(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::primitive_compatible_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::compatible(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_compatible_h);
            }

            /* Declare ::hyve::lang::primitive::construct(lang::primitive object) */
            if (!(::hyve::lang::primitive_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::construct(lang::primitive object)", "load: check if object '::hyve::lang::primitive::construct(lang::primitive object)' already exists."))) {
                ::hyve::lang::primitive_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::primitive_h, "construct(lang::primitive object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::primitive_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::construct(lang::primitive object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_construct_h);
            }

            /* Declare ::hyve::lang::primitive::convertId */
            if (!(::hyve::lang::primitive_convertId_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::convertId", "load: check if object '::hyve::lang::primitive::convertId' already exists."))) {
                ::hyve::lang::primitive_convertId_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::primitive_h, "convertId", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::primitive_convertId_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::convertId'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_convertId_h);
            }

            /* Declare ::hyve::lang::primitive::init(lang::primitive object) */
            if (!(::hyve::lang::primitive_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::init(lang::primitive object)", "load: check if object '::hyve::lang::primitive::init(lang::primitive object)' already exists."))) {
                ::hyve::lang::primitive_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::primitive_h, "init(lang::primitive object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::primitive_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::init(lang::primitive object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_init_h);
            }

            /* Declare ::hyve::lang::primitive::kind */
            if (!(::hyve::lang::primitive_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::kind", "load: check if object '::hyve::lang::primitive::kind' already exists."))) {
                ::hyve::lang::primitive_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::primitive_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::primitive_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_kind_h);
            }

            /* Declare ::hyve::lang::primitive::width */
            if (!(::hyve::lang::primitive_width_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::primitive::width", "load: check if object '::hyve::lang::primitive::width' already exists."))) {
                ::hyve::lang::primitive_width_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::primitive_h, "width", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::primitive_width_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitive::width'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitive_width_h);
            }

            /* Declare ::hyve::lang::primitiveKind */
            if (!(::hyve::lang::primitiveKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind", "load: check if object '::hyve::lang::primitiveKind' already exists."))) {
                ::hyve::lang::primitiveKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "primitiveKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::primitiveKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_h);
            }

            /* Declare ::hyve::lang::primitiveKind::ALIAS */
            if (!(::hyve::lang::primitiveKind_ALIAS_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::ALIAS", "load: check if object '::hyve::lang::primitiveKind::ALIAS' already exists."))) {
                ::hyve::lang::primitiveKind_ALIAS_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "ALIAS", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_ALIAS_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::ALIAS'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_ALIAS_h);
            }

            /* Declare ::hyve::lang::primitiveKind::BINARY */
            if (!(::hyve::lang::primitiveKind_BINARY_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::BINARY", "load: check if object '::hyve::lang::primitiveKind::BINARY' already exists."))) {
                ::hyve::lang::primitiveKind_BINARY_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "BINARY", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_BINARY_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::BINARY'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_BINARY_h);
            }

            /* Declare ::hyve::lang::primitiveKind::BITMASK */
            if (!(::hyve::lang::primitiveKind_BITMASK_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::BITMASK", "load: check if object '::hyve::lang::primitiveKind::BITMASK' already exists."))) {
                ::hyve::lang::primitiveKind_BITMASK_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "BITMASK", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_BITMASK_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::BITMASK'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_BITMASK_h);
            }

            /* Declare ::hyve::lang::primitiveKind::BOOLEAN */
            if (!(::hyve::lang::primitiveKind_BOOLEAN_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::BOOLEAN", "load: check if object '::hyve::lang::primitiveKind::BOOLEAN' already exists."))) {
                ::hyve::lang::primitiveKind_BOOLEAN_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "BOOLEAN", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_BOOLEAN_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::BOOLEAN'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_BOOLEAN_h);
            }

            /* Declare ::hyve::lang::primitiveKind::CHARACTER */
            if (!(::hyve::lang::primitiveKind_CHARACTER_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::CHARACTER", "load: check if object '::hyve::lang::primitiveKind::CHARACTER' already exists."))) {
                ::hyve::lang::primitiveKind_CHARACTER_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "CHARACTER", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_CHARACTER_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::CHARACTER'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_CHARACTER_h);
            }

            /* Declare ::hyve::lang::primitiveKind::ENUM */
            if (!(::hyve::lang::primitiveKind_ENUM_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::ENUM", "load: check if object '::hyve::lang::primitiveKind::ENUM' already exists."))) {
                ::hyve::lang::primitiveKind_ENUM_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "ENUM", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_ENUM_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::ENUM'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_ENUM_h);
            }

            /* Declare ::hyve::lang::primitiveKind::FLOAT */
            if (!(::hyve::lang::primitiveKind_FLOAT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::FLOAT", "load: check if object '::hyve::lang::primitiveKind::FLOAT' already exists."))) {
                ::hyve::lang::primitiveKind_FLOAT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "FLOAT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_FLOAT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::FLOAT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_FLOAT_h);
            }

            /* Declare ::hyve::lang::primitiveKind::INTEGER */
            if (!(::hyve::lang::primitiveKind_INTEGER_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::INTEGER", "load: check if object '::hyve::lang::primitiveKind::INTEGER' already exists."))) {
                ::hyve::lang::primitiveKind_INTEGER_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "INTEGER", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_INTEGER_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::INTEGER'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_INTEGER_h);
            }

            /* Declare ::hyve::lang::primitiveKind::TEXT */
            if (!(::hyve::lang::primitiveKind_TEXT_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::TEXT", "load: check if object '::hyve::lang::primitiveKind::TEXT' already exists."))) {
                ::hyve::lang::primitiveKind_TEXT_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "TEXT", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_TEXT_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::TEXT'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_TEXT_h);
            }

            /* Declare ::hyve::lang::primitiveKind::UINTEGER */
            if (!(::hyve::lang::primitiveKind_UINTEGER_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::primitiveKind::UINTEGER", "load: check if object '::hyve::lang::primitiveKind::UINTEGER' already exists."))) {
                ::hyve::lang::primitiveKind_UINTEGER_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::primitiveKind_h, "UINTEGER", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::primitiveKind_UINTEGER_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::primitiveKind::UINTEGER'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::primitiveKind_UINTEGER_h);
            }

            /* Declare ::hyve::lang::procedure */
            if (!(::hyve::lang::procedure_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::procedure", "load: check if object '::hyve::lang::procedure' already exists."))) {
                ::hyve::lang::procedure_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "procedure", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::procedure_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedure'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedure_h);
            }

            /* Declare ::hyve::lang::procedure::bind(lang::object object) */
            if (!(::hyve::lang::procedure_bind_h = (::hyve::lang::delegate)::hyve::resolve(NULL, NULL, "::hyve::lang::procedure::bind(lang::object object)", "load: check if object '::hyve::lang::procedure::bind(lang::object object)' already exists."))) {
                ::hyve::lang::procedure_bind_h = (::hyve::lang::delegate)::hyve::declare(::hyve::lang::procedure_h, "bind(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::delegate_h));
                if (!::hyve::lang::procedure_bind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedure::bind(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedure_bind_h);
            }

            /* Declare ::hyve::lang::procedure::init(lang::procedure object) */
            if (!(::hyve::lang::procedure_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::procedure::init(lang::procedure object)", "load: check if object '::hyve::lang::procedure::init(lang::procedure object)' already exists."))) {
                ::hyve::lang::procedure_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::procedure_h, "init(lang::procedure object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::procedure_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedure::init(lang::procedure object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedure_init_h);
            }

            /* Declare ::hyve::lang::procedure::kind */
            if (!(::hyve::lang::procedure_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::procedure::kind", "load: check if object '::hyve::lang::procedure::kind' already exists."))) {
                ::hyve::lang::procedure_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::procedure_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::procedure_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedure::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedure_kind_h);
            }

            /* Declare ::hyve::lang::procedure::unbind(lang::object object) */
            if (!(::hyve::lang::procedure_unbind_h = (::hyve::lang::delegate)::hyve::resolve(NULL, NULL, "::hyve::lang::procedure::unbind(lang::object object)", "load: check if object '::hyve::lang::procedure::unbind(lang::object object)' already exists."))) {
                ::hyve::lang::procedure_unbind_h = (::hyve::lang::delegate)::hyve::declare(::hyve::lang::procedure_h, "unbind(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::delegate_h));
                if (!::hyve::lang::procedure_unbind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedure::unbind(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedure_unbind_h);
            }

            /* Declare ::hyve::lang::procedureKind */
            if (!(::hyve::lang::procedureKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind", "load: check if object '::hyve::lang::procedureKind' already exists."))) {
                ::hyve::lang::procedureKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "procedureKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::procedureKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_h);
            }

            /* Declare ::hyve::lang::procedureKind::CALLBACK */
            if (!(::hyve::lang::procedureKind_CALLBACK_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::CALLBACK", "load: check if object '::hyve::lang::procedureKind::CALLBACK' already exists."))) {
                ::hyve::lang::procedureKind_CALLBACK_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "CALLBACK", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_CALLBACK_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::CALLBACK'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_CALLBACK_h);
            }

            /* Declare ::hyve::lang::procedureKind::DELEGATE */
            if (!(::hyve::lang::procedureKind_DELEGATE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::DELEGATE", "load: check if object '::hyve::lang::procedureKind::DELEGATE' already exists."))) {
                ::hyve::lang::procedureKind_DELEGATE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "DELEGATE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_DELEGATE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::DELEGATE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_DELEGATE_h);
            }

            /* Declare ::hyve::lang::procedureKind::FUNCTION */
            if (!(::hyve::lang::procedureKind_FUNCTION_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::FUNCTION", "load: check if object '::hyve::lang::procedureKind::FUNCTION' already exists."))) {
                ::hyve::lang::procedureKind_FUNCTION_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "FUNCTION", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_FUNCTION_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::FUNCTION'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_FUNCTION_h);
            }

            /* Declare ::hyve::lang::procedureKind::METAPROCEDURE */
            if (!(::hyve::lang::procedureKind_METAPROCEDURE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::METAPROCEDURE", "load: check if object '::hyve::lang::procedureKind::METAPROCEDURE' already exists."))) {
                ::hyve::lang::procedureKind_METAPROCEDURE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "METAPROCEDURE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_METAPROCEDURE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::METAPROCEDURE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_METAPROCEDURE_h);
            }

            /* Declare ::hyve::lang::procedureKind::METHOD */
            if (!(::hyve::lang::procedureKind_METHOD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::METHOD", "load: check if object '::hyve::lang::procedureKind::METHOD' already exists."))) {
                ::hyve::lang::procedureKind_METHOD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "METHOD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_METHOD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::METHOD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_METHOD_h);
            }

            /* Declare ::hyve::lang::procedureKind::OBSERVER */
            if (!(::hyve::lang::procedureKind_OBSERVER_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::procedureKind::OBSERVER", "load: check if object '::hyve::lang::procedureKind::OBSERVER' already exists."))) {
                ::hyve::lang::procedureKind_OBSERVER_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::procedureKind_h, "OBSERVER", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::procedureKind_OBSERVER_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::procedureKind::OBSERVER'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::procedureKind_OBSERVER_h);
            }

            /* Declare ::hyve::lang::sequence */
            if (!(::hyve::lang::sequence_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::sequence", "load: check if object '::hyve::lang::sequence' already exists."))) {
                ::hyve::lang::sequence_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "sequence", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::sequence_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::sequence'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::sequence_h);
            }

            /* Declare ::hyve::lang::sequence::construct(lang::sequence object) */
            if (!(::hyve::lang::sequence_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::sequence::construct(lang::sequence object)", "load: check if object '::hyve::lang::sequence::construct(lang::sequence object)' already exists."))) {
                ::hyve::lang::sequence_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::sequence_h, "construct(lang::sequence object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::sequence_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::sequence::construct(lang::sequence object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::sequence_construct_h);
            }

            /* Declare ::hyve::lang::sequence::init(lang::sequence object) */
            if (!(::hyve::lang::sequence_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::sequence::init(lang::sequence object)", "load: check if object '::hyve::lang::sequence::init(lang::sequence object)' already exists."))) {
                ::hyve::lang::sequence_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::sequence_h, "init(lang::sequence object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::sequence_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::sequence::init(lang::sequence object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::sequence_init_h);
            }

            /* Declare ::hyve::lang::sequence::size(lang::uint32 size) */
            if (!(::hyve::lang::sequence_size_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::sequence::size(lang::uint32 size)", "load: check if object '::hyve::lang::sequence::size(lang::uint32 size)' already exists."))) {
                ::hyve::lang::sequence_size_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::sequence_h, "size(lang::uint32 size)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::sequence_size_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::sequence::size(lang::uint32 size)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::sequence_size_h);
            }

            /* Declare ::hyve::lang::state */
            if (!(::hyve::lang::state_h = (::hyve::lang::bitmask)::hyve::resolve(NULL, NULL, "::hyve::lang::state", "load: check if object '::hyve::lang::state' already exists."))) {
                ::hyve::lang::state_h = (::hyve::lang::bitmask)::hyve::declare(::hyve::lang_h, "state", ((::hyve::lang::_typedef)::hyve::lang::bitmask_h));
                if (!::hyve::lang::state_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::state'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::state_h);
            }

            /* Declare ::hyve::lang::state::DECLARED */
            if (!(::hyve::lang::state_DECLARED_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::state::DECLARED", "load: check if object '::hyve::lang::state::DECLARED' already exists."))) {
                ::hyve::lang::state_DECLARED_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::state_h, "DECLARED", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::state_DECLARED_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::state::DECLARED'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::state_DECLARED_h);
            }

            /* Declare ::hyve::lang::state::DEFINED */
            if (!(::hyve::lang::state_DEFINED_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::state::DEFINED", "load: check if object '::hyve::lang::state::DEFINED' already exists."))) {
                ::hyve::lang::state_DEFINED_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::state_h, "DEFINED", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::state_DEFINED_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::state::DEFINED'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::state_DEFINED_h);
            }

            /* Declare ::hyve::lang::state::VALID */
            if (!(::hyve::lang::state_VALID_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::state::VALID", "load: check if object '::hyve::lang::state::VALID' already exists."))) {
                ::hyve::lang::state_VALID_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::state_h, "VALID", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::state_VALID_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::state::VALID'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::state_VALID_h);
            }

            /* Declare ::hyve::lang::string */
            if (!(::hyve::lang::string_h = (::hyve::lang::text)::hyve::resolve(NULL, NULL, "::hyve::lang::string", "load: check if object '::hyve::lang::string' already exists."))) {
                ::hyve::lang::string_h = (::hyve::lang::text)::hyve::declare(::hyve::lang_h, "string", ((::hyve::lang::_typedef)::hyve::lang::text_h));
                if (!::hyve::lang::string_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::string'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::string_h);
            }

            /* Declare ::hyve::lang::struct */
            if (!(::hyve::lang::_struct_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::struct", "load: check if object '::hyve::lang::struct' already exists."))) {
                ::hyve::lang::_struct_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "struct", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_struct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_h);
            }

            /* Declare ::hyve::lang::struct::baseAccess */
            if (!(::hyve::lang::_struct_baseAccess_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::baseAccess", "load: check if object '::hyve::lang::struct::baseAccess' already exists."))) {
                ::hyve::lang::_struct_baseAccess_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_struct_h, "baseAccess", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_struct_baseAccess_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::baseAccess'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_baseAccess_h);
            }

            /* Declare ::hyve::lang::struct::castable(lang::type type) */
            if (!(::hyve::lang::_struct_castable_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::castable(lang::type type)", "load: check if object '::hyve::lang::struct::castable(lang::type type)' already exists."))) {
                ::hyve::lang::_struct_castable_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_struct_h, "castable(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_struct_castable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::castable(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_castable_h);
            }

            /* Declare ::hyve::lang::struct::compatible(lang::type type) */
            if (!(::hyve::lang::_struct_compatible_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::compatible(lang::type type)", "load: check if object '::hyve::lang::struct::compatible(lang::type type)' already exists."))) {
                ::hyve::lang::_struct_compatible_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_struct_h, "compatible(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_struct_compatible_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::compatible(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_compatible_h);
            }

            /* Declare ::hyve::lang::struct::construct(lang::struct object) */
            if (!(::hyve::lang::_struct_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::construct(lang::struct object)", "load: check if object '::hyve::lang::struct::construct(lang::struct object)' already exists."))) {
                ::hyve::lang::_struct_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_struct_h, "construct(lang::struct object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_struct_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::construct(lang::struct object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_construct_h);
            }

            /* Declare ::hyve::lang::struct::delegateCount */
            if (!(::hyve::lang::_struct_delegateCount_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::delegateCount", "load: check if object '::hyve::lang::struct::delegateCount' already exists."))) {
                ::hyve::lang::_struct_delegateCount_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_struct_h, "delegateCount", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_struct_delegateCount_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::delegateCount'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_delegateCount_h);
            }

            /* Declare ::hyve::lang::struct::init(lang::struct object) */
            if (!(::hyve::lang::_struct_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::init(lang::struct object)", "load: check if object '::hyve::lang::struct::init(lang::struct object)' already exists."))) {
                ::hyve::lang::_struct_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_struct_h, "init(lang::struct object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_struct_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::init(lang::struct object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_init_h);
            }

            /* Declare ::hyve::lang::struct::resolveMember(lang::string name) */
            if (!(::hyve::lang::_struct_resolveMember_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::struct::resolveMember(lang::string name)", "load: check if object '::hyve::lang::struct::resolveMember(lang::string name)' already exists."))) {
                ::hyve::lang::_struct_resolveMember_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_struct_h, "resolveMember(lang::string name)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_struct_resolveMember_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::struct::resolveMember(lang::string name)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_struct_resolveMember_h);
            }

            /* Declare ::hyve::lang::text */
            if (!(::hyve::lang::text_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::text", "load: check if object '::hyve::lang::text' already exists."))) {
                ::hyve::lang::text_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "text", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::text_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::text'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::text_h);
            }

            /* Declare ::hyve::lang::text::charWidth */
            if (!(::hyve::lang::text_charWidth_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::text::charWidth", "load: check if object '::hyve::lang::text::charWidth' already exists."))) {
                ::hyve::lang::text_charWidth_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::text_h, "charWidth", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::text_charWidth_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::text::charWidth'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::text_charWidth_h);
            }

            /* Declare ::hyve::lang::text::init(lang::text object) */
            if (!(::hyve::lang::text_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::text::init(lang::text object)", "load: check if object '::hyve::lang::text::init(lang::text object)' already exists."))) {
                ::hyve::lang::text_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::text_h, "init(lang::text object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::text_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::text::init(lang::text object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::text_init_h);
            }

            /* Declare ::hyve::lang::text::length */
            if (!(::hyve::lang::text_length_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::text::length", "load: check if object '::hyve::lang::text::length' already exists."))) {
                ::hyve::lang::text_length_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::text_h, "length", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::text_length_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::text::length'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::text_length_h);
            }

            /* Declare ::hyve::lang::type */
            if (!(::hyve::lang::type_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::type", "load: check if object '::hyve::lang::type' already exists."))) {
                ::hyve::lang::type_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "type", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::type_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_h);
            }

            /* Declare ::hyve::lang::type::_init(lang::type object) */
            if (!(::hyve::lang::type__init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::type::_init(lang::type object)", "load: check if object '::hyve::lang::type::_init(lang::type object)' already exists."))) {
                ::hyve::lang::type__init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::type_h, "_init(lang::type object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::type__init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::_init(lang::type object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type__init_h);
            }

            /* Declare ::hyve::lang::type::alignment */
            if (!(::hyve::lang::type_alignment_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::alignment", "load: check if object '::hyve::lang::type::alignment' already exists."))) {
                ::hyve::lang::type_alignment_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "alignment", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_alignment_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::alignment'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_alignment_h);
            }

            /* Declare ::hyve::lang::type::alignmentof() */
            if (!(::hyve::lang::type_alignmentof_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::alignmentof()", "load: check if object '::hyve::lang::type::alignmentof()' already exists."))) {
                ::hyve::lang::type_alignmentof_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "alignmentof()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type_alignmentof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::alignmentof()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_alignmentof_h);
            }

            /* Declare ::hyve::lang::type::allocSize() */
            if (!(::hyve::lang::type_allocSize_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::allocSize()", "load: check if object '::hyve::lang::type::allocSize()' already exists."))) {
                ::hyve::lang::type_allocSize_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "allocSize()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type_allocSize_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::allocSize()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_allocSize_h);
            }

            /* Declare ::hyve::lang::type::castable(lang::type type) */
            if (!(::hyve::lang::type_castable_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::castable(lang::type type)", "load: check if object '::hyve::lang::type::castable(lang::type type)' already exists."))) {
                ::hyve::lang::type_castable_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "castable(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type_castable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::castable(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_castable_h);
            }

            /* Declare ::hyve::lang::type::compare(lang::any value) */
            if (!(::hyve::lang::type_compare_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::compare(lang::any value)", "load: check if object '::hyve::lang::type::compare(lang::any value)' already exists."))) {
                ::hyve::lang::type_compare_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "compare(lang::any value)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_compare_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::compare(lang::any value)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_compare_h);
            }

            /* Declare ::hyve::lang::type::compatible(lang::type type) */
            if (!(::hyve::lang::type_compatible_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::compatible(lang::type type)", "load: check if object '::hyve::lang::type::compatible(lang::type type)' already exists."))) {
                ::hyve::lang::type_compatible_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "compatible(lang::type type)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type_compatible_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::compatible(lang::type type)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_compatible_h);
            }

            /* Declare ::hyve::lang::type::construct(lang::type object) */
            if (!(::hyve::lang::type_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::type::construct(lang::type object)", "load: check if object '::hyve::lang::type::construct(lang::type object)' already exists."))) {
                ::hyve::lang::type_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::type_h, "construct(lang::type object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::type_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::construct(lang::type object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_construct_h);
            }

            /* Declare ::hyve::lang::type::copy(lang::any value) */
            if (!(::hyve::lang::type_copy_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::copy(lang::any value)", "load: check if object '::hyve::lang::type::copy(lang::any value)' already exists."))) {
                ::hyve::lang::type_copy_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "copy(lang::any value)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_copy_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::copy(lang::any value)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_copy_h);
            }

            /* Declare ::hyve::lang::type::defaultType */
            if (!(::hyve::lang::type_defaultType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::defaultType", "load: check if object '::hyve::lang::type::defaultType' already exists."))) {
                ::hyve::lang::type_defaultType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "defaultType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_defaultType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::defaultType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_defaultType_h);
            }

            /* Declare ::hyve::lang::type::destruct(lang::type object) */
            if (!(::hyve::lang::type_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::type::destruct(lang::type object)", "load: check if object '::hyve::lang::type::destruct(lang::type object)' already exists."))) {
                ::hyve::lang::type_destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::type_h, "destruct(lang::type object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::type_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::destruct(lang::type object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_destruct_h);
            }

            /* Declare ::hyve::lang::type::fullname() */
            if (!(::hyve::lang::type_fullname_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::fullname()", "load: check if object '::hyve::lang::type::fullname()' already exists."))) {
                ::hyve::lang::type_fullname_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "fullname()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_fullname_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::fullname()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_fullname_h);
            }

            /* Declare ::hyve::lang::type::hasResources */
            if (!(::hyve::lang::type_hasResources_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::hasResources", "load: check if object '::hyve::lang::type::hasResources' already exists."))) {
                ::hyve::lang::type_hasResources_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "hasResources", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_hasResources_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::hasResources'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_hasResources_h);
            }

            /* Declare ::hyve::lang::type::init(lang::object object) */
            if (!(::hyve::lang::type_init_h = (::hyve::lang::delegate)::hyve::resolve(NULL, NULL, "::hyve::lang::type::init(lang::object object)", "load: check if object '::hyve::lang::type::init(lang::object object)' already exists."))) {
                ::hyve::lang::type_init_h = (::hyve::lang::delegate)::hyve::declare(::hyve::lang::type_h, "init(lang::object object)", ((::hyve::lang::_typedef)::hyve::lang::delegate_h));
                if (!::hyve::lang::type_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::init(lang::object object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_init_h);
            }

            /* Declare ::hyve::lang::type::kind */
            if (!(::hyve::lang::type_kind_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::kind", "load: check if object '::hyve::lang::type::kind' already exists."))) {
                ::hyve::lang::type_kind_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "kind", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_kind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::kind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_kind_h);
            }

            /* Declare ::hyve::lang::type::metaprocedures */
            if (!(::hyve::lang::type_metaprocedures_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::metaprocedures", "load: check if object '::hyve::lang::type::metaprocedures' already exists."))) {
                ::hyve::lang::type_metaprocedures_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "metaprocedures", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_metaprocedures_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::metaprocedures'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_metaprocedures_h);
            }

            /* Declare ::hyve::lang::type::nameof() */
            if (!(::hyve::lang::type_nameof_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::nameof()", "load: check if object '::hyve::lang::type::nameof()' already exists."))) {
                ::hyve::lang::type_nameof_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "nameof()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_nameof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::nameof()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_nameof_h);
            }

            /* Declare ::hyve::lang::type::parentof() */
            if (!(::hyve::lang::type_parentof_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::parentof()", "load: check if object '::hyve::lang::type::parentof()' already exists."))) {
                ::hyve::lang::type_parentof_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "parentof()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_parentof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::parentof()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_parentof_h);
            }

            /* Declare ::hyve::lang::type::parentState */
            if (!(::hyve::lang::type_parentState_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::parentState", "load: check if object '::hyve::lang::type::parentState' already exists."))) {
                ::hyve::lang::type_parentState_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "parentState", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_parentState_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::parentState'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_parentState_h);
            }

            /* Declare ::hyve::lang::type::parentType */
            if (!(::hyve::lang::type_parentType_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::parentType", "load: check if object '::hyve::lang::type::parentType' already exists."))) {
                ::hyve::lang::type_parentType_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "parentType", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_parentType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::parentType'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_parentType_h);
            }

            /* Declare ::hyve::lang::type::reference */
            if (!(::hyve::lang::type_reference_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::reference", "load: check if object '::hyve::lang::type::reference' already exists."))) {
                ::hyve::lang::type_reference_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "reference", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_reference_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::reference'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_reference_h);
            }

            /* Declare ::hyve::lang::type::relname(lang::object from) */
            if (!(::hyve::lang::type_relname_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::relname(lang::object from)", "load: check if object '::hyve::lang::type::relname(lang::object from)' already exists."))) {
                ::hyve::lang::type_relname_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "relname(lang::object from)", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_relname_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::relname(lang::object from)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_relname_h);
            }

            /* Declare ::hyve::lang::type::resolveProcedure(lang::string name) */
            if (!(::hyve::lang::type_resolveProcedure_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::resolveProcedure(lang::string name)", "load: check if object '::hyve::lang::type::resolveProcedure(lang::string name)' already exists."))) {
                ::hyve::lang::type_resolveProcedure_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "resolveProcedure(lang::string name)", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type_resolveProcedure_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::resolveProcedure(lang::string name)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_resolveProcedure_h);
            }

            /* Declare ::hyve::lang::type::size */
            if (!(::hyve::lang::type_size_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::size", "load: check if object '::hyve::lang::type::size' already exists."))) {
                ::hyve::lang::type_size_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "size", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_size_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::size'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_size_h);
            }

            /* Declare ::hyve::lang::type::sizeof() */
            if (!(::hyve::lang::type__sizeof_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::type::sizeof()", "load: check if object '::hyve::lang::type::sizeof()' already exists."))) {
                ::hyve::lang::type__sizeof_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::type_h, "sizeof()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::type__sizeof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::sizeof()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type__sizeof_h);
            }

            /* Declare ::hyve::lang::type::templateId */
            if (!(::hyve::lang::type_templateId_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::type::templateId", "load: check if object '::hyve::lang::type::templateId' already exists."))) {
                ::hyve::lang::type_templateId_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::type_h, "templateId", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::type_templateId_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::templateId'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_templateId_h);
            }

            /* Declare ::hyve::lang::type::toString() */
            if (!(::hyve::lang::type_toString_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::toString()", "load: check if object '::hyve::lang::type::toString()' already exists."))) {
                ::hyve::lang::type_toString_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "toString()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_toString_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::toString()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_toString_h);
            }

            /* Declare ::hyve::lang::type::typeof() */
            if (!(::hyve::lang::type_typeof_h = (::hyve::lang::metaprocedure)::hyve::resolve(NULL, NULL, "::hyve::lang::type::typeof()", "load: check if object '::hyve::lang::type::typeof()' already exists."))) {
                ::hyve::lang::type_typeof_h = (::hyve::lang::metaprocedure)::hyve::declare(::hyve::lang::type_h, "typeof()", ((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h));
                if (!::hyve::lang::type_typeof_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::type::typeof()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::type_typeof_h);
            }

            /* Declare ::hyve::lang::typedef */
            if (!(::hyve::lang::_typedef_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef", "load: check if object '::hyve::lang::typedef' already exists."))) {
                ::hyve::lang::_typedef_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "typedef", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::_typedef_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_h);
            }

            /* Declare ::hyve::lang::typedef::construct(lang::typedef object) */
            if (!(::hyve::lang::_typedef_construct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::construct(lang::typedef object)", "load: check if object '::hyve::lang::typedef::construct(lang::typedef object)' already exists."))) {
                ::hyve::lang::_typedef_construct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_typedef_h, "construct(lang::typedef object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_typedef_construct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::construct(lang::typedef object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_construct_h);
            }

            /* Declare ::hyve::lang::typedef::destruct(lang::typedef object) */
            if (!(::hyve::lang::_typedef_destruct_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::destruct(lang::typedef object)", "load: check if object '::hyve::lang::typedef::destruct(lang::typedef object)' already exists."))) {
                ::hyve::lang::_typedef_destruct_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_typedef_h, "destruct(lang::typedef object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_typedef_destruct_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::destruct(lang::typedef object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_destruct_h);
            }

            /* Declare ::hyve::lang::typedef::init(lang::typedef object) */
            if (!(::hyve::lang::_typedef_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::init(lang::typedef object)", "load: check if object '::hyve::lang::typedef::init(lang::typedef object)' already exists."))) {
                ::hyve::lang::_typedef_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_typedef_h, "init(lang::typedef object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_typedef_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::init(lang::typedef object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_init_h);
            }

            /* Declare ::hyve::lang::typedef::real */
            if (!(::hyve::lang::_typedef_real_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::real", "load: check if object '::hyve::lang::typedef::real' already exists."))) {
                ::hyve::lang::_typedef_real_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_typedef_h, "real", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_typedef_real_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::real'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_real_h);
            }

            /* Declare ::hyve::lang::typedef::realType() */
            if (!(::hyve::lang::_typedef_realType_h = (::hyve::lang::method)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::realType()", "load: check if object '::hyve::lang::typedef::realType()' already exists."))) {
                ::hyve::lang::_typedef_realType_h = (::hyve::lang::method)::hyve::declare(::hyve::lang::_typedef_h, "realType()", ((::hyve::lang::_typedef)::hyve::lang::method_h));
                if (!::hyve::lang::_typedef_realType_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::realType()'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_realType_h);
            }

            /* Declare ::hyve::lang::typedef::type */
            if (!(::hyve::lang::_typedef_type_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::typedef::type", "load: check if object '::hyve::lang::typedef::type' already exists."))) {
                ::hyve::lang::_typedef_type_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::_typedef_h, "type", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::_typedef_type_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typedef::type'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_typedef_type_h);
            }

            /* Declare ::hyve::lang::typeKind */
            if (!(::hyve::lang::typeKind_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind", "load: check if object '::hyve::lang::typeKind' already exists."))) {
                ::hyve::lang::typeKind_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "typeKind", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::typeKind_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_h);
            }

            /* Declare ::hyve::lang::typeKind::ANY */
            if (!(::hyve::lang::typeKind_ANY_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind::ANY", "load: check if object '::hyve::lang::typeKind::ANY' already exists."))) {
                ::hyve::lang::typeKind_ANY_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::typeKind_h, "ANY", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::typeKind_ANY_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind::ANY'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_ANY_h);
            }

            /* Declare ::hyve::lang::typeKind::COLLECTION */
            if (!(::hyve::lang::typeKind_COLLECTION_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind::COLLECTION", "load: check if object '::hyve::lang::typeKind::COLLECTION' already exists."))) {
                ::hyve::lang::typeKind_COLLECTION_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::typeKind_h, "COLLECTION", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::typeKind_COLLECTION_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind::COLLECTION'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_COLLECTION_h);
            }

            /* Declare ::hyve::lang::typeKind::COMPOSITE */
            if (!(::hyve::lang::typeKind_COMPOSITE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind::COMPOSITE", "load: check if object '::hyve::lang::typeKind::COMPOSITE' already exists."))) {
                ::hyve::lang::typeKind_COMPOSITE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::typeKind_h, "COMPOSITE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::typeKind_COMPOSITE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind::COMPOSITE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_COMPOSITE_h);
            }

            /* Declare ::hyve::lang::typeKind::PRIMITIVE */
            if (!(::hyve::lang::typeKind_PRIMITIVE_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind::PRIMITIVE", "load: check if object '::hyve::lang::typeKind::PRIMITIVE' already exists."))) {
                ::hyve::lang::typeKind_PRIMITIVE_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::typeKind_h, "PRIMITIVE", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::typeKind_PRIMITIVE_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind::PRIMITIVE'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_PRIMITIVE_h);
            }

            /* Declare ::hyve::lang::typeKind::VOID */
            if (!(::hyve::lang::typeKind_VOID_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::typeKind::VOID", "load: check if object '::hyve::lang::typeKind::VOID' already exists."))) {
                ::hyve::lang::typeKind_VOID_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::typeKind_h, "VOID", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::typeKind_VOID_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::typeKind::VOID'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::typeKind_VOID_h);
            }

            /* Declare ::hyve::lang::uint */
            if (!(::hyve::lang::uint_h = (::hyve::lang::_class)::hyve::resolve(NULL, NULL, "::hyve::lang::uint", "load: check if object '::hyve::lang::uint' already exists."))) {
                ::hyve::lang::uint_h = (::hyve::lang::_class)::hyve::declare(::hyve::lang_h, "uint", ((::hyve::lang::_typedef)::hyve::lang::_class_h));
                if (!::hyve::lang::uint_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint_h);
            }

            /* Declare ::hyve::lang::uint::init(lang::uint object) */
            if (!(::hyve::lang::uint_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::uint::init(lang::uint object)", "load: check if object '::hyve::lang::uint::init(lang::uint object)' already exists."))) {
                ::hyve::lang::uint_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::uint_h, "init(lang::uint object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::uint_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint::init(lang::uint object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint_init_h);
            }

            /* Declare ::hyve::lang::uint::max */
            if (!(::hyve::lang::uint_max_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::uint::max", "load: check if object '::hyve::lang::uint::max' already exists."))) {
                ::hyve::lang::uint_max_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::uint_h, "max", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::uint_max_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint::max'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint_max_h);
            }

            /* Declare ::hyve::lang::uint::min */
            if (!(::hyve::lang::uint_min_h = (::hyve::lang::member)::hyve::resolve(NULL, NULL, "::hyve::lang::uint::min", "load: check if object '::hyve::lang::uint::min' already exists."))) {
                ::hyve::lang::uint_min_h = (::hyve::lang::member)::hyve::declare(::hyve::lang::uint_h, "min", ((::hyve::lang::_typedef)::hyve::lang::member_h));
                if (!::hyve::lang::uint_min_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint::min'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint_min_h);
            }

            /* Declare ::hyve::lang::uint16 */
            if (!(::hyve::lang::uint16_h = (::hyve::lang::uint)::hyve::resolve(NULL, NULL, "::hyve::lang::uint16", "load: check if object '::hyve::lang::uint16' already exists."))) {
                ::hyve::lang::uint16_h = (::hyve::lang::uint)::hyve::declare(::hyve::lang_h, "uint16", ((::hyve::lang::_typedef)::hyve::lang::uint_h));
                if (!::hyve::lang::uint16_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint16'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint16_h);
            }

            /* Declare ::hyve::lang::uint32 */
            if (!(::hyve::lang::uint32_h = (::hyve::lang::uint)::hyve::resolve(NULL, NULL, "::hyve::lang::uint32", "load: check if object '::hyve::lang::uint32' already exists."))) {
                ::hyve::lang::uint32_h = (::hyve::lang::uint)::hyve::declare(::hyve::lang_h, "uint32", ((::hyve::lang::_typedef)::hyve::lang::uint_h));
                if (!::hyve::lang::uint32_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint32'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint32_h);
            }

            /* Declare ::hyve::lang::uint64 */
            if (!(::hyve::lang::uint64_h = (::hyve::lang::uint)::hyve::resolve(NULL, NULL, "::hyve::lang::uint64", "load: check if object '::hyve::lang::uint64' already exists."))) {
                ::hyve::lang::uint64_h = (::hyve::lang::uint)::hyve::declare(::hyve::lang_h, "uint64", ((::hyve::lang::_typedef)::hyve::lang::uint_h));
                if (!::hyve::lang::uint64_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint64'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint64_h);
            }

            /* Declare ::hyve::lang::uint8 */
            if (!(::hyve::lang::uint8_h = (::hyve::lang::uint)::hyve::resolve(NULL, NULL, "::hyve::lang::uint8", "load: check if object '::hyve::lang::uint8' already exists."))) {
                ::hyve::lang::uint8_h = (::hyve::lang::uint)::hyve::declare(::hyve::lang_h, "uint8", ((::hyve::lang::_typedef)::hyve::lang::uint_h));
                if (!::hyve::lang::uint8_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::uint8'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::uint8_h);
            }

            /* Declare ::hyve::lang::virtual */
            if (!(::hyve::lang::_virtual_h = (::hyve::lang::procedure)::hyve::resolve(NULL, NULL, "::hyve::lang::virtual", "load: check if object '::hyve::lang::virtual' already exists."))) {
                ::hyve::lang::_virtual_h = (::hyve::lang::procedure)::hyve::declare(::hyve::lang_h, "virtual", ((::hyve::lang::_typedef)::hyve::lang::procedure_h));
                if (!::hyve::lang::_virtual_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::virtual'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_virtual_h);
            }

            /* Declare ::hyve::lang::virtual::init(lang::virtual object) */
            if (!(::hyve::lang::_virtual_init_h = (::hyve::lang::callback)::hyve::resolve(NULL, NULL, "::hyve::lang::virtual::init(lang::virtual object)", "load: check if object '::hyve::lang::virtual::init(lang::virtual object)' already exists."))) {
                ::hyve::lang::_virtual_init_h = (::hyve::lang::callback)::hyve::declare(::hyve::lang::_virtual_h, "init(lang::virtual object)", ((::hyve::lang::_typedef)::hyve::lang::callback_h));
                if (!::hyve::lang::_virtual_init_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::virtual::init(lang::virtual object)'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_virtual_init_h);
            }

            /* Declare ::hyve::lang::void */
            if (!(::hyve::lang::_void_h = (::hyve::lang::type)::hyve::resolve(NULL, NULL, "::hyve::lang::void", "load: check if object '::hyve::lang::void' already exists."))) {
                ::hyve::lang::_void_h = (::hyve::lang::type)::hyve::declare(::hyve::lang_h, "void", ((::hyve::lang::_typedef)::hyve::lang::type_h));
                if (!::hyve::lang::_void_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::void'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::_void_h);
            }

            /* Declare ::hyve::lang::vtable */
            if (!(::hyve::lang::vtable_h = (::hyve::lang::sequence)::hyve::resolve(NULL, NULL, "::hyve::lang::vtable", "load: check if object '::hyve::lang::vtable' already exists."))) {
                ::hyve::lang::vtable_h = (::hyve::lang::sequence)::hyve::declare(::hyve::lang_h, "vtable", ((::hyve::lang::_typedef)::hyve::lang::sequence_h));
                if (!::hyve::lang::vtable_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::vtable'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::vtable_h);
            }

            /* Declare ::hyve::lang::width */
            if (!(::hyve::lang::width_h = (::hyve::lang::_enum)::hyve::resolve(NULL, NULL, "::hyve::lang::width", "load: check if object '::hyve::lang::width' already exists."))) {
                ::hyve::lang::width_h = (::hyve::lang::_enum)::hyve::declare(::hyve::lang_h, "width", ((::hyve::lang::_typedef)::hyve::lang::_enum_h));
                if (!::hyve::lang::width_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_h);
            }

            /* Declare ::hyve::lang::width::WIDTH_16 */
            if (!(::hyve::lang::width_WIDTH_16_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::width::WIDTH_16", "load: check if object '::hyve::lang::width::WIDTH_16' already exists."))) {
                ::hyve::lang::width_WIDTH_16_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::width_h, "WIDTH_16", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::width_WIDTH_16_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width::WIDTH_16'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_WIDTH_16_h);
            }

            /* Declare ::hyve::lang::width::WIDTH_32 */
            if (!(::hyve::lang::width_WIDTH_32_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::width::WIDTH_32", "load: check if object '::hyve::lang::width::WIDTH_32' already exists."))) {
                ::hyve::lang::width_WIDTH_32_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::width_h, "WIDTH_32", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::width_WIDTH_32_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width::WIDTH_32'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_WIDTH_32_h);
            }

            /* Declare ::hyve::lang::width::WIDTH_64 */
            if (!(::hyve::lang::width_WIDTH_64_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::width::WIDTH_64", "load: check if object '::hyve::lang::width::WIDTH_64' already exists."))) {
                ::hyve::lang::width_WIDTH_64_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::width_h, "WIDTH_64", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::width_WIDTH_64_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width::WIDTH_64'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_WIDTH_64_h);
            }

            /* Declare ::hyve::lang::width::WIDTH_8 */
            if (!(::hyve::lang::width_WIDTH_8_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::width::WIDTH_8", "load: check if object '::hyve::lang::width::WIDTH_8' already exists."))) {
                ::hyve::lang::width_WIDTH_8_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::width_h, "WIDTH_8", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::width_WIDTH_8_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width::WIDTH_8'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_WIDTH_8_h);
            }

            /* Declare ::hyve::lang::width::WIDTH_WORD */
            if (!(::hyve::lang::width_WIDTH_WORD_h = (::hyve::lang::constant*)::hyve::resolve(NULL, NULL, "::hyve::lang::width::WIDTH_WORD", "load: check if object '::hyve::lang::width::WIDTH_WORD' already exists."))) {
                ::hyve::lang::width_WIDTH_WORD_h = (::hyve::lang::constant*)::hyve::declare(::hyve::lang::width_h, "WIDTH_WORD", ((::hyve::lang::_typedef)::hyve::lang::constant_h));
                if (!::hyve::lang::width_WIDTH_WORD_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::width::WIDTH_WORD'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::width_WIDTH_WORD_h);
            }

            /* Declare ::hyve::lang::word */
            if (!(::hyve::lang::word_h = (::hyve::lang::binary)::hyve::resolve(NULL, NULL, "::hyve::lang::word", "load: check if object '::hyve::lang::word' already exists."))) {
                ::hyve::lang::word_h = (::hyve::lang::binary)::hyve::declare(::hyve::lang_h, "word", ((::hyve::lang::_typedef)::hyve::lang::binary_h));
                if (!::hyve::lang::word_h) {
                    ::hyve::error("lang_load: failed to declare object '::hyve::lang::word'.");
                    goto error;
                }
            } else {
                ::hyve::free(::hyve::lang::word_h);
            }

            /* Define ::hyve::lang::alias */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::alias_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::alias_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::alias_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::alias_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::alias_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::alias_h)->baseAccess = 0x5;
                ::hyve::lang::alias_h->implements.length = 0;
                ::hyve::lang::alias_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::alias_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::alias'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::alias::init(lang::alias object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::alias_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::alias_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::alias_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::alias_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::alias_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::alias_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::alias_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::alias::init(lang::alias object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::alias::typeName */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::alias_typeName_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::alias_typeName_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                ::hyve::lang::alias_typeName_h->modifiers = 0x0;
                ::hyve::lang::alias_typeName_h->state = 0x6;
                ::hyve::lang::alias_typeName_h->weak = FALSE;
                ::hyve::lang::alias_typeName_h->id = 0;
                if (::hyve::define(::hyve::lang::alias_typeName_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::alias::typeName'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::any */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::any_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::any_h->defaultType = NULL;
                ::hyve::lang::any_h->parentType = NULL;
                ::hyve::lang::any_h->parentState = 0x6;
                if (::hyve::define(::hyve::lang::any_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::any'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::array */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::array_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::array_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::array_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::array_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::array_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::collection"));
                ((::hyve::lang::_struct)::hyve::lang::array_h)->baseAccess = 0x0;
                ::hyve::lang::array_h->implements.length = 0;
                ::hyve::lang::array_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::array_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::array'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::array::construct(lang::array object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::array_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::array_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::array_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::array_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::array_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::array_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::array_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::array::construct(lang::array object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::array::destruct(lang::array object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::array_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::array_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::array_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::array_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::array_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::array_destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::array_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::array::destruct(lang::array object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::array::elementType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::array_elementType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::array_elementType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::array_elementType_h->modifiers = 0x2;
                ::hyve::lang::array_elementType_h->state = 0x4;
                ::hyve::lang::array_elementType_h->weak = FALSE;
                ::hyve::lang::array_elementType_h->id = 0;
                if (::hyve::define(::hyve::lang::array_elementType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::array::elementType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::array::init(lang::array object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::array_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::array_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::array_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::array_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::array_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::array_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::array_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::array::init(lang::array object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::attr */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::attr_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::attr_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::attr'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::attr::ATTR_OBSERVABLE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::attr_ATTR_OBSERVABLE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::attr_ATTR_OBSERVABLE_h) = 4;
                if (::hyve::define(::hyve::lang::attr_ATTR_OBSERVABLE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::attr::ATTR_OBSERVABLE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::attr::ATTR_SCOPED */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::attr_ATTR_SCOPED_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::attr_ATTR_SCOPED_h) = 1;
                if (::hyve::define(::hyve::lang::attr_ATTR_SCOPED_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::attr::ATTR_SCOPED'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::attr::ATTR_WRITABLE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::attr_ATTR_WRITABLE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::attr_ATTR_WRITABLE_h) = 2;
                if (::hyve::define(::hyve::lang::attr_ATTR_WRITABLE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::attr::ATTR_WRITABLE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::binary */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::binary_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::binary_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::binary_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::binary_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::binary_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::binary_h)->baseAccess = 0x0;
                ::hyve::lang::binary_h->implements.length = 0;
                ::hyve::lang::binary_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::binary_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::binary'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::binary::init(lang::binary object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::binary_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::binary_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::binary_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::binary_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::binary_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::binary_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::binary_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::binary::init(lang::binary object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::bitmask */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::bitmask_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::bitmask_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::bitmask_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::bitmask_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::bitmask_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::enum"));
                ((::hyve::lang::_struct)::hyve::lang::bitmask_h)->baseAccess = 0x5;
                ::hyve::lang::bitmask_h->implements.length = 0;
                ::hyve::lang::bitmask_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::bitmask_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::bitmask'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::bitmask::init(lang::bitmask object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::bitmask_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::bitmask_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::bitmask_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::bitmask_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::bitmask_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::bitmask_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::bitmask_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::bitmask::init(lang::bitmask object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::bool */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_bool_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::_bool_h)->width = ::hyve::lang::WIDTH_8;
                if (::hyve::define(::hyve::lang::_bool_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::bool'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::boolean */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::boolean_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::boolean_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::boolean_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::boolean_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::boolean_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::boolean_h)->baseAccess = 0x4;
                ::hyve::lang::boolean_h->implements.length = 0;
                ::hyve::lang::boolean_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::boolean_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::boolean'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::boolean::init(lang::boolean object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::boolean_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::boolean_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::boolean_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::boolean_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::boolean_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::boolean_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::boolean_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::boolean::init(lang::boolean object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::callback */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::callback_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::callback_h->kind = ::hyve::lang::CALLBACK;
                if (::hyve::define(::hyve::lang::callback_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::callback'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::callback::bind(lang::callback object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::callback_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::callback_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::callback_bind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::bind(lang::object object)"));
                
                /* Bind ::hyve::lang::callback_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::callback_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::callback_bind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::callback_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::callback::bind(lang::callback object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::callback::delegate */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::callback_delegate_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::callback_delegate_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::delegate"));
                ::hyve::lang::callback_delegate_h->modifiers = 0x0;
                ::hyve::lang::callback_delegate_h->state = 0x4;
                ::hyve::lang::callback_delegate_h->weak = FALSE;
                ::hyve::lang::callback_delegate_h->id = 0;
                if (::hyve::define(::hyve::lang::callback_delegate_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::callback::delegate'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::callback::init(lang::callback object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::callback_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::callback_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::callback_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::callback_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::callback_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::callback_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::callback_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::callback::init(lang::callback object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::char */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_char_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::_char_h)->width = ::hyve::lang::WIDTH_8;
                if (::hyve::define(::hyve::lang::_char_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::char'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::character */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::character_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::character_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::character_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::character_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::character_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::character_h)->baseAccess = 0x0;
                ::hyve::lang::character_h->implements.length = 0;
                ::hyve::lang::character_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::character_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::character'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::character::init(lang::character object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::character_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::character_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::character_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::character_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::character_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::character_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::character_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::character::init(lang::character object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_class_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_class_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_class_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_class_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::struct"));
                ((::hyve::lang::_struct)::hyve::lang::_class_h)->baseAccess = 0x0;
                ::hyve::lang::_class_h->implements.length = 0;
                ::hyve::lang::_class_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_class_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::_construct(lang::class object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class__construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class__construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_class__construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::_class__construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class__construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class__construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_class__construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::_construct(lang::class object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::_destruct(lang::class object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class__destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class__destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::_class__destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::_class__destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class__destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class__destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_class__destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::_destruct(lang::class object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::allocSize() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_allocSize_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_allocSize_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::_class_allocSize_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::_class_allocSize_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_allocSize_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_allocSize_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_allocSize);
                if (::hyve::define(::hyve::lang::_class_allocSize_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::allocSize()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::bindMethod(lang::method method) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_bindMethod_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_bindMethod_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_class_bindMethod_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::_class_bindMethod_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_bindMethod_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_bindMethod_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_bindMethod);
                if (::hyve::define(::hyve::lang::_class_bindMethod_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::bindMethod(lang::method method)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::construct(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                
                /* Bind ::hyve::lang::_class_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_construct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_construct);
                if (::hyve::define(::hyve::lang::_class_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::construct(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::destruct(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                
                /* Bind ::hyve::lang::_class_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_destruct_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_destruct);
                if (::hyve::define(::hyve::lang::_class_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::destruct(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::implements */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_implements_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_class_implements_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interfaceSeq"));
                ::hyve::lang::_class_implements_h->modifiers = 0x0;
                ::hyve::lang::_class_implements_h->state = 0x6;
                ::hyve::lang::_class_implements_h->weak = FALSE;
                ::hyve::lang::_class_implements_h->id = 0;
                if (::hyve::define(::hyve::lang::_class_implements_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::implements'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::init(lang::class object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_class_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_class_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_class_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::init(lang::class object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::instanceof(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_instanceof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_instanceof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::_class_instanceof_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::_class_instanceof_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_instanceof_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_instanceof_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_instanceof);
                if (::hyve::define(::hyve::lang::_class_instanceof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::instanceof(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::interfaceVector */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_interfaceVector_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_class_interfaceVector_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interfaceVectorSeq"));
                ::hyve::lang::_class_interfaceVector_h->modifiers = 0x3;
                ::hyve::lang::_class_interfaceVector_h->state = 0x6;
                ::hyve::lang::_class_interfaceVector_h->weak = FALSE;
                ::hyve::lang::_class_interfaceVector_h->id = 1;
                if (::hyve::define(::hyve::lang::_class_interfaceVector_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::interfaceVector'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::observers */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_observers_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_class_observers_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observerSeq"));
                ::hyve::lang::_class_observers_h->modifiers = 0x3;
                ::hyve::lang::_class_observers_h->state = 0x6;
                ::hyve::lang::_class_observers_h->weak = FALSE;
                ::hyve::lang::_class_observers_h->id = 2;
                if (::hyve::define(::hyve::lang::_class_observers_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::observers'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_class_privateObserver_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_class_privateObserver_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observer"));
                ::hyve::lang::_class_privateObserver_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::_class_privateObserver_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_class_privateObserver_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_class_privateObserver_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__class_privateObserver);
                if (::hyve::define(::hyve::lang::_class_privateObserver_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::class::privateObserver(lang::object object,lang::observer observer)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::collection_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::collection_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::collection_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::collection_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::type"));
                ((::hyve::lang::_struct)::hyve::lang::collection_h)->baseAccess = 0x5;
                ::hyve::lang::collection_h->implements.length = 0;
                ::hyve::lang::collection_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::collection_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::castable(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_castable_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::collection_castable_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::collection_castable_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::collection_castable_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::collection_castable_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::collection_castable_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_collection_castable);
                if (::hyve::define(::hyve::lang::collection_castable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::castable(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::elementType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_elementType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::collection_elementType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::collection_elementType_h->modifiers = 0x0;
                ::hyve::lang::collection_elementType_h->state = 0x2;
                ::hyve::lang::collection_elementType_h->weak = FALSE;
                ::hyve::lang::collection_elementType_h->id = 1;
                if (::hyve::define(::hyve::lang::collection_elementType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::elementType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::init(lang::collection object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::collection_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::collection_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::collection_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::collection_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::collection_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::collection_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::init(lang::collection object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::collection_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::collectionKind"));
                ::hyve::lang::collection_kind_h->modifiers = 0x5;
                ::hyve::lang::collection_kind_h->state = 0x6;
                ::hyve::lang::collection_kind_h->weak = FALSE;
                ::hyve::lang::collection_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::collection_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::max */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_max_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::collection_max_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::collection_max_h->modifiers = 0x0;
                ::hyve::lang::collection_max_h->state = 0x6;
                ::hyve::lang::collection_max_h->weak = FALSE;
                ::hyve::lang::collection_max_h->id = 2;
                if (::hyve::define(::hyve::lang::collection_max_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::max'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collection::size() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collection_size_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::collection_size_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                if (::hyve::define(::hyve::lang::collection_size_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collection::size()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collectionKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collectionKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::collectionKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collectionKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collectionKind::ARRAY */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collectionKind_ARRAY_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::collectionKind_ARRAY_h) = 0;
                if (::hyve::define(::hyve::lang::collectionKind_ARRAY_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collectionKind::ARRAY'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collectionKind::LIST */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collectionKind_LIST_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::collectionKind_LIST_h) = 2;
                if (::hyve::define(::hyve::lang::collectionKind_LIST_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collectionKind::LIST'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collectionKind::MAP */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collectionKind_MAP_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::collectionKind_MAP_h) = 3;
                if (::hyve::define(::hyve::lang::collectionKind_MAP_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collectionKind::MAP'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::collectionKind::SEQUENCE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::collectionKind_SEQUENCE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::collectionKind_SEQUENCE_h) = 1;
                if (::hyve::define(::hyve::lang::collectionKind_SEQUENCE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::collectionKind::SEQUENCE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::compositeKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::compositeKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::compositeKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::compositeKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::compositeKind::CLASS */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::compositeKind_CLASS_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::compositeKind_CLASS_h) = 2;
                if (::hyve::define(::hyve::lang::compositeKind_CLASS_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::compositeKind::CLASS'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::compositeKind::INTERFACE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::compositeKind_INTERFACE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::compositeKind_INTERFACE_h) = 0;
                if (::hyve::define(::hyve::lang::compositeKind_INTERFACE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::compositeKind::INTERFACE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::compositeKind::PROCEDURE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::compositeKind_PROCEDURE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::compositeKind_PROCEDURE_h) = 3;
                if (::hyve::define(::hyve::lang::compositeKind_PROCEDURE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::compositeKind::PROCEDURE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::compositeKind::STRUCT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::compositeKind_STRUCT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::compositeKind_STRUCT_h) = 1;
                if (::hyve::define(::hyve::lang::compositeKind_STRUCT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::compositeKind::STRUCT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::constant */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::constant_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::constant_h)->width = ::hyve::lang::WIDTH_32;
                ::hyve::lang::constant_h->min = 0;
                ::hyve::lang::constant_h->max = -1;
                if (::hyve::define(::hyve::lang::constant_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::constant'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::constant::init(constant object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::constant_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::constant_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::constant_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::constant_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::constant_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::constant_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::constant_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::constant::init(constant object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::delegate */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::delegate_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::delegate_h->kind = ::hyve::lang::DELEGATE;
                if (::hyve::define(::hyve::lang::delegate_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::delegate'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::delegate::id */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::delegate_id_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::delegate_id_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::delegate_id_h->modifiers = 0x1;
                ::hyve::lang::delegate_id_h->state = 0x6;
                ::hyve::lang::delegate_id_h->weak = FALSE;
                ::hyve::lang::delegate_id_h->id = 0;
                if (::hyve::define(::hyve::lang::delegate_id_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::delegate::id'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::delegate::init(lang::delegate object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::delegate_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::delegate_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::delegate_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::delegate_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::delegate_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::delegate_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::delegate_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::delegate::init(lang::delegate object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::dispatcher */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::dispatcher_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::dispatcher_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::dispatcher_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::dispatcher_h)->parentState = 0x0;
                ::hyve::lang::dispatcher_h->base = NULL;
                if (::hyve::define(::hyve::lang::dispatcher_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::dispatcher'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::dispatcher_getEvent_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::dispatcher_getEvent_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observableEvent"));
                ::hyve::lang::dispatcher_getEvent_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::dispatcher_getEvent_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::dispatcher_getEvent_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::dispatcher_getEvent_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_dispatcher_getEvent);
            }
            /* Define ::hyve::lang::dispatcher::post(lang::event event) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::dispatcher_post_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::dispatcher_post_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::dispatcher_post_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::dispatcher_post_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::dispatcher_post_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::dispatcher_post_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_dispatcher_post);
            }
            /* Define ::hyve::lang::enum */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_enum_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_enum_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_enum_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_enum_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::_enum_h)->baseAccess = 0x5;
                ::hyve::lang::_enum_h->implements.length = 0;
                ::hyve::lang::_enum_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_enum_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::enum::constant(lang::int32 value) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_constant_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_enum_constant_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::_enum_constant_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::_enum_constant_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_enum_constant_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_enum_constant_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__enum_constant);
                if (::hyve::define(::hyve::lang::_enum_constant_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum::constant(lang::int32 value)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::enum::constants */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_constants_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_enum_constants_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::objectSeq"));
                ::hyve::lang::_enum_constants_h->modifiers = 0x3;
                ::hyve::lang::_enum_constants_h->state = 0x6;
                ::hyve::lang::_enum_constants_h->weak = FALSE;
                ::hyve::lang::_enum_constants_h->id = 0;
                if (::hyve::define(::hyve::lang::_enum_constants_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum::constants'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::enum::construct(lang::enum object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_enum_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_enum_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::_enum_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_enum_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_enum_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_enum_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum::construct(lang::enum object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::enum::destruct(lang::enum object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_enum_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::_enum_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::_enum_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_enum_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_enum_destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_enum_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum::destruct(lang::enum object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::enum::init(lang::enum object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_enum_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_enum_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_enum_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_enum_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_enum_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_enum_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_enum_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::enum::init(lang::enum object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::equalityKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::equalityKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::equalityKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::equalityKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::equalityKind::EQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::equalityKind_EQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::equalityKind_EQ_h) = 0;
                if (::hyve::define(::hyve::lang::equalityKind_EQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::equalityKind::EQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::equalityKind::GT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::equalityKind_GT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::equalityKind_GT_h) = 1;
                if (::hyve::define(::hyve::lang::equalityKind_GT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::equalityKind::GT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::equalityKind::LT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::equalityKind_LT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::equalityKind_LT_h) = -1;
                if (::hyve::define(::hyve::lang::equalityKind_LT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::equalityKind::LT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::equalityKind::NEQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::equalityKind_NEQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::equalityKind_NEQ_h) = 2;
                if (::hyve::define(::hyve::lang::equalityKind_NEQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::equalityKind::NEQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::event */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::event_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::event_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::event_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::event_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::event_h)->base = NULL;
                ((::hyve::lang::_struct)::hyve::lang::event_h)->baseAccess = 0x1;
                ::hyve::lang::event_h->implements.length = 0;
                ::hyve::lang::event_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::event_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::event'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::event::handled */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::event_handled_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::event_handled_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::event_handled_h->modifiers = 0x5;
                ::hyve::lang::event_handled_h->state = 0x6;
                ::hyve::lang::event_handled_h->weak = FALSE;
                ::hyve::lang::event_handled_h->id = 1;
                if (::hyve::define(::hyve::lang::event_handled_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::event::handled'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::event::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::event_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::event_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint16"));
                ::hyve::lang::event_kind_h->modifiers = 0x0;
                ::hyve::lang::event_kind_h->state = 0x6;
                ::hyve::lang::event_kind_h->weak = FALSE;
                ::hyve::lang::event_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::event_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::event::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::event::processed() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::event_processed_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::event_processed_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::event_processed_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::event_processed_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::event_processed_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::event_processed_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_event_processed);
                if (::hyve::define(::hyve::lang::event_processed_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::event::processed()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::event::uniqueKind() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::event_uniqueKind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::event_uniqueKind_h->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                
                /* Bind ::hyve::lang::event_uniqueKind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::event_uniqueKind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::event_uniqueKind_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_event_uniqueKind);
                if (::hyve::define(::hyve::lang::event_uniqueKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::event::uniqueKind()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::eventMask_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_DECLARE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_DECLARE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_DECLARE_h) = 1;
                if (::hyve::define(::hyve::lang::eventMask_ON_DECLARE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_DECLARE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_DEFINE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_DEFINE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_DEFINE_h) = 2;
                if (::hyve::define(::hyve::lang::eventMask_ON_DEFINE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_DEFINE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_DESTRUCT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_DESTRUCT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_DESTRUCT_h) = 4;
                if (::hyve::define(::hyve::lang::eventMask_ON_DESTRUCT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_DESTRUCT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_INVALIDATE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_INVALIDATE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_INVALIDATE_h) = 8;
                if (::hyve::define(::hyve::lang::eventMask_ON_INVALIDATE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_INVALIDATE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_METAVALUE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_METAVALUE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_METAVALUE_h) = 256;
                if (::hyve::define(::hyve::lang::eventMask_ON_METAVALUE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_METAVALUE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_SCOPE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_SCOPE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_SCOPE_h) = 64;
                if (::hyve::define(::hyve::lang::eventMask_ON_SCOPE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_SCOPE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_SELF */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_SELF_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_SELF_h) = 32;
                if (::hyve::define(::hyve::lang::eventMask_ON_SELF_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_SELF'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_UPDATE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_UPDATE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_UPDATE_h) = 16;
                if (::hyve::define(::hyve::lang::eventMask_ON_UPDATE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_UPDATE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::eventMask::ON_VALUE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::eventMask_ON_VALUE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::eventMask_ON_VALUE_h) = 128;
                if (::hyve::define(::hyve::lang::eventMask_ON_VALUE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::eventMask::ON_VALUE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_float_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_float_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_float_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_float_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_float_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::_float_h)->baseAccess = 0x0;
                ::hyve::lang::_float_h->implements.length = 0;
                ::hyve::lang::_float_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_float_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float::init(lang::float object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_float_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_float_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_float_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_float_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_float_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_float_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_float_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float::init(lang::float object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float::max */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_float_max_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_float_max_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::float64"));
                ::hyve::lang::_float_max_h->modifiers = 0x0;
                ::hyve::lang::_float_max_h->state = 0x6;
                ::hyve::lang::_float_max_h->weak = FALSE;
                ::hyve::lang::_float_max_h->id = 1;
                if (::hyve::define(::hyve::lang::_float_max_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float::max'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float::min */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_float_min_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_float_min_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::float64"));
                ::hyve::lang::_float_min_h->modifiers = 0x0;
                ::hyve::lang::_float_min_h->state = 0x6;
                ::hyve::lang::_float_min_h->weak = FALSE;
                ::hyve::lang::_float_min_h->id = 0;
                if (::hyve::define(::hyve::lang::_float_min_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float::min'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float32 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::float32_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::float32_h)->width = ::hyve::lang::WIDTH_32;
                ::hyve::lang::float32_h->min = 0.000000;
                ::hyve::lang::float32_h->max = 0.000000;
                if (::hyve::define(::hyve::lang::float32_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float32'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::float64 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::float64_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::float64_h)->width = ::hyve::lang::WIDTH_64;
                ::hyve::lang::float64_h->min = 0.000000;
                ::hyve::lang::float64_h->max = 0.000000;
                if (::hyve::define(::hyve::lang::float64_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::float64'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_h->kind = ::hyve::lang::FUNCTION;
                if (::hyve::define(::hyve::lang::function_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::bind(lang::function object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::function_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::function_bind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::bind(lang::object object)"));
                
                /* Bind ::hyve::lang::function_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::function_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::function_bind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::function_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::bind(lang::function object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::impl */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_impl_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_impl_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
                ::hyve::lang::function_impl_h->modifiers = 0x3;
                ::hyve::lang::function_impl_h->state = 0x6;
                ::hyve::lang::function_impl_h->weak = FALSE;
                ::hyve::lang::function_impl_h->id = 3;
                if (::hyve::define(::hyve::lang::function_impl_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::impl'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::impludata */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_impludata_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_impludata_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
                ::hyve::lang::function_impludata_h->modifiers = 0x3;
                ::hyve::lang::function_impludata_h->state = 0x6;
                ::hyve::lang::function_impludata_h->weak = FALSE;
                ::hyve::lang::function_impludata_h->id = 4;
                if (::hyve::define(::hyve::lang::function_impludata_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::impludata'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::init(lang::function object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::function_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::function_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::function_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::function_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::function_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::function_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::init(lang::function object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::function_kind_h->modifiers = 0x3;
                ::hyve::lang::function_kind_h->state = 0x6;
                ::hyve::lang::function_kind_h->weak = FALSE;
                ::hyve::lang::function_kind_h->id = 2;
                if (::hyve::define(::hyve::lang::function_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::nextParameterId */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_nextParameterId_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_nextParameterId_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::function_nextParameterId_h->modifiers = 0x3;
                ::hyve::lang::function_nextParameterId_h->state = 0x6;
                ::hyve::lang::function_nextParameterId_h->weak = FALSE;
                ::hyve::lang::function_nextParameterId_h->id = 8;
                if (::hyve::define(::hyve::lang::function_nextParameterId_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::nextParameterId'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::overloaded */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_overloaded_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_overloaded_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::function_overloaded_h->modifiers = 0x5;
                ::hyve::lang::function_overloaded_h->state = 0x6;
                ::hyve::lang::function_overloaded_h->weak = FALSE;
                ::hyve::lang::function_overloaded_h->id = 1;
                if (::hyve::define(::hyve::lang::function_overloaded_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::overloaded'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::parameters */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_parameters_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_parameters_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::parameterSeq"));
                ::hyve::lang::function_parameters_h->modifiers = 0x5;
                ::hyve::lang::function_parameters_h->state = 0x6;
                ::hyve::lang::function_parameters_h->weak = FALSE;
                ::hyve::lang::function_parameters_h->id = 7;
                if (::hyve::define(::hyve::lang::function_parameters_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::parameters'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::resource */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_resource_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_resource_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::function_resource_h->modifiers = 0x3;
                ::hyve::lang::function_resource_h->state = 0x6;
                ::hyve::lang::function_resource_h->weak = FALSE;
                ::hyve::lang::function_resource_h->id = 5;
                if (::hyve::define(::hyve::lang::function_resource_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::resource'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::returnType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_returnType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_returnType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::function_returnType_h->modifiers = 0x0;
                ::hyve::lang::function_returnType_h->state = 0x6;
                ::hyve::lang::function_returnType_h->weak = FALSE;
                ::hyve::lang::function_returnType_h->id = 0;
                if (::hyve::define(::hyve::lang::function_returnType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::returnType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::size */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_size_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::function_size_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::function_size_h->modifiers = 0x3;
                ::hyve::lang::function_size_h->state = 0x6;
                ::hyve::lang::function_size_h->weak = FALSE;
                ::hyve::lang::function_size_h->id = 6;
                if (::hyve::define(::hyve::lang::function_size_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::size'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::function::unbind(lang::function object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::function_unbind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::function_unbind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::function_unbind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::unbind(lang::object object)"));
                
                /* Bind ::hyve::lang::function_unbind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::function_unbind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::function_unbind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::function_unbind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::function::unbind(lang::function object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_int_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_int_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_int_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_int_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_int_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::_int_h)->baseAccess = 0x0;
                ::hyve::lang::_int_h->implements.length = 0;
                ::hyve::lang::_int_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_int_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int::init(lang::int object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_int_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_int_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_int_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_int_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_int_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_int_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_int_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int::init(lang::int object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int::max */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_int_max_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_int_max_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int64"));
                ::hyve::lang::_int_max_h->modifiers = 0x0;
                ::hyve::lang::_int_max_h->state = 0x6;
                ::hyve::lang::_int_max_h->weak = FALSE;
                ::hyve::lang::_int_max_h->id = 1;
                if (::hyve::define(::hyve::lang::_int_max_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int::max'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int::min */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_int_min_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_int_min_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int64"));
                ::hyve::lang::_int_min_h->modifiers = 0x0;
                ::hyve::lang::_int_min_h->state = 0x6;
                ::hyve::lang::_int_min_h->weak = FALSE;
                ::hyve::lang::_int_min_h->id = 0;
                if (::hyve::define(::hyve::lang::_int_min_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int::min'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int16 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::int16_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::int16_h)->width = ::hyve::lang::WIDTH_16;
                ::hyve::lang::int16_h->min = -1;
                ::hyve::lang::int16_h->max = -1;
                if (::hyve::define(::hyve::lang::int16_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int16'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int32 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::int32_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::int32_h)->width = ::hyve::lang::WIDTH_32;
                ::hyve::lang::int32_h->min = -1;
                ::hyve::lang::int32_h->max = -1;
                if (::hyve::define(::hyve::lang::int32_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int32'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int64 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::int64_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::int64_h)->width = ::hyve::lang::WIDTH_64;
                ::hyve::lang::int64_h->min = -1;
                ::hyve::lang::int64_h->max = -1;
                if (::hyve::define(::hyve::lang::int64_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int64'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::int8 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::int8_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::int8_h)->width = ::hyve::lang::WIDTH_8;
                ::hyve::lang::int8_h->min = -1;
                ::hyve::lang::int8_h->max = -1;
                if (::hyve::define(::hyve::lang::int8_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::int8'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::interface_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::interface_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::interface_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::interface_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::type"));
                ((::hyve::lang::_struct)::hyve::lang::interface_h)->baseAccess = 0x4;
                ::hyve::lang::interface_h->implements.length = 0;
                ::hyve::lang::interface_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::interface_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::base */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_base_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interface_base_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interface"));
                ::hyve::lang::interface_base_h->modifiers = 0x0;
                ::hyve::lang::interface_base_h->state = 0x4;
                ::hyve::lang::interface_base_h->weak = FALSE;
                ::hyve::lang::interface_base_h->id = 4;
                if (::hyve::define(::hyve::lang::interface_base_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::base'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::bindMethod(lang::method method) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_bindMethod_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_bindMethod_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::interface_bindMethod_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::interface_bindMethod_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_bindMethod_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_bindMethod_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_bindMethod);
                if (::hyve::define(::hyve::lang::interface_bindMethod_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::bindMethod(lang::method method)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::compatible(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_compatible_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_compatible_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::interface_compatible_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::interface_compatible_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_compatible_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_compatible_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_compatible);
                if (::hyve::define(::hyve::lang::interface_compatible_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::compatible(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::construct(lang::interface object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::interface_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::interface_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::interface_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::construct(lang::interface object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::destruct(lang::interface object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::interface_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::interface_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::interface_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::destruct(lang::interface object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::init(lang::interface object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::interface_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::interface_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::interface_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::init(lang::interface object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interface_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::compositeKind"));
                ::hyve::lang::interface_kind_h->modifiers = 0x5;
                ::hyve::lang::interface_kind_h->state = 0x6;
                ::hyve::lang::interface_kind_h->weak = FALSE;
                ::hyve::lang::interface_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::interface_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::members */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_members_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interface_members_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::memberSeq"));
                ::hyve::lang::interface_members_h->modifiers = 0x3;
                ::hyve::lang::interface_members_h->state = 0x6;
                ::hyve::lang::interface_members_h->weak = FALSE;
                ::hyve::lang::interface_members_h->id = 2;
                if (::hyve::define(::hyve::lang::interface_members_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::members'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::methods */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_methods_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interface_methods_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::vtable"));
                ::hyve::lang::interface_methods_h->modifiers = 0x3;
                ::hyve::lang::interface_methods_h->state = 0x6;
                ::hyve::lang::interface_methods_h->weak = FALSE;
                ::hyve::lang::interface_methods_h->id = 3;
                if (::hyve::define(::hyve::lang::interface_methods_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::methods'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::nextMemberId */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_nextMemberId_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interface_nextMemberId_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::interface_nextMemberId_h->modifiers = 0x3;
                ::hyve::lang::interface_nextMemberId_h->state = 0x6;
                ::hyve::lang::interface_nextMemberId_h->weak = FALSE;
                ::hyve::lang::interface_nextMemberId_h->id = 1;
                if (::hyve::define(::hyve::lang::interface_nextMemberId_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::nextMemberId'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::resolveMember(lang::string name) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_resolveMember_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_resolveMember_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ::hyve::lang::interface_resolveMember_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::interface_resolveMember_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_resolveMember_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_resolveMember_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_resolveMember);
                if (::hyve::define(::hyve::lang::interface_resolveMember_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::resolveMember(lang::string name)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::resolveMethod(lang::string name) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_resolveMethod_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethod_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::method"));
                ::hyve::lang::interface_resolveMethod_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::interface_resolveMethod_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethod_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethod_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_resolveMethod);
                if (::hyve::define(::hyve::lang::interface_resolveMethod_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::resolveMethod(lang::string name)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::resolveMethodById(lang::uint32 id) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_resolveMethodById_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodById_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::method"));
                ::hyve::lang::interface_resolveMethodById_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::interface_resolveMethodById_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodById_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodById_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_resolveMethodById);
                if (::hyve::define(::hyve::lang::interface_resolveMethodById_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::resolveMethodById(lang::uint32 id)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interface::resolveMethodId(lang::string name) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interface_resolveMethodId_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodId_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::interface_resolveMethodId_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::interface_resolveMethodId_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodId_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::interface_resolveMethodId_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_interface_resolveMethodId);
                if (::hyve::define(::hyve::lang::interface_resolveMethodId_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interface::resolveMethodId(lang::string name)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interfaceSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interfaceSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::interfaceSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interface"));
                ((::hyve::lang::collection)::hyve::lang::interfaceSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::interfaceSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interfaceSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interfaceVector */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interfaceVector_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::interfaceVector_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::interfaceVector_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::interfaceVector_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::interfaceVector_h)->base = NULL;
                ::hyve::lang::interfaceVector_h->baseAccess = 0x1;
                if (::hyve::define(::hyve::lang::interfaceVector_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interfaceVector'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interfaceVector::interface */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interfaceVector_interface_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interfaceVector_interface_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::word"));
                ::hyve::lang::interfaceVector_interface_h->modifiers = 0x0;
                ::hyve::lang::interfaceVector_interface_h->state = 0x6;
                ::hyve::lang::interfaceVector_interface_h->weak = FALSE;
                ::hyve::lang::interfaceVector_interface_h->id = 0;
                if (::hyve::define(::hyve::lang::interfaceVector_interface_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interfaceVector::interface'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interfaceVector::vector */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interfaceVector_vector_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::interfaceVector_vector_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::vtable"));
                ::hyve::lang::interfaceVector_vector_h->modifiers = 0x0;
                ::hyve::lang::interfaceVector_vector_h->state = 0x6;
                ::hyve::lang::interfaceVector_vector_h->weak = FALSE;
                ::hyve::lang::interfaceVector_vector_h->id = 1;
                if (::hyve::define(::hyve::lang::interfaceVector_vector_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interfaceVector::vector'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::interfaceVectorSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::interfaceVectorSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::interfaceVectorSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interfaceVector"));
                ((::hyve::lang::collection)::hyve::lang::interfaceVectorSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::interfaceVectorSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::interfaceVectorSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::list_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::list_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::list_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::list_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::collection"));
                ((::hyve::lang::_struct)::hyve::lang::list_h)->baseAccess = 0x0;
                ::hyve::lang::list_h->implements.length = 0;
                ::hyve::lang::list_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::list_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::append() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_append__h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_append__h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_append__h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::append()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::append(lang::any element) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_append_langany_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_append_langany_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_append_langany_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::append(lang::any element)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::clear() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_clear_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_clear_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_clear_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::clear()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::construct(lang::list object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::list_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::list_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::list_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::list_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::list_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::construct(lang::list object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::init(lang::list object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::list_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::list_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::list_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::list_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::list_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::init(lang::list object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::insert() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_insert__h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_insert__h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_insert__h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::insert()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::insert(lang::any element) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_insert_langany_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_insert_langany_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_insert_langany_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::insert(lang::any element)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::list::reverse() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::list_reverse_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::list_reverse_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::list_reverse_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::list::reverse()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::map_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::map_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::map_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::map_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::collection"));
                ((::hyve::lang::_struct)::hyve::lang::map_h)->baseAccess = 0x1;
                ::hyve::lang::map_h->implements.length = 0;
                ::hyve::lang::map_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::map_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map::construct(lang::map object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::map_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::map_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::map_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::map_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::map_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::map_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map::construct(lang::map object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map::elementType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_elementType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::map_elementType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::map_elementType_h->modifiers = 0x0;
                ::hyve::lang::map_elementType_h->state = 0x6;
                ::hyve::lang::map_elementType_h->weak = FALSE;
                ::hyve::lang::map_elementType_h->id = 0;
                if (::hyve::define(::hyve::lang::map_elementType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map::elementType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map::init(lang::map object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::map_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::map_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::map_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::map_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::map_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::map_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map::init(lang::map object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map::keyType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_keyType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::map_keyType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::map_keyType_h->modifiers = 0x0;
                ::hyve::lang::map_keyType_h->state = 0x6;
                ::hyve::lang::map_keyType_h->weak = FALSE;
                ::hyve::lang::map_keyType_h->id = 1;
                if (::hyve::define(::hyve::lang::map_keyType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map::keyType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::map::max */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::map_max_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::map_max_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::map_max_h->modifiers = 0x0;
                ::hyve::lang::map_max_h->state = 0x6;
                ::hyve::lang::map_max_h->weak = FALSE;
                ::hyve::lang::map_max_h->id = 2;
                if (::hyve::define(::hyve::lang::map_max_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::map::max'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::member_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::member_h)->parentType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::interface"));
                ((::hyve::lang::type)::hyve::lang::member_h)->parentState = 0x2;
                ((::hyve::lang::interface)::hyve::lang::member_h)->base = NULL;
                ((::hyve::lang::_struct)::hyve::lang::member_h)->baseAccess = 0x1;
                ::hyve::lang::member_h->implements.length = 0;
                ::hyve::lang::member_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::member_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::construct(lang::member object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::member_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::member_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::member_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::member_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::member_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::member_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::construct(lang::member object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::id */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_id_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_id_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::member_id_h->modifiers = 0x2;
                ::hyve::lang::member_id_h->state = 0x6;
                ::hyve::lang::member_id_h->weak = FALSE;
                ::hyve::lang::member_id_h->id = 4;
                if (::hyve::define(::hyve::lang::member_id_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::id'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::init(lang::member object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::member_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::member_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::member_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::member_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::member_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::member_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::init(lang::member object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::modifiers */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_modifiers_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_modifiers_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::modifier"));
                ::hyve::lang::member_modifiers_h->modifiers = 0x0;
                ::hyve::lang::member_modifiers_h->state = 0x6;
                ::hyve::lang::member_modifiers_h->weak = FALSE;
                ::hyve::lang::member_modifiers_h->id = 1;
                if (::hyve::define(::hyve::lang::member_modifiers_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::modifiers'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::offset */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_offset_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_offset_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::member_offset_h->modifiers = 0x3;
                ::hyve::lang::member_offset_h->state = 0x6;
                ::hyve::lang::member_offset_h->weak = FALSE;
                ::hyve::lang::member_offset_h->id = 5;
                if (::hyve::define(::hyve::lang::member_offset_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::offset'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::state */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_state_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_state_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::state"));
                ::hyve::lang::member_state_h->modifiers = 0x0;
                ::hyve::lang::member_state_h->state = 0x6;
                ::hyve::lang::member_state_h->weak = FALSE;
                ::hyve::lang::member_state_h->id = 2;
                if (::hyve::define(::hyve::lang::member_state_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::state'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::type */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_type_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_type_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::member_type_h->modifiers = 0x0;
                ::hyve::lang::member_type_h->state = 0x6;
                ::hyve::lang::member_type_h->weak = FALSE;
                ::hyve::lang::member_type_h->id = 0;
                if (::hyve::define(::hyve::lang::member_type_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::type'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::member::weak */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::member_weak_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::member_weak_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::member_weak_h->modifiers = 0x0;
                ::hyve::lang::member_weak_h->state = 0x6;
                ::hyve::lang::member_weak_h->weak = FALSE;
                ::hyve::lang::member_weak_h->id = 3;
                if (::hyve::define(::hyve::lang::member_weak_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::member::weak'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::memberSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::memberSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::memberSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::collection)::hyve::lang::memberSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::memberSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::memberSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::metaprocedure */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::metaprocedure_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::metaprocedure_h->kind = ::hyve::lang::METAPROCEDURE;
                if (::hyve::define(::hyve::lang::metaprocedure_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::metaprocedure'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::metaprocedure::bind(lang::metaprocedure object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::metaprocedure_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::metaprocedure_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::metaprocedure_bind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::bind(lang::object object)"));
                
                /* Bind ::hyve::lang::metaprocedure_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::metaprocedure_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::metaprocedure_bind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::metaprocedure_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::metaprocedure::bind(lang::metaprocedure object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::method */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::method_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::method_h->kind = ::hyve::lang::METHOD;
                if (::hyve::define(::hyve::lang::method_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::method'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::method::bind(lang::method object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::method_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::method_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::method_bind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::bind(lang::object object)"));
                
                /* Bind ::hyve::lang::method_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::method_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::method_bind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::method_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::method::bind(lang::method object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::method::init(lang::method object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::method_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::method_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::method_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::method_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::method_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::method_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::method_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::method::init(lang::method object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::method::virtual */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::method__virtual_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::method__virtual_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::method__virtual_h->modifiers = 0x0;
                ::hyve::lang::method__virtual_h->state = 0x6;
                ::hyve::lang::method__virtual_h->weak = FALSE;
                ::hyve::lang::method__virtual_h->id = 0;
                if (::hyve::define(::hyve::lang::method__virtual_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::method::virtual'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::modifier_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier::CONST */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_CONST_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::modifier_CONST_h) = 8;
                if (::hyve::define(::hyve::lang::modifier_CONST_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier::CONST'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier::GLOBAL */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_GLOBAL_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::modifier_GLOBAL_h) = 0;
                if (::hyve::define(::hyve::lang::modifier_GLOBAL_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier::GLOBAL'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier::LOCAL */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_LOCAL_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::modifier_LOCAL_h) = 1;
                if (::hyve::define(::hyve::lang::modifier_LOCAL_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier::LOCAL'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier::PRIVATE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_PRIVATE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::modifier_PRIVATE_h) = 2;
                if (::hyve::define(::hyve::lang::modifier_PRIVATE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier::PRIVATE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::modifier::READONLY */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::modifier_READONLY_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::modifier_READONLY_h) = 4;
                if (::hyve::define(::hyve::lang::modifier_READONLY_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::modifier::READONLY'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::object */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::object_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::object_h->defaultType = NULL;
                ::hyve::lang::object_h->parentType = NULL;
                ::hyve::lang::object_h->parentState = 0x6;
                if (::hyve::define(::hyve::lang::object_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::object'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::objectSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::objectSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::objectSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ((::hyve::lang::collection)::hyve::lang::objectSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::objectSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::objectSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observableEvent */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observableEvent_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::observableEvent_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::observableEvent_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::observableEvent_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::observableEvent_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::event"));
                ((::hyve::lang::_struct)::hyve::lang::observableEvent_h)->baseAccess = 0x0;
                ::hyve::lang::observableEvent_h->implements.length = 0;
                ::hyve::lang::observableEvent_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::observableEvent_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observableEvent'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observableEvent::me */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observableEvent_me_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observableEvent_me_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observableEvent_me_h->modifiers = 0x0;
                ::hyve::lang::observableEvent_me_h->state = 0x6;
                ::hyve::lang::observableEvent_me_h->weak = FALSE;
                ::hyve::lang::observableEvent_me_h->id = 1;
                if (::hyve::define(::hyve::lang::observableEvent_me_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observableEvent::me'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observableEvent::observable */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observableEvent_observable_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observableEvent_observable_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observableEvent_observable_h->modifiers = 0x0;
                ::hyve::lang::observableEvent_observable_h->state = 0x6;
                ::hyve::lang::observableEvent_observable_h->weak = FALSE;
                ::hyve::lang::observableEvent_observable_h->id = 3;
                if (::hyve::define(::hyve::lang::observableEvent_observable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observableEvent::observable'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observableEvent::observer */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observableEvent_observer_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observableEvent_observer_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observer"));
                ::hyve::lang::observableEvent_observer_h->modifiers = 0x0;
                ::hyve::lang::observableEvent_observer_h->state = 0x6;
                ::hyve::lang::observableEvent_observer_h->weak = FALSE;
                ::hyve::lang::observableEvent_observer_h->id = 0;
                if (::hyve::define(::hyve::lang::observableEvent_observer_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observableEvent::observer'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observableEvent::source */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observableEvent_source_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observableEvent_source_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observableEvent_source_h->modifiers = 0x0;
                ::hyve::lang::observableEvent_source_h->state = 0x6;
                ::hyve::lang::observableEvent_source_h->weak = FALSE;
                ::hyve::lang::observableEvent_source_h->id = 2;
                if (::hyve::define(::hyve::lang::observableEvent_source_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observableEvent::source'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_h->kind = ::hyve::lang::OBSERVER;
                if (::hyve::define(::hyve::lang::observer_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::bind(lang::observer object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::observer_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::observer_bind_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::procedure::bind(lang::object object)"));
                
                /* Bind ::hyve::lang::observer_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::observer_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::observer_bind_h)->impl = 0;
                if (::hyve::define(::hyve::lang::observer_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::bind(lang::observer object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::delayedBinder */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_delayedBinder_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_delayedBinder_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observer"));
                ::hyve::lang::observer_delayedBinder_h->modifiers = 0x3;
                ::hyve::lang::observer_delayedBinder_h->state = 0x6;
                ::hyve::lang::observer_delayedBinder_h->weak = FALSE;
                ::hyve::lang::observer_delayedBinder_h->id = 7;
                if (::hyve::define(::hyve::lang::observer_delayedBinder_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::delayedBinder'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::dispatcher */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_dispatcher_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_dispatcher_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::dispatcher"));
                ::hyve::lang::observer_dispatcher_h->modifiers = 0x0;
                ::hyve::lang::observer_dispatcher_h->state = 0x6;
                ::hyve::lang::observer_dispatcher_h->weak = FALSE;
                ::hyve::lang::observer_dispatcher_h->id = 4;
                if (::hyve::define(::hyve::lang::observer_dispatcher_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::dispatcher'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::expression */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_expression_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_expression_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                ::hyve::lang::observer_expression_h->modifiers = 0x0;
                ::hyve::lang::observer_expression_h->state = 0x6;
                ::hyve::lang::observer_expression_h->weak = FALSE;
                ::hyve::lang::observer_expression_h->id = 2;
                if (::hyve::define(::hyve::lang::observer_expression_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::expression'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::init(lang::observer object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::observer_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::observer_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::observer_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::observer_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::observer_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::observer_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::init(lang::observer object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::listen(lang::object observable,lang::object me) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_listen_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::observer_listen_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::observer_listen_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::observer_listen_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::observer_listen_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::observer_listen_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_observer_listen);
                if (::hyve::define(::hyve::lang::observer_listen_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::listen(lang::object observable,lang::object me)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::mask */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_mask_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_mask_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::eventMask"));
                ::hyve::lang::observer_mask_h->modifiers = 0x0;
                ::hyve::lang::observer_mask_h->state = 0x6;
                ::hyve::lang::observer_mask_h->weak = FALSE;
                ::hyve::lang::observer_mask_h->id = 1;
                if (::hyve::define(::hyve::lang::observer_mask_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::mask'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::me */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_me_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_me_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observer_me_h->modifiers = 0x0;
                ::hyve::lang::observer_me_h->state = 0x6;
                ::hyve::lang::observer_me_h->weak = FALSE;
                ::hyve::lang::observer_me_h->id = 5;
                if (::hyve::define(::hyve::lang::observer_me_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::me'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::observable */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_observable_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_observable_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observer_observable_h->modifiers = 0x0;
                ::hyve::lang::observer_observable_h->state = 0x6;
                ::hyve::lang::observer_observable_h->weak = FALSE;
                ::hyve::lang::observer_observable_h->id = 0;
                if (::hyve::define(::hyve::lang::observer_observable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::observable'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::observing */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_observing_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer_observing_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                ::hyve::lang::observer_observing_h->modifiers = 0x3;
                ::hyve::lang::observer_observing_h->state = 0x6;
                ::hyve::lang::observer_observing_h->weak = FALSE;
                ::hyve::lang::observer_observing_h->id = 6;
                if (::hyve::define(::hyve::lang::observer_observing_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::observing'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_setDispatcher_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::observer_setDispatcher_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::observer_setDispatcher_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::observer_setDispatcher_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::observer_setDispatcher_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::observer_setDispatcher_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_observer_setDispatcher);
                if (::hyve::define(::hyve::lang::observer_setDispatcher_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::silence(lang::object me) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer_silence_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::observer_silence_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::observer_silence_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::observer_silence_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::observer_silence_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::observer_silence_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_observer_silence);
                if (::hyve::define(::hyve::lang::observer_silence_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::silence(lang::object me)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observer::template */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observer__template_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::observer__template_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::observer__template_h->modifiers = 0x0;
                ::hyve::lang::observer__template_h->state = 0x6;
                ::hyve::lang::observer__template_h->weak = FALSE;
                ::hyve::lang::observer__template_h->id = 3;
                if (::hyve::define(::hyve::lang::observer__template_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observer::template'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::observerSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::observerSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::observerSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::observer"));
                ((::hyve::lang::collection)::hyve::lang::observerSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::observerSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::observerSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::octet */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::octet_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::octet_h)->width = ::hyve::lang::WIDTH_8;
                if (::hyve::define(::hyve::lang::octet_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::octet'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::operatorKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ADD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ADD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ADD_h) = 1;
                if (::hyve::define(::hyve::lang::operatorKind_ADD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ADD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::AND */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_AND_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_AND_h) = 10;
                if (::hyve::define(::hyve::lang::operatorKind_AND_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::AND'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_h) = 0;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_ADD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_ADD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_ADD_h) = 12;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_ADD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_ADD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_AND */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_AND_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_AND_h) = 19;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_AND_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_AND'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_DIV */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_DIV_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_DIV_h) = 15;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_DIV_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_DIV'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_MOD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_MOD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_MOD_h) = 16;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_MOD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_MOD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_MUL */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_MUL_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_MUL_h) = 14;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_MUL_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_MUL'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_OR */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_OR_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_OR_h) = 18;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_OR_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_OR'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_SUB */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_SUB_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_SUB_h) = 13;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_SUB_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_SUB'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ASSIGN_XOR */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ASSIGN_XOR_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ASSIGN_XOR_h) = 17;
                if (::hyve::define(::hyve::lang::operatorKind_ASSIGN_XOR_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ASSIGN_XOR'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::BRACKET_CLOSE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_BRACKET_CLOSE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_BRACKET_CLOSE_h) = 37;
                if (::hyve::define(::hyve::lang::operatorKind_BRACKET_CLOSE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::BRACKET_CLOSE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::BRACKET_OPEN */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_BRACKET_OPEN_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_BRACKET_OPEN_h) = 36;
                if (::hyve::define(::hyve::lang::operatorKind_BRACKET_OPEN_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::BRACKET_OPEN'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COMMA */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COMMA_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COMMA_h) = 31;
                if (::hyve::define(::hyve::lang::operatorKind_COMMA_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COMMA'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_AND */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_AND_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_AND_h) = 21;
                if (::hyve::define(::hyve::lang::operatorKind_COND_AND_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_AND'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_EQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_EQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_EQ_h) = 23;
                if (::hyve::define(::hyve::lang::operatorKind_COND_EQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_EQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_GT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_GT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_GT_h) = 25;
                if (::hyve::define(::hyve::lang::operatorKind_COND_GT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_GT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_GTEQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_GTEQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_GTEQ_h) = 27;
                if (::hyve::define(::hyve::lang::operatorKind_COND_GTEQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_GTEQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_LT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_LT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_LT_h) = 26;
                if (::hyve::define(::hyve::lang::operatorKind_COND_LT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_LT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_LTEQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_LTEQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_LTEQ_h) = 28;
                if (::hyve::define(::hyve::lang::operatorKind_COND_LTEQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_LTEQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_NEQ */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_NEQ_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_NEQ_h) = 24;
                if (::hyve::define(::hyve::lang::operatorKind_COND_NEQ_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_NEQ'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_NOT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_NOT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_NOT_h) = 22;
                if (::hyve::define(::hyve::lang::operatorKind_COND_NOT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_NOT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::COND_OR */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_COND_OR_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_COND_OR_h) = 20;
                if (::hyve::define(::hyve::lang::operatorKind_COND_OR_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::COND_OR'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::DEC */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_DEC_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_DEC_h) = 7;
                if (::hyve::define(::hyve::lang::operatorKind_DEC_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::DEC'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::DIV */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_DIV_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_DIV_h) = 4;
                if (::hyve::define(::hyve::lang::operatorKind_DIV_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::DIV'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ELEMENT_CLOSE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ELEMENT_CLOSE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ELEMENT_CLOSE_h) = 35;
                if (::hyve::define(::hyve::lang::operatorKind_ELEMENT_CLOSE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ELEMENT_CLOSE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::ELEMENT_OPEN */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_ELEMENT_OPEN_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_ELEMENT_OPEN_h) = 34;
                if (::hyve::define(::hyve::lang::operatorKind_ELEMENT_OPEN_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::ELEMENT_OPEN'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::INC */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_INC_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_INC_h) = 6;
                if (::hyve::define(::hyve::lang::operatorKind_INC_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::INC'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::MEMBER_RESOLVE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_MEMBER_RESOLVE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_MEMBER_RESOLVE_h) = 33;
                if (::hyve::define(::hyve::lang::operatorKind_MEMBER_RESOLVE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::MEMBER_RESOLVE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::MOD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_MOD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_MOD_h) = 5;
                if (::hyve::define(::hyve::lang::operatorKind_MOD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::MOD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::MUL */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_MUL_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_MUL_h) = 3;
                if (::hyve::define(::hyve::lang::operatorKind_MUL_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::MUL'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::NOT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_NOT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_NOT_h) = 11;
                if (::hyve::define(::hyve::lang::operatorKind_NOT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::NOT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::OR */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_OR_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_OR_h) = 9;
                if (::hyve::define(::hyve::lang::operatorKind_OR_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::OR'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::REF */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_REF_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_REF_h) = 32;
                if (::hyve::define(::hyve::lang::operatorKind_REF_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::REF'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::SHIFT_LEFT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_SHIFT_LEFT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_SHIFT_LEFT_h) = 29;
                if (::hyve::define(::hyve::lang::operatorKind_SHIFT_LEFT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::SHIFT_LEFT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::SHIFT_RIGHT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_SHIFT_RIGHT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_SHIFT_RIGHT_h) = 30;
                if (::hyve::define(::hyve::lang::operatorKind_SHIFT_RIGHT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::SHIFT_RIGHT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::SUB */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_SUB_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_SUB_h) = 2;
                if (::hyve::define(::hyve::lang::operatorKind_SUB_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::SUB'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::operatorKind::XOR */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::operatorKind_XOR_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::operatorKind_XOR_h) = 8;
                if (::hyve::define(::hyve::lang::operatorKind_XOR_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::operatorKind::XOR'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::parameter */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::parameter_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::parameter_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::parameter_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::parameter_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::parameter_h)->base = NULL;
                ::hyve::lang::parameter_h->baseAccess = 0x1;
                if (::hyve::define(::hyve::lang::parameter_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::parameter'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::parameter::name */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::parameter_name_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::parameter_name_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                ::hyve::lang::parameter_name_h->modifiers = 0x0;
                ::hyve::lang::parameter_name_h->state = 0x6;
                ::hyve::lang::parameter_name_h->weak = FALSE;
                ::hyve::lang::parameter_name_h->id = 0;
                if (::hyve::define(::hyve::lang::parameter_name_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::parameter::name'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::parameter::passByReference */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::parameter_passByReference_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::parameter_passByReference_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::parameter_passByReference_h->modifiers = 0x0;
                ::hyve::lang::parameter_passByReference_h->state = 0x6;
                ::hyve::lang::parameter_passByReference_h->weak = FALSE;
                ::hyve::lang::parameter_passByReference_h->id = 2;
                if (::hyve::define(::hyve::lang::parameter_passByReference_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::parameter::passByReference'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::parameter::type */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::parameter_type_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::parameter_type_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::parameter_type_h->modifiers = 0x0;
                ::hyve::lang::parameter_type_h->state = 0x6;
                ::hyve::lang::parameter_type_h->weak = FALSE;
                ::hyve::lang::parameter_type_h->id = 1;
                if (::hyve::define(::hyve::lang::parameter_type_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::parameter::type'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::parameterSeq */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::parameterSeq_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::parameterSeq_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::parameter"));
                ((::hyve::lang::collection)::hyve::lang::parameterSeq_h)->max = 0;
                if (::hyve::define(::hyve::lang::parameterSeq_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::parameterSeq'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::primitive_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::primitive_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::primitive_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::primitive_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::type"));
                ((::hyve::lang::_struct)::hyve::lang::primitive_h)->baseAccess = 0x5;
                ::hyve::lang::primitive_h->implements.length = 0;
                ::hyve::lang::primitive_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::primitive_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::castable(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_castable_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::primitive_castable_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::primitive_castable_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::primitive_castable_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::primitive_castable_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::primitive_castable_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_primitive_castable);
                if (::hyve::define(::hyve::lang::primitive_castable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::castable(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::compatible(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_compatible_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::primitive_compatible_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::primitive_compatible_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::primitive_compatible_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::primitive_compatible_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::primitive_compatible_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_primitive_compatible);
                if (::hyve::define(::hyve::lang::primitive_compatible_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::compatible(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::construct(lang::primitive object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::primitive_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::primitive_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::primitive_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::primitive_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::primitive_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::primitive_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::construct(lang::primitive object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::convertId */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_convertId_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::primitive_convertId_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint8"));
                ::hyve::lang::primitive_convertId_h->modifiers = 0x3;
                ::hyve::lang::primitive_convertId_h->state = 0x6;
                ::hyve::lang::primitive_convertId_h->weak = FALSE;
                ::hyve::lang::primitive_convertId_h->id = 2;
                if (::hyve::define(::hyve::lang::primitive_convertId_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::convertId'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::init(lang::primitive object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::primitive_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::primitive_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::primitive_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::primitive_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::primitive_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::primitive_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::init(lang::primitive object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::primitive_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::primitiveKind"));
                ::hyve::lang::primitive_kind_h->modifiers = 0x5;
                ::hyve::lang::primitive_kind_h->state = 0x6;
                ::hyve::lang::primitive_kind_h->weak = FALSE;
                ::hyve::lang::primitive_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::primitive_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitive::width */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitive_width_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::primitive_width_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::width"));
                ::hyve::lang::primitive_width_h->modifiers = 0x0;
                ::hyve::lang::primitive_width_h->state = 0x6;
                ::hyve::lang::primitive_width_h->weak = FALSE;
                ::hyve::lang::primitive_width_h->id = 1;
                if (::hyve::define(::hyve::lang::primitive_width_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitive::width'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::primitiveKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::ALIAS */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_ALIAS_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_ALIAS_h) = 9;
                if (::hyve::define(::hyve::lang::primitiveKind_ALIAS_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::ALIAS'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::BINARY */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_BINARY_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_BINARY_h) = 0;
                if (::hyve::define(::hyve::lang::primitiveKind_BINARY_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::BINARY'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::BITMASK */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_BITMASK_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_BITMASK_h) = 8;
                if (::hyve::define(::hyve::lang::primitiveKind_BITMASK_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::BITMASK'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::BOOLEAN */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_BOOLEAN_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_BOOLEAN_h) = 1;
                if (::hyve::define(::hyve::lang::primitiveKind_BOOLEAN_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::BOOLEAN'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::CHARACTER */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_CHARACTER_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_CHARACTER_h) = 2;
                if (::hyve::define(::hyve::lang::primitiveKind_CHARACTER_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::CHARACTER'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::ENUM */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_ENUM_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_ENUM_h) = 7;
                if (::hyve::define(::hyve::lang::primitiveKind_ENUM_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::ENUM'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::FLOAT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_FLOAT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_FLOAT_h) = 5;
                if (::hyve::define(::hyve::lang::primitiveKind_FLOAT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::FLOAT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::INTEGER */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_INTEGER_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_INTEGER_h) = 3;
                if (::hyve::define(::hyve::lang::primitiveKind_INTEGER_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::INTEGER'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::TEXT */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_TEXT_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_TEXT_h) = 6;
                if (::hyve::define(::hyve::lang::primitiveKind_TEXT_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::TEXT'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::primitiveKind::UINTEGER */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::primitiveKind_UINTEGER_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::primitiveKind_UINTEGER_h) = 4;
                if (::hyve::define(::hyve::lang::primitiveKind_UINTEGER_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::primitiveKind::UINTEGER'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedure */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedure_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::procedure_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::procedure_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::procedure_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::procedure_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::struct"));
                ((::hyve::lang::_struct)::hyve::lang::procedure_h)->baseAccess = 0x5;
                ::hyve::lang::procedure_h->implements.length = 0;
                ::hyve::lang::procedure_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::procedure_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedure'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedure::bind(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedure_bind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::procedure_bind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                
                /* Bind ::hyve::lang::procedure_bind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::procedure_bind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::procedure_bind_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_procedure_bind);
                if (::hyve::define(::hyve::lang::procedure_bind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedure::bind(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedure::init(lang::procedure object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedure_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::procedure_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::procedure_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::procedure_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::procedure_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::procedure_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::procedure_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedure::init(lang::procedure object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedure::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedure_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::procedure_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::procedureKind"));
                ::hyve::lang::procedure_kind_h->modifiers = 0x0;
                ::hyve::lang::procedure_kind_h->state = 0x6;
                ::hyve::lang::procedure_kind_h->weak = FALSE;
                ::hyve::lang::procedure_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::procedure_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedure::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedure::unbind(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedure_unbind_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::procedure_unbind_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                
                /* Bind ::hyve::lang::procedure_unbind_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::procedure_unbind_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::procedure_unbind_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_procedure_unbind);
                if (::hyve::define(::hyve::lang::procedure_unbind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedure::unbind(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::procedureKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::CALLBACK */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_CALLBACK_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_CALLBACK_h) = 3;
                if (::hyve::define(::hyve::lang::procedureKind_CALLBACK_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::CALLBACK'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::DELEGATE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_DELEGATE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_DELEGATE_h) = 2;
                if (::hyve::define(::hyve::lang::procedureKind_DELEGATE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::DELEGATE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::FUNCTION */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_FUNCTION_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_FUNCTION_h) = 0;
                if (::hyve::define(::hyve::lang::procedureKind_FUNCTION_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::FUNCTION'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::METAPROCEDURE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_METAPROCEDURE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_METAPROCEDURE_h) = 5;
                if (::hyve::define(::hyve::lang::procedureKind_METAPROCEDURE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::METAPROCEDURE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::METHOD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_METHOD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_METHOD_h) = 1;
                if (::hyve::define(::hyve::lang::procedureKind_METHOD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::METHOD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::procedureKind::OBSERVER */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::procedureKind_OBSERVER_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::procedureKind_OBSERVER_h) = 4;
                if (::hyve::define(::hyve::lang::procedureKind_OBSERVER_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::procedureKind::OBSERVER'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::sequence */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::sequence_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::sequence_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::sequence_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::sequence_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::sequence_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::collection"));
                ((::hyve::lang::_struct)::hyve::lang::sequence_h)->baseAccess = 0x0;
                ::hyve::lang::sequence_h->implements.length = 0;
                ::hyve::lang::sequence_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::sequence_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::sequence'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::sequence::construct(lang::sequence object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::sequence_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::sequence_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::sequence_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::sequence_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::sequence_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::sequence_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::sequence_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::sequence::construct(lang::sequence object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::sequence::init(lang::sequence object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::sequence_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::sequence_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::sequence_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::sequence_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::sequence_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::sequence_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::sequence_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::sequence::init(lang::sequence object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::sequence::size(lang::uint32 size) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::sequence_size_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::sequence_size_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                if (::hyve::define(::hyve::lang::sequence_size_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::sequence::size(lang::uint32 size)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::state */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::state_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::state_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::state'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::state::DECLARED */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::state_DECLARED_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::state_DECLARED_h) = 2;
                if (::hyve::define(::hyve::lang::state_DECLARED_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::state::DECLARED'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::state::DEFINED */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::state_DEFINED_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::state_DEFINED_h) = 4;
                if (::hyve::define(::hyve::lang::state_DEFINED_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::state::DEFINED'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::state::VALID */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::state_VALID_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::state_VALID_h) = 1;
                if (::hyve::define(::hyve::lang::state_VALID_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::state::VALID'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::string */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::string_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::string_h->charWidth = ::hyve::lang::WIDTH_8;
                ::hyve::lang::string_h->length = 0ULL;
                if (::hyve::define(::hyve::lang::string_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::string'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_struct_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_struct_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_struct_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_struct_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::interface"));
                ((::hyve::lang::_struct)::hyve::lang::_struct_h)->baseAccess = 0x0;
                ::hyve::lang::_struct_h->implements.length = 0;
                ::hyve::lang::_struct_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_struct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::baseAccess */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_baseAccess_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_struct_baseAccess_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::modifier"));
                ::hyve::lang::_struct_baseAccess_h->modifiers = 0x0;
                ::hyve::lang::_struct_baseAccess_h->state = 0x6;
                ::hyve::lang::_struct_baseAccess_h->weak = FALSE;
                ::hyve::lang::_struct_baseAccess_h->id = 0;
                if (::hyve::define(::hyve::lang::_struct_baseAccess_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::baseAccess'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::castable(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_castable_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_struct_castable_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::_struct_castable_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::_struct_castable_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_struct_castable_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_struct_castable_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__struct_castable);
                if (::hyve::define(::hyve::lang::_struct_castable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::castable(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::compatible(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_compatible_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_struct_compatible_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::_struct_compatible_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::_struct_compatible_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_struct_compatible_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_struct_compatible_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__struct_compatible);
                if (::hyve::define(::hyve::lang::_struct_compatible_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::compatible(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::construct(lang::struct object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_struct_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_struct_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::_struct_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_struct_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_struct_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_struct_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::construct(lang::struct object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::delegateCount */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_delegateCount_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_struct_delegateCount_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint16"));
                ::hyve::lang::_struct_delegateCount_h->modifiers = 0x3;
                ::hyve::lang::_struct_delegateCount_h->state = 0x6;
                ::hyve::lang::_struct_delegateCount_h->weak = FALSE;
                ::hyve::lang::_struct_delegateCount_h->id = 1;
                if (::hyve::define(::hyve::lang::_struct_delegateCount_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::delegateCount'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::init(lang::struct object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_struct_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_struct_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_struct_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_struct_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_struct_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_struct_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::init(lang::struct object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::struct::resolveMember(lang::string name) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_struct_resolveMember_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_struct_resolveMember_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ::hyve::lang::_struct_resolveMember_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::_struct_resolveMember_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_struct_resolveMember_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_struct_resolveMember_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__struct_resolveMember);
                if (::hyve::define(::hyve::lang::_struct_resolveMember_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::struct::resolveMember(lang::string name)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::text */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::text_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::text_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::text_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::text_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::text_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::text_h)->baseAccess = 0x1;
                ::hyve::lang::text_h->implements.length = 0;
                ::hyve::lang::text_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::text_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::text'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::text::charWidth */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::text_charWidth_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::text_charWidth_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::width"));
                ::hyve::lang::text_charWidth_h->modifiers = 0x0;
                ::hyve::lang::text_charWidth_h->state = 0x6;
                ::hyve::lang::text_charWidth_h->weak = FALSE;
                ::hyve::lang::text_charWidth_h->id = 0;
                if (::hyve::define(::hyve::lang::text_charWidth_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::text::charWidth'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::text::init(lang::text object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::text_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::text_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::text_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::text_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::text_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::text_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::text_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::text::init(lang::text object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::text::length */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::text_length_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::text_length_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint64"));
                ::hyve::lang::text_length_h->modifiers = 0x0;
                ::hyve::lang::text_length_h->state = 0x6;
                ::hyve::lang::text_length_h->weak = FALSE;
                ::hyve::lang::text_length_h->id = 1;
                if (::hyve::define(::hyve::lang::text_length_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::text::length'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::type_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::type_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::type_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::type_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ((::hyve::lang::_struct)::hyve::lang::type_h)->baseAccess = 0x5;
                ::hyve::lang::type_h->implements.length = 0;
                ::hyve::lang::type_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::type_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::_init(lang::type object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type__init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type__init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::type__init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::type__init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type__init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type__init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::type__init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::_init(lang::type object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::alignment */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_alignment_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_alignment_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint16"));
                ::hyve::lang::type_alignment_h->modifiers = 0x3;
                ::hyve::lang::type_alignment_h->state = 0x6;
                ::hyve::lang::type_alignment_h->weak = FALSE;
                ::hyve::lang::type_alignment_h->id = 5;
                if (::hyve::define(::hyve::lang::type_alignment_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::alignment'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::alignmentof() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_alignmentof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_alignmentof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint16"));
                ::hyve::lang::type_alignmentof_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::type_alignmentof_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_alignmentof_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_alignmentof_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_alignmentof);
                if (::hyve::define(::hyve::lang::type_alignmentof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::alignmentof()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::allocSize() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_allocSize_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_allocSize_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::type_allocSize_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::type_allocSize_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_allocSize_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_allocSize_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_allocSize);
                if (::hyve::define(::hyve::lang::type_allocSize_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::allocSize()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::castable(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_castable_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_castable_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::type_castable_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::type_castable_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_castable_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_castable_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_castable);
                if (::hyve::define(::hyve::lang::type_castable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::castable(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::compare(lang::any value) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_compare_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_compare_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::equalityKind"));
                if (::hyve::define(::hyve::lang::type_compare_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::compare(lang::any value)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::compatible(lang::type type) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_compatible_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_compatible_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::type_compatible_h->_virtual = TRUE;
                
                /* Bind ::hyve::lang::type_compatible_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_compatible_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_compatible_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_compatible);
                if (::hyve::define(::hyve::lang::type_compatible_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::compatible(lang::type type)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::construct(lang::type object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::type_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::type_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::type_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::construct(lang::type object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::copy(lang::any value) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_copy_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_copy_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                if (::hyve::define(::hyve::lang::type_copy_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::copy(lang::any value)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::defaultType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_defaultType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_defaultType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::type_defaultType_h->modifiers = 0x0;
                ::hyve::lang::type_defaultType_h->state = 0x4;
                ::hyve::lang::type_defaultType_h->weak = FALSE;
                ::hyve::lang::type_defaultType_h->id = 6;
                if (::hyve::define(::hyve::lang::type_defaultType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::defaultType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::destruct(lang::type object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::type_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::type_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::type_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::destruct(lang::type object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::fullname() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_fullname_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_fullname_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                if (::hyve::define(::hyve::lang::type_fullname_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::fullname()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::hasResources */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_hasResources_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_hasResources_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::type_hasResources_h->modifiers = 0x5;
                ::hyve::lang::type_hasResources_h->state = 0x6;
                ::hyve::lang::type_hasResources_h->weak = FALSE;
                ::hyve::lang::type_hasResources_h->id = 2;
                if (::hyve::define(::hyve::lang::type_hasResources_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::hasResources'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::init(lang::object object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                
                /* Bind ::hyve::lang::type_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_init_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_init);
                if (::hyve::define(::hyve::lang::type_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::init(lang::object object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::kind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_kind_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_kind_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typeKind"));
                ::hyve::lang::type_kind_h->modifiers = 0x5;
                ::hyve::lang::type_kind_h->state = 0x6;
                ::hyve::lang::type_kind_h->weak = FALSE;
                ::hyve::lang::type_kind_h->id = 0;
                if (::hyve::define(::hyve::lang::type_kind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::kind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::metaprocedures */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_metaprocedures_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_metaprocedures_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::vtable"));
                ::hyve::lang::type_metaprocedures_h->modifiers = 0x3;
                ::hyve::lang::type_metaprocedures_h->state = 0x6;
                ::hyve::lang::type_metaprocedures_h->weak = FALSE;
                ::hyve::lang::type_metaprocedures_h->id = 9;
                if (::hyve::define(::hyve::lang::type_metaprocedures_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::metaprocedures'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::nameof() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_nameof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_nameof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                if (::hyve::define(::hyve::lang::type_nameof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::nameof()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::parentof() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_parentof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_parentof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::object"));
                if (::hyve::define(::hyve::lang::type_parentof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::parentof()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::parentState */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_parentState_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_parentState_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::state"));
                ::hyve::lang::type_parentState_h->modifiers = 0x0;
                ::hyve::lang::type_parentState_h->state = 0x6;
                ::hyve::lang::type_parentState_h->weak = FALSE;
                ::hyve::lang::type_parentState_h->id = 8;
                if (::hyve::define(::hyve::lang::type_parentState_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::parentState'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::parentType */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_parentType_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_parentType_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::type_parentType_h->modifiers = 0x0;
                ::hyve::lang::type_parentType_h->state = 0x4;
                ::hyve::lang::type_parentType_h->weak = FALSE;
                ::hyve::lang::type_parentType_h->id = 7;
                if (::hyve::define(::hyve::lang::type_parentType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::parentType'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::reference */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_reference_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_reference_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::bool"));
                ::hyve::lang::type_reference_h->modifiers = 0x5;
                ::hyve::lang::type_reference_h->state = 0x6;
                ::hyve::lang::type_reference_h->weak = FALSE;
                ::hyve::lang::type_reference_h->id = 1;
                if (::hyve::define(::hyve::lang::type_reference_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::reference'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::relname(lang::object from) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_relname_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_relname_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                if (::hyve::define(::hyve::lang::type_relname_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::relname(lang::object from)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::resolveProcedure(lang::string name) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_resolveProcedure_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_resolveProcedure_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::function"));
                ::hyve::lang::type_resolveProcedure_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::type_resolveProcedure_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type_resolveProcedure_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type_resolveProcedure_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type_resolveProcedure);
                if (::hyve::define(::hyve::lang::type_resolveProcedure_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::resolveProcedure(lang::string name)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::size */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_size_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_size_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::type_size_h->modifiers = 0x3;
                ::hyve::lang::type_size_h->state = 0x6;
                ::hyve::lang::type_size_h->weak = FALSE;
                ::hyve::lang::type_size_h->id = 4;
                if (::hyve::define(::hyve::lang::type_size_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::size'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::sizeof() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type__sizeof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type__sizeof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::type__sizeof_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::type__sizeof_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::type__sizeof_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::type__sizeof_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp_type__sizeof);
                if (::hyve::define(::hyve::lang::type__sizeof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::sizeof()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::templateId */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_templateId_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::type_templateId_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint32"));
                ::hyve::lang::type_templateId_h->modifiers = 0x5;
                ::hyve::lang::type_templateId_h->state = 0x6;
                ::hyve::lang::type_templateId_h->weak = FALSE;
                ::hyve::lang::type_templateId_h->id = 3;
                if (::hyve::define(::hyve::lang::type_templateId_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::templateId'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::toString() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_toString_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_toString_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::string"));
                if (::hyve::define(::hyve::lang::type_toString_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::toString()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::type::typeof() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::type_typeof_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::type_typeof_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::type"));
                if (::hyve::define(::hyve::lang::type_typeof_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::type::typeof()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::_typedef_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::_typedef_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::_typedef_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::_typedef_h)->base = NULL;
                ((::hyve::lang::_struct)::hyve::lang::_typedef_h)->baseAccess = 0x1;
                ::hyve::lang::_typedef_h->implements.length = 0;
                ::hyve::lang::_typedef_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::_typedef_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::construct(lang::typedef object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_construct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_typedef_construct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_typedef_construct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::construct(lang::object object)"));
                
                /* Bind ::hyve::lang::_typedef_construct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_typedef_construct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_typedef_construct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_typedef_construct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::construct(lang::typedef object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::destruct(lang::typedef object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_destruct_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_typedef_destruct_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::void"));
                ::hyve::lang::_typedef_destruct_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::class::destruct(lang::object object)"));
                
                /* Bind ::hyve::lang::_typedef_destruct_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_typedef_destruct_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_typedef_destruct_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_typedef_destruct_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::destruct(lang::typedef object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::init(lang::typedef object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_typedef_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_typedef_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_typedef_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_typedef_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_typedef_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_typedef_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::init(lang::typedef object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::real */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_real_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_typedef_real_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::type"));
                ::hyve::lang::_typedef_real_h->modifiers = 0x1;
                ::hyve::lang::_typedef_real_h->state = 0x4;
                ::hyve::lang::_typedef_real_h->weak = FALSE;
                ::hyve::lang::_typedef_real_h->id = 1;
                if (::hyve::define(::hyve::lang::_typedef_real_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::real'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::realType() */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_realType_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_typedef_realType_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::type"));
                ::hyve::lang::_typedef_realType_h->_virtual = FALSE;
                
                /* Bind ::hyve::lang::_typedef_realType_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_typedef_realType_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_typedef_realType_h)->impl = reinterpret_cast< ::hyve::lang::word>(__cpp__typedef_realType);
                if (::hyve::define(::hyve::lang::_typedef_realType_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::realType()'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typedef::type */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_typedef_type_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_typedef_type_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::typedef"));
                ::hyve::lang::_typedef_type_h->modifiers = 0x0;
                ::hyve::lang::_typedef_type_h->state = 0x4;
                ::hyve::lang::_typedef_type_h->weak = FALSE;
                ::hyve::lang::_typedef_type_h->id = 0;
                if (::hyve::define(::hyve::lang::_typedef_type_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typedef::type'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::typeKind_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind::ANY */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_ANY_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::typeKind_ANY_h) = 1;
                if (::hyve::define(::hyve::lang::typeKind_ANY_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind::ANY'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind::COLLECTION */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_COLLECTION_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::typeKind_COLLECTION_h) = 4;
                if (::hyve::define(::hyve::lang::typeKind_COLLECTION_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind::COLLECTION'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind::COMPOSITE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_COMPOSITE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::typeKind_COMPOSITE_h) = 3;
                if (::hyve::define(::hyve::lang::typeKind_COMPOSITE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind::COMPOSITE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind::PRIMITIVE */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_PRIMITIVE_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::typeKind_PRIMITIVE_h) = 2;
                if (::hyve::define(::hyve::lang::typeKind_PRIMITIVE_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind::PRIMITIVE'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::typeKind::VOID */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::typeKind_VOID_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::typeKind_VOID_h) = 0;
                if (::hyve::define(::hyve::lang::typeKind_VOID_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::typeKind::VOID'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::type)::hyve::lang::uint_h)->defaultType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::member"));
                ((::hyve::lang::type)::hyve::lang::uint_h)->parentType = NULL;
                ((::hyve::lang::type)::hyve::lang::uint_h)->parentState = 0x6;
                ((::hyve::lang::interface)::hyve::lang::uint_h)->base = ((::hyve::lang::interface)::hyve::resolve(NULL, "::hyve::lang::primitive"));
                ((::hyve::lang::_struct)::hyve::lang::uint_h)->baseAccess = 0x0;
                ::hyve::lang::uint_h->implements.length = 0;
                ::hyve::lang::uint_h->implements.buffer = NULL;
                if (::hyve::define(::hyve::lang::uint_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint::init(lang::uint object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::uint_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::uint_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::uint_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::uint_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::uint_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::uint_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint::init(lang::uint object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint::max */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint_max_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::uint_max_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint64"));
                ::hyve::lang::uint_max_h->modifiers = 0x0;
                ::hyve::lang::uint_max_h->state = 0x6;
                ::hyve::lang::uint_max_h->weak = FALSE;
                ::hyve::lang::uint_max_h->id = 1;
                if (::hyve::define(::hyve::lang::uint_max_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint::max'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint::min */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint_min_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::uint_min_h->type = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::uint64"));
                ::hyve::lang::uint_min_h->modifiers = 0x0;
                ::hyve::lang::uint_min_h->state = 0x6;
                ::hyve::lang::uint_min_h->weak = FALSE;
                ::hyve::lang::uint_min_h->id = 0;
                if (::hyve::define(::hyve::lang::uint_min_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint::min'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint16 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint16_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::uint16_h)->width = ::hyve::lang::WIDTH_16;
                ::hyve::lang::uint16_h->min = 0ULL;
                ::hyve::lang::uint16_h->max = 18446744073709551615ULL;
                if (::hyve::define(::hyve::lang::uint16_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint16'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint32 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint32_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::uint32_h)->width = ::hyve::lang::WIDTH_32;
                ::hyve::lang::uint32_h->min = 0ULL;
                ::hyve::lang::uint32_h->max = 18446744073709551615ULL;
                if (::hyve::define(::hyve::lang::uint32_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint32'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint64 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint64_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::uint64_h)->width = ::hyve::lang::WIDTH_64;
                ::hyve::lang::uint64_h->min = 0ULL;
                ::hyve::lang::uint64_h->max = 18446744073709551615ULL;
                if (::hyve::define(::hyve::lang::uint64_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint64'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::uint8 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::uint8_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::uint8_h)->width = ::hyve::lang::WIDTH_8;
                ::hyve::lang::uint8_h->min = 0ULL;
                ::hyve::lang::uint8_h->max = 18446744073709551615ULL;
                if (::hyve::define(::hyve::lang::uint8_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::uint8'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::virtual */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_virtual_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_virtual_h->kind = ::hyve::lang::METHOD;
                if (::hyve::define(::hyve::lang::_virtual_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::virtual'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::virtual::init(lang::virtual object) */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_virtual_init_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::function)::hyve::lang::_virtual_init_h)->returnType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::int16"));
                ::hyve::lang::_virtual_init_h->delegate = ((::hyve::lang::delegate)::hyve::resolve(NULL, "::hyve::lang::type::init(lang::object object)"));
                
                /* Bind ::hyve::lang::_virtual_init_h with C++ function */
                ((::hyve::lang::function)::hyve::lang::_virtual_init_h)->kind = DB_PROCEDURE_CDECL;
                ((::hyve::lang::function)::hyve::lang::_virtual_init_h)->impl = 0;
                if (::hyve::define(::hyve::lang::_virtual_init_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::virtual::init(lang::virtual object)'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::void */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::_void_h, ::hyve::lang::DEFINED)) {
                ::hyve::lang::_void_h->defaultType = NULL;
                ::hyve::lang::_void_h->parentType = NULL;
                ::hyve::lang::_void_h->parentState = 0x6;
                if (::hyve::define(::hyve::lang::_void_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::void'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::vtable */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::vtable_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::collection)::hyve::lang::vtable_h)->elementType = ((::hyve::lang::_typedef)::hyve::resolve(NULL, "::hyve::lang::function"));
                ((::hyve::lang::collection)::hyve::lang::vtable_h)->max = 0;
                if (::hyve::define(::hyve::lang::vtable_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::vtable'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_h, ::hyve::lang::DEFINED)) {
                if (::hyve::define(::hyve::lang::width_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width::WIDTH_16 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_WIDTH_16_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::width_WIDTH_16_h) = 1;
                if (::hyve::define(::hyve::lang::width_WIDTH_16_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width::WIDTH_16'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width::WIDTH_32 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_WIDTH_32_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::width_WIDTH_32_h) = 2;
                if (::hyve::define(::hyve::lang::width_WIDTH_32_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width::WIDTH_32'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width::WIDTH_64 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_WIDTH_64_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::width_WIDTH_64_h) = 3;
                if (::hyve::define(::hyve::lang::width_WIDTH_64_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width::WIDTH_64'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width::WIDTH_8 */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_WIDTH_8_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::width_WIDTH_8_h) = 0;
                if (::hyve::define(::hyve::lang::width_WIDTH_8_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width::WIDTH_8'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::width::WIDTH_WORD */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::width_WIDTH_WORD_h, ::hyve::lang::DEFINED)) {
                (*::hyve::lang::width_WIDTH_WORD_h) = 4;
                if (::hyve::define(::hyve::lang::width_WIDTH_WORD_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::width::WIDTH_WORD'.");
                    goto error;
                }
            }
            /* Define ::hyve::lang::word */
            if (!::hyve::checkState((::hyve::lang::object)::hyve::lang::word_h, ::hyve::lang::DEFINED)) {
                ((::hyve::lang::primitive)::hyve::lang::word_h)->width = ::hyve::lang::WIDTH_WORD;
                if (::hyve::define(::hyve::lang::word_h)) {
                    ::hyve::error("lang_load: failed to define object '::hyve::lang::word'.");
                    goto error;
                }
            }
            ::hyve::lang::alias_o = new ::hyve::lang::Class(::hyve::lang::alias_h);
            ::hyve::lang::array_o = new ::hyve::lang::Class(::hyve::lang::array_h);
            ::hyve::lang::binary_o = new ::hyve::lang::Class(::hyve::lang::binary_h);
            ::hyve::lang::bitmask_o = new ::hyve::lang::Class(::hyve::lang::bitmask_h);
            ::hyve::lang::boolean_o = new ::hyve::lang::Class(::hyve::lang::boolean_h);
            ::hyve::lang::callback_o = new ::hyve::lang::Procedure(::hyve::lang::callback_h);
            ::hyve::lang::character_o = new ::hyve::lang::Class(::hyve::lang::character_h);
            ::hyve::lang::_class_o = new ::hyve::lang::Class(::hyve::lang::_class_h);
            ::hyve::lang::collection_o = new ::hyve::lang::Class(::hyve::lang::collection_h);
            ::hyve::lang::delegate_o = new ::hyve::lang::Procedure(::hyve::lang::delegate_h);
            ::hyve::lang::dispatcher_o = new ::hyve::lang::Interface(::hyve::lang::dispatcher_h);
            ::hyve::lang::_enum_o = new ::hyve::lang::Class(::hyve::lang::_enum_h);
            ::hyve::lang::event_o = new ::hyve::lang::Class(::hyve::lang::event_h);
            ::hyve::lang::_float_o = new ::hyve::lang::Class(::hyve::lang::_float_h);
            ::hyve::lang::function_o = new ::hyve::lang::Procedure(::hyve::lang::function_h);
            ::hyve::lang::_int_o = new ::hyve::lang::Class(::hyve::lang::_int_h);
            ::hyve::lang::interface_o = new ::hyve::lang::Class(::hyve::lang::interface_h);
            ::hyve::lang::list_o = new ::hyve::lang::Class(::hyve::lang::list_h);
            ::hyve::lang::map_o = new ::hyve::lang::Class(::hyve::lang::map_h);
            ::hyve::lang::member_o = new ::hyve::lang::Class(::hyve::lang::member_h);
            ::hyve::lang::metaprocedure_o = new ::hyve::lang::Procedure(::hyve::lang::metaprocedure_h);
            ::hyve::lang::method_o = new ::hyve::lang::Procedure(::hyve::lang::method_h);
            ::hyve::lang::observableEvent_o = new ::hyve::lang::Class(::hyve::lang::observableEvent_h);
            ::hyve::lang::observer_o = new ::hyve::lang::Procedure(::hyve::lang::observer_h);
            ::hyve::lang::primitive_o = new ::hyve::lang::Class(::hyve::lang::primitive_h);
            ::hyve::lang::procedure_o = new ::hyve::lang::Class(::hyve::lang::procedure_h);
            ::hyve::lang::sequence_o = new ::hyve::lang::Class(::hyve::lang::sequence_h);
            ::hyve::lang::_struct_o = new ::hyve::lang::Class(::hyve::lang::_struct_h);
            ::hyve::lang::text_o = new ::hyve::lang::Class(::hyve::lang::text_h);
            ::hyve::lang::type_o = new ::hyve::lang::Class(::hyve::lang::type_h);
            ::hyve::lang::_typedef_o = new ::hyve::lang::Class(::hyve::lang::_typedef_h);
            ::hyve::lang::uint_o = new ::hyve::lang::Class(::hyve::lang::uint_h);
            ::hyve::lang::_virtual_o = new ::hyve::lang::Procedure(::hyve::lang::_virtual_h);
            hyve::onunload(unload, NULL);
            if (_a_) {
                ::hyve::free(NULL, _a_, "load: free temporary reference.");
            }

            return 0;
        error:
            return -1;
        }
    }
}
