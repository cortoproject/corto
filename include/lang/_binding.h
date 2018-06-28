/* _binding.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_LANG_BINDING_H
#define CORTO_LANG_BINDING_H

/* -- Type casting -- */
#define corto_typeKind(o) ((corto_typeKind*)corto_assert_type((corto_type)corto_typeKind_o, o))
#define corto_bool(o) ((bool*)corto_assert_type((corto_type)corto_bool_o, o))
#define corto_attr(o) ((corto_attr*)corto_assert_type((corto_type)corto_attr_o, o))
#define corto_state(o) ((corto_state*)corto_assert_type((corto_type)corto_state_o, o))
#define corto_uint16(o) ((uint16_t*)corto_assert_type((corto_type)corto_uint16_o, o))
#define corto_uint32(o) ((uint32_t*)corto_assert_type((corto_type)corto_uint32_o, o))
#define corto_object(o) ((corto_object)o)
#define corto_objectseq(o) ((corto_objectseq*)corto_assert_type((corto_type)corto_objectseq_o, o))
#define corto_word(o) ((uintptr_t*)corto_assert_type((corto_type)corto_word_o, o))
#define corto_string(o) ((corto_string*)corto_assert_type((corto_type)corto_string_o, o))
#define corto_inout(o) ((corto_inout*)corto_assert_type((corto_type)corto_inout_o, o))
#define corto_parameter(o) ((corto_parameter*)corto_assert_type((corto_type)corto_parameter_o, o))
#define corto_parameterseq(o) ((corto_parameterseq*)corto_assert_type((corto_type)corto_parameterseq_o, o))
#define corto_function(o) ((corto_function)corto_assert_type((corto_type)corto_function_o, o))
#define corto_delegatedata(o) ((corto_delegatedata*)corto_assert_type((corto_type)corto_delegatedata_o, o))
#define corto_pre_action(o) ((corto_pre_action*)corto_assert_type((corto_type)corto_pre_action_o, o))
#define corto_post_action(o) ((corto_post_action*)corto_assert_type((corto_type)corto_post_action_o, o))
#define corto_name_action(o) ((corto_name_action*)corto_assert_type((corto_type)corto_name_action_o, o))
#define corto_type(o) ((corto_type)corto_assert_type((corto_type)corto_type_o, o))
#define corto_modifier(o) ((corto_modifier*)corto_assert_type((corto_type)corto_modifier_o, o))
#define corto_quantity(o) ((corto_quantity)corto_assert_type((corto_type)corto_quantity_o, o))
#define corto_unit(o) ((corto_unit)corto_assert_type((corto_type)corto_unit_o, o))
#define corto_int8(o) ((int8_t*)corto_assert_type((corto_type)corto_int8_o, o))
#define corto_tag(o) ((corto_tag)corto_assert_type((corto_type)corto_tag_o, o))
#define corto_taglist(o) ((corto_taglist*)corto_assert_type((corto_type)corto_taglist_o, o))
#define corto_member(o) ((corto_member)corto_assert_type((corto_type)corto_member_o, o))
#define corto_alias(o) ((corto_alias)corto_assert_type((corto_type)corto_alias_o, o))
#define corto_any(o) ((corto_any*)corto_assert_type((corto_type)corto_any_o, o))
#define corto_stringlist(o) ((corto_stringlist*)corto_assert_type((corto_type)corto_stringlist_o, o))
#define corto_package(o) ((corto_package)corto_assert_type((corto_type)corto_package_o, o))
#define corto_application(o) ((corto_application)corto_assert_type((corto_type)corto_application_o, o))
#define corto_collectionKind(o) ((corto_collectionKind*)corto_assert_type((corto_type)corto_collectionKind_o, o))
#define corto_collection(o) ((corto_collection)corto_assert_type((corto_type)corto_collection_o, o))
#define corto_array(o) ((corto_array)corto_assert_type((corto_type)corto_array_o, o))
#define corto_primitiveKind(o) ((corto_primitiveKind*)corto_assert_type((corto_type)corto_primitiveKind_o, o))
#define corto_width(o) ((corto_width*)corto_assert_type((corto_type)corto_width_o, o))
#define corto_uint8(o) ((uint8_t*)corto_assert_type((corto_type)corto_uint8_o, o))
#define corto_primitive(o) ((corto_primitive)corto_assert_type((corto_type)corto_primitive_o, o))
#define corto_binary(o) ((corto_binary)corto_assert_type((corto_type)corto_binary_o, o))
#define corto_enum(o) ((corto_enum)corto_assert_type((corto_type)corto_enum_o, o))
#define corto_bitmask(o) ((corto_bitmask)corto_assert_type((corto_type)corto_bitmask_o, o))
#define corto_boolean(o) ((corto_boolean)corto_assert_type((corto_type)corto_boolean_o, o))
#define corto_int32(o) ((int32_t*)corto_assert_type((corto_type)corto_int32_o, o))
#define corto_int32seq(o) ((corto_int32seq*)corto_assert_type((corto_type)corto_int32seq_o, o))
#define corto_case(o) ((corto_case)corto_assert_type((corto_type)corto_case_o, o))
#define corto_char(o) ((char*)corto_assert_type((corto_type)corto_char_o, o))
#define corto_character(o) ((corto_character)corto_assert_type((corto_type)corto_character_o, o))
#define corto_compositeKind(o) ((corto_compositeKind*)corto_assert_type((corto_type)corto_compositeKind_o, o))
#define corto_interface(o) ((corto_interface)corto_assert_type((corto_type)corto_interface_o, o))
#define corto_stringseq(o) ((corto_stringseq*)corto_assert_type((corto_type)corto_stringseq_o, o))
#define corto_struct(o) ((corto_struct)corto_assert_type((corto_type)corto_struct_o, o))
#define corto_interfaceseq(o) ((corto_interfaceseq*)corto_assert_type((corto_type)corto_interfaceseq_o, o))
#define corto_interfaceVector(o) ((corto_interfaceVector*)corto_assert_type((corto_type)corto_interfaceVector_o, o))
#define corto_interfaceVectorseq(o) ((corto_interfaceVectorseq*)corto_assert_type((corto_type)corto_interfaceVectorseq_o, o))
#define corto_class(o) ((corto_class)corto_assert_type((corto_type)corto_class_o, o))
#define corto_constant(o) ((int32_t*)corto_assert_type((corto_type)corto_constant_o, o))
#define corto_container(o) ((corto_container)corto_assert_type((corto_type)corto_container_o, o))
#define corto_default(o) ((corto_default)corto_assert_type((corto_type)corto_default_o, o))
#define corto_delegate(o) ((corto_delegate)corto_assert_type((corto_type)corto_delegate_o, o))
#define corto_equalityKind(o) ((corto_equalityKind*)corto_assert_type((corto_type)corto_equalityKind_o, o))
#define corto_float64(o) ((double*)corto_assert_type((corto_type)corto_float64_o, o))
#define corto_float(o) ((corto_float)corto_assert_type((corto_type)corto_float_o, o))
#define corto_float32(o) ((float*)corto_assert_type((corto_type)corto_float32_o, o))
#define corto_int64(o) ((int64_t*)corto_assert_type((corto_type)corto_int64_o, o))
#define corto_int(o) ((corto_int)corto_assert_type((corto_type)corto_int_o, o))
#define corto_int16(o) ((int16_t*)corto_assert_type((corto_type)corto_int16_o, o))
#define corto_iterator(o) ((corto_iterator)corto_assert_type((corto_type)corto_iterator_o, o))
#define corto_leaf(o) ((corto_leaf)corto_assert_type((corto_type)corto_leaf_o, o))
#define corto_list(o) ((corto_list)corto_assert_type((corto_type)corto_list_o, o))
#define corto_map(o) ((corto_map)corto_assert_type((corto_type)corto_map_o, o))
#define corto_metaprocedure(o) ((corto_metaprocedure)corto_assert_type((corto_type)corto_metaprocedure_o, o))
#define corto_method(o) ((corto_method)corto_assert_type((corto_type)corto_method_o, o))
#define corto_objectlist(o) ((corto_objectlist*)corto_assert_type((corto_type)corto_objectlist_o, o))
#define corto_octet(o) ((uint8_t*)corto_assert_type((corto_type)corto_octet_o, o))
#define corto_overridable(o) ((corto_overridable)corto_assert_type((corto_type)corto_overridable_o, o))
#define corto_override(o) ((corto_override)corto_assert_type((corto_type)corto_override_o, o))
#define corto_procedure(o) ((corto_procedure)corto_assert_type((corto_type)corto_procedure_o, o))
#define corto_ref_kind(o) ((corto_ref_kind*)corto_assert_type((corto_type)corto_ref_kind_o, o))
#define corto_sequence(o) ((corto_sequence)corto_assert_type((corto_type)corto_sequence_o, o))
#define corto_table(o) ((corto_table)corto_assert_type((corto_type)corto_table_o, o))
#define corto_tableinstance(o) ((corto_tableinstance)corto_assert_type((corto_type)corto_tableinstance_o, o))
#define corto_target(o) ((corto_target)corto_assert_type((corto_type)corto_target_o, o))
#define corto_uint64(o) ((uint64_t*)corto_assert_type((corto_type)corto_uint64_o, o))
#define corto_text(o) ((corto_text)corto_assert_type((corto_type)corto_text_o, o))
#define corto_tool(o) ((corto_tool)corto_assert_type((corto_type)corto_tool_o, o))
#define corto_uint(o) ((corto_uint)corto_assert_type((corto_type)corto_uint_o, o))
#define corto_union(o) ((corto_union)corto_assert_type((corto_type)corto_union_o, o))
#define corto_unknown(o) ((void*)o)
#define corto_verbatim(o) ((corto_verbatim)corto_assert_type((corto_type)corto_verbatim_o, o))
#define corto_void(o) ((void*)o)
#define corto_wordseq(o) ((corto_wordseq*)corto_assert_type((corto_type)corto_wordseq_o, o))

/* -- Non-expanding typedefs -- */
typedef corto_typeKind _type_corto_typeKind;
typedef corto_bool _type_corto_bool;
typedef corto_attr _type_corto_attr;
typedef corto_state _type_corto_state;
typedef corto_uint16 _type_corto_uint16;
typedef corto_uint32 _type_corto_uint32;
typedef corto_object _type_corto_object;
typedef corto_objectseq _type_corto_objectseq;
typedef corto_word _type_corto_word;
typedef corto_string _type_corto_string;
typedef corto_inout _type_corto_inout;
typedef corto_parameter _type_corto_parameter;
typedef corto_parameterseq _type_corto_parameterseq;
typedef corto_function _type_corto_function;
typedef corto_delegatedata _type_corto_delegatedata;
typedef corto_pre_action _type_corto_pre_action;
typedef corto_post_action _type_corto_post_action;
typedef corto_name_action _type_corto_name_action;
typedef corto_type _type_corto_type;
typedef corto_modifier _type_corto_modifier;
typedef corto_quantity _type_corto_quantity;
typedef corto_unit _type_corto_unit;
typedef corto_int8 _type_corto_int8;
typedef corto_tag _type_corto_tag;
typedef corto_taglist _type_corto_taglist;
typedef corto_member _type_corto_member;
typedef corto_alias _type_corto_alias;
typedef corto_any _type_corto_any;
typedef corto_stringlist _type_corto_stringlist;
typedef corto_package _type_corto_package;
typedef corto_application _type_corto_application;
typedef corto_collectionKind _type_corto_collectionKind;
typedef corto_collection _type_corto_collection;
typedef corto_array _type_corto_array;
typedef corto_primitiveKind _type_corto_primitiveKind;
typedef corto_width _type_corto_width;
typedef corto_uint8 _type_corto_uint8;
typedef corto_primitive _type_corto_primitive;
typedef corto_binary _type_corto_binary;
typedef corto_enum _type_corto_enum;
typedef corto_bitmask _type_corto_bitmask;
typedef corto_boolean _type_corto_boolean;
typedef corto_int32 _type_corto_int32;
typedef corto_int32seq _type_corto_int32seq;
typedef corto_case _type_corto_case;
typedef corto_char _type_corto_char;
typedef corto_character _type_corto_character;
typedef corto_compositeKind _type_corto_compositeKind;
typedef corto_interface _type_corto_interface;
typedef corto_stringseq _type_corto_stringseq;
typedef corto_struct _type_corto_struct;
typedef corto_interfaceseq _type_corto_interfaceseq;
typedef corto_interfaceVector _type_corto_interfaceVector;
typedef corto_interfaceVectorseq _type_corto_interfaceVectorseq;
typedef corto_class _type_corto_class;
typedef corto_constant _type_corto_constant;
typedef corto_container _type_corto_container;
typedef corto_default _type_corto_default;
typedef corto_delegate _type_corto_delegate;
typedef corto_equalityKind _type_corto_equalityKind;
typedef corto_float64 _type_corto_float64;
typedef corto_float _type_corto_float;
typedef corto_float32 _type_corto_float32;
typedef corto_int64 _type_corto_int64;
typedef corto_int _type_corto_int;
typedef corto_int16 _type_corto_int16;
typedef corto_iterator _type_corto_iterator;
typedef corto_leaf _type_corto_leaf;
typedef corto_list _type_corto_list;
typedef corto_map _type_corto_map;
typedef corto_metaprocedure _type_corto_metaprocedure;
typedef corto_method _type_corto_method;
typedef corto_objectlist _type_corto_objectlist;
typedef corto_octet _type_corto_octet;
typedef corto_overridable _type_corto_overridable;
typedef corto_override _type_corto_override;
typedef corto_procedure _type_corto_procedure;
typedef corto_ref_kind _type_corto_ref_kind;
typedef corto_sequence _type_corto_sequence;
typedef corto_table _type_corto_table;
typedef corto_tableinstance _type_corto_tableinstance;
typedef corto_target _type_corto_target;
typedef corto_uint64 _type_corto_uint64;
typedef corto_text _type_corto_text;
typedef corto_tool _type_corto_tool;
typedef corto_uint _type_corto_uint;
typedef corto_union _type_corto_union;
typedef corto_unknown _type_corto_unknown;
typedef corto_verbatim _type_corto_verbatim;
typedef corto_void _type_corto_void;
typedef corto_wordseq _type_corto_wordseq;

/* -- Argument type casting -- */
#ifndef CORTO_IMPL
#define corto_alias_construct(_this) _corto_alias_construct(corto_alias(_this))
#define corto_array_construct(_this) _corto_array_construct(corto_array(_this))
#define corto_array_destruct(_this) _corto_array_destruct(corto_array(_this))
#define corto_array_init(_this) _corto_array_init(corto_array(_this))
#define corto_binary_init(_this) _corto_binary_init(corto_binary(_this))
#define corto_bitmask_init(_this) _corto_bitmask_init(corto_bitmask(_this))
#define corto_boolean_init(_this) _corto_boolean_init(corto_boolean(_this))
#define corto_character_init(_this) _corto_character_init(corto_character(_this))
#define corto_class_construct(_this) _corto_class_construct(corto_class(_this))
#define corto_class_destruct(_this) _corto_class_destruct(corto_class(_this))
#define corto_class_init(_this) _corto_class_init(corto_class(_this))
#define corto_class_instanceof(_this, object) _corto_class_instanceof(corto_class(_this), object)
#define corto_class_resolveInterfaceMethod(_this, interface, method) _corto_class_resolveInterfaceMethod(corto_class(_this), corto_interface(interface), method)
#define corto_collection_castable_v(_this, type) _corto_collection_castable_v(corto_collection(_this), corto_type(type))
#define corto_collection_compatible_v(_this, type) _corto_collection_compatible_v(corto_collection(_this), corto_type(type))
#define corto_collection_init(_this) _corto_collection_init(corto_collection(_this))
#define corto_collection_requires_alloc(elementType) _corto_collection_requires_alloc(corto_type(elementType))
#define corto_constant_init(_this) _corto_constant_init(_this)
#define corto_container_construct(_this) _corto_container_construct(corto_container(_this))
#define corto_delegate_bind(object) _corto_delegate_bind(corto_function(object))
#define corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
#define corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))
#define corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))
#define corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)
#define corto_enum_constant_from_id(_this, id) _corto_enum_constant_from_id(corto_enum(_this), id)
#define corto_enum_constant_from_value(_this, value) _corto_enum_constant_from_value(corto_enum(_this), value)
#define corto_enum_construct(_this) _corto_enum_construct(corto_enum(_this))
#define corto_enum_destruct(_this) _corto_enum_destruct(corto_enum(_this))
#define corto_enum_init(_this) _corto_enum_init(corto_enum(_this))
#define corto_float_init(_this) _corto_float_init(corto_float(_this))
#define corto_function_construct(_this) _corto_function_construct(corto_function(_this))
#define corto_function_destruct(_this) _corto_function_destruct(corto_function(_this))
#define corto_function_init(_this) _corto_function_init(corto_function(_this))
#define corto_function_parseParamString(_this, params) _corto_function_parseParamString(corto_function(_this), params)
#define corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)
#define corto_int_init(_this) _corto_int_init(corto_int(_this))
#define corto_interface_baseof(_this, type) _corto_interface_baseof(corto_interface(_this), corto_interface(type))
#define corto_interface_bindMethod(_this, method) _corto_interface_bindMethod(corto_interface(_this), corto_method(method))
#define corto_interface_compatible_v(_this, type) _corto_interface_compatible_v(corto_interface(_this), corto_type(type))
#define corto_interface_construct(_this) _corto_interface_construct(corto_interface(_this))
#define corto_interface_deinit(_this) _corto_interface_deinit(corto_interface(_this))
#define corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))
#define corto_interface_init(_this) _corto_interface_init(corto_interface(_this))
#define corto_interface_resolve_member_v(_this, name) _corto_interface_resolve_member_v(corto_interface(_this), name)
#define corto_interface_resolve_member_by_tag(_this, tag) _corto_interface_resolve_member_by_tag(corto_interface(_this), corto_tag(tag))
#define corto_interface_resolve_method(_this, name) _corto_interface_resolve_method(corto_interface(_this), name)
#define corto_interface_resolve_method_by_id(_this, id) _corto_interface_resolve_method_by_id(corto_interface(_this), id)
#define corto_interface_resolve_method_id(_this, name) _corto_interface_resolve_method_id(corto_interface(_this), name)
#define corto_iterator_castable_v(_this, type) _corto_iterator_castable_v(corto_iterator(_this), corto_type(type))
#define corto_iterator_compatible_v(_this, type) _corto_iterator_compatible_v(corto_iterator(_this), corto_type(type))
#define corto_iterator_init(_this) _corto_iterator_init(corto_iterator(_this))
#define corto_list_construct(_this) _corto_list_construct(corto_list(_this))
#define corto_list_init(_this) _corto_list_init(corto_list(_this))
#define corto_map_construct(_this) _corto_map_construct(corto_map(_this))
#define corto_map_init(_this) _corto_map_init(corto_map(_this))
#define corto_member_construct(_this) _corto_member_construct(corto_member(_this))
#define corto_member_init(_this) _corto_member_init(corto_member(_this))
#define corto_metaprocedure_construct(_this) _corto_metaprocedure_construct(corto_metaprocedure(_this))
#define corto_overridable_init(_this) _corto_overridable_init(corto_overridable(_this))
#define corto_package_define(_this) _corto_package_define(corto_package(_this))
#define corto_package_init(_this) _corto_package_init(corto_package(_this))
#define corto_primitive_castable_v(_this, type) _corto_primitive_castable_v(corto_primitive(_this), corto_type(type))
#define corto_primitive_compatible_v(_this, type) _corto_primitive_compatible_v(corto_primitive(_this), corto_type(type))
#define corto_primitive_construct(_this) _corto_primitive_construct(corto_primitive(_this))
#define corto_primitive_init(_this) _corto_primitive_init(corto_primitive(_this))
#define corto_primitive_isInteger(_this) _corto_primitive_isInteger(corto_primitive(_this))
#define corto_primitive_isNumber(_this) _corto_primitive_isNumber(corto_primitive(_this))
#define corto_procedure_construct(_this) _corto_procedure_construct(corto_procedure(_this))
#define corto_procedure_init(_this) _corto_procedure_init(corto_procedure(_this))
#define corto_sequence_construct(_this) _corto_sequence_construct(corto_sequence(_this))
#define corto_sequence_init(_this) _corto_sequence_init(corto_sequence(_this))
#define corto_struct_castable_v(_this, type) _corto_struct_castable_v(corto_struct(_this), corto_type(type))
#define corto_struct_compatible_v(_this, type) _corto_struct_compatible_v(corto_struct(_this), corto_type(type))
#define corto_struct_construct(_this) _corto_struct_construct(corto_struct(_this))
#define corto_struct_init(_this) _corto_struct_init(corto_struct(_this))
#define corto_struct_resolve_member_v(_this, name) _corto_struct_resolve_member_v(corto_struct(_this), name)
#define corto_table_construct(_this) _corto_table_construct(corto_table(_this))
#define corto_target_construct(_this) _corto_target_construct(corto_target(_this))
#define corto_text_init(_this) _corto_text_init(corto_text(_this))
#define corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
#define corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
#define corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))
#define corto_type_construct(_this) _corto_type_construct(corto_type(_this))
#define corto_type_deinit(_this) _corto_type_deinit(corto_type(_this))
#define corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))
#define corto_type_init(_this) _corto_type_init(corto_type(_this))
#define corto_type_resolve_procedure(_this, name) _corto_type_resolve_procedure(corto_type(_this), name)
#define corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))
#define corto_uint_init(_this) _corto_uint_init(corto_uint(_this))
#define corto_union_construct(_this) _corto_union_construct(corto_union(_this))
#define corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)
#define corto_union_init(_this) _corto_union_init(corto_union(_this))
#define corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
#define corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
#define corto_verbatim_init(_this) _corto_verbatim_init(corto_verbatim(_this))
#else
/* Can't use argument type casting macro's within project, as they would
 * substitute headers in implementation files. */
#define corto_alias_construct _corto_alias_construct
#define corto_array_construct _corto_array_construct
#define corto_array_destruct _corto_array_destruct
#define corto_array_init _corto_array_init
#define corto_binary_init _corto_binary_init
#define corto_bitmask_init _corto_bitmask_init
#define corto_boolean_init _corto_boolean_init
#define corto_character_init _corto_character_init
#define corto_class_construct _corto_class_construct
#define corto_class_destruct _corto_class_destruct
#define corto_class_init _corto_class_init
#define corto_class_instanceof _corto_class_instanceof
#define corto_class_resolveInterfaceMethod _corto_class_resolveInterfaceMethod
#define corto_collection_castable_v _corto_collection_castable_v
#define corto_collection_compatible_v _corto_collection_compatible_v
#define corto_collection_init _corto_collection_init
#define corto_collection_requires_alloc _corto_collection_requires_alloc
#define corto_constant_init _corto_constant_init
#define corto_container_construct _corto_container_construct
#define corto_delegate_bind _corto_delegate_bind
#define corto_delegate_castable_v _corto_delegate_castable_v
#define corto_delegate_compatible_v _corto_delegate_compatible_v
#define corto_delegate_init _corto_delegate_init
#define corto_delegate_instanceof _corto_delegate_instanceof
#define corto_enum_constant_from_id _corto_enum_constant_from_id
#define corto_enum_constant_from_value _corto_enum_constant_from_value
#define corto_enum_construct _corto_enum_construct
#define corto_enum_destruct _corto_enum_destruct
#define corto_enum_init _corto_enum_init
#define corto_float_init _corto_float_init
#define corto_function_construct _corto_function_construct
#define corto_function_destruct _corto_function_destruct
#define corto_function_init _corto_function_init
#define corto_function_parseParamString _corto_function_parseParamString
#define corto_function_stringToParameterSeq _corto_function_stringToParameterSeq
#define corto_int_init _corto_int_init
#define corto_interface_baseof _corto_interface_baseof
#define corto_interface_bindMethod _corto_interface_bindMethod
#define corto_interface_compatible_v _corto_interface_compatible_v
#define corto_interface_construct _corto_interface_construct
#define corto_interface_deinit _corto_interface_deinit
#define corto_interface_destruct _corto_interface_destruct
#define corto_interface_init _corto_interface_init
#define corto_interface_resolve_member_v _corto_interface_resolve_member_v
#define corto_interface_resolve_member_by_tag _corto_interface_resolve_member_by_tag
#define corto_interface_resolve_method _corto_interface_resolve_method
#define corto_interface_resolve_method_by_id _corto_interface_resolve_method_by_id
#define corto_interface_resolve_method_id _corto_interface_resolve_method_id
#define corto_iterator_castable_v _corto_iterator_castable_v
#define corto_iterator_compatible_v _corto_iterator_compatible_v
#define corto_iterator_init _corto_iterator_init
#define corto_list_construct _corto_list_construct
#define corto_list_init _corto_list_init
#define corto_map_construct _corto_map_construct
#define corto_map_init _corto_map_init
#define corto_member_construct _corto_member_construct
#define corto_member_init _corto_member_init
#define corto_metaprocedure_construct _corto_metaprocedure_construct
#define corto_overridable_init _corto_overridable_init
#define corto_package_define _corto_package_define
#define corto_package_init _corto_package_init
#define corto_primitive_castable_v _corto_primitive_castable_v
#define corto_primitive_compatible_v _corto_primitive_compatible_v
#define corto_primitive_construct _corto_primitive_construct
#define corto_primitive_init _corto_primitive_init
#define corto_primitive_isInteger _corto_primitive_isInteger
#define corto_primitive_isNumber _corto_primitive_isNumber
#define corto_procedure_construct _corto_procedure_construct
#define corto_procedure_init _corto_procedure_init
#define corto_sequence_construct _corto_sequence_construct
#define corto_sequence_init _corto_sequence_init
#define corto_struct_castable_v _corto_struct_castable_v
#define corto_struct_compatible_v _corto_struct_compatible_v
#define corto_struct_construct _corto_struct_construct
#define corto_struct_init _corto_struct_init
#define corto_struct_resolve_member_v _corto_struct_resolve_member_v
#define corto_table_construct _corto_table_construct
#define corto_target_construct _corto_target_construct
#define corto_text_init _corto_text_init
#define corto_type_alignmentof _corto_type_alignmentof
#define corto_type_castable_v _corto_type_castable_v
#define corto_type_compatible_v _corto_type_compatible_v
#define corto_type_construct _corto_type_construct
#define corto_type_deinit _corto_type_deinit
#define corto_type_destruct _corto_type_destruct
#define corto_type_init _corto_type_init
#define corto_type_resolve_procedure _corto_type_resolve_procedure
#define corto_type_sizeof _corto_type_sizeof
#define corto_uint_init _corto_uint_init
#define corto_union_construct _corto_union_construct
#define corto_union_findCase _corto_union_findCase
#define corto_union_init _corto_union_init
#define corto_unit_construct _corto_unit_construct
#define corto_unit_init _corto_unit_init
#define corto_verbatim_init _corto_verbatim_init
/* Macro for doing argument type casting within project. */
#define safe_corto_alias_construct(_this) _corto_alias_construct(corto_alias(_this))
#define safe_corto_array_construct(_this) _corto_array_construct(corto_array(_this))
#define safe_corto_array_destruct(_this) _corto_array_destruct(corto_array(_this))
#define safe_corto_array_init(_this) _corto_array_init(corto_array(_this))
#define safe_corto_binary_init(_this) _corto_binary_init(corto_binary(_this))
#define safe_corto_bitmask_init(_this) _corto_bitmask_init(corto_bitmask(_this))
#define safe_corto_boolean_init(_this) _corto_boolean_init(corto_boolean(_this))
#define safe_corto_character_init(_this) _corto_character_init(corto_character(_this))
#define safe_corto_class_construct(_this) _corto_class_construct(corto_class(_this))
#define safe_corto_class_destruct(_this) _corto_class_destruct(corto_class(_this))
#define safe_corto_class_init(_this) _corto_class_init(corto_class(_this))
#define safe_corto_class_instanceof(_this, object) _corto_class_instanceof(corto_class(_this), object)
#define safe_corto_class_resolveInterfaceMethod(_this, interface, method) _corto_class_resolveInterfaceMethod(corto_class(_this), corto_interface(interface), method)
#define safe_corto_collection_castable_v(_this, type) _corto_collection_castable_v(corto_collection(_this), corto_type(type))
#define safe_corto_collection_compatible_v(_this, type) _corto_collection_compatible_v(corto_collection(_this), corto_type(type))
#define safe_corto_collection_init(_this) _corto_collection_init(corto_collection(_this))
#define safe_corto_collection_requires_alloc(elementType) _corto_collection_requires_alloc(corto_type(elementType))
#define safe_corto_constant_init(_this) _corto_constant_init(_this)
#define safe_corto_container_construct(_this) _corto_container_construct(corto_container(_this))
#define safe_corto_delegate_bind(object) _corto_delegate_bind(corto_function(object))
#define safe_corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
#define safe_corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))
#define safe_corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))
#define safe_corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)
#define safe_corto_enum_constant_from_id(_this, id) _corto_enum_constant_from_id(corto_enum(_this), id)
#define safe_corto_enum_constant_from_value(_this, value) _corto_enum_constant_from_value(corto_enum(_this), value)
#define safe_corto_enum_construct(_this) _corto_enum_construct(corto_enum(_this))
#define safe_corto_enum_destruct(_this) _corto_enum_destruct(corto_enum(_this))
#define safe_corto_enum_init(_this) _corto_enum_init(corto_enum(_this))
#define safe_corto_float_init(_this) _corto_float_init(corto_float(_this))
#define safe_corto_function_construct(_this) _corto_function_construct(corto_function(_this))
#define safe_corto_function_destruct(_this) _corto_function_destruct(corto_function(_this))
#define safe_corto_function_init(_this) _corto_function_init(corto_function(_this))
#define safe_corto_function_parseParamString(_this, params) _corto_function_parseParamString(corto_function(_this), params)
#define safe_corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)
#define safe_corto_int_init(_this) _corto_int_init(corto_int(_this))
#define safe_corto_interface_baseof(_this, type) _corto_interface_baseof(corto_interface(_this), corto_interface(type))
#define safe_corto_interface_bindMethod(_this, method) _corto_interface_bindMethod(corto_interface(_this), corto_method(method))
#define safe_corto_interface_compatible_v(_this, type) _corto_interface_compatible_v(corto_interface(_this), corto_type(type))
#define safe_corto_interface_construct(_this) _corto_interface_construct(corto_interface(_this))
#define safe_corto_interface_deinit(_this) _corto_interface_deinit(corto_interface(_this))
#define safe_corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))
#define safe_corto_interface_init(_this) _corto_interface_init(corto_interface(_this))
#define safe_corto_interface_resolve_member_v(_this, name) _corto_interface_resolve_member_v(corto_interface(_this), name)
#define safe_corto_interface_resolve_member_by_tag(_this, tag) _corto_interface_resolve_member_by_tag(corto_interface(_this), corto_tag(tag))
#define safe_corto_interface_resolve_method(_this, name) _corto_interface_resolve_method(corto_interface(_this), name)
#define safe_corto_interface_resolve_method_by_id(_this, id) _corto_interface_resolve_method_by_id(corto_interface(_this), id)
#define safe_corto_interface_resolve_method_id(_this, name) _corto_interface_resolve_method_id(corto_interface(_this), name)
#define safe_corto_iterator_castable_v(_this, type) _corto_iterator_castable_v(corto_iterator(_this), corto_type(type))
#define safe_corto_iterator_compatible_v(_this, type) _corto_iterator_compatible_v(corto_iterator(_this), corto_type(type))
#define safe_corto_iterator_init(_this) _corto_iterator_init(corto_iterator(_this))
#define safe_corto_list_construct(_this) _corto_list_construct(corto_list(_this))
#define safe_corto_list_init(_this) _corto_list_init(corto_list(_this))
#define safe_corto_map_construct(_this) _corto_map_construct(corto_map(_this))
#define safe_corto_map_init(_this) _corto_map_init(corto_map(_this))
#define safe_corto_member_construct(_this) _corto_member_construct(corto_member(_this))
#define safe_corto_member_init(_this) _corto_member_init(corto_member(_this))
#define safe_corto_metaprocedure_construct(_this) _corto_metaprocedure_construct(corto_metaprocedure(_this))
#define safe_corto_overridable_init(_this) _corto_overridable_init(corto_overridable(_this))
#define safe_corto_package_define(_this) _corto_package_define(corto_package(_this))
#define safe_corto_package_init(_this) _corto_package_init(corto_package(_this))
#define safe_corto_primitive_castable_v(_this, type) _corto_primitive_castable_v(corto_primitive(_this), corto_type(type))
#define safe_corto_primitive_compatible_v(_this, type) _corto_primitive_compatible_v(corto_primitive(_this), corto_type(type))
#define safe_corto_primitive_construct(_this) _corto_primitive_construct(corto_primitive(_this))
#define safe_corto_primitive_init(_this) _corto_primitive_init(corto_primitive(_this))
#define safe_corto_primitive_isInteger(_this) _corto_primitive_isInteger(corto_primitive(_this))
#define safe_corto_primitive_isNumber(_this) _corto_primitive_isNumber(corto_primitive(_this))
#define safe_corto_procedure_construct(_this) _corto_procedure_construct(corto_procedure(_this))
#define safe_corto_procedure_init(_this) _corto_procedure_init(corto_procedure(_this))
#define safe_corto_sequence_construct(_this) _corto_sequence_construct(corto_sequence(_this))
#define safe_corto_sequence_init(_this) _corto_sequence_init(corto_sequence(_this))
#define safe_corto_struct_castable_v(_this, type) _corto_struct_castable_v(corto_struct(_this), corto_type(type))
#define safe_corto_struct_compatible_v(_this, type) _corto_struct_compatible_v(corto_struct(_this), corto_type(type))
#define safe_corto_struct_construct(_this) _corto_struct_construct(corto_struct(_this))
#define safe_corto_struct_init(_this) _corto_struct_init(corto_struct(_this))
#define safe_corto_struct_resolve_member_v(_this, name) _corto_struct_resolve_member_v(corto_struct(_this), name)
#define safe_corto_table_construct(_this) _corto_table_construct(corto_table(_this))
#define safe_corto_target_construct(_this) _corto_target_construct(corto_target(_this))
#define safe_corto_text_init(_this) _corto_text_init(corto_text(_this))
#define safe_corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
#define safe_corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
#define safe_corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))
#define safe_corto_type_construct(_this) _corto_type_construct(corto_type(_this))
#define safe_corto_type_deinit(_this) _corto_type_deinit(corto_type(_this))
#define safe_corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))
#define safe_corto_type_init(_this) _corto_type_init(corto_type(_this))
#define safe_corto_type_resolve_procedure(_this, name) _corto_type_resolve_procedure(corto_type(_this), name)
#define safe_corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))
#define safe_corto_uint_init(_this) _corto_uint_init(corto_uint(_this))
#define safe_corto_union_construct(_this) _corto_union_construct(corto_union(_this))
#define safe_corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)
#define safe_corto_union_init(_this) _corto_union_init(corto_union(_this))
#define safe_corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
#define safe_corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
#define safe_corto_verbatim_init(_this) _corto_verbatim_init(corto_verbatim(_this))
#endif

/* -- Overridable methods -- */
#define corto_collection_castable(_this, type) ( \
    ((corto_function)corto_collection_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_castable_o)->index - 1])->fptr)(corto_collection(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_castable_o)->index - 1], alloca(sizeof(bool)), corto_collection(_this), corto_type(type)) \
    )
#define corto_collection_compatible(_this, type) ( \
    ((corto_function)corto_collection_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_compatible_o)->index - 1])->fptr)(corto_collection(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_compatible_o)->index - 1], alloca(sizeof(bool)), corto_collection(_this), corto_type(type)) \
    )
#define corto_delegate_castable(_this, type) ( \
    ((corto_function)corto_delegate_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_castable_o)->index - 1])->fptr)(corto_delegate(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_castable_o)->index - 1], alloca(sizeof(bool)), corto_delegate(_this), corto_type(type)) \
    )
#define corto_delegate_compatible(_this, type) ( \
    ((corto_function)corto_delegate_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_compatible_o)->index - 1])->fptr)(corto_delegate(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_compatible_o)->index - 1], alloca(sizeof(bool)), corto_delegate(_this), corto_type(type)) \
    )
#define corto_interface_compatible(_this, type) ( \
    ((corto_function)corto_interface_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_compatible_o)->index - 1])->fptr)(corto_interface(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_compatible_o)->index - 1], alloca(sizeof(bool)), corto_interface(_this), corto_type(type)) \
    )
#define corto_interface_resolve_member(_this, name) ( \
    ((corto_function)corto_interface_resolve_member_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_member (*)(corto_object, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_resolve_member_o)->index - 1])->fptr)(corto_interface(_this), name) \
    : *(corto_member*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_resolve_member_o)->index - 1], alloca(sizeof(corto_member)), corto_interface(_this), name) \
    )
#define corto_iterator_castable(_this, type) ( \
    ((corto_function)corto_iterator_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_castable_o)->index - 1])->fptr)(corto_iterator(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_castable_o)->index - 1], alloca(sizeof(bool)), corto_iterator(_this), corto_type(type)) \
    )
#define corto_iterator_compatible(_this, type) ( \
    ((corto_function)corto_iterator_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_compatible_o)->index - 1])->fptr)(corto_iterator(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_compatible_o)->index - 1], alloca(sizeof(bool)), corto_iterator(_this), corto_type(type)) \
    )
#define corto_primitive_castable(_this, type) ( \
    ((corto_function)corto_primitive_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_castable_o)->index - 1])->fptr)(corto_primitive(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_castable_o)->index - 1], alloca(sizeof(bool)), corto_primitive(_this), corto_type(type)) \
    )
#define corto_primitive_compatible(_this, type) ( \
    ((corto_function)corto_primitive_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_compatible_o)->index - 1])->fptr)(corto_primitive(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_compatible_o)->index - 1], alloca(sizeof(bool)), corto_primitive(_this), corto_type(type)) \
    )
#define corto_struct_castable(_this, type) ( \
    ((corto_function)corto_struct_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_castable_o)->index - 1])->fptr)(corto_struct(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_castable_o)->index - 1], alloca(sizeof(bool)), corto_struct(_this), corto_type(type)) \
    )
#define corto_struct_compatible(_this, type) ( \
    ((corto_function)corto_struct_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_compatible_o)->index - 1])->fptr)(corto_struct(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_compatible_o)->index - 1], alloca(sizeof(bool)), corto_struct(_this), corto_type(type)) \
    )
#define corto_struct_resolve_member(_this, name) ( \
    ((corto_function)corto_struct_resolve_member_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_member (*)(corto_object, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_resolve_member_o)->index - 1])->fptr)(corto_struct(_this), name) \
    : *(corto_member*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_resolve_member_o)->index - 1], alloca(sizeof(corto_member)), corto_struct(_this), name) \
    )
#define corto_type_castable(_this, type) ( \
    ((corto_function)corto_type_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_castable_o)->index - 1])->fptr)(corto_type(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_castable_o)->index - 1], alloca(sizeof(bool)), corto_type(_this), corto_type(type)) \
    )
#define corto_type_compatible(_this, type) ( \
    ((corto_function)corto_type_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_compatible_o)->index - 1])->fptr)(corto_type(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_compatible_o)->index - 1], alloca(sizeof(bool)), corto_type(_this), corto_type(type)) \
    )

/* -- Short identifier translation -- */

/* -- Short object variable translation -- */

#endif

