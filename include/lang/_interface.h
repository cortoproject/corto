/* _interface.h
 *
 * This file contains generated package function and method declarations.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_LANG_INTERFACE_H
#define CORTO_LANG_INTERFACE_H

#include <corto/_project.h>


#ifdef __cplusplus
extern "C" {
#endif

/* -- Procudure declarations -- */


/* package corto/lang */



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

/* bool corto_collection_castable(corto_collection, corto_type) */
#define corto_collection_castable(_this, type) ( \
    ((corto_function)corto_collection_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_castable_o)->index - 1])->fptr)(corto_collection(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_castable_o)->index - 1], alloca(sizeof(bool)), corto_collection(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_collection_compatible_v(
    corto_collection _this,
    corto_type type);

/* bool corto_collection_compatible(corto_collection, corto_type) */
#define corto_collection_compatible(_this, type) ( \
    ((corto_function)corto_collection_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_compatible_o)->index - 1])->fptr)(corto_collection(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_collection_compatible_o)->index - 1], alloca(sizeof(bool)), corto_collection(_this), corto_type(type)) \
    )

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

/* bool corto_delegate_castable(corto_delegate, corto_type) */
#define corto_delegate_castable(_this, type) ( \
    ((corto_function)corto_delegate_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_castable_o)->index - 1])->fptr)(corto_delegate(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_castable_o)->index - 1], alloca(sizeof(bool)), corto_delegate(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_delegate_compatible_v(
    corto_delegate _this,
    corto_type type);

/* bool corto_delegate_compatible(corto_delegate, corto_type) */
#define corto_delegate_compatible(_this, type) ( \
    ((corto_function)corto_delegate_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_compatible_o)->index - 1])->fptr)(corto_delegate(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_delegate_compatible_o)->index - 1], alloca(sizeof(bool)), corto_delegate(_this), corto_type(type)) \
    )

CORTO_EXPORT
int16_t _corto_delegate_init(
    corto_delegate _this);

CORTO_EXPORT
bool _corto_delegate_instanceof(
    corto_delegate _this,
    corto_object object);


/* class corto/lang/enum */

CORTO_EXPORT
corto_object _corto_enum_constant(
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

/* bool corto_interface_compatible(corto_interface, corto_type) */
#define corto_interface_compatible(_this, type) ( \
    ((corto_function)corto_interface_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_compatible_o)->index - 1])->fptr)(corto_interface(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_compatible_o)->index - 1], alloca(sizeof(bool)), corto_interface(_this), corto_type(type)) \
    )

CORTO_EXPORT
int16_t _corto_interface_construct(
    corto_interface _this);

CORTO_EXPORT
void _corto_interface_destruct(
    corto_interface _this);

CORTO_EXPORT
int16_t _corto_interface_init(
    corto_interface _this);

CORTO_EXPORT
    void _corto_interface_deinit(
        corto_interface _this);

CORTO_EXPORT
corto_member _corto_interface_resolveMember_v(
    corto_interface _this,
    const char *name);

/* corto_member corto_interface_resolveMember(corto_interface, const char *) */
#define corto_interface_resolveMember(_this, name) ( \
    ((corto_function)corto_interface_resolveMember_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_member (*)(corto_object, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_resolveMember_o)->index - 1])->fptr)(corto_interface(_this), name) \
    : *(corto_member*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_interface_resolveMember_o)->index - 1], alloca(sizeof(corto_member)), corto_interface(_this), name) \
    )

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

/* bool corto_iterator_castable(corto_iterator, corto_type) */
#define corto_iterator_castable(_this, type) ( \
    ((corto_function)corto_iterator_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_castable_o)->index - 1])->fptr)(corto_iterator(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_castable_o)->index - 1], alloca(sizeof(bool)), corto_iterator(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_iterator_compatible_v(
    corto_iterator _this,
    corto_type type);

/* bool corto_iterator_compatible(corto_iterator, corto_type) */
#define corto_iterator_compatible(_this, type) ( \
    ((corto_function)corto_iterator_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_compatible_o)->index - 1])->fptr)(corto_iterator(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_iterator_compatible_o)->index - 1], alloca(sizeof(bool)), corto_iterator(_this), corto_type(type)) \
    )

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

/* bool corto_primitive_castable(corto_primitive, corto_type) */
#define corto_primitive_castable(_this, type) ( \
    ((corto_function)corto_primitive_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_castable_o)->index - 1])->fptr)(corto_primitive(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_castable_o)->index - 1], alloca(sizeof(bool)), corto_primitive(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_primitive_compatible_v(
    corto_primitive _this,
    corto_type type);

/* bool corto_primitive_compatible(corto_primitive, corto_type) */
#define corto_primitive_compatible(_this, type) ( \
    ((corto_function)corto_primitive_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_compatible_o)->index - 1])->fptr)(corto_primitive(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_primitive_compatible_o)->index - 1], alloca(sizeof(bool)), corto_primitive(_this), corto_type(type)) \
    )

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

/* bool corto_struct_castable(corto_struct, corto_type) */
#define corto_struct_castable(_this, type) ( \
    ((corto_function)corto_struct_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_castable_o)->index - 1])->fptr)(corto_struct(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_castable_o)->index - 1], alloca(sizeof(bool)), corto_struct(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_struct_compatible_v(
    corto_struct _this,
    corto_type type);

/* bool corto_struct_compatible(corto_struct, corto_type) */
#define corto_struct_compatible(_this, type) ( \
    ((corto_function)corto_struct_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_compatible_o)->index - 1])->fptr)(corto_struct(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_compatible_o)->index - 1], alloca(sizeof(bool)), corto_struct(_this), corto_type(type)) \
    )

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

/* corto_member corto_struct_resolveMember(corto_struct, const char *) */
#define corto_struct_resolveMember(_this, name) ( \
    ((corto_function)corto_struct_resolveMember_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_member (*)(corto_object, const char *))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_resolveMember_o)->index - 1])->fptr)(corto_struct(_this), name) \
    : *(corto_member*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_struct_resolveMember_o)->index - 1], alloca(sizeof(corto_member)), corto_struct(_this), name) \
    )


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

/* bool corto_type_castable(corto_type, corto_type) */
#define corto_type_castable(_this, type) ( \
    ((corto_function)corto_type_castable_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_castable_o)->index - 1])->fptr)(corto_type(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_castable_o)->index - 1], alloca(sizeof(bool)), corto_type(_this), corto_type(type)) \
    )

CORTO_EXPORT
bool _corto_type_compatible_v(
    corto_type _this,
    corto_type type);

/* bool corto_type_compatible(corto_type, corto_type) */
#define corto_type_compatible(_this, type) ( \
    ((corto_function)corto_type_compatible_o)->kind == CORTO_PROCEDURE_CDECL \
    ? ((_type_corto_bool (*)(corto_object, corto_type))((corto_function)((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_compatible_o)->index - 1])->fptr)(corto_type(_this), corto_type(type)) \
    : *(bool*)corto_invoke(((corto_interface)corto_typeof(_this))->methods.buffer[((corto_method)corto_type_compatible_o)->index - 1], alloca(sizeof(bool)), corto_type(_this), corto_type(type)) \
    )

CORTO_EXPORT
int16_t _corto_type_construct(
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

/* -- Support macro's -- */
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
#define corto_collection_requiresAlloc(elementType) _corto_collection_requiresAlloc(corto_type(elementType))
#define corto_constant_init(_this) _corto_constant_init(_this)
#define corto_container_construct(_this) _corto_container_construct(corto_container(_this))
#define corto_delegate_bind(object) _corto_delegate_bind(corto_function(object))
#define corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
#define corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))
#define corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))
#define corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)
#define corto_enum_constant(_this, value) _corto_enum_constant(corto_enum(_this), value)
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
#define corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))
#define corto_interface_deinit(_this) _corto_interface_deinit(corto_interface(_this))
#define corto_interface_init(_this) _corto_interface_init(corto_interface(_this))
#define corto_interface_resolveMember_v(_this, name) _corto_interface_resolveMember_v(corto_interface(_this), name)
#define corto_interface_resolveMemberByTag(_this, tag) _corto_interface_resolveMemberByTag(corto_interface(_this), corto_tag(tag))
#define corto_interface_resolveMethod(_this, name) _corto_interface_resolveMethod(corto_interface(_this), name)
#define corto_interface_resolveMethodById(_this, id) _corto_interface_resolveMethodById(corto_interface(_this), id)
#define corto_interface_resolveMethodId(_this, name) _corto_interface_resolveMethodId(corto_interface(_this), name)
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
#define corto_struct_resolveMember_v(_this, name) _corto_struct_resolveMember_v(corto_struct(_this), name)
#define corto_table_construct(_this) _corto_table_construct(corto_table(_this))
#define corto_target_construct(_this) _corto_target_construct(corto_target(_this))
#define corto_text_init(_this) _corto_text_init(corto_text(_this))
#define corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
#define corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
#define corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))
#define corto_type_construct(_this) _corto_type_construct(corto_type(_this))
#define corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))
#define corto_type_init(_this) _corto_type_init(corto_type(_this))
#define corto_type_resolveProcedure(_this, name) _corto_type_resolveProcedure(corto_type(_this), name)
#define corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))
#define corto_uint_init(_this) _corto_uint_init(corto_uint(_this))
#define corto_union_construct(_this) _corto_union_construct(corto_union(_this))
#define corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)
#define corto_union_init(_this) _corto_union_init(corto_union(_this))
#define corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
#define corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
#define corto_verbatim_init(_this) _corto_verbatim_init(corto_verbatim(_this))
#else
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
#define corto_collection_requiresAlloc _corto_collection_requiresAlloc
#define corto_constant_init _corto_constant_init
#define corto_container_construct _corto_container_construct
#define corto_delegate_bind _corto_delegate_bind
#define corto_delegate_castable_v _corto_delegate_castable_v
#define corto_delegate_compatible_v _corto_delegate_compatible_v
#define corto_delegate_init _corto_delegate_init
#define corto_delegate_instanceof _corto_delegate_instanceof
#define corto_enum_constant _corto_enum_constant
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
#define corto_interface_destruct _corto_interface_destruct
#define corto_interface_deinit _corto_interface_deinit
#define corto_interface_init _corto_interface_init
#define corto_interface_resolveMember_v _corto_interface_resolveMember_v
#define corto_interface_resolveMemberByTag _corto_interface_resolveMemberByTag
#define corto_interface_resolveMethod _corto_interface_resolveMethod
#define corto_interface_resolveMethodById _corto_interface_resolveMethodById
#define corto_interface_resolveMethodId _corto_interface_resolveMethodId
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
#define corto_struct_resolveMember_v _corto_struct_resolveMember_v
#define corto_table_construct _corto_table_construct
#define corto_target_construct _corto_target_construct
#define corto_text_init _corto_text_init
#define corto_type_alignmentof _corto_type_alignmentof
#define corto_type_castable_v _corto_type_castable_v
#define corto_type_compatible_v _corto_type_compatible_v
#define corto_type_construct _corto_type_construct
#define corto_type_destruct _corto_type_destruct
#define corto_type_init _corto_type_init
#define corto_type_resolveProcedure _corto_type_resolveProcedure
#define corto_type_sizeof _corto_type_sizeof
#define corto_uint_init _corto_uint_init
#define corto_union_construct _corto_union_construct
#define corto_union_findCase _corto_union_findCase
#define corto_union_init _corto_union_init
#define corto_unit_construct _corto_unit_construct
#define corto_unit_init _corto_unit_init
#define corto_verbatim_init _corto_verbatim_init
#ifndef __cplusplus
#endif
#endif
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
#define safe_corto_collection_requiresAlloc(elementType) _corto_collection_requiresAlloc(corto_type(elementType))
#define safe_corto_constant_init(_this) _corto_constant_init(_this)
#define safe_corto_container_construct(_this) _corto_container_construct(corto_container(_this))
#define safe_corto_delegate_bind(object) _corto_delegate_bind(corto_function(object))
#define safe_corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
#define safe_corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))
#define safe_corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))
#define safe_corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)
#define safe_corto_enum_constant(_this, value) _corto_enum_constant(corto_enum(_this), value)
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
#define safe_corto_interface_destruct(_this) _corto_interface_destruct(corto_interface(_this))
#define safe_corto_interface_deinit(_this) _corto_interface_deinit(corto_interface(_this))
#define safe_corto_interface_init(_this) _corto_interface_init(corto_interface(_this))
#define safe_corto_interface_resolveMember_v(_this, name) _corto_interface_resolveMember_v(corto_interface(_this), name)
#define safe_corto_interface_resolveMemberByTag(_this, tag) _corto_interface_resolveMemberByTag(corto_interface(_this), corto_tag(tag))
#define safe_corto_interface_resolveMethod(_this, name) _corto_interface_resolveMethod(corto_interface(_this), name)
#define safe_corto_interface_resolveMethodById(_this, id) _corto_interface_resolveMethodById(corto_interface(_this), id)
#define safe_corto_interface_resolveMethodId(_this, name) _corto_interface_resolveMethodId(corto_interface(_this), name)
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
#define safe_corto_struct_resolveMember_v(_this, name) _corto_struct_resolveMember_v(corto_struct(_this), name)
#define safe_corto_table_construct(_this) _corto_table_construct(corto_table(_this))
#define safe_corto_target_construct(_this) _corto_target_construct(corto_target(_this))
#define safe_corto_text_init(_this) _corto_text_init(corto_text(_this))
#define safe_corto_type_alignmentof(_this) _corto_type_alignmentof(corto_type(_this))
#define safe_corto_type_castable_v(_this, type) _corto_type_castable_v(corto_type(_this), corto_type(type))
#define safe_corto_type_compatible_v(_this, type) _corto_type_compatible_v(corto_type(_this), corto_type(type))
#define safe_corto_type_construct(_this) _corto_type_construct(corto_type(_this))
#define safe_corto_type_destruct(_this) _corto_type_destruct(corto_type(_this))
#define safe_corto_type_init(_this) _corto_type_init(corto_type(_this))
#define safe_corto_type_resolveProcedure(_this, name) _corto_type_resolveProcedure(corto_type(_this), name)
#define safe_corto_type_sizeof(_this) _corto_type_sizeof(corto_type(_this))
#define safe_corto_uint_init(_this) _corto_uint_init(corto_uint(_this))
#define safe_corto_union_construct(_this) _corto_union_construct(corto_union(_this))
#define safe_corto_union_findCase(_this, discriminator) _corto_union_findCase(corto_union(_this), discriminator)
#define safe_corto_union_init(_this) _corto_union_init(corto_union(_this))
#define safe_corto_unit_construct(_this) _corto_unit_construct(corto_unit(_this))
#define safe_corto_unit_init(_this) _corto_unit_init(corto_unit(_this))
#define safe_corto_verbatim_init(_this) _corto_verbatim_init(corto_verbatim(_this))

#ifdef __cplusplus
}
#endif

#endif
