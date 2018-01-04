/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* This file contains all the builtin-objects, which are defined in process
 * memory instead of the heap, to speed up boottime of corto. As the datatypes
 * for some of the objects are complex, the code heavily uses macro's to
 * improve readability.
 */

#ifndef CORTO_BOOTSTRAP_H_
#define CORTO_BOOTSTRAP_H_

#include <corto/corto.h>
#include "object.h"

/* Keep include local because of clashing macro's with other libraries (yacc) */
#ifdef __MACH__
#include "ffi/ffi.h"
#else
#include "ffi.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_UINT8  (uint64_t)(0xFF)
#define MAX_UINT16 (uint64_t)(0xFFFF)
#define MAX_UINT32 (uint64_t)(0xFFFFFFFF)
#define MAX_UINT64 (uint64_t)(0xFFFFFFFFFFFFFFFF)
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
CORTO_STATIC_SCOPED_REFOBJECT(verbatim);
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
CORTO_STATIC_SCOPED_REFOBJECT(overridable);
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
#define CORTO_FWDECL_VSTORE(type, name) CORTO_FWDECL_SSO(type, vstore_##name); corto_##type corto_##name##_o = &vstore_##name##__o.v
#define CORTO_FWDECL_NATIVE(type, name) CORTO_FWDECL_SSO(type, native_##name); corto_##type corto_native_##name##_o = &native_##name##__o.v
#define CORTO_FWDECL_SECURE(type, name) CORTO_FWDECL_SSO(type, secure_##name); corto_##type corto_secure_##name##_o = &secure_##name##__o.v

#define CORTO_FWDECL_(type, name) CORTO_FWDECL_SSO(type, lang_##name##_); corto_##type corto_##name##_o = &lang_##name##___o.v
#define CORTO_FWDECL__VSTORE(type, name) CORTO_FWDECL_SSO(type, vstore_##name##_); corto_##type corto_##name##_o = &vstore_##name##___o.v
#define CORTO_FWDECL__NATIVE(type, name) CORTO_FWDECL_SSO(type, native_##name##_); corto_##type corto_native_##name##_o = &native_##name##___o.v
#define CORTO_FWDECL__SECURE(type, name) CORTO_FWDECL_SSO(type, secure_##name##_); corto_##type corto_secure_##name##_o = &secure_##name##___o.v

/* SSO */
#ifndef NDEBUG
#define CORTO_ADD_MAGIC ,CORTO_MAGIC
#else
#define CORTO_ADD_MAGIC
#endif
#define CORTO_ATTR_SSOO {{1, 0, 1, 0, 1, 0, 0}}
#define CORTO_ATTR_SSO {{1, 0, 0, 0, 1, 0, 0}}
#define CORTO_ATTR_SO {{0, 0, 0, 0, 1, 0, 0}}
#define CORTO_ROOT_V() {{NULL, NULL, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}},{NULL,NULL,{CORTO_RWMUTEX_INITIALIZER},NULL,NULL},{CORTO_ATTR_SSOO CORTO_ADD_MAGIC, 2, (corto_type)&lang_package__o.v}}
#define CORTO_PACKAGE_V(parent, name, description, version, author, uri) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}},{NULL,NULL,{CORTO_RWMUTEX_INITIALIZER},NULL,NULL},{CORTO_ATTR_SSOO CORTO_ADD_MAGIC, 2, (corto_type)&lang_package__o.v}}, {description, version, author, "cortoproject", uri}
#define CORTO_SSO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}},{CORTO_ATTR_SSO CORTO_ADD_MAGIC, 2, (corto_type)&type##__o.v}}
#define CORTO_SSO_PO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSO)), name, _(scope)NULL, _(scopeLock){CORTO_RWMUTEX_INITIALIZER}},{CORTO_ATTR_SSO CORTO_ADD_MAGIC, 2, (corto_type)&type##__o.v}}

/* SSO identifier */
#define CORTO_ID(name) name##__o
#define CORTO_TYPE_ID(name) (corto_type)&CORTO_ID(name).v

/* Forward declarations of delegates */
#define CORTO_FW_I(parent, name) sso_method CORTO_ID(parent##_##name##_init_)
#define CORTO_FW_C(parent, name) sso_method CORTO_ID(parent##_##name##_construct_)
#define CORTO_FW_IC(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_)
#define CORTO_FW_ICD(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)
#define CORTO_FW_IFCDD(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_deinit_), CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_), CORTO_ID(parent##_##name##_define_)
#define CORTO_FW_IF(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_deinit_)
#define CORTO_FW_CD(parent, name) sso_method CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)

/* Delegate assignments */
#define CORTO_DELEGATE(name, delegate) {{NULL, (corto_function)&CORTO_ID(name##_##delegate##_).v}}
#define CORTO_INIT(name) CORTO_DELEGATE(name, init)
#define CORTO_DEINIT(name) CORTO_DELEGATE(name, deinit)
#define CORTO_CONSTRUCT(name) CORTO_DELEGATE(name, construct)
#define CORTO_BIND(name) CORTO_DELEGATE(name, construct)
#define CORTO_DESTRUCT(name) CORTO_DELEGATE(name, destruct)
#define CORTO__DEFINE(name) CORTO_DELEGATE(name, define)

#define CORTO_I_TYPE(name) CORTO_INIT(name), {{NULL, NULL}}
#define CORTO_I_CLASS(name) {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}

#define CORTO_C_TYPE(name)
#define CORTO_C_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}

#define CORTO_IC_TYPE(name) CORTO_INIT(name), {{NULL, NULL}}
#define CORTO_IC_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}

#define CORTO_ICD_TYPE(name) CORTO_INIT(name), {{NULL, NULL}}
#define CORTO_ICD_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, CORTO_DESTRUCT(name), {{NULL, NULL}}

#define CORTO_IFCDD_TYPE(name) CORTO_INIT(name), CORTO_DEINIT(name)
#define CORTO_IFCDD_CLASS(name) CORTO_CONSTRUCT(name), CORTO__DEFINE(name), {{NULL, NULL}}, {{NULL, NULL}}, CORTO_DESTRUCT(name), {{NULL, NULL}}

#define CORTO_IF_TYPE(name) CORTO_INIT(name), CORTO_DEINIT(name)
#define CORTO_IF_CLASS(name)

#define CORTO_CD_TYPE(name)
#define CORTO_CD_CLASS(name) CORTO_CONSTRUCT(name), {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, CORTO_DESTRUCT(name), {{NULL, NULL}}

#define CORTO_NODELEGATE_TYPE(name) {{NULL, NULL}}, {{NULL, NULL}}
#define CORTO_NODELEGATE_CLASS(name) {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}, {{NULL, NULL}}

/* type */
#define CORTO_TYPE_V(parent, name, kind, reference, attr, scopeType, scopeTypeKind, defaultType, defaultProcedureType, DELEGATE) \
  {kind, reference, attr, {scopeType, scopeTypeKind, defaultType, defaultProcedureType}, 0, 0, 0, {0,NULL}, DELEGATE##_TYPE(parent##_##name)}

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
    {CORTO_TYPE_V(parent, name, CORTO_COLLECTION, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE), kind, (corto_type)&elementType##__o.v, max}

/* sequence */
#define CORTO_SEQUENCE_V(subType, length, ...) {length, (subType[]){__VA_ARGS__}}
#define CORTO_SEQUENCE_EMPTY_V(subType) {0, NULL}

/* member */
#define CORTO_MEMBER_V(type, access, state, cond, weak) {(corto_type)&type##__o.v, access, NULL, state, cond, weak, 0, 0}

/* object */
#define CORTO_PACKAGE_O(name, uri, description) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(root, #name, uri, NULL, "Sander Mertens", description)}
#define CORTO_PACKAGE_O_SCOPE(parent, name, uri, description) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(parent, #name, uri, NULL, "Sander Mertens", description)}

/* type object */
#define CORTO_TYPE_O(parent, name, kind, reference, attr)\
    static sso_type parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_type), CORTO_TYPE_V(parent, name, kind, reference, attr, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE)}

/* primitive object */
#define CORTO_PRIMITIVE_O(parent, name, kind, width)\
    sso_primitive parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_primitive), CORTO_PRIMITIVE_V(parent, name, kind, width, CORTO_NODELEGATE)}

/* binary object */
#define CORTO_BINARY_O(parent, name, width)\
    sso_binary parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_binary), {CORTO_PRIMITIVE_V(parent, name, CORTO_BINARY, width, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE)}}

/* boolean object */
#define CORTO_BOOLEAN_O(parent, name)\
    sso_boolean parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_boolean), {CORTO_PRIMITIVE_V(parent, name, CORTO_BOOLEAN, CORTO_WIDTH_8, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE)}}

/* character object */
#define CORTO_CHARACTER_O(parent, name, width)\
    sso_character parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_character), {CORTO_PRIMITIVE_V(parent, name, CORTO_CHARACTER, width, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE)}}

/* int object */
#define CORTO_INT_O(parent, name, width, min, max, scopeType, scopeStateKind, DELEGATE)\
    sso_int parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_int), {CORTO_PRIMITIVE_V(parent, name, CORTO_INTEGER, width, scopeType, scopeStateKind, DELEGATE), min, max}}

/* uint object */
#define CORTO_UINT_O(parent, name, width, min, max)\
    sso_uint parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_uint), {CORTO_PRIMITIVE_V(parent, name, CORTO_UINTEGER, width, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE), min, max}}

/* float object */
#define CORTO_FLOAT_O(parent, name, width, min, max)\
    sso_float parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_float), {CORTO_PRIMITIVE_V(parent, name, CORTO_FLOAT, width, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE), min, max}}

/* text object */
#define CORTO_TEXT_O(parent, name, width, length)\
    sso_text parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_text), {CORTO_PRIMITIVE_V(parent, name, CORTO_TEXT, CORTO_WIDTH_WORD, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE), width, length}}

/* enum object */
#define CORTO_ENUM_O(parent, name)\
    sso_enum parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_enum), {CORTO_PRIMITIVE_V(parent, name, CORTO_ENUM, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}

/* bitmask object */
#define CORTO_BITMASK_O(parent, name)\
    sso_bitmask parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_bitmask), {{CORTO_PRIMITIVE_V(parent, name, CORTO_BITMASK, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}}

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

/* struct object */
#define CORTO_STRUCT_BASE_O(parent, name, base, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE)\
    sso_struct parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_struct), CORTO_STRUCT_V(parent, name, CORTO_STRUCT, base, CORTO_GLOBAL, FALSE, attr, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE)}

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
#define CORTO_IMETHOD_O(parent, name, args, returnType) \
    sso_method parent##_##name##__o = \
    {CORTO_SSO_PO_V(parent, #name args, lang_overridable), {{(corto_type)&returnType##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, 0, 0, 0}}}

/* observer object */
#define CORTO_OBSERVER_O(parent, name, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_observer parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, vstore_observer), {{(corto_type)&lang_void##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, 0}}

/* subscriber object */
#define CORTO_SUBSCRIBER_O(parent, name, impl) \
    void __##impl(void *f, void *r, void *a); \
    sso_subscriber parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, vstore_subscriber), {{{(corto_type)&lang_void##__o.v, FALSE, {0,NULL}, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, 0}, 0}}}

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
    {CORTO_SSO_PO_V(parent, #name, lang_member), CORTO_MEMBER_V(type, access, CORTO_DECLARED | CORTO_VALID, NULL, FALSE)}

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
    {CORTO_SSO_V(parent, #name, lang_delegate), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_DELEGATE, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED|CORTO_VALID, NULL, NULL, CORTO_NODELEGATE), (corto_type)&returnType##__o.v, FALSE, CORTO_SEQUENCE_EMPTY_V(parameter)}}

#define CORTO_ITERATOR_O(parent, name, elementType) \
    sso_iterator parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_iterator), {CORTO_TYPE_V(parent, name, CORTO_ITERATOR, FALSE, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE), (corto_type)&elementType##__o.v}}


/* Forward declarations of classes */
CORTO_FWDECL(class, alias);
CORTO_FWDECL(class, application);
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
CORTO_FWDECL(class, character);
CORTO_FWDECL(class, collection);
CORTO_FWDECL(class, enum);
CORTO_FWDECL(class, int);
CORTO_FWDECL(class, float);
CORTO_FWDECL(class, interface);
CORTO_FWDECL_VSTORE(struct, invokeEvent);
CORTO_FWDECL(class, iterator);
CORTO_FWDECL_SECURE(class, key);
CORTO_FWDECL(class, leaf);
CORTO_FWDECL(class, list);
CORTO_FWDECL_VSTORE(class, loader);
CORTO_FWDECL_SECURE(class, lock);
CORTO_FWDECL(class, map);
CORTO_FWDECL(class, member);
CORTO_FWDECL_VSTORE(class, mount);
CORTO_FWDECL_VSTORE(class, notifyEvent);
CORTO_FWDECL(class, package);
CORTO_FWDECL(class, primitive);
CORTO_FWDECL(class, procedure);
CORTO_FWDECL(class, quantity);
CORTO_FWDECL_VSTORE(class, router);
CORTO_FWDECL_VSTORE(class, routerimpl);
CORTO_FWDECL(class, table);
CORTO_FWDECL(class, tableinstance);
CORTO_FWDECL_VSTORE(class, tool);
CORTO_FWDECL(class, unit);

CORTO_FWDECL(class, sequence);
CORTO_FWDECL(class, struct);
CORTO_FWDECL(class, union);
CORTO_FWDECL(class, text);
CORTO_FWDECL(class, verbatim);
CORTO_FWDECL(class, type);
CORTO_FWDECL(class, uint);
CORTO_FWDECL_NATIVE(class, type);

CORTO_FWDECL_VSTORE(struct, event);
CORTO_FWDECL(struct, delegatedata);
CORTO_FWDECL(struct, interfaceVector);
CORTO_FWDECL(struct, parameter);
CORTO_FWDECL(struct, typeOptions);
CORTO_FWDECL_VSTORE(struct, frame);
CORTO_FWDECL_VSTORE(struct, query);
CORTO_FWDECL_VSTORE(struct, queuePolicy);
CORTO_FWDECL_VSTORE(struct, mountPolicy);
CORTO_FWDECL_VSTORE(struct, mountSubscription);
CORTO_FWDECL_VSTORE(struct, observerEvent);
CORTO_FWDECL_VSTORE(struct, result);
CORTO_FWDECL_VSTORE(struct, sample);
CORTO_FWDECL_VSTORE(struct, subscriberEvent);

/* Abstract classes */
CORTO_FWDECL_VSTORE(interface, dispatcher);

/* Primitives */
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

/* Direct instances of type */
static CORTO_FWDECL(type, any);
static CORTO_FWDECL(type, object);
static CORTO_FWDECL(type, void);
static CORTO_FWDECL(type, unknown);

/* Procedures */
CORTO_FWDECL(procedure, function);
CORTO_FWDECL(procedure, metaprocedure);
CORTO_FWDECL(procedure, method);
CORTO_FWDECL_VSTORE(procedure, remote);
CORTO_FWDECL_VSTORE(procedure, observer);
CORTO_FWDECL_VSTORE(procedure, subscriber);
CORTO_FWDECL_VSTORE(procedure, route);
CORTO_FWDECL(procedure, override);
CORTO_FWDECL(procedure, overridable);

/* Enumerations */
CORTO_FWDECL(enum, collectionKind);
CORTO_FWDECL(enum, compositeKind);
CORTO_FWDECL(enum, equalityKind);
CORTO_FWDECL(enum, inout);
CORTO_FWDECL(enum, primitiveKind);
CORTO_FWDECL(enum, procedureKind);
CORTO_FWDECL(enum, typeKind);
CORTO_FWDECL(enum, width);
CORTO_FWDECL_VSTORE(enum, frameKind);
CORTO_FWDECL_VSTORE(enum, ownership);
CORTO_FWDECL_VSTORE(enum, operatorKind);
CORTO_FWDECL_SECURE(enum, accessKind);
CORTO_FWDECL_SECURE(enum, actionKind);

/* Bitmasks */
CORTO_FWDECL(bitmask, attr);
CORTO_FWDECL_VSTORE(bitmask, eventMask);
CORTO_FWDECL(bitmask, modifier);
CORTO_FWDECL_VSTORE(bitmask, mountMask);
CORTO_FWDECL_VSTORE(bitmask, resultMask);
CORTO_FWDECL(bitmask, state);

/* Sequences */
CORTO_FWDECL(sequence, interfaceseq);
CORTO_FWDECL(sequence, interfaceVectorseq);
CORTO_FWDECL(sequence, int32seq);
CORTO_FWDECL(sequence, objectseq);
CORTO_FWDECL(sequence, parameterseq);
CORTO_FWDECL(sequence, stringseq);
CORTO_FWDECL(sequence, wordseq);

/* Lists */
CORTO_FWDECL_VSTORE(list, resultList);
CORTO_FWDECL(list, objectlist);
CORTO_FWDECL(list, stringlist);
CORTO_FWDECL_VSTORE(list, mountSubscriptionList);

/* Delegates */
CORTO_FWDECL(delegate, post_action);
CORTO_FWDECL(delegate, pre_action);
CORTO_FWDECL(delegate, name_action);
CORTO_FWDECL_VSTORE(delegate, handleAction);

/* Iterators */
CORTO_FWDECL_VSTORE(iterator, resultIter);
CORTO_FWDECL_VSTORE(iterator, subscriberEventIter);
CORTO_FWDECL_VSTORE(iterator, objectIter);
CORTO_FWDECL_VSTORE(iterator, sampleIter);

CORTO_FWDECL_VSTORE(struct, time);

/* Function objects */
CORTO_FWDECL_VSTORE(function, observerEvent_handle);
CORTO_FWDECL_VSTORE(function, subscriberEvent_handle);

/* Overridable objects */
CORTO_FWDECL_(method, type_castable);
CORTO_FWDECL_(method, collection_castable);
CORTO_FWDECL_(method, type_compatible);
CORTO_FWDECL_(method, struct_compatible);
CORTO_FWDECL_(method, interface_resolveMember);
CORTO_FWDECL__SECURE(method, key_authenticate);
CORTO_FWDECL__SECURE(method, lock_authorize);
CORTO_FWDECL__VSTORE(method, routerimpl_findRoute);
CORTO_FWDECL__VSTORE(method, routerimpl_matchRoute);
CORTO_FWDECL__VSTORE(method, mount_onInvoke);
CORTO_FWDECL__VSTORE(method, mount_onId);
CORTO_FWDECL__VSTORE(method, mount_onResume);
CORTO_FWDECL__VSTORE(method, mount_onQuery);
CORTO_FWDECL__VSTORE(method, mount_onHistoryQuery);
CORTO_FWDECL__VSTORE(method, mount_onNotify);
CORTO_FWDECL__VSTORE(method, mount_onBatchNotify);
CORTO_FWDECL__VSTORE(method, mount_onHistoryBatchNotify);
CORTO_FWDECL__VSTORE(method, mount_onSubscribe);
CORTO_FWDECL__VSTORE(method, mount_onUnsubscribe);
CORTO_FWDECL__VSTORE(method, mount_onMount);
CORTO_FWDECL__VSTORE(method, mount_onUnmount);

/* database root */
corto_ssoo_package root__o = {CORTO_ROOT_V(), {"http://corto.io/doc"}};
corto_package root_o = CORTO_OFFSET(&root__o.o.o, sizeof(corto__object));

/* /corto, /corto/lang, /corto/vstore, /corto/secure */
CORTO_PACKAGE_O(corto, "Corto runtime library", "https://www.corto.io");
CORTO_PACKAGE_O_SCOPE(corto, lang, "Corto typesystem", "https://www.corto.io");
CORTO_PACKAGE_O_SCOPE(corto, vstore, "Corto virtual store", "https://www.corto.io");
CORTO_PACKAGE_O_SCOPE(corto, native, "Corto native type integration", "https://www.corto.io");
CORTO_PACKAGE_O_SCOPE(corto, secure, "Corto security framework", "https://www.corto.io");

corto_package corto_o = CORTO_OFFSET(&corto__o.o.o, sizeof(corto__object));
corto_package corto_lang_o = CORTO_OFFSET(&lang__o.o.o, sizeof(corto__object));
corto_package corto_vstore_o = CORTO_OFFSET(&vstore__o.o.o, sizeof(corto__object));
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
CORTO_INT_O(lang, int8, CORTO_WIDTH_8, MIN_INT8, MAX_INT8, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE);
CORTO_INT_O(lang, int16, CORTO_WIDTH_16, MIN_INT16, MAX_INT16, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE);
CORTO_INT_O(lang, int32, CORTO_WIDTH_32, MIN_INT32, MAX_INT32, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE);
CORTO_INT_O(lang, int64, CORTO_WIDTH_64, MIN_INT64, MAX_INT64, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_NODELEGATE);
CORTO_FLOAT_O(lang, float32, CORTO_WIDTH_32, 0, 0);
CORTO_FLOAT_O(lang, float64, CORTO_WIDTH_64, 0, 0);
CORTO_TEXT_O(lang, string, CORTO_WIDTH_8, 0);
CORTO_BINARY_O(lang, word, CORTO_WIDTH_WORD);
CORTO_FW_I(lang, constant);
CORTO_INT_O(lang, constant, CORTO_WIDTH_32, 0, MAX_INT32, CORTO_TYPE_ID(lang_enum), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_constant, init, "()", lang_int16, corto_constant_init);

/* Any type */
CORTO_TYPE_O(lang, any, CORTO_ANY, FALSE, CORTO_ATTR_DEFAULT);

/* Void type */
CORTO_TYPE_O(lang, void, CORTO_VOID, FALSE, CORTO_ATTR_DEFAULT);

/* Unknown type */
CORTO_TYPE_O(lang, unknown, CORTO_VOID, FALSE, CORTO_ATTR_NAMED);

/* Object type */
CORTO_TYPE_O(lang, object, CORTO_VOID, TRUE, CORTO_ATTR_DEFAULT);

/* Package type */
CORTO_FW_IC(lang, package);
CORTO_CLASS_NOBASE_O(lang, package, CORTO_ATTR_DEFAULT|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(lang_package, description, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, version, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, author, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, organization, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, url, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, repository, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, license, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, icon, lang_string, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, use, lang_stringlist, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, public, lang_bool, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_package, managed, lang_bool, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_METHOD_O(lang_package, construct, "()", lang_int16, corto_package_construct);
    CORTO_METHOD_O(lang_package, init, "()", lang_int16, corto_package_init);

CORTO_CLASS_O(lang, application, lang_package, CORTO_GLOBAL, CORTO_ATTR_DEFAULT|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE);
CORTO_CLASS_O(lang, tool, lang_package, CORTO_GLOBAL, CORTO_ATTR_DEFAULT|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE);

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

CORTO_ENUM_O(vstore, operatorKind);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_ADD);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_SUB);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_MUL);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_DIV);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_MOD);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_XOR);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_OR);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_AND);
    CORTO_CONSTANT_O(vstore_operatorKind, ASSIGN_UPDATE);
    CORTO_CONSTANT_O(vstore_operatorKind, ADD);
    CORTO_CONSTANT_O(vstore_operatorKind, SUB);
    CORTO_CONSTANT_O(vstore_operatorKind, MUL);
    CORTO_CONSTANT_O(vstore_operatorKind, DIV);
    CORTO_CONSTANT_O(vstore_operatorKind, MOD);
    CORTO_CONSTANT_O(vstore_operatorKind, INC);
    CORTO_CONSTANT_O(vstore_operatorKind, DEC);
    CORTO_CONSTANT_O(vstore_operatorKind, XOR);
    CORTO_CONSTANT_O(vstore_operatorKind, OR);
    CORTO_CONSTANT_O(vstore_operatorKind, AND);
    CORTO_CONSTANT_O(vstore_operatorKind, NOT);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_OR);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_AND);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_NOT);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_EQ);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_NEQ);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_GT);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_LT);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_GTEQ);
    CORTO_CONSTANT_O(vstore_operatorKind, COND_LTEQ);
    CORTO_CONSTANT_O(vstore_operatorKind, SHIFT_LEFT);
    CORTO_CONSTANT_O(vstore_operatorKind, SHIFT_RIGHT);
    CORTO_CONSTANT_O(vstore_operatorKind, REF);

CORTO_ENUM_O(vstore, ownership);
    CORTO_CONSTANT_O(vstore_ownership, REMOTE_SOURCE);
    CORTO_CONSTANT_O(vstore_ownership, LOCAL_SOURCE);
    CORTO_CONSTANT_O(vstore_ownership, CACHE_OWNER);

CORTO_BITMASK_O(vstore, mountMask);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_QUERY);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_HISTORY_QUERY);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_NOTIFY);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_BATCH_NOTIFY);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_HISTORY_BATCH_NOTIFY);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_SUBSCRIBE);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_MOUNT);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_RESUME);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_INVOKE);
    CORTO_CONSTANT_O(vstore_mountMask, MOUNT_ID);

CORTO_ENUM_O(vstore, frameKind);
    CORTO_CONSTANT_O(vstore_frameKind, FRAME_NOW);
    CORTO_CONSTANT_O(vstore_frameKind, FRAME_TIME);
    CORTO_CONSTANT_O(vstore_frameKind, FRAME_DURATION);

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
    CORTO_CONSTANT_O(lang_state, DELETED);
    CORTO_CONSTANT_O(lang_state, DECLARED);

CORTO_BITMASK_O(lang, attr);
    CORTO_CONSTANT_O(lang_attr, ATTR_NAMED);
    CORTO_CONSTANT_O(lang_attr, ATTR_WRITABLE);
    CORTO_CONSTANT_O(lang_attr, ATTR_OBSERVABLE);
    CORTO_CONSTANT_O(lang_attr, ATTR_PERSISTENT);
    CORTO_CONSTANT_O(lang_attr, ATTR_DEFAULT);

CORTO_BITMASK_O(vstore, eventMask);
    CORTO_CONSTANT_O(vstore_eventMask, DECLARE);
    CORTO_CONSTANT_O(vstore_eventMask, DEFINE);
    CORTO_CONSTANT_O(vstore_eventMask, DELETE);
    CORTO_CONSTANT_O(vstore_eventMask, INVALIDATE);
    CORTO_CONSTANT_O(vstore_eventMask, UPDATE);
    CORTO_CONSTANT_O(vstore_eventMask, RESUME);
    CORTO_CONSTANT_O(vstore_eventMask, SUSPEND);
    CORTO_CONSTANT_O(vstore_eventMask, ON_SELF);
    CORTO_CONSTANT_O(vstore_eventMask, ON_SCOPE);
    CORTO_CONSTANT_O(vstore_eventMask, ON_TREE);
    CORTO_CONSTANT_O(vstore_eventMask, ON_VALUE);
    CORTO_CONSTANT_O(vstore_eventMask, ON_METAVALUE);
    CORTO_CONSTANT_O(vstore_eventMask, ON_ANY);

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

CORTO_BITMASK_O(vstore, resultMask);
    CORTO_CONSTANT_O(vstore_resultMask, RESULT_LEAF);
    CORTO_CONSTANT_O(vstore_resultMask, RESULT_HIDDEN);

/* Collections */
CORTO_SEQUENCE_O(lang, interfaceseq, lang_interface, 0);
CORTO_SEQUENCE_O(lang, interfaceVectorseq, lang_interfaceVector, 0);
CORTO_SEQUENCE_O(lang, int32seq, lang_int32, 0);
CORTO_SEQUENCE_O(lang, objectseq, lang_object, 0);
CORTO_SEQUENCE_O(lang, parameterseq, lang_parameter, 0);
CORTO_SEQUENCE_O(lang, stringseq, lang_string, 0);
CORTO_SEQUENCE_O(lang, wordseq, lang_word, 0);
CORTO_LIST_O(lang, stringlist, lang_string, 0);
CORTO_LIST_O(lang, objectlist, lang_object, 0);
CORTO_LIST_O(vstore, resultList, vstore_result, 0);
CORTO_LIST_O(vstore, mountSubscriptionList, vstore_mountSubscription, 0);

/* Delegate types */
CORTO_DELEGATE_O(lang, pre_action, lang_int16);
CORTO_DELEGATE_O(lang, name_action, lang_string);
CORTO_DELEGATE_O(lang, post_action, lang_void);
CORTO_DELEGATE_O(vstore, handleAction, lang_void);

/* Iterator types */
CORTO_ITERATOR_O(vstore, objectIter, lang_object);
CORTO_ITERATOR_O(vstore, resultIter, vstore_result);
CORTO_ITERATOR_O(vstore, subscriberEventIter, vstore_subscriberEvent);
CORTO_ITERATOR_O(vstore, sampleIter, vstore_sample);

/* /corto/lang/typeOptions */
CORTO_STRUCT_O(lang, typeOptions, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_REFERENCE_O(lang_typeOptions, parentType, lang_type, CORTO_GLOBAL, CORTO_DECLARED|CORTO_VALID, NULL, FALSE);
    CORTO_MEMBER_O(lang_typeOptions, parentState, lang_state, CORTO_GLOBAL);
    CORTO_REFERENCE_O(lang_typeOptions, defaultType, lang_type, CORTO_GLOBAL, CORTO_VALID, NULL, FALSE);
    CORTO_REFERENCE_O(lang_typeOptions, defaultProcedureType, lang_type, CORTO_GLOBAL, CORTO_VALID, NULL, FALSE);

/* /corto/lang/type */
CORTO_FW_ICD(lang, type);
CORTO_CLASS_NOBASE_O(lang, type, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_type, kind, lang_typeKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, reference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, attr, lang_attr, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, options, lang_typeOptions, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_type, flags, lang_uint16, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, size, lang_uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, alignment, lang_uint16, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, metaprocedures, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, init, lang_pre_action, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, deinit, lang_post_action, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, nameof, lang_name_action, CORTO_LOCAL | CORTO_PRIVATE);
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
CORTO_CLASS_O(lang, primitive, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
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
CORTO_CLASS_O(lang, interface, lang_type, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_overridable), CORTO_ICD);
    CORTO_MEMBER_O(lang_interface, kind, lang_compositeKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_interface, nextMemberId, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, members, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, methods, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_REFERENCE_O(lang_interface, base, lang_interface, CORTO_GLOBAL, CORTO_VALID, NULL, FALSE);
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
CORTO_CLASS_O(lang, collection, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_collection, kind, lang_collectionKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_REFERENCE_O(lang_collection, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(lang_collection, max, lang_uint32, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(lang_collection, castable, "(type type)", lang_bool, corto_collection_castable_v);
    CORTO_OVERRIDABLE_O(lang_collection, compatible, "(type type)", lang_bool, corto_collection_compatible_v);
    CORTO_FUNCTION_O(lang_collection, requiresAlloc, "(type elementType)", lang_bool, corto_collection_requiresAlloc);
    CORTO_METHOD_O(lang_collection, init, "()", lang_int16, corto_collection_init);

/* /corto/lang/iterator */
CORTO_FW_I(lang, iterator);
CORTO_CLASS_O(lang, iterator, lang_type, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_REFERENCE_O(lang_iterator, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, NULL, FALSE);
    CORTO_METHOD_O(lang_iterator, init, "()", lang_int16, corto_iterator_init);
    CORTO_OVERRIDABLE_O(lang_iterator, compatible, "(type type)", lang_bool, corto_iterator_compatible_v);
    CORTO_OVERRIDABLE_O(lang_iterator, castable, "(type type)", lang_bool, corto_iterator_castable_v);

/* /corto/lang/binary */
CORTO_FW_I(lang, binary);
CORTO_CLASS_O(lang, binary, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_binary, init, "()", lang_int16, corto_binary_init);

/* /corto/lang/boolean */
CORTO_FW_I(lang, boolean);
CORTO_CLASS_O(lang, boolean, lang_primitive, CORTO_GLOBAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_boolean, init, "()", lang_int16, corto_boolean_init);

/* /corto/lang/character */
CORTO_FW_I(lang, character);
CORTO_CLASS_O(lang, character, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_character, init, "()", lang_int16, corto_character_init);

/* /corto/lang/int */
CORTO_FW_I(lang, int);
CORTO_CLASS_O(lang, int, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_int, min, lang_int64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_int, max, lang_int64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_int, init, "()", lang_int16, corto_int_init);

/* /corto/lang/uint */
CORTO_FW_I(lang, uint);
CORTO_CLASS_O(lang, uint, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_uint, min, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_uint, max, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_uint, init, "()", lang_int16, corto_uint_init);

/* /corto/lang/float */
CORTO_FW_I(lang, float);
CORTO_CLASS_O(lang, float, lang_primitive, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_float, min, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_float, max, lang_float64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_float, init, "()", lang_int16, corto_float_init);

/* /corto/lang/text */
CORTO_FW_I(lang, text);
CORTO_CLASS_O(lang, text, lang_primitive, CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_text, charWidth, lang_width, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_text, length, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_text, init, "()", lang_int16, corto_text_init);

/* /corto/lang/verbatim */
CORTO_FW_I(lang, verbatim);
CORTO_CLASS_O(lang, verbatim, lang_primitive, CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_verbatim, contentType, lang_string, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_verbatim, init, "()", lang_int16, corto_text_init);

/* /corto/lang/enum */
CORTO_FW_ICD(lang, enum);
CORTO_CLASS_O(lang, enum, lang_primitive, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_constant), NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_enum, constants, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_enum, init, "()", lang_int16, corto_enum_init);
    CORTO_METHOD_O(lang_enum, construct, "()", lang_int16, corto_enum_construct);
    CORTO_METHOD_O(lang_enum, destruct, "()", lang_void, corto_enum_destruct);
    CORTO_METHOD_O(lang_enum, constant, "(int32 value)", lang_object, corto_enum_constant);

/* /corto/lang/bitmask */
CORTO_FW_I(lang, bitmask);
CORTO_CLASS_O(lang, bitmask, lang_enum, CORTO_LOCAL | CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_constant), NULL, CORTO_I);
    CORTO_METHOD_O(lang_bitmask, init, "()", lang_int16, corto_bitmask_init);

/* /corto/lang/struct */
CORTO_FW_ICD(lang, struct);
CORTO_CLASS_O(lang, struct, lang_interface, CORTO_HIDDEN, CORTO_ATTR_DEFAULT|CORTO_ATTR_NAMED, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_ALIAS_O (lang_struct, base, lang_interface_base, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_struct, baseAccess, lang_modifier, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_struct, keys, lang_stringseq, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_struct, keycache, lang_objectseq, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_struct, freeops, lang_word, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_OVERRIDABLE_O(lang_struct, compatible, "(type type)", lang_bool, corto_struct_compatible_v);
    CORTO_OVERRIDABLE_O(lang_struct, castable, "(type type)", lang_bool, corto_struct_castable_v);
    CORTO_OVERRIDABLE_O(lang_struct, resolveMember, "(string name)", lang_member, corto_struct_resolveMember_v);
    CORTO_METHOD_O(lang_struct, init, "()", lang_int16, corto_struct_init);
    CORTO_METHOD_O(lang_struct, construct, "()", lang_int16, corto_struct_construct);
    CORTO_METHOD_O(lang_struct, destruct, "()", lang_void, corto_struct_destruct);

/* /corto/lang/union */
CORTO_FW_IC(lang, union);
CORTO_CLASS_O(lang, union, lang_interface, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_case), CORTO_TYPE_ID(lang_method), CORTO_IC);
    CORTO_MEMBER_O(lang_union, discriminator, lang_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_union, init, "()", lang_int16, corto_union_init);
    CORTO_METHOD_O(lang_union, construct, "()", lang_int16, corto_union_construct);
    CORTO_METHOD_O(lang_union, findCase, "(int32 discriminator)", lang_member, corto_union_findCase);

/* /corto/lang/interfaceVector */
CORTO_STRUCT_O(lang, interfaceVector, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(lang_interfaceVector, interface, lang_interface, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_interfaceVector, vector, lang_objectseq, CORTO_GLOBAL);

/* /corto/lang/class */
CORTO_FW_ICD(lang, class);
CORTO_CLASS_O(lang, class, lang_struct, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_ALIAS_O (lang_class, base, lang_struct_base, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_class, baseAccess, lang_struct_baseAccess, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_class, implements, lang_interfaceseq, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_class, interfaceVector, lang_interfaceVectorseq, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, construct, lang_pre_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, define, lang_post_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, validate, lang_pre_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, update, lang_post_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, destruct, lang_post_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, delete, lang_post_action, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(lang_class, init, "()", lang_int16, corto_class_init);
    CORTO_METHOD_O(lang_class, construct, "()", lang_int16, corto_class_construct);
    CORTO_METHOD_O(lang_class, destruct, "()", lang_void, corto_class_destruct);
    CORTO_METHOD_O(lang_class, instanceof, "(object object)", lang_bool, corto_class_instanceof);
    CORTO_METHOD_O(lang_class, resolveInterfaceMethod, "(interface interface,uint32 method)", lang_method, corto_class_resolveInterfaceMethod);

/* /corto/lang/delegatedata */
CORTO_STRUCT_O(lang, delegatedata, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(lang_delegatedata, instance, lang_object, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegatedata, procedure, lang_function, CORTO_GLOBAL);

/* /corto/lang/delegate */
CORTO_FW_I(lang, delegate);
CORTO_CLASS_O(lang, delegate, lang_struct, CORTO_READONLY, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_I);
    CORTO_METHOD_O(lang_delegate, init, "()", lang_int16, corto_delegate_init);
    CORTO_REFERENCE_O(lang_delegate, returnType, lang_type, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(lang_delegate, returnsReference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegate, parameters, lang_parameterseq, CORTO_GLOBAL);
    CORTO_OVERRIDABLE_O(lang_delegate, compatible, "(type type)", lang_bool, corto_delegate_compatible_v);
    CORTO_OVERRIDABLE_O(lang_delegate, castable, "(type type)", lang_bool, corto_delegate_compatible_v);
    CORTO_METHOD_O(lang_delegate, instanceof, "(object object)", lang_bool, corto_delegate_instanceof);
    CORTO_FUNCTION_O(lang_delegate, bind, "(function object)", lang_int16, corto_delegate_bind);

/* /corto/lang/target */
CORTO_FW_C(lang, target);
CORTO_CLASS_O(lang, target, lang_struct, CORTO_READONLY, CORTO_ATTR_NAMED|CORTO_ATTR_OBSERVABLE, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_C);
    CORTO_METHOD_O(lang_target, construct, "()", lang_int16, corto_target_construct);
    CORTO_MEMBER_O(lang_target, type, lang_type, CORTO_GLOBAL);

/* /corto/lang/procedure */
CORTO_FW_IC(lang, procedure);
CORTO_CLASS_O(lang, procedure, lang_class, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(lang_procedure, hasThis, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_procedure, thisType, lang_type, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_procedure, init, "()", lang_int16, corto_procedure_init);
    CORTO_METHOD_O(lang_procedure, construct, "()", lang_int16, corto_procedure_construct);

/* /corto/lang/array */
CORTO_FW_ICD(lang, array);
CORTO_CLASS_O(lang, array, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_ICD);
    CORTO_REFERENCE_O(lang_array, elementType, lang_type, CORTO_GLOBAL|CORTO_PRIVATE, CORTO_VALID, NULL, FALSE);
    CORTO_METHOD_O(lang_array, init, "()", lang_int16, corto_array_init);
    CORTO_METHOD_O(lang_array, construct, "()", lang_int16, corto_array_construct);
    CORTO_METHOD_O(lang_array, destruct, "()", lang_void, corto_array_destruct);

/* /corto/lang/sequence */
CORTO_FW_IC(lang, sequence);
CORTO_CLASS_O(lang, sequence, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_sequence, init, "()", lang_int16, corto_sequence_init);
    CORTO_METHOD_O(lang_sequence, construct, "()", lang_int16, corto_sequence_construct);

/* /corto/lang/list */
CORTO_FW_IC(lang, list);
CORTO_CLASS_O(lang, list, lang_collection, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_list, init, "()", lang_int16, corto_list_init);
    CORTO_METHOD_O(lang_list, construct, "()", lang_int16, corto_list_construct);

/* /corto/lang/map */
CORTO_FW_IC(lang, map);
CORTO_CLASS_O(lang, map, lang_collection, CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    /* Duplicate members for a more convenient order in the initializer */
    CORTO_REFERENCE_O(lang_map, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_VALID, NULL, FALSE);
    CORTO_REFERENCE_O(lang_map, keyType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_VALID, NULL, FALSE);
    CORTO_MEMBER_O(lang_map, max, lang_uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_map, init, "()", lang_int16, corto_map_init);
    CORTO_METHOD_O(lang_map, construct, "()", lang_int16, corto_map_construct);

/* /corto/lang/function */
CORTO_FW_ICD(lang, function);
CORTO_PROCEDURE_NOBASE_O(lang, function, FALSE, NULL, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_ICD);
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
CORTO_PROCEDURE_O(lang, method, TRUE, NULL, lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_method, index, lang_uint32, CORTO_LOCAL|CORTO_PRIVATE);

/* /corto/lang/overridable */
CORTO_FW_I(lang, overridable);
CORTO_PROCEDURE_O(lang, overridable, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_overridable, init, "()", lang_int16, corto_overridable_init);


/* /corto/lang/override */
CORTO_PROCEDURE_O(lang, override, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_NODELEGATE);

/* /corto/lang/metaprocedure */
CORTO_FW_C(lang, metaprocedure);
CORTO_PROCEDURE_O(lang, metaprocedure, TRUE, CORTO_TYPE_ID(lang_any), lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED|CORTO_VALID, CORTO_C);
    CORTO_METHOD_O(lang_metaprocedure, construct, "()", lang_int16, corto_metaprocedure_construct);
    CORTO_MEMBER_O(lang_metaprocedure, referenceOnly, lang_bool, CORTO_GLOBAL);

/* /corto/lang/member */
CORTO_FW_IC(lang, member);
CORTO_CLASS_NOBASE_O(lang, member, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(lang_member, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_VALID, "reference", FALSE);
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
CORTO_FW_C(lang, alias);
CORTO_CLASS_O(lang, alias, lang_member, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_struct), CORTO_DECLARED, NULL, NULL, CORTO_C);
    CORTO_REFERENCE_O(lang_alias, member, lang_member, CORTO_GLOBAL, CORTO_VALID, NULL, FALSE);
    CORTO_METHOD_O(lang_alias, construct, "()", lang_int16, corto_alias_construct);

/* /corto/lang/case */
CORTO_CLASS_O(lang, case, lang_member, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_union), CORTO_DECLARED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_case, discriminator, lang_int32seq, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_case, type, lang_member_type, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_case, modifiers, lang_member_modifiers, CORTO_GLOBAL);

/* /corto/lang/default */
CORTO_CLASS_O(lang, default, lang_case, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, CORTO_TYPE_ID(lang_union), CORTO_DECLARED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_ALIAS_O (lang_default, type, lang_case_type, CORTO_GLOBAL);

/* /corto/lang/parameter */
CORTO_STRUCT_O(lang, parameter, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(lang_parameter, name, lang_string, CORTO_GLOBAL);
    CORTO_REFERENCE_O(lang_parameter, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_VALID, NULL, FALSE);
    CORTO_MEMBER_O(lang_parameter, inout, lang_inout, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_parameter, passByReference, lang_bool, CORTO_GLOBAL);

/* /corto/lang/quantity */
CORTO_CLASS_NOBASE_O(lang, quantity, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_quantity, base_unit, lang_unit, CORTO_GLOBAL);

/* /corto/lang/unit */
CORTO_FW_IC(lang, unit);
CORTO_CLASS_NOBASE_O(lang, unit, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(lang_unit, quantity, lang_quantity, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, symbol, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, conversion, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, type, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_unit, toQuantity, lang_word, CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_unit, fromQuantity, lang_word, CORTO_PRIVATE);
    CORTO_METHOD_O(lang_unit, init, "()", lang_int16, corto_unit_init);
    CORTO_METHOD_O(lang_unit, construct, "()", lang_int16, corto_unit_construct);

/* /corto/lang/container */
CORTO_FW_C(lang, container);
CORTO_CLASS_O(lang, container, lang_class, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_C);
    CORTO_METHOD_O(lang_container, construct, "()", lang_int16, corto_container_construct);
    CORTO_MEMBER_O(lang_container, type, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_container, value, lang_string, CORTO_GLOBAL);

/* /corto/lang/leaf */
CORTO_CLASS_O(lang, leaf, lang_container, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_NODELEGATE);

/* /corto/lang/table */
CORTO_FW_C(lang, table);
CORTO_CLASS_O(lang, table, lang_container, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_C);
    CORTO_METHOD_O(lang_table, construct, "()", lang_int16, corto_table_construct);

/* /corto/lang/tableinstance */
CORTO_CLASS_NOBASE_O(lang, tableinstance, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(lang_tableinstance, type, lang_struct, CORTO_GLOBAL);

/* /corto/vstore/sample */
CORTO_STRUCT_O(vstore, sample, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_sample, timestamp, vstore_time, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_sample, value, lang_word, CORTO_GLOBAL);

/* /corto/vstore/result */
CORTO_STRUCT_O(vstore, result, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_result, id, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, name, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, value, lang_word, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, flags, vstore_resultMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_result, object, lang_object, CORTO_HIDDEN);
    CORTO_MEMBER_O(vstore_result, history, vstore_sampleIter, CORTO_HIDDEN);
    CORTO_MEMBER_O(vstore_result, owner, lang_object, CORTO_HIDDEN);
    CORTO_METHOD_O(vstore_result, getText, "()", lang_string, corto_result_getText);
    CORTO_METHOD_O(vstore_result, fromcontent, "(string contentType,string content)", lang_int16, corto_result_fromcontent);
    CORTO_METHOD_O(vstore_result, contentof, "(string contentType)", lang_string, corto_result_contentof);

/* /corto/lang/dispatcher */
CORTO_INTERFACE_O(vstore, dispatcher);
    CORTO_IMETHOD_O(vstore_dispatcher, post, "(event e)", lang_void);

/* /corto/lang/event */
CORTO_STRUCT_O(vstore, event, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_event, handleAction, vstore_handleAction, CORTO_LOCAL | CORTO_READONLY);
    CORTO_METHOD_O(vstore_event, handle, "()", lang_void, corto_event_handle);

/* /corto/lang/observerEvent */
CORTO_FW_IF(vstore, observerEvent);
CORTO_STRUCT_BASE_O(vstore, observerEvent, vstore_event, 0, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IF);
    CORTO_REFERENCE_O(vstore_observerEvent, observer, vstore_observer, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_observerEvent, instance, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_observerEvent, source, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(vstore_observerEvent, event, vstore_eventMask, CORTO_GLOBAL);
    CORTO_REFERENCE_O(vstore_observerEvent, data, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(vstore_observerEvent, thread, lang_word, CORTO_GLOBAL);
    CORTO_FUNCTION_O(vstore_observerEvent, handle, "(vstore/event e)", lang_void, corto_observerEvent_handle);
    CORTO_METHOD_O(vstore_observerEvent, init, "()", lang_int16, corto_observerEvent_init);
    CORTO_METHOD_O(vstore_observerEvent, deinit, "()", lang_void, corto_observerEvent_deinit);

/* /corto/lang/subscriberEvent */
CORTO_FW_IF(vstore, subscriberEvent);
CORTO_STRUCT_BASE_O(vstore, subscriberEvent, vstore_event, 0, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_IF);
    CORTO_REFERENCE_O(vstore_subscriberEvent, subscriber, vstore_subscriber, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_subscriberEvent, instance, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_subscriberEvent, source, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(vstore_subscriberEvent, event, vstore_eventMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_subscriberEvent, data, vstore_result, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_subscriberEvent, contentTypeHandle, lang_word, CORTO_GLOBAL);
    CORTO_FUNCTION_O(vstore_subscriberEvent, handle, "(vstore/event e)", lang_void, corto_subscriberEvent_handle);
    CORTO_METHOD_O(vstore_subscriberEvent, init, "()", lang_int16, corto_subscriberEvent_init);
    CORTO_METHOD_O(vstore_subscriberEvent, deinit, "()", lang_void, corto_subscriberEvent_deinit);

/* /corto/lang/invokeEvent */
CORTO_STRUCT_BASE_O(vstore, invokeEvent, vstore_event, 0, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(vstore_invokeEvent, mount, vstore_mount, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_invokeEvent, instance, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_invokeEvent, function, lang_function, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_invokeEvent, args, lang_word, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_OVERRIDABLE_O(vstore_invokeEvent, handle, "()", lang_void, corto_invokeEvent_handle_v);

/* /corto/vstore/remote */
CORTO_PROCEDURE_O(vstore, remote, TRUE, NULL, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_NODELEGATE);

/* /corto/vstore/observer */
CORTO_FW_ICD(vstore, observer);
CORTO_PROCEDURE_O(vstore, observer, FALSE, NULL, lang_function, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_ICD);
    CORTO_MEMBER_O(vstore_observer, mask, vstore_eventMask, CORTO_GLOBAL);
    CORTO_REFERENCE_O(vstore_observer, observable, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_observer, instance, lang_object, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_REFERENCE_O(vstore_observer, dispatcher, vstore_dispatcher, CORTO_GLOBAL, CORTO_VALID | CORTO_DECLARED, NULL, FALSE);
    CORTO_MEMBER_O(vstore_observer, type, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_observer, enabled, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_observer, active, lang_uint32, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_METHOD_O(vstore_observer, init, "()", lang_int16, corto_observer_init);
    CORTO_METHOD_O(vstore_observer, construct, "()", lang_int16, corto_observer_construct);
    CORTO_METHOD_O(vstore_observer, destruct, "()", lang_void, corto_observer_destruct);
    CORTO_METHOD_O(vstore_observer, observe, "(object instance,object observable)", lang_int16, corto_observer_observe);
    CORTO_METHOD_O(vstore_observer, unobserve, "(object instance,object observable)", lang_int16, corto_observer_unobserve);
    CORTO_METHOD_O(vstore_observer, observing, "(object instance,object observable)", lang_bool, corto_observer_observing);

/* /corto/vstore/query */
CORTO_STRUCT_O(vstore, query, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_query, select, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, from, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, member, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, where, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, offset, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, limit, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, soffset, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, slimit, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, timeBegin, vstore_frame, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, timeEnd, vstore_frame, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_query, content, lang_bool, CORTO_GLOBAL|CORTO_HIDDEN);
    CORTO_METHOD_O(vstore_query, cardinality, "()", lang_uint32, corto_query_cardinality);
    CORTO_METHOD_O(vstore_query, match, "(vstore/result result)", lang_bool, corto_query_cardinality);

/* /corto/vstore/subscriber */
CORTO_FW_IFCDD(vstore, subscriber);
CORTO_PROCEDURE_O(vstore, subscriber, FALSE, NULL, vstore_observer, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_VALID, CORTO_IFCDD);
    CORTO_MEMBER_O(vstore_subscriber, query, vstore_query, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_subscriber, contentType, lang_string, CORTO_GLOBAL);
    CORTO_ALIAS_O(vstore_subscriber, instance, vstore_observer_instance, CORTO_GLOBAL);
    CORTO_ALIAS_O(vstore_subscriber, dispatcher, vstore_observer_dispatcher, CORTO_GLOBAL);
    CORTO_ALIAS_O(vstore_subscriber, enabled, vstore_observer_enabled, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_subscriber, contentTypeHandle, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_MEMBER_O(vstore_subscriber, idmatch, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_MEMBER_O(vstore_subscriber, isAligning, lang_bool, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_subscriber, alignMutex, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_subscriber, alignQueue, lang_objectlist, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(vstore_subscriber, init, "()", lang_int16, corto_subscriber_init);
    CORTO_METHOD_O(vstore_subscriber, deinit, "()", lang_void, corto_subscriber_deinit);
    CORTO_METHOD_O(vstore_subscriber, construct, "()", lang_int16, corto_subscriber_construct);
    CORTO_METHOD_O(vstore_subscriber, define, "()", lang_void, corto_subscriber_define);
    CORTO_METHOD_O(vstore_subscriber, destruct, "()", lang_void, corto_subscriber_destruct);
    CORTO_METHOD_O(vstore_subscriber, subscribe, "(object instance)", lang_int16, corto_subscriber_subscribe);
    CORTO_METHOD_O(vstore_subscriber, unsubscribe, "(object instance)", lang_int16, corto_subscriber_unsubscribe);

/* /corto/vstore/queuePolicy */
CORTO_STRUCT_O(vstore, queuePolicy, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_queuePolicy, max, lang_uint32, CORTO_GLOBAL);

/* /corto/vstore/mountPolicy */
CORTO_STRUCT_O(vstore, mountPolicy, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_mountPolicy, ownership, vstore_ownership, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountPolicy, mask, vstore_mountMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountPolicy, sampleRate, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountPolicy, queue, vstore_queuePolicy, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountPolicy, expiryTime, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountPolicy, filterResults, lang_bool, CORTO_GLOBAL);

/* /corto/vstore/mountSubscription */
CORTO_STRUCT_O(vstore, mountSubscription, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_mountSubscription, query, vstore_query, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountSubscription, mountCount, lang_uint32, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountSubscription, subscriberCount, lang_uint32, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountSubscription, subscriberCtx, lang_word, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mountSubscription, mountCtx, lang_word, CORTO_GLOBAL);

/* /corto/vstore/mount */
CORTO_FW_ICD(vstore, mount);
CORTO_CLASS_O(vstore, mount, vstore_subscriber, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_ICD);
    CORTO_ALIAS_O(vstore_mount, query, vstore_subscriber_query, CORTO_GLOBAL);
    CORTO_ALIAS_O(vstore_mount, contentType, vstore_subscriber_contentType, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mount, policy, vstore_mountPolicy, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_mount, mount, lang_object, CORTO_HIDDEN);
    CORTO_MEMBER_O(vstore_mount, attr, lang_attr, CORTO_HIDDEN);
    CORTO_MEMBER_O(vstore_mount, subscriptions, vstore_mountSubscriptionList, CORTO_READONLY);
    CORTO_MEMBER_O(vstore_mount, events, lang_objectlist, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, historicalEvents, lang_objectlist, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, lastPoll, vstore_time, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, lastPost, vstore_time, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, lastSleep, vstore_time, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, dueSleep, vstore_time, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, lastQueueSize, lang_uint32, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, passThrough, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, explicitResume, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, thread, lang_word, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, quit, lang_bool, CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_mount, contentTypeOut, lang_string, CORTO_READONLY|CORTO_LOCAL);
    CORTO_MEMBER_O(vstore_mount, contentTypeOutHandle, lang_word, CORTO_READONLY|CORTO_LOCAL);
    CORTO_METHOD_O(vstore_mount, init, "()", lang_int16, corto_mount_init);
    CORTO_METHOD_O(vstore_mount, construct, "()", lang_int16, corto_mount_construct);
    CORTO_METHOD_O(vstore_mount, destruct, "()", lang_void, corto_mount_destruct);
    CORTO_METHOD_O(vstore_mount, post, "(event e)", lang_void, corto_mount_post);
    CORTO_METHOD_O(vstore_mount, onPoll, "()", lang_void, corto_mount_onPoll);
    CORTO_METHOD_O(vstore_mount, setContentType, "(string type)", lang_int16, corto_mount_setContentType);
    CORTO_METHOD_O(vstore_mount, setContentTypeIn, "(string type)", lang_int16, corto_mount_setContentTypeIn);
    CORTO_METHOD_O(vstore_mount, setContentTypeOut, "(string type)", lang_int16, corto_mount_setContentTypeOut);
    CORTO_METHOD_O(vstore_mount, return, "(vstore/result r)", lang_void, corto_mount_return);
    CORTO_METHOD_O(vstore_mount, publish, "(vstore/eventMask event,string from,string id,string type,word value)", lang_void, corto_mount_unsubscribe);
    CORTO_METHOD_O(vstore_mount, invoke, "(object instance,function proc,word argptrs)", lang_void, corto_mount_invoke);
    CORTO_METHOD_O(vstore_mount, id, "()", lang_string, corto_mount_id);
    CORTO_METHOD_O(vstore_mount, query, "(vstore/query query)", vstore_resultIter, corto_mount_query);
    CORTO_METHOD_O(vstore_mount, historyQuery, "(vstore/query query)", vstore_resultIter, corto_mount_query);
    CORTO_METHOD_O(vstore_mount, resume, "(string parent,string name,object o)", lang_object, corto_mount_resume);
    CORTO_METHOD_O(vstore_mount, subscribe, "(/corto/vstore/query query)", lang_void, corto_mount_subscribe);
    CORTO_METHOD_O(vstore_mount, unsubscribe, "(/corto/vstore/query query)", lang_void, corto_mount_unsubscribe);
    CORTO_OVERRIDABLE_O(vstore_mount, onInvoke, "(object instance,function proc,word argptrs)", lang_void, corto_mount_onInvoke_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onId, "()", lang_string, corto_mount_onId_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onQuery, "(/corto/vstore/query query)", vstore_resultIter, corto_mount_onQuery_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onHistoryQuery, "(/corto/vstore/query query)", vstore_resultIter, corto_mount_onHistoryQuery_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onResume, "(string parent,string id,object object)", lang_object, corto_mount_onResume_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onNotify, "(vstore/subscriberEvent event)", lang_void, corto_mount_onNotify_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onBatchNotify, "(vstore/subscriberEventIter events)", lang_void, corto_mount_onBatchNotify_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onHistoryBatchNotify, "(vstore/subscriberEventIter events)", lang_void, corto_mount_onBatchNotify_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onSubscribe, "(vstore/query query,lang/word ctx)", lang_word, corto_mount_onSubscribe_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onUnsubscribe, "(vstore/query query,lang/word ctx)", lang_void, corto_mount_onUnsubscribe_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onMount, "(vstore/query query,lang/word ctx)", lang_word, corto_mount_onMount_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onUnmount, "(vstore/query query,lang/word ctx)", lang_void, corto_mount_onUnmount_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onTransactionBegin, "()", lang_word, corto_mount_onSubscribe_v);
    CORTO_OVERRIDABLE_O(vstore_mount, onTransactionEnd, "(vstore/subscriberEventIter events,word ctx)", lang_void, corto_mount_onUnsubscribe_v);

/* /corto/vstore/router */
CORTO_FW_IC(vstore, router);
CORTO_CLASS_O(vstore, router, lang_class, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, CORTO_TYPE_ID(lang_method), CORTO_IC);
    CORTO_METHOD_O(vstore_router, init, "()", lang_int16, corto_router_init);
    CORTO_METHOD_O(vstore_router, construct, "()", lang_int16, corto_router_construct);
    CORTO_MEMBER_O(vstore_router, returnType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_router, paramType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_router, paramName, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_router, routerDataType, lang_type, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_router, routerDataName, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_router, elementSeparator, lang_string, CORTO_GLOBAL);
    CORTO_FUNCTION_O(vstore_router, match, "(lang/object instance,string request,any param,any result,out:vstore/route matched)", lang_int16, corto_router_match);

/* /corto/vstore/routerimpl */
CORTO_FW_CD(vstore, routerimpl);
CORTO_CLASS_O(vstore, routerimpl, lang_class, CORTO_GLOBAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_CD);
    CORTO_METHOD_O(vstore_routerimpl, construct, "()", lang_int16, corto_routerimpl_construct);
    CORTO_METHOD_O(vstore_routerimpl, destruct, "()", lang_void, corto_routerimpl_destruct);
    CORTO_MEMBER_O(vstore_routerimpl, maxArgs, lang_uint16, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(vstore_routerimpl, matched, vstore_route, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_OVERRIDABLE_O(vstore_routerimpl, matchRoute, "(vstore/route route,stringseq pattern,any param,out:any routerData)", lang_int32, corto_routerimpl_matchRoute_v);
    CORTO_OVERRIDABLE_O(vstore_routerimpl, findRoute, "(object instance,stringseq pattern,any param,out:any routerData)", vstore_route, corto_routerimpl_findRoute_v);


/* /corto/vstore/route */
CORTO_FW_IC(vstore, route);
CORTO_PROCEDURE_O(vstore, route, TRUE, NULL, lang_method, CORTO_LOCAL | CORTO_READONLY, CORTO_TYPE_ID(vstore_routerimpl), CORTO_DECLARED, CORTO_IC);
    CORTO_MEMBER_O(vstore_route, pattern, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_route, elements, lang_stringseq, CORTO_READONLY);
    CORTO_METHOD_O(vstore_route, init, "()", lang_int16, corto_route_init);
    CORTO_METHOD_O(vstore_route, construct, "()", lang_int16, corto_route_construct);

/* /corto/vstore/time */
CORTO_STRUCT_O(vstore, time, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_time, sec, lang_int32, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_time, nanosec, lang_uint32, CORTO_GLOBAL);

/* /corto/vstore/frame */
CORTO_STRUCT_O(vstore, frame, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL);
    CORTO_MEMBER_O(vstore_frame, kind, vstore_frameKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(vstore_frame, value, lang_int64, CORTO_GLOBAL);
    CORTO_METHOD_O(vstore_frame, getTime, "()", vstore_time, corto_frame_getTime);

/* /corto/native/type */
CORTO_FW_I(native, type);
CORTO_CLASS_O(native, type, lang_binary, CORTO_HIDDEN, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(native_type, name, lang_string, CORTO_GLOBAL);
    CORTO_METHOD_O(native_type, init, "()", lang_int16, corto_native_type_init);

/* /corto/secure/key */
CORTO_FW_CD(secure, key);
CORTO_CLASS_NOBASE_O(secure, key, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_CD);
    CORTO_METHOD_O(secure_key, construct, "()", lang_int16, corto_secure_key_construct);
    CORTO_METHOD_O(secure_key, destruct, "()", lang_void, corto_secure_key_destruct);
    CORTO_OVERRIDABLE_O(secure_key, authenticate, "(string user,string password)", lang_string, corto_secure_key_authenticate_v);

/* /corto/secure/lock */
CORTO_FW_CD(secure, lock);
CORTO_CLASS_NOBASE_O(secure, lock, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(secure_lock, mount, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(secure_lock, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(secure_lock, priority, lang_int16, CORTO_GLOBAL);
    CORTO_METHOD_O(secure_lock, construct, "()", lang_int16, corto_secure_lock_construct);
    CORTO_METHOD_O(secure_lock, destruct, "()", lang_void, corto_secure_lock_destruct);
    CORTO_OVERRIDABLE_O(secure_lock, authorize, "(string token,secure/actionKind action)", secure_accessKind, corto_secure_lock_authorize_v);

/* /corto/vstore/loader */
CORTO_FW_CD(vstore, loader);
CORTO_CLASS_O(vstore, loader, vstore_mount, CORTO_PRIVATE|CORTO_LOCAL, CORTO_ATTR_DEFAULT, NULL, CORTO_DECLARED | CORTO_VALID, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(vstore_loader, autoLoad, lang_bool, CORTO_GLOBAL);
    CORTO_METHOD_O(vstore_loader, construct, "()", lang_int16, corto_loader_construct);
    CORTO_METHOD_O(vstore_loader, destruct, "()", lang_void, corto_loader_destruct);
    CORTO_OVERRIDABLE_O(vstore_loader, onQuery, "(/corto/vstore/query query)", vstore_resultIter, corto_loader_onQuery_v);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_BOOTSTRAP_H_ */
