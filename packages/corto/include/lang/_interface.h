/* _interface.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_INTERFACE_H
#define CORTO_LANG_INTERFACE_H

#include <corto/_project.h>

#ifdef __cplusplus
extern "C" {
#endif


#define corto_alias_construct(_this) _corto_alias_construct(corto_alias(_this))
CORTO_EXPORT
corto_int16 _corto_alias_construct(
    corto_alias _this);

#define corto_alias_init(_this) _corto_alias_init(corto_alias(_this))
CORTO_EXPORT
corto_int16 _corto_alias_init(
    corto_alias _this);

#define corto_array_construct(_this) _corto_array_construct(corto_array(_this))
CORTO_EXPORT
corto_int16 _corto_array_construct(
    corto_array _this);

#define corto_array_destruct(_this) _corto_array_destruct(corto_array(_this))
CORTO_EXPORT
corto_void _corto_array_destruct(
    corto_array _this);

#define corto_array_init(_this) _corto_array_init(corto_array(_this))
CORTO_EXPORT
corto_int16 _corto_array_init(
    corto_array _this);

#define corto_binary_init(_this) _corto_binary_init(corto_binary(_this))
CORTO_EXPORT
corto_int16 _corto_binary_init(
    corto_binary _this);

#define corto_bitmask_init(_this) _corto_bitmask_init(corto_bitmask(_this))
CORTO_EXPORT
corto_int16 _corto_bitmask_init(
    corto_bitmask _this);

#define corto_boolean_init(_this) _corto_boolean_init(corto_boolean(_this))
CORTO_EXPORT
corto_int16 _corto_boolean_init(
    corto_boolean _this);

#define corto_case_construct(_this) _corto_case_construct(corto_case(_this))
CORTO_EXPORT
corto_int16 _corto_case_construct(
    corto_case _this);

#define corto_character_init(_this) _corto_character_init(corto_character(_this))
CORTO_EXPORT
corto_int16 _corto_character_init(
    corto_character _this);

#define corto_class_construct(_this) _corto_class_construct(corto_class(_this))
CORTO_EXPORT
corto_int16 _corto_class_construct(
    corto_class _this);

#define corto_class_destruct(_this) _corto_class_destruct(corto_class(_this))
CORTO_EXPORT
corto_void _corto_class_destruct(
    corto_class _this);

#define corto_class_init(_this) _corto_class_init(corto_class(_this))
CORTO_EXPORT
corto_int16 _corto_class_init(
    corto_class _this);

#define corto_class_instanceof(_this, object) _corto_class_instanceof(corto_class(_this), object)
CORTO_EXPORT
corto_bool _corto_class_instanceof(
    corto_class _this,
    corto_object object);

#define corto_class_resolveInterfaceMethod(_this, interface, method) _corto_class_resolveInterfaceMethod(corto_class(_this), corto_interface(interface), method)
CORTO_EXPORT
corto_method _corto_class_resolveInterfaceMethod(
    corto_class _this,
    corto_interface interface,
    corto_uint32 method);

#define corto_collection_castable_v(_this, type) _corto_collection_castable_v(corto_collection(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_collection_castable_v(
    corto_collection _this,
    corto_type type);

#define corto_collection_castable(_this, type) _corto_collection_castable(corto_collection(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_collection_castable(
    corto_collection _this,
    corto_type type);

#define corto_collection_compatible_v(_this, type) _corto_collection_compatible_v(corto_collection(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_collection_compatible_v(
    corto_collection _this,
    corto_type type);

#define corto_collection_compatible(_this, type) _corto_collection_compatible(corto_collection(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_collection_compatible(
    corto_collection _this,
    corto_type type);

#define corto_collection_init(_this) _corto_collection_init(corto_collection(_this))
CORTO_EXPORT
corto_int16 _corto_collection_init(
    corto_collection _this);

#define corto_collection_requiresAlloc(elementType) _corto_collection_requiresAlloc(corto_type(elementType))
CORTO_EXPORT
corto_bool _corto_collection_requiresAlloc(
    corto_type elementType);

#define corto_constant_init(_this) _corto_constant_init(_this)
CORTO_EXPORT
corto_int16 _corto_constant_init(
    corto_constant* _this);

#define corto_default_construct(_this) _corto_default_construct(corto_default(_this))
CORTO_EXPORT
corto_int16 _corto_default_construct(
    corto_default _this);

#define corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_delegate_castable_v(
    corto_delegate _this,
    corto_type type);

#define corto_delegate_castable(_this, type) _corto_delegate_castable(corto_delegate(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_delegate_castable(
    corto_delegate _this,
    corto_type type);

#define corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_delegate_compatible_v(
    corto_delegate _this,
    corto_type type);

#define corto_delegate_compatible(_this, type) _corto_delegate_compatible(corto_delegate(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_delegate_compatible(
    corto_delegate _this,
    corto_type type);

#define corto_delegate_construct(object) _corto_delegate_construct(corto_function(object))
CORTO_EXPORT
corto_int16 _corto_delegate_construct(
    corto_function object);

#define corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))
CORTO_EXPORT
corto_int16 _corto_delegate_init(
    corto_delegate _this);

#define corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)
CORTO_EXPORT
corto_bool _corto_delegate_instanceof(
    corto_delegate _this,
    corto_object object);

#define corto_enum_constant(_this, value) _corto_enum_constant(corto_enum(_this), value)
CORTO_EXPORT
corto_object _corto_enum_constant(
    corto_enum _this,
    corto_int32 value);

#define corto_enum_construct(_this) _corto_enum_construct(corto_enum(_this))
CORTO_EXPORT
corto_int16 _corto_enum_construct(
    corto_enum _this);

#define corto_enum_destruct(_this) _corto_enum_destruct(corto_enum(_this))
CORTO_EXPORT
corto_void _corto_enum_destruct(
    corto_enum _this);

#define corto_enum_init(_this) _corto_enum_init(corto_enum(_this))
CORTO_EXPORT
corto_int16 _corto_enum_init(
    corto_enum _this);

#define corto_float_init(_this) _corto_float_init(corto_float(_this))
CORTO_EXPORT
corto_int16 _corto_float_init(
    corto_float _this);

#define corto_function_construct(_this) _corto_function_construct(corto_function(_this))
CORTO_EXPORT
corto_int16 _corto_function_construct(
    corto_function _this);

#define corto_function_destruct(_this) _corto_function_destruct(corto_function(_this))
CORTO_EXPORT
corto_void _corto_function_destruct(
    corto_function _this);

#define corto_function_init(_this) _corto_function_init(corto_function(_this))
CORTO_EXPORT
corto_int16 _corto_function_init(
    corto_function _this);

#define corto_function_parseParamString(_this, params) _corto_function_parseParamString(corto_function(_this), params)
CORTO_EXPORT
corto_int16 _corto_function_parseParamString(
    corto_function _this,
    corto_string params);

#define corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)
CORTO_EXPORT
corto_parameterseq _corto_function_stringToParameterSeq(
    corto_string name,
    corto_object scope);

#define corto_int_init(_this) _corto_int_init(corto_int(_this))
CORTO_EXPORT
corto_int16 _corto_int_init(
    corto_int _this);

#define corto_interface_baseof(_this, type) _corto_interface_baseof(corto_interface(_this), corto_interface(type))
CORTO_EXPORT
corto_int16 _corto_interface_baseof(
    corto_interface _this,
    corto_interface type);

#define corto_interface_bindMethod(_this, method) _corto_interface_bindMethod(corto_interface(_this), corto_method(method))
CORTO_EXPORT
corto_int16 _corto_interface_bindMethod(
    corto_interface _this,
    corto_method method);

#define corto_interface_compatible_v(_this, type) _corto_interface_compatible_v(corto_interface(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_interface_compatible_v(
    corto_interface _this,
    corto_type type);

#define corto_interface_compatible(_this, type) _corto_interface_compatible(corto_interface(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_interface_compatible(
    corto_interface _this,
    corto_type type);

#define corto_interface_construct(_this) _corto_interface_construct(corto_interface(_this))
CORTO_EXPORT
corto_int16 _corto_interface_construct(
    corto_interface _this);

#define corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))
CORTO_EXPORT
corto_void _corto_interface_destruct(
    corto_interface _this);

#define corto_interface_init(_this) _corto_interface_init(corto_interface(_this))
CORTO_EXPORT
corto_int16 _corto_interface_init(
    corto_interface _this);

#define corto_interface_resolveMember_v(_this, name) _corto_interface_resolveMember_v(corto_interface(_this), name)
CORTO_EXPORT
corto_member _corto_interface_resolveMember_v(
    corto_interface _this,
    corto_string name);

#define corto_interface_resolveMember(_this, name) _corto_interface_resolveMember(corto_interface(_this), name)
CORTO_EXPORT
corto_member _corto_interface_resolveMember(
    corto_interface _this,
    corto_string name);

#define corto_interface_resolveMethod(_this, name) _corto_interface_resolveMethod(corto_interface(_this), name)
CORTO_EXPORT
corto_method _corto_interface_resolveMethod(
    corto_interface _this,
    corto_string name);

#define corto_interface_resolveMethodById(_this, id) _corto_interface_resolveMethodById(corto_interface(_this), id)
CORTO_EXPORT
corto_method _corto_interface_resolveMethodById(
    corto_interface _this,
    corto_uint32 id);

#define corto_interface_resolveMethodId(_this, name) _corto_interface_resolveMethodId(corto_interface(_this), name)
CORTO_EXPORT
corto_uint32 _corto_interface_resolveMethodId(
    corto_interface _this,
    corto_string name);

#define corto_iterator_castable_v(_this, type) _corto_iterator_castable_v(corto_iterator(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_iterator_castable_v(
    corto_iterator _this,
    corto_type type);

#define corto_iterator_castable(_this, type) _corto_iterator_castable(corto_iterator(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_iterator_castable(
    corto_iterator _this,
    corto_type type);

#define corto_iterator_compatible_v(_this, type) _corto_iterator_compatible_v(corto_iterator(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_iterator_compatible_v(
    corto_iterator _this,
    corto_type type);

#define corto_iterator_compatible(_this, type) _corto_iterator_compatible(corto_iterator(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_iterator_compatible(
    corto_iterator _this,
    corto_type type);

#define corto_iterator_init(_this) _corto_iterator_init(corto_iterator(_this))
CORTO_EXPORT
corto_int16 _corto_iterator_init(
    corto_iterator _this);

#define corto_list_construct(_this) _corto_list_construct(corto_list(_this))
CORTO_EXPORT
corto_int16 _corto_list_construct(
    corto_list _this);

#define corto_list_init(_this) _corto_list_init(corto_list(_this))
CORTO_EXPORT
corto_int16 _corto_list_init(
    corto_list _this);

#define corto_map_construct(_this) _corto_map_construct(corto_map(_this))
CORTO_EXPORT
corto_int16 _corto_map_construct(
    corto_map _this);

#define corto_map_init(_this) _corto_map_init(corto_map(_this))
CORTO_EXPORT
corto_int16 _corto_map_init(
    corto_map _this);

#define corto_member_construct(_this) _corto_member_construct(corto_member(_this))
CORTO_EXPORT
corto_int16 _corto_member_construct(
    corto_member _this);

#define corto_member_init(_this) _corto_member_init(corto_member(_this))
CORTO_EXPORT
corto_int16 _corto_member_init(
    corto_member _this);

#define corto_metaprocedure_construct(_this) _corto_metaprocedure_construct(corto_metaprocedure(_this))
CORTO_EXPORT
corto_int16 _corto_metaprocedure_construct(
    corto_metaprocedure _this);

#define corto_method_construct(_this) _corto_method_construct(corto_method(_this))
CORTO_EXPORT
corto_int16 _corto_method_construct(
    corto_method _this);

#define corto_method_init(_this) _corto_method_init(corto_method(_this))
CORTO_EXPORT
corto_int16 _corto_method_init(
    corto_method _this);

#define corto_overridable_init(_this) _corto_overridable_init(corto_overridable(_this))
CORTO_EXPORT
corto_int16 _corto_overridable_init(
    corto_overridable _this);

#define corto_override_init(_this) _corto_override_init(corto_override(_this))
CORTO_EXPORT
corto_int16 _corto_override_init(
    corto_override _this);

#define corto_primitive_castable_v(_this, type) _corto_primitive_castable_v(corto_primitive(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_primitive_castable_v(
    corto_primitive _this,
    corto_type type);

#define corto_primitive_castable(_this, type) _corto_primitive_castable(corto_primitive(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_primitive_castable(
    corto_primitive _this,
    corto_type type);

#define corto_primitive_compatible_v(_this, type) _corto_primitive_compatible_v(corto_primitive(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_primitive_compatible_v(
    corto_primitive _this,
    corto_type type);

#define corto_primitive_compatible(_this, type) _corto_primitive_compatible(corto_primitive(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_primitive_compatible(
    corto_primitive _this,
    corto_type type);

#define corto_primitive_construct(_this) _corto_primitive_construct(corto_primitive(_this))
CORTO_EXPORT
corto_int16 _corto_primitive_construct(
    corto_primitive _this);

#define corto_primitive_init(_this) _corto_primitive_init(corto_primitive(_this))
CORTO_EXPORT
corto_int16 _corto_primitive_init(
    corto_primitive _this);

#define corto_primitive_isInteger(_this) _corto_primitive_isInteger(corto_primitive(_this))
CORTO_EXPORT
corto_bool _corto_primitive_isInteger(
    corto_primitive _this);

#define corto_primitive_isNumber(_this) _corto_primitive_isNumber(corto_primitive(_this))
CORTO_EXPORT
corto_bool _corto_primitive_isNumber(
    corto_primitive _this);

#define corto_procedure_init(_this) _corto_procedure_init(corto_procedure(_this))
CORTO_EXPORT
corto_int16 _corto_procedure_init(
    corto_procedure _this);

#define corto_sequence_construct(_this) _corto_sequence_construct(corto_sequence(_this))
CORTO_EXPORT
corto_int16 _corto_sequence_construct(
    corto_sequence _this);

#define corto_sequence_init(_this) _corto_sequence_init(corto_sequence(_this))
CORTO_EXPORT
corto_int16 _corto_sequence_init(
    corto_sequence _this);

#define corto_struct_castable_v(_this, type) _corto_struct_castable_v(corto_struct(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_struct_castable_v(
    corto_struct _this,
    corto_type type);

#define corto_struct_castable(_this, type) _corto_struct_castable(corto_struct(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_struct_castable(
    corto_struct _this,
    corto_type type);

#define corto_struct_compatible_v(_this, type) _corto_struct_compatible_v(corto_struct(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_struct_compatible_v(
    corto_struct _this,
    corto_type type);

#define corto_struct_compatible(_this, type) _corto_struct_compatible(corto_struct(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_struct_compatible(
    corto_struct _this,
    corto_type type);

#define corto_struct_construct(_this) _corto_struct_construct(corto_struct(_this))
CORTO_EXPORT
corto_int16 _corto_struct_construct(
    corto_struct _this);

#define corto_struct_init(_this) _corto_struct_init(corto_struct(_this))
CORTO_EXPORT
corto_int16 _corto_struct_init(
    corto_struct _this);

#define corto_struct_resolveMember_v(_this, name) _corto_struct_resolveMember_v(corto_struct(_this), name)
CORTO_EXPORT
corto_member _corto_struct_resolveMember_v(
    corto_struct _this,
    corto_string name);

#define corto_struct_resolveMember(_this, name) _corto_struct_resolveMember(corto_struct(_this), name)
CORTO_EXPORT
corto_member _corto_struct_resolveMember(
    corto_struct _this,
    corto_string name);

#define corto_table_construct(_this) _corto_table_construct(corto_table(_this))
CORTO_EXPORT
corto_int16 _corto_table_construct(
    corto_table _this);

#define corto_target_construct(_this) _corto_target_construct(corto_target(_this))
CORTO_EXPORT
corto_int16 _corto_target_construct(
    corto_target _this);

#define corto_text_init(_this) _corto_text_init(corto_text(_this))
CORTO_EXPORT
corto_int16 _corto_text_init(
    corto_text _this);

#define corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
CORTO_EXPORT
corto_uint16 _corto_type_alignmentof(
    corto_type _this);

#define corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_type_castable_v(
    corto_type _this,
    corto_type type);

#define corto_type_castable(_this, type) _corto_type_castable(corto_type(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_type_castable(
    corto_type _this,
    corto_type type);

#define corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_type_compatible_v(
    corto_type _this,
    corto_type type);

#define corto_type_compatible(_this, type) _corto_type_compatible(corto_type(_this), corto_type(type))
CORTO_EXPORT
corto_bool _corto_type_compatible(
    corto_type _this,
    corto_type type);

#define corto_type_construct(_this) _corto_type_construct(corto_type(_this))
CORTO_EXPORT
corto_int16 _corto_type_construct(
    corto_type _this);

#define corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))
CORTO_EXPORT
corto_void _corto_type_destruct(
    corto_type _this);

#define corto_type_init(_this) _corto_type_init(corto_type(_this))
CORTO_EXPORT
corto_int16 _corto_type_init(
    corto_type _this);

#define corto_type_resolveProcedure(_this, name) _corto_type_resolveProcedure(corto_type(_this), name)
CORTO_EXPORT
corto_function _corto_type_resolveProcedure(
    corto_type _this,
    corto_string name);

#define corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))
CORTO_EXPORT
corto_uint32 _corto_type_sizeof(
    corto_type _this);

#define corto_uint_init(_this) _corto_uint_init(corto_uint(_this))
CORTO_EXPORT
corto_int16 _corto_uint_init(
    corto_uint _this);

#define corto_union_construct(_this) _corto_union_construct(corto_union(_this))
CORTO_EXPORT
corto_int16 _corto_union_construct(
    corto_union _this);

#define corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)
CORTO_EXPORT
corto_member _corto_union_findCase(
    corto_union _this,
    corto_int32 discriminator);

#define corto_union_init(_this) _corto_union_init(corto_union(_this))
CORTO_EXPORT
corto_int16 _corto_union_init(
    corto_union _this);

#define corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
CORTO_EXPORT
corto_int16 _corto_unit_construct(
    corto_unit _this);

#define corto_unit_destruct(_this) _corto_unit_destruct(corto_unit(_this))
CORTO_EXPORT
corto_void _corto_unit_destruct(
    corto_unit _this);

#define corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
CORTO_EXPORT
corto_int16 _corto_unit_init(
    corto_unit _this);

#define corto_verbatim_init(_this) _corto_verbatim_init(corto_verbatim(_this))
CORTO_EXPORT
corto_int16 _corto_verbatim_init(
    corto_verbatim _this);

#ifdef __cplusplus
}
#endif

#endif

