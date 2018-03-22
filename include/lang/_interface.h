/* _interface.h
 * This file is generated. Do not modify the contents of this file.
 */

#ifndef CORTO_LANG_INTERFACE_H
#define CORTO_LANG_INTERFACE_H

#include <corto/_project.h>


#ifdef __cplusplus
extern "C" {
#endif



/* class corto/lang/alias */

CORTO_EXPORT
int16_t _corto_alias_construct(
    corto_alias _this);


/* class corto/lang/array */

CORTO_EXPORT
int16_t _corto_array_construct(
    corto_array _this);

CORTO_EXPORT
void _corto_array_destruct(
    corto_array _this);

CORTO_EXPORT
int16_t _corto_array_init(
    corto_array _this);


/* class corto/lang/binary */

CORTO_EXPORT
int16_t _corto_binary_init(
    corto_binary _this);


/* class corto/lang/bitmask */

CORTO_EXPORT
int16_t _corto_bitmask_init(
    corto_bitmask _this);


/* class corto/lang/boolean */

CORTO_EXPORT
int16_t _corto_boolean_init(
    corto_boolean _this);


/* class corto/lang/character */

CORTO_EXPORT
int16_t _corto_character_init(
    corto_character _this);


/* class corto/lang/class */

CORTO_EXPORT
int16_t _corto_class_construct(
    corto_class _this);

CORTO_EXPORT
void _corto_class_destruct(
    corto_class _this);

CORTO_EXPORT
int16_t _corto_class_init(
    corto_class _this);

CORTO_EXPORT
bool _corto_class_instanceof(
    corto_class _this,
    corto_object object);

CORTO_EXPORT
corto_method _corto_class_resolveInterfaceMethod(
    corto_class _this,
    corto_interface interface,
    uint32_t method);


/* class corto/lang/collection */

CORTO_EXPORT
bool _corto_collection_castable_v(
    corto_collection _this,
    corto_type type);

CORTO_EXPORT
bool _corto_collection_compatible_v(
    corto_collection _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_collection_init(
    corto_collection _this);

CORTO_EXPORT
bool _corto_collection_requiresAlloc(
    corto_type elementType);


/* int corto/lang/constant */

CORTO_EXPORT
int16_t _corto_constant_init(
    int32_t* _this);


/* class corto/lang/container */

CORTO_EXPORT
int16_t _corto_container_construct(
    corto_container _this);


/* class corto/lang/delegate */

CORTO_EXPORT
int16_t _corto_delegate_bind(
    corto_function object);

CORTO_EXPORT
bool _corto_delegate_castable_v(
    corto_delegate _this,
    corto_type type);

CORTO_EXPORT
bool _corto_delegate_compatible_v(
    corto_delegate _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_delegate_init(
    corto_delegate _this);

CORTO_EXPORT
bool _corto_delegate_instanceof(
    corto_delegate _this,
    corto_object object);


/* class corto/lang/enum */

CORTO_EXPORT
corto_object _corto_enum_constant_from_id(
    corto_enum _this,
    const char *id);

CORTO_EXPORT
corto_object _corto_enum_constant_from_value(
    corto_enum _this,
    int32_t value);

CORTO_EXPORT
int16_t _corto_enum_construct(
    corto_enum _this);

CORTO_EXPORT
void _corto_enum_destruct(
    corto_enum _this);

CORTO_EXPORT
int16_t _corto_enum_init(
    corto_enum _this);


/* class corto/lang/float */

CORTO_EXPORT
int16_t _corto_float_init(
    corto_float _this);


/* procedure corto/lang/function */

CORTO_EXPORT
int16_t _corto_function_construct(
    corto_function _this);

CORTO_EXPORT
void _corto_function_destruct(
    corto_function _this);

CORTO_EXPORT
int16_t _corto_function_init(
    corto_function _this);

CORTO_EXPORT
int16_t _corto_function_parseParamString(
    corto_function _this,
    const char *params);

CORTO_EXPORT
corto_parameterseq _corto_function_stringToParameterSeq(
    const char *name,
    corto_object scope);


/* class corto/lang/int */

CORTO_EXPORT
int16_t _corto_int_init(
    corto_int _this);


/* class corto/lang/interface */

CORTO_EXPORT
int16_t _corto_interface_baseof(
    corto_interface _this,
    corto_interface type);

CORTO_EXPORT
int16_t _corto_interface_bindMethod(
    corto_interface _this,
    corto_method method);

CORTO_EXPORT
bool _corto_interface_compatible_v(
    corto_interface _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_interface_construct(
    corto_interface _this);

CORTO_EXPORT
void _corto_interface_deinit(
    corto_interface _this);

CORTO_EXPORT
void _corto_interface_destruct(
    corto_interface _this);

CORTO_EXPORT
int16_t _corto_interface_init(
    corto_interface _this);

CORTO_EXPORT
corto_member _corto_interface_resolveMember_v(
    corto_interface _this,
    const char *name);

CORTO_EXPORT
corto_member _corto_interface_resolveMemberByTag(
    corto_interface _this,
    corto_tag tag);

CORTO_EXPORT
corto_method _corto_interface_resolveMethod(
    corto_interface _this,
    const char *name);

CORTO_EXPORT
corto_method _corto_interface_resolveMethodById(
    corto_interface _this,
    uint32_t id);

CORTO_EXPORT
uint32_t _corto_interface_resolveMethodId(
    corto_interface _this,
    const char *name);


/* class corto/lang/iterator */

CORTO_EXPORT
bool _corto_iterator_castable_v(
    corto_iterator _this,
    corto_type type);

CORTO_EXPORT
bool _corto_iterator_compatible_v(
    corto_iterator _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_iterator_init(
    corto_iterator _this);


/* class corto/lang/list */

CORTO_EXPORT
int16_t _corto_list_construct(
    corto_list _this);

CORTO_EXPORT
int16_t _corto_list_init(
    corto_list _this);


/* class corto/lang/map */

CORTO_EXPORT
int16_t _corto_map_construct(
    corto_map _this);

CORTO_EXPORT
int16_t _corto_map_init(
    corto_map _this);


/* class corto/lang/member */

CORTO_EXPORT
int16_t _corto_member_construct(
    corto_member _this);

CORTO_EXPORT
int16_t _corto_member_init(
    corto_member _this);


/* procedure corto/lang/metaprocedure */

CORTO_EXPORT
int16_t _corto_metaprocedure_construct(
    corto_metaprocedure _this);


/* procedure corto/lang/overridable */

CORTO_EXPORT
int16_t _corto_overridable_init(
    corto_overridable _this);


/* class corto/lang/package */

CORTO_EXPORT
void _corto_package_define(
    corto_package _this);

CORTO_EXPORT
int16_t _corto_package_init(
    corto_package _this);


/* class corto/lang/primitive */

CORTO_EXPORT
bool _corto_primitive_castable_v(
    corto_primitive _this,
    corto_type type);

CORTO_EXPORT
bool _corto_primitive_compatible_v(
    corto_primitive _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_primitive_construct(
    corto_primitive _this);

CORTO_EXPORT
int16_t _corto_primitive_init(
    corto_primitive _this);

CORTO_EXPORT
bool _corto_primitive_isInteger(
    corto_primitive _this);

CORTO_EXPORT
bool _corto_primitive_isNumber(
    corto_primitive _this);


/* class corto/lang/procedure */

CORTO_EXPORT
int16_t _corto_procedure_construct(
    corto_procedure _this);

CORTO_EXPORT
int16_t _corto_procedure_init(
    corto_procedure _this);


/* class corto/lang/sequence */

CORTO_EXPORT
int16_t _corto_sequence_construct(
    corto_sequence _this);

CORTO_EXPORT
int16_t _corto_sequence_init(
    corto_sequence _this);


/* class corto/lang/struct */

CORTO_EXPORT
bool _corto_struct_castable_v(
    corto_struct _this,
    corto_type type);

CORTO_EXPORT
bool _corto_struct_compatible_v(
    corto_struct _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_struct_construct(
    corto_struct _this);

CORTO_EXPORT
int16_t _corto_struct_init(
    corto_struct _this);

CORTO_EXPORT
corto_member _corto_struct_resolveMember_v(
    corto_struct _this,
    const char *name);


/* class corto/lang/table */

CORTO_EXPORT
int16_t _corto_table_construct(
    corto_table _this);


/* class corto/lang/target */

CORTO_EXPORT
int16_t _corto_target_construct(
    corto_target _this);


/* class corto/lang/text */

CORTO_EXPORT
int16_t _corto_text_init(
    corto_text _this);


/* class corto/lang/type */

CORTO_EXPORT
uint16_t _corto_type_alignmentof(
    corto_type _this);

CORTO_EXPORT
bool _corto_type_castable_v(
    corto_type _this,
    corto_type type);

CORTO_EXPORT
bool _corto_type_compatible_v(
    corto_type _this,
    corto_type type);

CORTO_EXPORT
int16_t _corto_type_construct(
    corto_type _this);

CORTO_EXPORT
void _corto_type_deinit(
    corto_type _this);

CORTO_EXPORT
void _corto_type_destruct(
    corto_type _this);

CORTO_EXPORT
int16_t _corto_type_init(
    corto_type _this);

CORTO_EXPORT
corto_function _corto_type_resolveProcedure(
    corto_type _this,
    const char *name);

CORTO_EXPORT
uint32_t _corto_type_sizeof(
    corto_type _this);


/* class corto/lang/uint */

CORTO_EXPORT
int16_t _corto_uint_init(
    corto_uint _this);


/* class corto/lang/union */

CORTO_EXPORT
int16_t _corto_union_construct(
    corto_union _this);

CORTO_EXPORT
corto_member _corto_union_findCase(
    corto_union _this,
    int32_t discriminator);

CORTO_EXPORT
int16_t _corto_union_init(
    corto_union _this);


/* class corto/lang/unit */

CORTO_EXPORT
int16_t _corto_unit_construct(
    corto_unit _this);

CORTO_EXPORT
int16_t _corto_unit_init(
    corto_unit _this);


/* class corto/lang/verbatim */

CORTO_EXPORT
int16_t _corto_verbatim_init(
    corto_verbatim _this);

#ifdef __cplusplus
}
#endif

#endif

