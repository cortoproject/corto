/*
 * corto_bootstrap.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CORTO_BOOTSTRAP_H_
#define CORTO_BOOTSTRAP_H_

#include "corto/corto.h"
#include "_object.h"
#include "_equals.h"

/* Keep include local because of clashing macro's with other libraries (yacc) */
#ifdef __MACH__
#include "ffi/ffi.h"
#else
#include "ffi.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_UINT8  (0xFF)
#define MAX_UINT16 (0xFFFF)
#define MAX_UINT32 (0xFFFFFFFF)
#define MAX_UINT64 (0xFFFFFFFFFFFFFFFF)
#define MAX_INT8  ((MAX_UINT8/2))
#define MAX_INT16 ((MAX_UINT16/2))
#define MAX_INT32 ((MAX_UINT32/2))
#define MAX_INT64 ((MAX_UINT64/2))
#define MIN_INT8  (-(MAX_UINT8/2+1))
#define MIN_INT16 (-(MAX_UINT16/2+1))
#define MIN_INT32 (-(MAX_UINT32/2+1))
#define MIN_INT64 (-(MAX_UINT64/2+1))

#define CORTO_STATIC_SCOPED_OBJECT(type)\
typedef struct sso_##type {\
    corto_SSO o;\
    corto_##type v;\
}sso_##type

#define CORTO_STATIC_SCOPED_REFOBJECT(type)\
typedef struct sso_##type {\
    corto_SSO o;\
    struct corto_##type##_s v;\
}sso_##type

/* Static Scoped Object */
typedef struct corto_SSO {
    corto__scope s;
    corto__object o;
}corto_SSO;

/* Static Scoped Observable Object */
typedef struct corto_SSOO {
    corto__scope s;
    corto__observable v;
    corto__object o;
}corto_SSOO;

/* Static Scoped Observable Object (used for scopes) */
typedef struct corto_ssoo_package {
    corto_SSOO o;
    struct corto_package_s v;\
}corto_ssoo_package;

CORTO_STATIC_SCOPED_REFOBJECT(delegate);
CORTO_STATIC_SCOPED_REFOBJECT(type);
CORTO_STATIC_SCOPED_REFOBJECT(primitive);
CORTO_STATIC_SCOPED_REFOBJECT(collection);
CORTO_STATIC_SCOPED_REFOBJECT(procedure);
CORTO_STATIC_SCOPED_REFOBJECT(binary);
CORTO_STATIC_SCOPED_REFOBJECT(boolean);
CORTO_STATIC_SCOPED_REFOBJECT(character);
CORTO_STATIC_SCOPED_REFOBJECT(int);
CORTO_STATIC_SCOPED_REFOBJECT(uint);
CORTO_STATIC_SCOPED_REFOBJECT(float);
CORTO_STATIC_SCOPED_REFOBJECT(text);
CORTO_STATIC_SCOPED_REFOBJECT(enum);
CORTO_STATIC_SCOPED_REFOBJECT(bitmask);
CORTO_STATIC_SCOPED_REFOBJECT(interface);
CORTO_STATIC_SCOPED_REFOBJECT(struct);
CORTO_STATIC_SCOPED_REFOBJECT(class);
CORTO_STATIC_SCOPED_REFOBJECT(array);
CORTO_STATIC_SCOPED_REFOBJECT(sequence);
CORTO_STATIC_SCOPED_REFOBJECT(list);
CORTO_STATIC_SCOPED_REFOBJECT(map);
CORTO_STATIC_SCOPED_REFOBJECT(function);
CORTO_STATIC_SCOPED_REFOBJECT(method);
CORTO_STATIC_SCOPED_REFOBJECT(observer);
CORTO_STATIC_SCOPED_REFOBJECT(subscriber);
CORTO_STATIC_SCOPED_REFOBJECT(metaprocedure);
CORTO_STATIC_SCOPED_REFOBJECT(member);
CORTO_STATIC_SCOPED_REFOBJECT(alias);
CORTO_STATIC_SCOPED_REFOBJECT(iterator);
CORTO_STATIC_SCOPED_OBJECT(parameter);

CORTO_STATIC_SCOPED_OBJECT(constant);

#define CORTO_FWDECL_SSO(type, name) sso_##type name##__o
#define CORTO_FWDECL(type, name) CORTO_FWDECL_SSO(type, lang_##name); corto_##type corto_##name##_o = &lang_##name##__o.v
#define CORTO_FWDECL_CORE(type, name) CORTO_FWDECL_SSO(type, core_##name); corto_##type corto_##name##_o = &core_##name##__o.v
#define CORTO_FWDECL_NATIVE(type, name) CORTO_FWDECL_SSO(type, native_##name); corto_##type corto_native_##name##_o = &native_##name##__o.v
#define CORTO_FWDECL_SECURE(type, name) CORTO_FWDECL_SSO(type, secure_##name); corto_##type corto_secure_##name##_o = &secure_##name##__o.v

/* SSO */
#ifndef NDEBUG
#define CORTO_ADD_MAGIC ,CORTO_MAGIC
#else
#define CORTO_ADD_MAGIC
#endif
#define CORTO_ATTR_SSOO {{1, 0, 1, 0, CORTO_VALID | CORTO_DECLARED}}
#define CORTO_ATTR_SSO {{1, 0, 0, 0, CORTO_VALID | CORTO_DECLARED}}
#define CORTO_ATTR_SO {{0, 0, 0, 0, CORTO_VALID | CORTO_DECLARED}}
#define CORTO_ROOT_V() {{NULL, NULL, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}, _(extensions)NULL},{NULL,NULL,{CORTO_RWMUTEX_INITIALIZER},NULL,NULL},{CORTO_ATTR_SSOO CORTO_ADD_MAGIC, 2, (corto_type)&core_package__o.v}}
#define CORTO_PACKAGE_V(parent, name, uri) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}, _(extensions)NULL},{NULL,NULL,{CORTO_RWMUTEX_INITIALIZER},NULL,NULL},{CORTO_ATTR_SSOO CORTO_ADD_MAGIC, 2, (corto_type)&core_package__o.v}}, {uri}
#define CORTO_SSO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}, _(extensions)NULL},{CORTO_ATTR_SSO CORTO_ADD_MAGIC, 2, (corto_type)&type##__o.v}}
#define CORTO_SSO_PO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}, _(extensions)NULL},{CORTO_ATTR_SSO CORTO_ADD_MAGIC, 2, (corto_type)&type##__o.v}}

/* SSO identifier */
#define CORTO_ID(name) name##__o
#define CORTO_TYPE_ID(name) (corto_type)&CORTO_ID(name).v

/* Forward declarations of delegates */
#define CORTO_FW_I(parent, name) sso_method CORTO_ID(parent##_##name##_init_)
#define CORTO_FW_C(parent, name) sso_method CORTO_ID(parent##_##name##_construct_)
#define CORTO_FW_IC(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_)
#define CORTO_FW_ICD(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)
#define CORTO_FW_CD(parent, name) sso_method CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)

/* Delegate assignments */
#define CORTO_DELEGATE(name, delegate) {{NULL, (corto_function)&CORTO_ID(name##_##delegate##_).v}}
#define CORTO_INIT(name) CORTO_DELEGATE(name, init)
#define CORTO_CONSTRUCT(name) CORTO_DELEGATE(name, construct)
#define CORTO_BIND(name) CORTO_DELEGATE(name, construct)
#define CORTO_DESTRUCT(name) CORTO_DELEGATE(name, destruct)

#define CORTO_I_TYPE(name) CORTO_INIT(name)
#define CORTO_I_CLASS(name) {{NULL, NULL}}, {{NULL, NULL}}
#define CORTO_I_PROC(name) {{NULL, NULL}}

#define CORTO_B_TYPE(name) {{NULL, NULL}}
#define CORTO_B_PROC(name) CORTO_BIND(name)

#define CORTO_C_TYPE(name)
#define CORTO_C_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}

#define CORTO_IC_TYPE(name) CORTO_INIT(name)
#define CORTO_IC_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}
#define CORTO_IC_PROC(name) CORTO_BIND(name)

#define CORTO_ICD_TYPE(name) CORTO_INIT(name)
#define CORTO_ICD_CLASS(name) CORTO_CONSTRUCT(name), CORTO_DESTRUCT(name)

#define CORTO_CD_TYPE(name)
#define CORTO_CD_CLASS(name) CORTO_CONSTRUCT(name), CORTO_DESTRUCT(name)
#define CORTO_CD_PROC(name)

#define CORTO_NODELEGATE_TYPE(name) {{NULL, NULL}}
#define CORTO_NODELEGATE_CLASS(name) {{NULL, NULL}}, {{NULL, NULL}}
#define CORTO_NODELEGATE_PROC(name) {{NULL, NULL}}

/* type */
#define CORTO_TYPE_V(parent, name, kind, reference, attr, scopeType, scopeTypeKind, defaultType, defaultProcedureType, DELEGATE) \
  {kind, reference, attr, {scopeType, scopeTypeKind, defaultType, defaultProcedureType}, FALSE, FALSE, 0, 0, {0,NULL}, DELEGATE##_TYPE(parent##_##name)}

/* primitive */
#define CORTO_PRIMITIVE_V(parent, name, kind, width, scopeType, scopeStateKind, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_PRIMITIVE, FALSE, CORTO_ATTR_DEFAULT, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, width, 0}

/* interface */
#define CORTO_COMPOSITE_V(parent, name, kind, base, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_COMPOSITE, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, (corto_interface)&base##__o.v}

/* interface */
#define CORTO_COMPOSITE_NOBASE_V(parent, name, kind, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_COMPOSITE, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, NULL}

/* struct */
#define CORTO_STRUCT_V(parent, name, kind, base, baseAccess, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_V(parent, name, kind, base, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), baseAccess}

#define CORTO_STRUCT_NOBASE_V(parent, name, kind, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_NOBASE_V(parent, name, kind, reference, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), CORTO_LOCAL}

/* collection */
#define CORTO_COLLECTION_V(parent, name, kind, elementType, max) \
    {CORTO_TYPE_V(parent, name, CORTO_COLLECTION, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), kind, (corto_type)&elementType##__o.v, max}

/* sequence */
#define CORTO_SEQUENCE_V(subType, length, ...) {length, (subType[]){__VA_ARGS__}}
#define CORTO_SEQUENCE_EMPTY_V(subType) {0, NULL}

/* member */
#define CORTO_MEMBER_V(type, access, state, cond, weak) {(corto_type)&type##__o.v, access, NULL, state, cond, weak, 0, 0}

/* object */
#define CORTO_PACKAGE_O(name, uri) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(root, #name, uri)}
#define CORTO_PACKAGE_O_SCOPE(parent, name, uri) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(parent, #name, uri)}

/* type object */
#define CORTO_TYPE_O(parent, name, kind, reference)\
    static sso_type parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_type), CORTO_TYPE_V(parent, name, kind, reference, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE)}

/* primitive object */
#define CORTO_PRIMITIVE_O(parent, name, kind, width)\
    sso_primitive parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_primitive), CORTO_PRIMITIVE_V(parent, name, kind, width, CORTO_NODELEGATE)}

/* binary object */
#define CORTO_BINARY_O(parent, name, width)\
    sso_binary parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_binary), {CORTO_PRIMITIVE_V(parent, name, CORTO_BINARY, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}}

/* boolean object */
#define CORTO_BOOLEAN_O(parent, name)\
    sso_boolean parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_boolean), {CORTO_PRIMITIVE_V(parent, name, CORTO_BOOLEAN, CORTO_WIDTH_8, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}}

/* character object */
#define CORTO_CHARACTER_O(parent, name, width)\
    sso_character parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_character), {CORTO_PRIMITIVE_V(parent, name, CORTO_CHARACTER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}}

/* int object */
#define CORTO_INT_O(parent, name, width, min, max, scopeType, scopeStateKind, DELEGATE)\
    sso_int parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_int), {CORTO_PRIMITIVE_V(parent, name, CORTO_INTEGER, width, scopeType, scopeStateKind, DELEGATE), min, max}}

/* uint object */
#define CORTO_UINT_O(parent, name, width, min, max)\
    sso_uint parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_uint), {CORTO_PRIMITIVE_V(parent, name, CORTO_UINTEGER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}}

/* float object */
#define CORTO_FLOAT_O(parent, name, width, min, max)\
    sso_float parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_float), {CORTO_PRIMITIVE_V(parent, name, CORTO_FLOAT, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}}

/* text object */
#define CORTO_TEXT_O(parent, name, width, length)\
    sso_text parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_text), {CORTO_PRIMITIVE_V(parent, name, CORTO_TEXT, CORTO_WIDTH_WORD, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), width, length}}

/* enum object */
#define CORTO_ENUM_O(parent, name)\
    sso_enum parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_enum), {CORTO_PRIMITIVE_V(parent, name, CORTO_ENUM, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}

/* bitmask object */
#define CORTO_BITMASK_O(parent, name)\
    sso_bitmask parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_bitmask), {{CORTO_PRIMITIVE_V(parent, name, CORTO_BITMASK, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}}

/* constant object */
#define CORTO_CONSTANT_O(parent, name)\
    sso_constant parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name, lang_constant), CORTO_##name}

/* constant object in secure scope */
#define CORTO_SECURE_CONSTANT_O(parent, name)\
    sso_constant parent##_SECURE_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name, lang_constant), CORTO_SECURE_##name}

/* struct object */
#define CORTO_STRUCT_O(parent, name, scopeType, scopeStateKind, defaultType, defaultProcedureType)\
    sso_struct parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_struct), CORTO_STRUCT_NOBASE_V(parent, name, CORTO_STRUCT, FALSE, CORTO_ATTR_DEFAULT, scopeType, scopeStateKind, defaultType, defaultProcedureType, CORTO_NODELEGATE)}

/* interface object */
#define CORTO_INTERFACE_O(parent, name)\
    sso_interface parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_interface), CORTO_COMPOSITE_NOBASE_V(parent, name, CORTO_INTERFACE, TRUE, CORTO_ATTR_DEFAULT, NULL, 0, NULL, CORTO_TYPE_ID(lang_method), CORTO_NODELEGATE)}

/* class object */
#define CORTO_CLASS_NOBASE_O(parent, name, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE)\
    sso_class parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_CLASS, TRUE, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}}

#define CORTO_CLASS_O(parent, name, base, baseAccess, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE)\
    sso_class parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_V(parent, name, CORTO_CLASS, base, baseAccess, TRUE, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}}

#define CORTO_CLASS_IMPLEMENTS_O(parent, name, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, interface, DELEGATE)\
    sso_class parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_CLASS, TRUE, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {1,{interface}}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}}

/* array object */
#define CORTO_ARRAY_O(parent, name, elementType, size)\
    sso_array parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_array), {CORTO_COLLECTION_V(parent, name, CORTO_ARRAY, elementType, size)}}

/* sequence object */
#define CORTO_SEQUENCE_O(parent, name, elementType, max)\
    sso_sequence parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_sequence), {CORTO_COLLECTION_V(parent, name, CORTO_SEQUENCE, elementType, max)}}

/* list object */
#define CORTO_LIST_O(parent, name, elementType, max)\
    sso_list parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_list), {CORTO_COLLECTION_V(parent, name, CORTO_LIST, elementType, max)}}

/* map object */
#define CORTO_MAP_O(parent, name, elementType, keyType, max)\
    sso_map parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_map), {CORTO_COLLECTION_V(parent, name, CORTO_MAP, elementType, max), (corto_type)&keyType##__o.v}}

/* procedure object */
#define CORTO_PROCEDURE_NOBASE_O(parent, name, hasThis, thisType, scopeType, scopeStateKind, DELEGATE) \
    sso_procedure parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_procedure), {{CORTO_STRUCT_NOBASE_V(parent, name, CORTO_PROCEDURE, TRUE, CORTO_ATTR_DEFAULT, scopeType, scopeStateKind, NULL, NULL, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}, hasThis, thisType}}

#define CORTO_PROCEDURE_O(parent, name, hasThis, thisType, base, baseAccess, scopeType, scopeStateKind, DELEGATE) \
    sso_procedure parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_procedure), {{CORTO_STRUCT_V(parent, name, CORTO_PROCEDURE, base, baseAccess, TRUE, CORTO_ATTR_DEFAULT, scopeType, scopeStateKind, NULL, NULL, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}, hasThis, thisType}}

/* function object */
#define CORTO_FUNCTION_O(parent, name, args, returnType, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_function parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name args, lang_function), {(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}}

#define CORTO_FUNCTION_OO_O(parent, name, args, returnType, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_function parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name args, lang_function), {(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}}

#define CORTO_FUNCTION_OVERLOAD_OO_O(parent, name, args, returnType, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_function parent##_##name##__o = \
    {CORTO_SSO_V(parent, args, lang_function), {(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}}

/* method object */
#define CORTO_METHOD_O(parent, name, args, returnType, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_method parent##_##name##___o = \
    {CORTO_SSO_PO_V(parent, #name args, lang_method), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}}}

/* overridable method */
#define CORTO_OVERRIDABLE_O(parent, name, args, returnType, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_method parent##_##name##___o = \
    {CORTO_SSO_PO_V(parent, #name args, lang_overridable), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}}}

/* interface method object */
#define CORTO_IMETHOD_O(parent, name, args, returnType, overridable) \
    sso_method parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name args, lang_method), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, overridable, FALSE, CORTO_PROCEDURE_CDECL, 0, 0, 0}}}

/* observer object */
#define CORTO_OBSERVER_O(parent, name, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_observer parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, core_observer), {{(corto_type)&lang_void##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, 0}}

/* subscriber object */
#define CORTO_SUBSCRIBER_O(parent, name, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_subscriber parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, core_subscriber), {{{(corto_type)&lang_void##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, 0}}}

/* metaprocedure object */
#define CORTO_METAPROCEDURE_O(parent, name, args, returnType, referenceOnly, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, lang_metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, referenceOnly}}

#define CORTO_METAPROCEDURE_NAME_O(parent, name, actualName, args, returnType, referenceOnly, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #actualName args, lang_metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, referenceOnly}}

/* member object */
#define CORTO_MEMBER_O(parent, name, type, access) \
    sso_member parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name, lang_member), CORTO_MEMBER_V(type, access, CORTO_DECLARED | CORTO_DEFINED, NULL, FALSE)}

/* member object */
#define CORTO_ALIAS_O(parent, name, member, access) \
    sso_alias parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name, lang_alias), {CORTO_MEMBER_V(lang_word, access, 0, NULL, FALSE), (corto_member)&member##__o.v}}

/* reference object */
#define CORTO_REFERENCE_O(parent, name, type, access, state, cond, weak) \
    sso_member parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name, lang_member), CORTO_MEMBER_V(type, access, state, cond, weak)}

/* Delegate type */
#define CORTO_DELEGATE_O(parent, name, returnType) \
    sso_delegate parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_delegate), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_DELEGATE, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED|CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), (corto_type)&returnType##__o.v, FALSE, CORTO_SEQUENCE_EMPTY_V(parameter)}}

#define CORTO_ITERATOR_O(parent, name, elementType) \
    sso_iterator parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_iterator), {CORTO_TYPE_V(parent, name, CORTO_ITERATOR, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), (corto_type)&elementType##__o.v}}


/* Forward declarations of classes */
CORTO_FWDECL(class, alias);
CORTO_FWDECL_CORE(class, application);
CORTO_FWDECL(class, array);
CORTO_FWDECL(class, binary);
CORTO_FWDECL(class, bitmask);
CORTO_FWDECL(class, boolean);
CORTO_FWDECL(class, case);
CORTO_FWDECL(class, class);
CORTO_FWDECL(class, container);
CORTO_FWDECL(class, default);
CORTO_FWDECL(class, delegate);
CORTO_FWDECL(class, target);
CORTO_FWDECL_CORE(class, event);
CORTO_FWDECL(class, character);
CORTO_FWDECL(class, collection);
CORTO_FWDECL(class, enum);
CORTO_FWDECL(class, int);
CORTO_FWDECL(class, float);
CORTO_FWDECL(class, interface);
CORTO_FWDECL_CORE(class, invokeEvent);
CORTO_FWDECL(class, iterator);
CORTO_FWDECL_SECURE(class, key);
CORTO_FWDECL(class, leaf);
CORTO_FWDECL(class, list);
CORTO_FWDECL_CORE(class, loader);
CORTO_FWDECL_SECURE(class, lock);
CORTO_FWDECL(class, map);
CORTO_FWDECL(class, member);
CORTO_FWDECL_CORE(class, mount);
CORTO_FWDECL_CORE(class, notifyEvent);
CORTO_FWDECL_CORE(class, observableEvent);
CORTO_FWDECL_CORE(class, package);
CORTO_FWDECL(class, primitive);
CORTO_FWDECL(class, procedure);
CORTO_FWDECL(class, quantity);
CORTO_FWDECL_CORE(class, router);
CORTO_FWDECL_CORE(class, routerimpl);
CORTO_FWDECL_CORE(class, stager);
CORTO_FWDECL_CORE(class, subscriberEvent);
CORTO_FWDECL(class, table);
CORTO_FWDECL(class, tablescope);
CORTO_FWDECL(class, unit);

CORTO_FWDECL(class, sequence);
CORTO_FWDECL(class, struct);
CORTO_FWDECL(class, union);
CORTO_FWDECL(class, text);
CORTO_FWDECL(class, type);
CORTO_FWDECL(class, uint);
CORTO_FWDECL_NATIVE(class, type);

CORTO_FWDECL(struct, delegatedata);
CORTO_FWDECL(struct, interfaceVector);
CORTO_FWDECL(struct, parameter);
CORTO_FWDECL(struct, typeOptions);
CORTO_FWDECL_CORE(struct, augmentData);
CORTO_FWDECL_CORE(struct, frame);
CORTO_FWDECL_CORE(struct, mountStats);
CORTO_FWDECL_CORE(struct, mountPolicy);
CORTO_FWDECL_CORE(struct, mountSubscription);
CORTO_FWDECL_CORE(struct, result);
CORTO_FWDECL_CORE(struct, request);
CORTO_FWDECL_CORE(struct, sample);

/* Abstract classes */
CORTO_FWDECL_CORE(interface, dispatcher);

CORTO_FWDECL(binary, octet);
CORTO_FWDECL(binary, word);
CORTO_FWDECL(boolean, bool);
CORTO_FWDECL(character, char);
CORTO_FWDECL(float, float32);
CORTO_FWDECL(float, float64);
CORTO_FWDECL(int, int8);
CORTO_FWDECL(int, int16);
CORTO_FWDECL(int, int32);
CORTO_FWDECL(int, int64);
CORTO_FWDECL(int, constant);
CORTO_FWDECL(uint, uint8);
CORTO_FWDECL(uint, uint16);
CORTO_FWDECL(uint, uint32);
CORTO_FWDECL(uint, uint64);
CORTO_FWDECL(text, string);

static CORTO_FWDECL(type, any);
static CORTO_FWDECL(type, object);
static CORTO_FWDECL(type, void);

CORTO_FWDECL(procedure, function);
CORTO_FWDECL(procedure, metaprocedure);
CORTO_FWDECL(procedure, method);
CORTO_FWDECL_CORE(procedure, remote);
CORTO_FWDECL_CORE(procedure, observer);
CORTO_FWDECL_CORE(procedure, subscriber);
CORTO_FWDECL_CORE(procedure, route);
CORTO_FWDECL(procedure, override);
CORTO_FWDECL(procedure, overridable);

CORTO_FWDECL(enum, collectionKind);
CORTO_FWDECL(enum, compositeKind);
CORTO_FWDECL(enum, equalityKind);
CORTO_FWDECL(enum, inout);
CORTO_FWDECL(enum, primitiveKind);
CORTO_FWDECL(enum, procedureKind);
CORTO_FWDECL(enum, typeKind);
CORTO_FWDECL(enum, width);
CORTO_FWDECL_CORE(enum, frameKind);
CORTO_FWDECL_CORE(enum, mountKind);
CORTO_FWDECL_CORE(enum, operatorKind);
CORTO_FWDECL_SECURE(enum, accessKind);
CORTO_FWDECL_SECURE(enum, actionKind);

CORTO_FWDECL(bitmask, attr);
CORTO_FWDECL_CORE(bitmask, eventMask);
CORTO_FWDECL(bitmask, modifier);
CORTO_FWDECL(bitmask, state);

CORTO_FWDECL(sequence, interfaceseq);
CORTO_FWDECL(sequence, interfaceVectorseq);
CORTO_FWDECL(sequence, int32seq);
CORTO_FWDECL(sequence, objectseq);
CORTO_FWDECL(sequence, parameterseq);
CORTO_FWDECL(sequence, stringseq);
CORTO_FWDECL(sequence, wordseq);
CORTO_FWDECL_CORE(sequence, augmentseq);

CORTO_FWDECL_CORE(list, resultList);
CORTO_FWDECL(list, objectlist);
CORTO_FWDECL(list, stringlist);
CORTO_FWDECL_CORE(list, mountSubscriptionList);

CORTO_FWDECL(delegate, destructAction);
CORTO_FWDECL(delegate, initAction);
CORTO_FWDECL(delegate, nameAction);

CORTO_FWDECL_CORE(iterator, resultIter);
CORTO_FWDECL_CORE(iterator, objectIter);
CORTO_FWDECL_CORE(iterator, sampleIter);

CORTO_FWDECL_CORE(struct, time);
CORTO_FWDECL_CORE(struct, position);

/* database root */
corto_ssoo_package root__o = {CORTO_ROOT_V(), {"http://corto.io/doc"}};
corto_package root_o = CORTO_OFFSET(&root__o.o.o, sizeof(corto__object));

/* /corto, /corto/lang, /corto/core, /corto/secure */
CORTO_PACKAGE_O(corto, "http://corto.io/doc/corto");
CORTO_PACKAGE_O_SCOPE(corto, lang, "http://corto.io/doc/corto/lang");
CORTO_PACKAGE_O_SCOPE(corto, core, "http://corto.io/doc/corto/core");
CORTO_PACKAGE_O_SCOPE(corto, native, "http://corto.io/doc/corto/native");
CORTO_PACKAGE_O_SCOPE(corto, secure, "http://corto.io/doc/corto/secure");

corto_package corto_o = CORTO_OFFSET(&corto__o.o.o, sizeof(corto__object));
corto_package corto_lang_o = CORTO_OFFSET(&lang__o.o.o, sizeof(corto__object));
corto_package corto_core_o = CORTO_OFFSET(&core__o.o.o, sizeof(corto__object));
corto_package corto_native_o = CORTO_OFFSET(&native__o.o.o, sizeof(corto__object));
corto_package corto_secure_o = CORTO_OFFSET(&secure__o.o.o, sizeof(corto__object));

/* Primitives */
CORTO_BINARY_O(lang, octet, CORTO_WIDTH_8);
CORTO_BOOLEAN_O(lang, bool);
CORTO_CHARACTER_O(lang, char, CORTO_WIDTH_8);
CORTO_UINT_O(lang, uint8, CORTO_WIDTH_8, 0, MAX_UINT8);
CORTO_UINT_O(lang, uint16, CORTO_WIDTH_16, 0, MAX_UINT16);
CORTO_UINT_O(lang, uint32, CORTO_WIDTH_32, 0, MAX_UINT32);
CORTO_UINT_O(lang, uint64, CORTO_WIDTH_64, 0, MAX_UINT64);
CORTO_INT_O(lang, int8, CORTO_WIDTH_8, MIN_INT8, MAX_INT8, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(lang, int16, CORTO_WIDTH_16, MIN_INT16, MAX_INT16, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(lang, int32, CORTO_WIDTH_32, MIN_INT32, MAX_INT32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(lang, int64, CORTO_WIDTH_64, MIN_INT64, MAX_INT64, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_FLOAT_O(lang, float32, CORTO_WIDTH_32, 0, 0);
CORTO_FLOAT_O(lang, float64, CORTO_WIDTH_64, 0, 0);
CORTO_TEXT_O(lang, string, CORTO_WIDTH_8, 0);
CORTO_BINARY_O(lang, word, CORTO_WIDTH_WORD);
CORTO_FW_I(lang, constant);
CORTO_INT_O(lang, constant, CORTO_WIDTH_32, 0, MAX_INT32, CORTO_TYPE_ID(lang_enum), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_constant, init, "()", lang_int16, corto_constant_init);

/* Any type */
CORTO_TYPE_O(lang, any, CORTO_ANY, FALSE);

/* Void type */
CORTO_TYPE_O(lang, void, CORTO_VOID, FALSE);

/* Object type */
CORTO_TYPE_O(lang, object, CORTO_VOID, TRUE);

/* Package type */
CORTO_FW_C(core, package);
CORTO_CLASS_NOBASE_O(core, package, CORTO_ATTR_DEFAULT|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_C);
    CORTO_MEMBER_O(core_package, url, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, version, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, author, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, description, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, env, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, nocorto, lang_bool, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, noapi, lang_bool, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, cflags, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, dependencies, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, definitions, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, prefix, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, cortoVersion, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, local, lang_bool, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, lib, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, libpath, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, include, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_package, link, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_METHOD_O(core_package, construct, "()", lang_int16, corto_package_construct);

CORTO_CLASS_O(core, application, core_package, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);

/* Enumerations */
CORTO_ENUM_O(lang, width);
    CORTO_CONSTANT_O(lang_width, WIDTH_8);
    CORTO_CONSTANT_O(lang_width, WIDTH_16);
    CORTO_CONSTANT_O(lang_width, WIDTH_32);
    CORTO_CONSTANT_O(lang_width, WIDTH_64);
    CORTO_CONSTANT_O(lang_width, WIDTH_WORD);

CORTO_ENUM_O(lang, typeKind);
    CORTO_CONSTANT_O(lang_typeKind, VOID);
    CORTO_CONSTANT_O(lang_typeKind, ANY);
    CORTO_CONSTANT_O(lang_typeKind, PRIMITIVE);
    CORTO_CONSTANT_O(lang_typeKind, COMPOSITE);
    CORTO_CONSTANT_O(lang_typeKind, COLLECTION);
    CORTO_CONSTANT_O(lang_typeKind, ITERATOR);

CORTO_ENUM_O(lang, primitiveKind);
    CORTO_CONSTANT_O(lang_primitiveKind, BINARY);
    CORTO_CONSTANT_O(lang_primitiveKind, BOOLEAN);
    CORTO_CONSTANT_O(lang_primitiveKind, CHARACTER);
    CORTO_CONSTANT_O(lang_primitiveKind, INTEGER);
    CORTO_CONSTANT_O(lang_primitiveKind, UINTEGER);
    CORTO_CONSTANT_O(lang_primitiveKind, FLOAT);
    CORTO_CONSTANT_O(lang_primitiveKind, TEXT);
    CORTO_CONSTANT_O(lang_primitiveKind, ENUM);
    CORTO_CONSTANT_O(lang_primitiveKind, BITMASK);

CORTO_ENUM_O(lang, compositeKind);
    CORTO_CONSTANT_O(lang_compositeKind, INTERFACE);
    CORTO_CONSTANT_O(lang_compositeKind, STRUCT);
    CORTO_CONSTANT_O(lang_compositeKind, UNION);
    CORTO_CONSTANT_O(lang_compositeKind, CLASS);
    CORTO_CONSTANT_O(lang_compositeKind, DELEGATE);
    CORTO_CONSTANT_O(lang_compositeKind, PROCEDURE);

CORTO_ENUM_O(lang, collectionKind);
    CORTO_CONSTANT_O(lang_collectionKind, ARRAY);
    CORTO_CONSTANT_O(lang_collectionKind, SEQUENCE);
    CORTO_CONSTANT_O(lang_collectionKind, LIST);
    CORTO_CONSTANT_O(lang_collectionKind, MAP);

CORTO_ENUM_O(lang, equalityKind);
    CORTO_CONSTANT_O(lang_equalityKind, EQ);
    CORTO_CONSTANT_O(lang_equalityKind, LT);
    CORTO_CONSTANT_O(lang_equalityKind, GT);
    CORTO_CONSTANT_O(lang_equalityKind, NEQ);

CORTO_ENUM_O(lang, inout);
    CORTO_CONSTANT_O(lang_inout, IN);
    CORTO_CONSTANT_O(lang_inout, OUT);
    CORTO_CONSTANT_O(lang_inout, INOUT);

CORTO_ENUM_O(core, operatorKind);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_ADD);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_SUB);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_MUL);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_DIV);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_MOD);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_XOR);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_OR);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_AND);
    CORTO_CONSTANT_O(core_operatorKind, ASSIGN_UPDATE);
    CORTO_CONSTANT_O(core_operatorKind, ADD);
    CORTO_CONSTANT_O(core_operatorKind, SUB);
    CORTO_CONSTANT_O(core_operatorKind, MUL);
    CORTO_CONSTANT_O(core_operatorKind, DIV);
    CORTO_CONSTANT_O(core_operatorKind, MOD);
    CORTO_CONSTANT_O(core_operatorKind, INC);
    CORTO_CONSTANT_O(core_operatorKind, DEC);
    CORTO_CONSTANT_O(core_operatorKind, XOR);
    CORTO_CONSTANT_O(core_operatorKind, OR);
    CORTO_CONSTANT_O(core_operatorKind, AND);
    CORTO_CONSTANT_O(core_operatorKind, NOT);
    CORTO_CONSTANT_O(core_operatorKind, COND_OR);
    CORTO_CONSTANT_O(core_operatorKind, COND_AND);
    CORTO_CONSTANT_O(core_operatorKind, COND_NOT);
    CORTO_CONSTANT_O(core_operatorKind, COND_EQ);
    CORTO_CONSTANT_O(core_operatorKind, COND_NEQ);
    CORTO_CONSTANT_O(core_operatorKind, COND_GT);
    CORTO_CONSTANT_O(core_operatorKind, COND_LT);
    CORTO_CONSTANT_O(core_operatorKind, COND_GTEQ);
    CORTO_CONSTANT_O(core_operatorKind, COND_LTEQ);
    CORTO_CONSTANT_O(core_operatorKind, SHIFT_LEFT);
    CORTO_CONSTANT_O(core_operatorKind, SHIFT_RIGHT);
    CORTO_CONSTANT_O(core_operatorKind, REF);

CORTO_ENUM_O(core, mountKind);
    CORTO_CONSTANT_O(core_mountKind, SOURCE);
    CORTO_CONSTANT_O(core_mountKind, SINK);
    CORTO_CONSTANT_O(core_mountKind, CACHE);
    CORTO_CONSTANT_O(core_mountKind, HISTORIAN);

CORTO_ENUM_O(core, frameKind);
    CORTO_CONSTANT_O(core_frameKind, FRAME_NOW);
    CORTO_CONSTANT_O(core_frameKind, FRAME_TIME);
    CORTO_CONSTANT_O(core_frameKind, FRAME_DURATION);
    CORTO_CONSTANT_O(core_frameKind, FRAME_SAMPLE);
    CORTO_CONSTANT_O(core_frameKind, FRAME_DEPTH);

CORTO_ENUM_O(secure, accessKind);
    CORTO_SECURE_CONSTANT_O(secure_accessKind, ACCESS_GRANTED);
    CORTO_SECURE_CONSTANT_O(secure_accessKind, ACCESS_DENIED);
    CORTO_SECURE_CONSTANT_O(secure_accessKind, ACCESS_UNDEFINED);

CORTO_ENUM_O(secure, actionKind);
    CORTO_SECURE_CONSTANT_O(secure_actionKind, ACTION_CREATE);
    CORTO_SECURE_CONSTANT_O(secure_actionKind, ACTION_READ);
    CORTO_SECURE_CONSTANT_O(secure_actionKind, ACTION_UPDATE);
    CORTO_SECURE_CONSTANT_O(secure_actionKind, ACTION_DELETE);

CORTO_BITMASK_O(lang, state);
    CORTO_CONSTANT_O(lang_state, VALID);
    CORTO_CONSTANT_O(lang_state, DECLARED);
    CORTO_CONSTANT_O(lang_state, DEFINED);
    CORTO_CONSTANT_O(lang_state, DESTRUCTED);

CORTO_BITMASK_O(lang, attr);
    CORTO_CONSTANT_O(lang_attr, ATTR_SCOPED);
    CORTO_CONSTANT_O(lang_attr, ATTR_WRITABLE);
    CORTO_CONSTANT_O(lang_attr, ATTR_OBSERVABLE);
    CORTO_CONSTANT_O(lang_attr, ATTR_PERSISTENT);
    CORTO_CONSTANT_O(lang_attr, ATTR_DEFAULT);

CORTO_BITMASK_O(core, eventMask);
    CORTO_CONSTANT_O(core_eventMask, ON_DECLARE);
    CORTO_CONSTANT_O(core_eventMask, ON_DEFINE);
    CORTO_CONSTANT_O(core_eventMask, ON_DELETE);
    CORTO_CONSTANT_O(core_eventMask, ON_INVALIDATE);
    CORTO_CONSTANT_O(core_eventMask, ON_UPDATE);
    CORTO_CONSTANT_O(core_eventMask, ON_RESUME);
    CORTO_CONSTANT_O(core_eventMask, ON_SUSPEND);
    CORTO_CONSTANT_O(core_eventMask, ON_SELF);
    CORTO_CONSTANT_O(core_eventMask, ON_SCOPE);
    CORTO_CONSTANT_O(core_eventMask, ON_TREE);
    CORTO_CONSTANT_O(core_eventMask, ON_VALUE);
    CORTO_CONSTANT_O(core_eventMask, ON_METAVALUE);
    CORTO_CONSTANT_O(core_eventMask, ON_ANY);

CORTO_BITMASK_O(lang, modifier);
    CORTO_CONSTANT_O(lang_modifier, GLOBAL);
    CORTO_CONSTANT_O(lang_modifier, LOCAL);
    CORTO_CONSTANT_O(lang_modifier, PRIVATE);
    CORTO_CONSTANT_O(lang_modifier, READONLY);
    CORTO_CONSTANT_O(lang_modifier, CONST);
    CORTO_CONSTANT_O(lang_modifier, HIDDEN);
    CORTO_CONSTANT_O(lang_modifier, OPTIONAL);
    CORTO_CONSTANT_O(lang_modifier, OBSERVABLE);
    CORTO_CONSTANT_O(lang_modifier, KEY);

/* Collections */
CORTO_SEQUENCE_O(core, augmentseq, core_augmentData, 0);
CORTO_SEQUENCE_O(lang, interfaceseq, lang_interface, 0);
CORTO_SEQUENCE_O(lang, interfaceVectorseq, lang_interfaceVector, 0);
CORTO_SEQUENCE_O(lang, int32seq, lang_int32, 0);
CORTO_SEQUENCE_O(lang, objectseq, lang_object, 0);
CORTO_SEQUENCE_O(lang, parameterseq, lang_parameter, 0);
CORTO_SEQUENCE_O(lang, stringseq, lang_string, 0);
CORTO_SEQUENCE_O(lang, wordseq, lang_word, 0);
CORTO_LIST_O(lang, stringlist, lang_string, 0);
CORTO_LIST_O(lang, objectlist, lang_object, 0);
CORTO_LIST_O(core, resultList, core_result, 0);
CORTO_LIST_O(core, mountSubscriptionList, core_mountSubscription, 0);

/* Delegate types */
CORTO_DELEGATE_O(lang, initAction, lang_int16);
CORTO_DELEGATE_O(lang, nameAction, lang_string);
CORTO_DELEGATE_O(lang, destructAction, lang_void);

/* Iterator types */
CORTO_ITERATOR_O(core, objectIter, lang_object);
CORTO_ITERATOR_O(core, resultIter, core_result);
CORTO_ITERATOR_O(core, sampleIter, core_sample);

/* /corto/lang/typeOptions */
CORTO_STRUCT_O(lang, typeOptions, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_REFERENCE_O(lang_typeOptions, parentType, lang_type, CORTO_GLOBAL, CORTO_DECLARED|CORTO_DEFINED, NULL, FALSE);
    CORTO_MEMBER_O(lang_typeOptions, parentState, lang_state, CORTO_GLOBAL);
    CORTO_REFERENCE_O(lang_typeOptions, defaultType, lang_type, CORTO_GLOBAL, CORTO_DEFINED, NULL, FALSE);
    CORTO_REFERENCE_O(lang_typeOptions, defaultProcedureType, lang_type, CORTO_GLOBAL, CORTO_DEFINED, NULL, FALSE);

/* /corto/lang/type */
CORTO_FW_ICD(lang, type);
CORTO_CLASS_NOBASE_O(lang, type, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_type, kind, lang_typeKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, reference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, attr, lang_attr, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, options, lang_typeOptions, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_type, hasResources, lang_bool, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, hasTarget, lang_bool, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, size, lang_uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, alignment, lang_uint16, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, metaprocedures, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, init, lang_initAction, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, nameof, lang_nameAction, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_type, sizeof, "()", lang_uint32, corto_type_sizeof);
    CORTO_METHOD_O(lang_type, alignmentof, "()", lang_uint16, corto_type_alignmentof);
    CORTO_OVERRIDABLE_O(lang_type, castable, "(type type)", lang_bool, corto_type_castable_v);
    CORTO_OVERRIDABLE_O(lang_type, compatible, "(type type)", lang_bool, corto_type_compatible_v);
    CORTO_METHOD_O(lang_type, resolveProcedure, "(string name)", lang_function, corto_type_resolveProcedure);
    CORTO_METHOD_O(lang_type, init, "()", lang_int16, corto_type_init);
    CORTO_METHOD_O(lang_type, construct, "()", lang_int16, corto_type_construct);
    CORTO_METHOD_O(lang_type, destruct, "()", lang_void, corto_type_destruct);

/* /corto/lang/primitive */
CORTO_FW_IC(lang, primitive);
CORTO_CLASS_O(lang, primitive, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(lang_primitive, kind, lang_primitiveKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_primitive, width, lang_width, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_primitive, convertId, lang_uint8, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_OVERRIDABLE_O(lang_primitive, castable, "(type type)", lang_bool, corto_primitive_castable_v);
    CORTO_OVERRIDABLE_O(lang_primitive, compatible, "(type type)", lang_bool, corto_primitive_compatible_v);
    CORTO_METHOD_O(lang_primitive, isInteger, "()", lang_bool, corto_primitive_isInteger);
    CORTO_METHOD_O(lang_primitive, isNumber, "()", lang_bool, corto_primitive_isNumber);
    CORTO_METHOD_O(lang_primitive, init, "()", lang_int16, corto_primitive_init);
    CORTO_METHOD_O(lang_primitive, construct, "()", lang_int16, corto_primitive_construct);

/* /corto/lang/interface */
CORTO_FW_ICD(lang, interface);
CORTO_CLASS_O(lang, interface, lang_type, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_MEMBER_O(lang_interface, kind, lang_compositeKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_interface, nextMemberId, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, members, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, methods, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_REFERENCE_O(lang_interface, base, lang_interface, CORTO_GLOBAL, CORTO_DEFINED, NULL, FALSE);
    CORTO_METHOD_O(lang_interface, init, "()", lang_int16, corto_interface_init);
    CORTO_METHOD_O(lang_interface, construct, "()", lang_int16, corto_interface_construct);
    CORTO_METHOD_O(lang_interface, destruct, "()", lang_void, corto_interface_destruct);
    CORTO_OVERRIDABLE_O(lang_interface, resolveMember, "(string name)", lang_member, corto_interface_resolveMember_v);
    CORTO_OVERRIDABLE_O(lang_interface, compatible, "(type type)", lang_bool, corto_interface_compatible_v);
    CORTO_METHOD_O(lang_interface, resolveMethod, "(string name)", lang_method, corto_interface_resolveMethod);
    CORTO_METHOD_O(lang_interface, resolveMethodId, "(string name)", lang_uint32, corto_interface_resolveMethodId);
    CORTO_METHOD_O(lang_interface, resolveMethodById, "(uint32 id)", lang_method, corto_interface_resolveMethodById);
    CORTO_METHOD_O(lang_interface, bindMethod, "(method method)", lang_int16, corto_interface_bindMethod);
    CORTO_METHOD_O(lang_interface, baseof, "(interface type)", lang_int16, corto_interface_baseof);

/* /corto/lang/collection */
CORTO_FW_I(lang, collection);
CORTO_CLASS_O(lang, collection, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_collection, kind, lang_collectionKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_REFERENCE_O(lang_collection, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(lang_collection, max, lang_uint32, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(lang_collection, castable, "(type type)", lang_bool, corto_collection_castable_v);
    CORTO_OVERRIDABLE_O(lang_collection, compatible, "(type type)", lang_bool, corto_collection_compatible_v);
    CORTO_FUNCTION_O(lang_collection, requiresAlloc, "(type elementType)", lang_bool, corto_collection_requiresAlloc);
    CORTO_METHOD_O(lang_collection, init, "()", lang_int16, corto_collection_init);

/* /corto/lang/iterator */
CORTO_FW_I(lang, iterator);
CORTO_CLASS_O(lang, iterator, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_REFERENCE_O(lang_iterator, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, NULL, FALSE);
    CORTO_METHOD_O(lang_iterator, init, "()", lang_int16, corto_iterator_init);
    CORTO_OVERRIDABLE_O(lang_iterator, compatible, "(type type)", lang_bool, corto_iterator_compatible_v);
    CORTO_OVERRIDABLE_O(lang_iterator, castable, "(type type)", lang_bool, corto_iterator_castable_v);

/* /corto/lang/binary */
CORTO_FW_I(lang, binary);
CORTO_CLASS_O(lang, binary, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_binary, init, "()", lang_int16, corto_binary_init);

/* /corto/lang/boolean */
CORTO_FW_I(lang, boolean);
CORTO_CLASS_O(lang, boolean, lang_primitive, CORTO_GLOBAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_boolean, init, "()", lang_int16, corto_boolean_init);

/* /corto/lang/character */
CORTO_FW_I(lang, character);
CORTO_CLASS_O(lang, character, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_character, init, "()", lang_int16, corto_character_init);

/* /corto/lang/int */
CORTO_FW_I(lang, int);
CORTO_CLASS_O(lang, int, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_int, min, lang_int64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_int, max, lang_int64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_int, init, "()", lang_int16, corto_int_init);

/* /corto/lang/uint */
CORTO_FW_I(lang, uint);
CORTO_CLASS_O(lang, uint, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_uint, min, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_uint, max, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_uint, init, "()", lang_int16, corto_uint_init);

/* /corto/lang/float */
CORTO_FW_I(lang, float);
CORTO_CLASS_O(lang, float, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_float, min, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_float, max, lang_float64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_float, init, "()", lang_int16, corto_float_init);

/* /corto/lang/text */
CORTO_FW_I(lang, text);
CORTO_CLASS_O(lang, text, lang_primitive, CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_text, charWidth, lang_width, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_text, length, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_text, init, "()", lang_int16, corto_text_init);

/* /corto/lang/enum */
CORTO_FW_ICD(lang, enum);
CORTO_CLASS_O(lang, enum, lang_primitive, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_constant), NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_enum, constants, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_enum, init, "()", lang_int16, corto_enum_init);
    CORTO_METHOD_O(lang_enum, construct, "()", lang_int16, corto_enum_construct);
    CORTO_METHOD_O(lang_enum, destruct, "()", lang_void, corto_enum_destruct);
    CORTO_METHOD_O(lang_enum, constant, "(int32 value)", lang_object, corto_enum_constant);

/* /corto/lang/bitmask */
CORTO_FW_I(lang, bitmask);
CORTO_CLASS_O(lang, bitmask, lang_enum, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_constant), NULL, CORTO_I);
    CORTO_METHOD_O(lang_bitmask, init, "()", lang_int16, corto_bitmask_init);

/* /corto/lang/struct */
CORTO_FW_IC(lang, struct);
CORTO_CLASS_O(lang, struct, lang_interface, CORTO_HIDDEN, CORTO_ATTR_DEFAULT|CORTO_ATTR_SCOPED, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_IC);
    CORTO_ALIAS_O (lang_struct, base, lang_interface_base, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_struct, baseAccess, lang_modifier, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_struct, keys, lang_stringseq, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_struct, keycache, lang_objectseq, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_OVERRIDABLE_O(lang_struct, compatible, "(type type)", lang_bool, corto_struct_compatible_v);
    CORTO_OVERRIDABLE_O(lang_struct, castable, "(type type)", lang_bool, corto_struct_castable_v);
    CORTO_OVERRIDABLE_O(lang_struct, resolveMember, "(string name)", lang_member, corto_struct_resolveMember_v);
    CORTO_METHOD_O(lang_struct, init, "()", lang_int16, corto_struct_init);
    CORTO_METHOD_O(lang_struct, construct, "()", lang_int16, corto_struct_construct);

/* /corto/lang/union */
CORTO_FW_IC(lang, union);
CORTO_CLASS_O(lang, union, lang_interface, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_case), CORTO_TYPE_ID(lang_method), CORTO_IC);
    CORTO_MEMBER_O(lang_union, discriminator, lang_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_union, init, "()", lang_int16, corto_union_init);
    CORTO_METHOD_O(lang_union, construct, "()", lang_int16, corto_union_construct);
    CORTO_METHOD_O(lang_union, findCase, "(int32 discriminator)", lang_member, corto_union_findCase);

/* /corto/lang/interfaceVector */
CORTO_STRUCT_O(lang, interfaceVector, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_interfaceVector, interface, lang_interface, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_interfaceVector, vector, lang_objectseq, CORTO_GLOBAL);

/* /corto/lang/class */
CORTO_FW_ICD(lang, class);
CORTO_CLASS_O(lang, class, lang_struct, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_ALIAS_O (lang_class, base, lang_struct_base, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_class, baseAccess, lang_struct_baseAccess, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_class, implements, lang_interfaceseq, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_class, interfaceVector, lang_interfaceVectorseq, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, construct, lang_initAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, destruct, lang_destructAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(lang_class, init, "()", lang_int16, corto_class_init);
    CORTO_METHOD_O(lang_class, construct, "()", lang_int16, corto_class_construct);
    CORTO_METHOD_O(lang_class, destruct, "()", lang_void, corto_class_destruct);
    CORTO_METHOD_O(lang_class, instanceof, "(object object)", lang_bool, corto_class_instanceof);
    CORTO_METHOD_O(lang_class, resolveInterfaceMethod, "(interface interface,uint32 method)", lang_method, corto_class_resolveInterfaceMethod);

/* /corto/lang/delegatedata */
CORTO_STRUCT_O(lang, delegatedata, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_delegatedata, instance, lang_object, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegatedata, procedure, lang_function, CORTO_GLOBAL);

/* /corto/lang/delegate */
CORTO_FW_I(lang, delegate);
CORTO_CLASS_O(lang, delegate, lang_struct, CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_I);
    CORTO_METHOD_O(lang_delegate, init, "()", lang_int16, corto_delegate_init);
    CORTO_REFERENCE_O(lang_delegate, returnType, lang_type, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(lang_delegate, returnsReference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegate, parameters, lang_parameterseq, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(lang_delegate, compatible, "(type type)", lang_bool, corto_delegate_compatible_v);
    CORTO_OVERRIDABLE_O(lang_delegate, castable, "(type type)", lang_bool, corto_delegate_compatible_v);
    CORTO_METHOD_O(lang_delegate, instanceof, "(object object)", lang_bool, corto_delegate_instanceof);
    CORTO_FUNCTION_O(lang_delegate, construct, "(function object)", lang_int16, corto_delegate_construct);

/* /corto/lang/target */
CORTO_FW_C(lang, target);
CORTO_CLASS_O(lang, target, lang_struct, CORTO_READONLY, CORTO_ATTR_SCOPED|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_C);
    CORTO_METHOD_O(lang_target, construct, "()", lang_int16, corto_target_construct);
    CORTO_MEMBER_O(lang_target, type, lang_type, CORTO_GLOBAL);

/* /corto/lang/procedure */
CORTO_FW_I(lang, procedure);
CORTO_CLASS_O(lang, procedure, lang_class, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_procedure, hasThis, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_procedure, thisType, lang_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_procedure, init, "()", lang_int16, corto_procedure_init);

/* /corto/lang/array */
CORTO_FW_ICD(lang, array);
CORTO_CLASS_O(lang, array, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_REFERENCE_O(lang_array, elementType, lang_type, CORTO_GLOBAL|CORTO_PRIVATE, CORTO_DEFINED, NULL, FALSE);
    CORTO_METHOD_O(lang_array, init, "()", lang_int16, corto_array_init);
    CORTO_METHOD_O(lang_array, construct, "()", lang_int16, corto_array_construct);
    CORTO_METHOD_O(lang_array, destruct, "()", lang_void, corto_array_destruct);

/* /corto/lang/sequence */
CORTO_FW_IC(lang, sequence);
CORTO_CLASS_O(lang, sequence, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_sequence, init, "()", lang_int16, corto_sequence_init);
    CORTO_METHOD_O(lang_sequence, construct, "()", lang_int16, corto_sequence_construct);

/* /corto/lang/list */
CORTO_FW_IC(lang, list);
CORTO_CLASS_O(lang, list, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_list, init, "()", lang_int16, corto_list_init);
    CORTO_METHOD_O(lang_list, construct, "()", lang_int16, corto_list_construct);

/* /corto/lang/map */
CORTO_FW_IC(lang, map);
CORTO_CLASS_O(lang, map, lang_collection, CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    /* Duplicate members for a more convenient order in the initializer */
    CORTO_REFERENCE_O(lang_map, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, NULL, FALSE);
    CORTO_REFERENCE_O(lang_map, keyType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, NULL, FALSE);
    CORTO_MEMBER_O(lang_map, max, lang_uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_map, init, "()", lang_int16, corto_map_init);
    CORTO_METHOD_O(lang_map, construct, "()", lang_int16, corto_map_construct);

/* /corto/lang/function */
CORTO_FW_ICD(lang, function);
CORTO_PROCEDURE_NOBASE_O(lang, function, FALSE, NULL, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_ICD);
    CORTO_REFERENCE_O(lang_function, returnType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(lang_function, returnsReference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_function, parameters, lang_parameterseq, CORTO_LOCAL | CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_function, overridable, lang_bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_MEMBER_O(lang_function, overloaded, lang_bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_MEMBER_O(lang_function, kind, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, impl, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, fptr, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, fdata, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, size, lang_uint16, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(lang_function, init, "()", lang_int16, corto_function_init);
    CORTO_METHOD_O(lang_function, construct, "()", lang_int16, corto_function_construct);
    CORTO_METHOD_O(lang_function, destruct, "()", lang_void, corto_function_destruct);
    CORTO_FUNCTION_O(lang_function, stringToParameterSeq, "(string name,object scope)", lang_parameterseq, corto_function_stringToParameterSeq);
    CORTO_METHOD_O(lang_function, parseParamString, "(string params)", lang_int16, corto_function_parseParamString);

/* /corto/lang/method */
CORTO_FW_IC(lang, method);
CORTO_PROCEDURE_O(lang, method, TRUE, NULL, lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_IC);
    CORTO_METHOD_O(lang_method, init, "()", lang_int16, corto_method_init);
    CORTO_METHOD_O(lang_method, construct, "()", lang_int16, corto_method_construct);

/* /corto/lang/overridable */
CORTO_FW_I(lang, overridable);
CORTO_PROCEDURE_O(lang, overridable, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_overridable, init, "()", lang_int16, corto_overridable_init);

/* /corto/lang/override */
CORTO_FW_I(lang, override);
CORTO_PROCEDURE_O(lang, override, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_override, init, "()", lang_int16, corto_overridable_init);

/* /corto/lang/metaprocedure */
CORTO_FW_C(lang, metaprocedure);
CORTO_PROCEDURE_O(lang, metaprocedure, TRUE, CORTO_TYPE_ID(lang_any), lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED|CORTO_DEFINED, CORTO_C);
    CORTO_METHOD_O(lang_metaprocedure, construct, "()", lang_int16, corto_metaprocedure_construct);
    CORTO_MEMBER_O(lang_metaprocedure, referenceOnly, lang_bool, CORTO_GLOBAL);

/* /corto/lang/member */
CORTO_FW_IC(lang, member);
CORTO_CLASS_NOBASE_O(lang, member, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(lang_member, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, "reference", FALSE);
    CORTO_MEMBER_O(lang_member, modifiers, lang_modifier, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_member, unit, lang_unit, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, state, lang_state, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, stateCondExpr, lang_string, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, weak, lang_bool, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, id, lang_uint32, CORTO_GLOBAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_member, offset, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_member, init, "()", lang_int16, corto_member_init);
    CORTO_METHOD_O(lang_member, construct, "()", lang_int16, corto_member_construct);

/* /corto/lang/alias */
CORTO_FW_IC(lang, alias);
CORTO_CLASS_O(lang, alias, lang_member, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_struct), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(lang_alias, member, lang_member, CORTO_GLOBAL, CORTO_DEFINED, NULL, FALSE);
    CORTO_METHOD_O(lang_alias, init, "()", lang_int16, corto_alias_init);
    CORTO_METHOD_O(lang_alias, construct, "()", lang_int16, corto_alias_construct);

/* /corto/lang/case */
CORTO_FW_C(lang, case);
CORTO_CLASS_O(lang, case, lang_member, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_union), CORTO_DECLARED, NULL, NULL, CORTO_C);
    CORTO_MEMBER_O(lang_case, discriminator, lang_int32seq, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_case, type, lang_member_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_case, construct, "()", lang_int16, corto_case_construct);

/* /corto/lang/default */
CORTO_FW_C(lang, default);
CORTO_CLASS_O(lang, default, lang_case, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_union), CORTO_DECLARED, NULL, NULL, CORTO_C);
    CORTO_ALIAS_O (lang_default, type, lang_case_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_default, construct, "()", lang_int16, corto_default_construct);

/* /corto/lang/parameter */
CORTO_STRUCT_O(lang, parameter, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_parameter, name, lang_string, CORTO_GLOBAL);
    CORTO_REFERENCE_O(lang_parameter, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, NULL, FALSE);
    CORTO_MEMBER_O(lang_parameter, inout, lang_inout, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_parameter, passByReference, lang_bool, CORTO_GLOBAL);

/* /corto/lang/quantity */
CORTO_CLASS_NOBASE_O(lang, quantity, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_quantity, description, lang_string, CORTO_GLOBAL);

/* /corto/lang/unit */
CORTO_FW_ICD(lang, unit);
CORTO_CLASS_O(lang, unit, lang_class, CORTO_PRIVATE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_unit, quantity, lang_quantity, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, symbol, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, conversion, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, type, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, toQuantity, lang_word, CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_unit, fromQuantity, lang_word, CORTO_PRIVATE);
    CORTO_METHOD_O(lang_unit, init, "()", lang_int16, corto_unit_init);
    CORTO_METHOD_O(lang_unit, construct, "()", lang_int16, corto_unit_construct);
    CORTO_METHOD_O(lang_unit, destruct, "()", lang_void, corto_unit_destruct);

/* /corto/lang/container */
CORTO_CLASS_O(lang, container, lang_class, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_container, type, lang_type, CORTO_GLOBAL);

/* /corto/lang/leaf */
CORTO_CLASS_O(lang, leaf, lang_container, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_NODELEGATE);

/* /corto/lang/table */
CORTO_FW_C(lang, table);
CORTO_CLASS_O(lang, table, lang_container, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_C);
    CORTO_METHOD_O(lang_table, construct, "()", lang_int16, corto_table_construct);

/* /corto/lang/tablescope */
CORTO_CLASS_NOBASE_O(lang, tablescope, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_tablescope, type, lang_struct, CORTO_GLOBAL);

/* /corto/core/augmentData */
CORTO_STRUCT_O(core, augmentData, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_augmentData, id, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_augmentData, data, lang_word, CORTO_GLOBAL);

/* /corto/core/sample */
CORTO_STRUCT_O(core, sample, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_sample, timestamp, core_time, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_sample, value, lang_word, CORTO_GLOBAL);

/* /corto/core/result */
CORTO_STRUCT_O(core, result, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_result, id, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, name, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, value, lang_word, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, leaf, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, object, lang_object, CORTO_HIDDEN);
    CORTO_MEMBER_O(core_result, history, core_sampleIter, CORTO_HIDDEN);
    CORTO_MEMBER_O(core_result, augments, core_augmentseq, CORTO_HIDDEN);
    CORTO_MEMBER_O(core_result, owner, lang_object, CORTO_HIDDEN);
    CORTO_METHOD_O(core_result, getText, "()", lang_string, corto_result_getText);
    CORTO_METHOD_O(core_result, fromcontent, "(string contentType,string content)", lang_int16, corto_result_fromcontent);
    CORTO_METHOD_O(core_result, contentof, "(string contentType)", lang_string, corto_result_contentof);

/* /corto/core/request */
CORTO_STRUCT_O(core, request, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_request, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, offset, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, limit, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, content, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, from, core_frame, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, to, core_frame, CORTO_GLOBAL);

/* /corto/lang/dispatcher */
CORTO_INTERFACE_O(core, dispatcher);
    CORTO_IMETHOD_O(core_dispatcher, post, "(event e)", lang_void, FALSE);

/* /corto/core/stageItem */
CORTO_STRUCT_O(core, stageItem, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_stageItem, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, offset, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, limit, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, content, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, from, core_frame, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_stageItem, to, core_frame, CORTO_GLOBAL);

/* /corto/core/stager */
CORTO_FW_CD(core, stager);
CORTO_CLASS_NOBASE_O(core, stager, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(core_stager, resolver, lang_word, CORTO_PRIVATE|CORTO_LOCAL);
    CORTO_METHOD_O(core_stager, construct, "()", lang_int16, corto_loader_construct);
    CORTO_METHOD_O(core_stager, destruct, "()", lang_void, corto_loader_destruct);
    CORTO_METHOD_O(core_stager, add, "(string id,string type,string contentType,word content,uint64 childcount)", lang_int16, corto_subscriberEvent_handle_v);

/* /corto/lang/event */
CORTO_CLASS_NOBASE_O(core, event, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(core_event, kind, lang_uint16, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_event, handled, lang_bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_OVERRIDABLE_O(core_event, handle, "()", lang_void, corto_event_handle_v);
    CORTO_FUNCTION_O(core_event, uniqueKind, "()", lang_int16, corto_event_uniqueKind);

/* /corto/lang/observableEvent */
CORTO_CLASS_O(core, observableEvent, core_event, CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(core_observableEvent, observer, lang_function, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, me, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, source, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, observable, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(core_observableEvent, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_observableEvent, thread, lang_word, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(core_observableEvent, handle, "()", lang_void, corto_observableEvent_handle_v);

/* /corto/lang/subscriberEvent */
CORTO_FW_CD(core, subscriberEvent);
CORTO_CLASS_O(core, subscriberEvent, core_observableEvent, CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(core_subscriberEvent, result, core_result, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_subscriberEvent, contentTypeHandle, lang_word, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(core_subscriberEvent, handle, "()", lang_void, corto_subscriberEvent_handle_v);
    CORTO_METHOD_O(core_subscriberEvent, construct, "()", lang_int16, corto_subscriberEvent_construct);
    CORTO_METHOD_O(core_subscriberEvent, destruct, "()", lang_void, corto_subscriberEvent_destruct);

/* /corto/lang/invokeEvent */
CORTO_CLASS_O(core, invokeEvent, core_event, CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(core_invokeEvent, mount, core_mount, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, instance, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, function, lang_function, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, args, lang_word, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_OVERRIDABLE_O(core_invokeEvent, handle, "()", lang_void, corto_invokeEvent_handle_v);

/* /corto/core/remote */
CORTO_PROCEDURE_O(core, remote, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_NODELEGATE);

/* /corto/core/observer */
CORTO_FW_ICD(core, observer);
CORTO_PROCEDURE_O(core, observer, TRUE, NULL, lang_function, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_ICD);
    CORTO_MEMBER_O(core_observer, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_REFERENCE_O(core_observer, observable, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_observer, instance, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(core_observer, dispatcher, core_dispatcher, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(core_observer, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_observer, enabled, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_observer, active, lang_uint32, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(core_observer, typeReference, lang_type, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(core_observer, init, "()", lang_int16, corto_observer_init);
    CORTO_METHOD_O(core_observer, construct, "()", lang_int16, corto_observer_construct);
    CORTO_METHOD_O(core_observer, destruct, "()", lang_void, corto_observer_destruct);
    CORTO_METHOD_O(core_observer, observe, "(object instance,object observable)", lang_int16, corto_observer_observe);
    CORTO_METHOD_O(core_observer, unobserve, "(object instance,object observable)", lang_int16, corto_observer_unobserve);
    CORTO_METHOD_O(core_observer, observing, "(object instance,object observable)", lang_bool, corto_observer_observing);

/* /corto/core/subscriber */
CORTO_FW_ICD(core, subscriber);
CORTO_PROCEDURE_O(core, subscriber, TRUE, NULL, core_observer, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_ICD);
    CORTO_ALIAS_O(core_subscriber, mask, core_observer_mask, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_subscriber, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_subscriber, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_subscriber, contentType, lang_string, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_subscriber, instance, core_observer_instance, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_subscriber, dispatcher, core_observer_dispatcher, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_subscriber, type, core_observer_type, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_subscriber, enabled, core_observer_enabled, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_subscriber, contentTypeHandle, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_MEMBER_O(core_subscriber, matchProgram, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_METHOD_O(core_subscriber, init, "()", lang_int16, corto_subscriber_init);
    CORTO_METHOD_O(core_subscriber, construct, "()", lang_int16, corto_subscriber_construct);
    CORTO_METHOD_O(core_subscriber, destruct, "()", lang_void, corto_subscriber_destruct);
    CORTO_METHOD_O(core_subscriber, subscribe, "(object instance)", lang_int16, corto_subscriber_subscribe);
    CORTO_METHOD_O(core_subscriber, unsubscribe, "(object instance)", lang_int16, corto_subscriber_unsubscribe);

/* /corto/core/mountStats */
CORTO_STRUCT_O(core, mountStats, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_mountStats, declares, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountStats, updates, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountStats, deletes, lang_uint64, CORTO_GLOBAL);

/* /corto/core/mountPolicy */
CORTO_STRUCT_O(core, mountPolicy, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_mountPolicy, sampleRate, lang_float64, CORTO_GLOBAL);

/* /corto/core/mountSubscription */
CORTO_STRUCT_O(core, mountSubscription, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_mountSubscription, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountSubscription, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountSubscription, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountSubscription, count, lang_uint32, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mountSubscription, userData, lang_word, CORTO_GLOBAL);

/* /corto/core/router */
CORTO_FW_ICD(core, router);
CORTO_CLASS_O(core, router, lang_class, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_METHOD_O(core_router, init, "()", lang_int16, corto_router_init);
    CORTO_METHOD_O(core_router, construct, "()", lang_int16, corto_router_construct);
    CORTO_MEMBER_O(core_router, returnType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_router, paramType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_router, paramName, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_router, routerDataType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_router, routerDataName, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_router, elementSeparator, lang_string, CORTO_GLOBAL);
    CORTO_FUNCTION_O(core_router, match, "(lang/object instance,string request,any param,any result,out:core/route matched)", lang_int16, corto_router_match);

/* /corto/core/routerimpl */
CORTO_FW_CD(core, routerimpl);
CORTO_CLASS_O(core, routerimpl, lang_class, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_METHOD_O(core_routerimpl, construct, "()", lang_int16, corto_routerimpl_construct);
    CORTO_METHOD_O(core_routerimpl, destruct, "()", lang_void, corto_routerimpl_destruct);
    CORTO_MEMBER_O(core_routerimpl, maxArgs, lang_uint16, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(core_routerimpl, matched, core_route, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_OVERRIDABLE_O(core_routerimpl, matchRoute, "(core/route route,stringseq pattern,any param,out:any routerData)", lang_int32, corto_routerimpl_matchRoute_v);
    CORTO_OVERRIDABLE_O(core_routerimpl, findRoute, "(object instance,stringseq pattern,any param,out:any routerData)", core_route, corto_routerimpl_findRoute_v);

/* /corto/core/mount */
CORTO_FW_ICD(core, mount);
CORTO_CLASS_O(core, mount, core_subscriber, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(core_mount, kind, core_mountKind, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_mount, parent, core_subscriber_parent, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_mount, expr, core_subscriber_expr, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_mount, type, core_subscriber_type, CORTO_GLOBAL);
    CORTO_ALIAS_O(core_mount, contentType, core_subscriber_contentType, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, policy, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, mount, lang_object, CORTO_HIDDEN);
    CORTO_MEMBER_O(core_mount, attr, lang_attr, CORTO_HIDDEN);
    CORTO_MEMBER_O(core_mount, sent, core_mountStats, CORTO_READONLY);
    CORTO_MEMBER_O(core_mount, received, core_mountStats, CORTO_READONLY);
    CORTO_MEMBER_O(core_mount, sentDiscarded, core_mountStats, CORTO_READONLY);
    CORTO_MEMBER_O(core_mount, policies, core_mountPolicy, CORTO_READONLY);
    CORTO_MEMBER_O(core_mount, subscriptions, core_mountSubscriptionList, CORTO_READONLY);
    CORTO_MEMBER_O(core_mount, events, lang_objectlist, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, passThrough, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, thread, lang_word, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, quit, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, hasNotify, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, hasResume, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, hasSubscribe, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(core_mount, contentTypeOut, lang_string, CORTO_READONLY|CORTO_LOCAL);
    CORTO_MEMBER_O(core_mount, contentTypeOutHandle, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_METHOD_O(core_mount, init, "()", lang_int16, corto_mount_init);
    CORTO_METHOD_O(core_mount, construct, "()", lang_int16, corto_mount_construct);
    CORTO_METHOD_O(core_mount, destruct, "()", lang_void, corto_mount_destruct);
    CORTO_METHOD_O(core_mount, post, "(event e)", lang_void, corto_mount_post);
    CORTO_OVERRIDABLE_O(core_mount, onPoll, "()", lang_void, corto_mount_onPoll_v);
    CORTO_METHOD_O(core_mount, setContentType, "(string type)", lang_int16, corto_mount_setContentType);
    CORTO_METHOD_O(core_mount, setContentTypeIn, "(string type)", lang_int16, corto_mount_setContentTypeIn);
    CORTO_METHOD_O(core_mount, setContentTypeOut, "(string type)", lang_int16, corto_mount_setContentTypeOut);
    CORTO_METHOD_O(core_mount, return, "(core/result r)", lang_void, corto_mount_return);
    CORTO_METHOD_O(core_mount, invoke, "(object instance,function proc,word argptrs)", lang_void, corto_mount_invoke);
    CORTO_METHOD_O(core_mount, id, "()", lang_string, corto_mount_onRequest_v);
    CORTO_METHOD_O(core_mount, request, "(core/request request)", core_resultIter, corto_mount_request);
    CORTO_METHOD_O(core_mount, resume, "(string parent,string name,object o)", lang_object, corto_mount_resume);
    CORTO_METHOD_O(core_mount, subscribe, "(/corto/core/request request)", lang_void, corto_mount_subscribe);
    CORTO_METHOD_O(core_mount, unsubscribe, "(/corto/core/request request)", lang_void, corto_mount_unsubscribe);
    CORTO_OVERRIDABLE_O(core_mount, onInvoke, "(object instance,function proc,word argptrs)", lang_void, corto_mount_onInvoke_v);
    CORTO_OVERRIDABLE_O(core_mount, onId, "()", lang_string, corto_mount_onRequest_v);
    CORTO_OVERRIDABLE_O(core_mount, onRequest, "(/corto/core/request request)", core_resultIter, corto_mount_onRequest_v);
    CORTO_OVERRIDABLE_O(core_mount, onResume, "(string parent,string name,object o)", lang_object, corto_mount_onResume_v);
    CORTO_OVERRIDABLE_O(core_mount, onNotify, "(core/eventMask event,core/result object)", lang_void, corto_mount_onNotify_v);
    CORTO_OVERRIDABLE_O(core_mount, onSubscribe, "(string parent,string expr,lang/word ctx)", lang_word, corto_mount_onSubscribe_v);
    CORTO_OVERRIDABLE_O(core_mount, onUnsubscribe, "(string parent,string expr,lang/word ctx)", lang_void, corto_mount_onUnsubscribe_v);

/* /corto/core/route */
CORTO_FW_IC(core, route);
CORTO_PROCEDURE_O(core, route, TRUE, NULL, lang_method, CORTO_LOCAL | CORTO_READONLY, CORTO_TYPE_ID(core_routerimpl), CORTO_DECLARED | CORTO_DEFINED, CORTO_IC);
    CORTO_MEMBER_O(core_route, pattern, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_route, elements, lang_stringseq, CORTO_READONLY);
    CORTO_METHOD_O(core_route, init, "()", lang_int16, corto_route_init);
    CORTO_METHOD_O(core_route, construct, "()", lang_int16, corto_route_construct);

/* /corto/core/time */
CORTO_STRUCT_O(core, time, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_time, sec, lang_int32, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_time, nanosec, lang_uint32, CORTO_GLOBAL);

/* /corto/core/position */
CORTO_STRUCT_O(core, position, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_position, latitude, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_position, longitude, lang_float64, CORTO_GLOBAL);

/* /corto/core/frame */
CORTO_STRUCT_O(core, frame, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_frame, kind, core_frameKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_frame, value, lang_int64, CORTO_GLOBAL);
    CORTO_METHOD_O(core_frame, getTime, "()", core_time, corto_frame_getTime);

/* /corto/native/type */
CORTO_FW_I(native, type);
CORTO_CLASS_O(native, type, lang_binary, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(native_type, name, lang_string, CORTO_GLOBAL);
    CORTO_METHOD_O(native_type, init, "()", lang_int16, corto_native_type_init);

/* /corto/secure/key */
CORTO_FW_CD(secure, key);
CORTO_CLASS_NOBASE_O(secure, key, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_METHOD_O(secure_key, construct, "()", lang_int16, corto_secure_key_construct);
    CORTO_METHOD_O(secure_key, destruct, "()", lang_void, corto_secure_key_destruct);
    CORTO_OVERRIDABLE_O(secure_key, authenticate, "(string user,string password)", lang_string, corto_secure_key_authenticate_v);

/* /corto/secure/lock */
CORTO_FW_CD(secure, lock);
CORTO_CLASS_NOBASE_O(secure, lock, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(secure_lock, mount, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(secure_lock, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(secure_lock, priority, lang_int16, CORTO_GLOBAL);
    CORTO_METHOD_O(secure_lock, construct, "()", lang_int16, corto_secure_lock_construct);
    CORTO_METHOD_O(secure_lock, destruct, "()", lang_void, corto_secure_lock_destruct);
    CORTO_OVERRIDABLE_O(secure_lock, authorize, "(string token,secure/actionKind action)", secure_accessKind, corto_secure_lock_authorize_v);

/* /corto/core/loader */
CORTO_FW_CD(core, loader);
CORTO_CLASS_O(core, loader, core_mount, CORTO_PRIVATE|CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(core_loader, autoLoad, lang_bool, CORTO_GLOBAL);
    CORTO_METHOD_O(core_loader, construct, "()", lang_int16, corto_loader_construct);
    CORTO_METHOD_O(core_loader, destruct, "()", lang_void, corto_loader_destruct);
    CORTO_OVERRIDABLE_O(core_loader, onRequest, "(/corto/core/request request)", core_resultIter, corto_loader_onRequest_v);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_BOOTSTRAP_H_ */
