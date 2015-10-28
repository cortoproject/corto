/*
 * corto_bootstrap.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CORTO_BOOTSTRAP_H_
#define CORTO_BOOTSTRAP_H_

#include "corto.h"
#include "corto__object.h"
#include "corto__equals.h"

/* Notes about the typesystem
 *
 * Composite objects
 *  Composite objects describe aggregations of information. There are 5 classes that make up for the
 *  interface framework. Each of these classes implements a distinct and orthogonal piece of functionality.
 *  Here follows a short description of each one:
 *
 *   - Interface
 *      This class is the base-interface type. An interface can hold methods and members. It is not possible
 *      to directly instantiate an interface. Interfaces must be implemented by classes. Interfaces can
 *      inherit from other interfaces.
 *
 *   - Struct (base = Interface)
 *      The struct class is derived from interface, and has non-reference semantics. The struct-class
 *      introduces the ability to apply a modifier (PRIVATE,LOCAL,READONLY,..) to its base.
 *
 *   - Class (base = Struct)
 *      Classes inherit the behavior from struct but are of a reference type. They add the capability to
 *      define a constructor, destructor and template observables.
 *
 *   - Procedure (base = Struct)
 *      The procedure class describes objects that implement functionality. There are five
 *      procedure-types in the type-system, each with unique characteristics:
 *
 *      - Function
 *          The function is the most basic procedure. It has a returntype, parameterlist and an
 *          implementation that can be provided in various languages. All other procedure-types
 *          inherit from function. Functions with a returntype introduce a variable with the
 *          name of the function, which allows the implementation to assign a returnvalue for
 *          the function.
 *
 *      - Method (base = function)
 *          A method is procedure that is always defined in an interface type. A method can be invoked on
 *          an instantiated object from any type derived from interface. Methods can be virtual
 *          when they are declared in an struct parent, in which case they can be re-implemented
 *          by a subtype. Methods introduce a 'this' variable, and in case of an struct parent,
 *          which inherits from a base-class, a 'super' alias for 'this' with the type of the base-class.
 *
 *      - Delegate (base = function)
 *          Delegates provide a type-safe manner of specifying callback routines. They result in a
 *          callback-vtable on the instantiated object. This table is populated by callback objects
 *          which must have a compatible signature with the delegate definition. Delegates can only
 *          be declared in class-objects.
 *
 *      - Callback (base = function)
 *          Callbacks are used to provide implementations for delegates. Their signature must match
 *          that of the delegate object. Callbacks may be declared within the scope of any object
 *          for which it's type is a class and has delegates. A callback is always annotated with the
 *          delegate it implements.
 *
 *       - Observer (base = function)
 *          Observers are procedures that are executed whenever an event occurs in the system. They
 *          are therefore not called in a traditional fashion and as such, the argumentlist of an
 *          observer is usually hidden for the user. Observers have access to the source of the event
 *          and the observable, through resp. the 'source' variable and the 'observable' variable.
 *
 *
 */

/* Bootstrap curiosities:
 *  1. The virtual callback table is usually allocated along with the memory of an object, and
 *     is placed after the object's value. This vtable is free'd along with the memory of the object.
 *     Since at creation of an object it is known how many delegates it's type has, the vtable for
 *     the worst case can be allocated at object creation.
 *     For SSO objects, the vtable must be of a static size however. Therefore all vtables of SSO's
 *     are of size 16, which is more than the maximum number of delegates for any builtin-class.
 *
 *  2. All static objects are assigned an initial refcount of 2. This prevents static objects being
 *     cleaned up using the regular path, which would result in trying to free static memory and
 *     bootstrap issues at shutdown (wouldn't be able to free class, because it's a class etc.).
 *     The database shutdown takes care of correct cleanup of builtin objects.
 *
 *  3. The 'object' type has a bootstrap issue because it's scope is an 'object'. Static objects are checked on
 *     refcounts when they are free'd, but 'object' is still referenced by it's scope and therefore
 *     would report a refcount other than expected. 'object' can't be removed after the scopes
 *     however, because that would result in a 'scope not empty' error during the removal of the scope.
 *     Therefore an exception is made in the freeSSO function, to not check object. object is checked
 *     manually in the bootstrap.
 *
 *  4. During destruction, types set their typedef.real pointer to NULL. When destructing the builtin-types,
 *     this prevents from referring to the real type, because there is no 'right' order in which objects can be
 *     destructed without this issue occurring. To counter this issue, the 'real' pointer is restored for
 *     builtin-types after destruction.
 *
 *  5. The delegate-callback mechanism is used by type initializers and class constructors\destructors, which
 *     are in turn required by the bootstrap to initialize and define types. However, initially, the corresponding
 *     delegates are not yet defined, thus no callbacks can be binded to them, causing a major pain during
 *     bootstrap - it would be necessary to first initialize and define all callbacks before anything other could
 *     happen. As a relaxation, callbacks are allowed to call their constructors (transparently, without this being
 *     visible in the object-state) during bootstrap-initialization, because all information is then already available
 *     during initialization. This localized solution keeps the bootstrap smal(ler) and easier to comprehend.
 *
 *  6. The unbind callbacks are not resolved using a regular delegate-lookup function, but instead are directly
 *     forwarded to the corto_function_unbind function. Because procedures are destructed after the destruction of
 *     all classes, the vtable of corto_procedure_o does no longer exist, so the callback lookup would crash.
 *     Because lang::function is the only object with an unbind this is a safe workaround. Consequence is that
 *     end-users won't be able to use the procedure::unbind delegate, which is acceptable.
 *
 *  7. The virtual method 'interface::bindMethod' is required to bind methods to classes and interfaces. However,
 *     there is a bootstrap issue here (who binds bindMethod) which cannot be easily solved by a hard-coded
 *     bind of bindMethod. Since virtual methods are looked-up by methodId's, and methodId's are only stable
 *     after the parent of a method is defined, bindMethod can only be looked up after both 'interface' and
 *     'class' are defined. To get defined though, these classes need to bind all their methods, hence the
 *     bootstrap. This issue is solved by calling the method::init initializer call the implementations of the
 *     virtual method 'interface::bindMethod' directly, so no methodId lookup is required.
 *     For delegate functions this is the same, but here the implementation is easier, since the delegate::init
 *     function does not need to distinct between interface's and classes. Delegates can only be defined on a class.
 */

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
    struct { /* vtable */\
        corto_uint32 length;\
        void* buffer;\
    }vtable;\
    corto_object vbuff[16];\
}sso_##type

#define CORTO_STATIC_SCOPED_REFOBJECT(type)\
typedef struct sso_##type {\
    corto_SSO o;\
    struct corto_##type##_s v;\
    struct { /* vtable */\
        corto_uint32 length;\
        void* buffer;\
    }vtable;\
    corto_object vbuff[16];\
}sso_##type

/* Static Scoped Object */
typedef struct corto_SSO {
    corto__scope s;
    corto__object o;
}corto_SSO;

/* Static Scoped Observable Object */
typedef struct corto_SSOO {
    corto__observable v;
    corto__scope s;
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
CORTO_STATIC_SCOPED_REFOBJECT(metaprocedure);
CORTO_STATIC_SCOPED_REFOBJECT(member);
CORTO_STATIC_SCOPED_REFOBJECT(alias);
CORTO_STATIC_SCOPED_OBJECT(parameter);

CORTO_STATIC_SCOPED_OBJECT(constant);

#define VTABLE_V {16,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
#define CORTO_FWDECL_SSO(type, name) sso_##type name##__o
#define CORTO_FWDECL(type, name) CORTO_FWDECL_SSO(type, name); corto_##type corto_##name##_o = &name##__o.v

/* SSO */
#define CORTO_ATTR_SSOO {1, 0, 1, 0, CORTO_VALID | CORTO_DECLARED}
#define CORTO_ATTR_SSO {1, 0, 0, 0, CORTO_VALID | CORTO_DECLARED}
#define CORTO_ATTR_SO {0, 0, 0, 0,C X_VALID | CORTO_DECLARED}
#define CORTO_ROOT_V() {{NULL,NULL,CORTO_RWMUTEX_INITIALIZER,CORTO_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE,FALSE},{NULL, NULL, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{CORTO_ATTR_SSOO, 2, (corto_type)&package__o.v, CORTO_MMNODE_INIT}}
#define CORTO_PACKAGE_V(parent, name, uri) {{NULL,NULL,CORTO_RWMUTEX_INITIALIZER,CORTO_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE,FALSE},{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{CORTO_ATTR_SSOO, 2, (corto_type)&package__o.v, CORTO_MMNODE_INIT}}, {uri}
#define CORTO_SSO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{CORTO_ATTR_SSO, 2, (corto_type)&type##__o.v, CORTO_MMNODE_INIT}}
#define CORTO_SSO_PO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{CORTO_ATTR_SSO, 2, (corto_type)&type##__o.v, CORTO_MMNODE_INIT}}

/* SSO identifier */
#define CORTO_ID(name) name##__o
#define CORTO_TYPE_ID(name) (corto_type)&CORTO_ID(name).v

/* Forward declarations of delegates */
#define CORTO_FW_I(name) sso_method CORTO_ID(name##_init_)
#define CORTO_FW_IC(name) sso_method CORTO_ID(name##_init_), CORTO_ID(name##_construct_)
#define CORTO_FW_ICD(name) sso_method CORTO_ID(name##_init_), CORTO_ID(name##_construct_), CORTO_ID(name##_destruct_)
#define CORTO_FW_IB(name) sso_method CORTO_ID(name##_init_), CORTO_ID(name##_bind_)
#define CORTO_FW_B(name) sso_method CORTO_ID(name##_bind_)
#define CORTO_FW_CD(name) sso_method CORTO_ID(name##_construct_), CORTO_ID(name##_destruct_)

/* Delegate assignments */
#define CORTO_DELEGATE(name, delegate) {{NULL, (corto_function)&CORTO_ID(name##_##delegate##_).v}}
#define CORTO_INIT(name) CORTO_DELEGATE(name, init)
#define CORTO_CONSTRUCT(name) CORTO_DELEGATE(name, construct)
#define CORTO_BIND(name) CORTO_DELEGATE(name, bind)
#define CORTO_DESTRUCT(name) CORTO_DELEGATE(name, destruct)

#define CORTO_I_TYPE(name) CORTO_INIT(name)
#define CORTO_I_CLASS(name) {{NULL, NULL}}, {{NULL, NULL}}
#define CORTO_I_PROC(name) {{NULL, NULL}}

#define CORTO_B_TYPE(name) {{NULL, NULL}}
#define CORTO_B_PROC(name) CORTO_BIND(name)

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

/* type */
#define CORTO_TYPE_V(name, kind, reference, scopeType, scopeTypeKind, defaultType, defaultProcedureType, DELEGATE) \
  {kind, reference, FALSE, 0, 0, 0, scopeType, scopeTypeKind, defaultType, defaultProcedureType, {0,NULL}, DELEGATE##_TYPE(name)}

/* primitive */
#define CORTO_PRIMITIVE_V(name, kind, width, scopeType, scopeStateKind, DELEGATE) \
  {CORTO_TYPE_V(name, CORTO_PRIMITIVE, FALSE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, width, 0}

/* interface */
#define CORTO_COMPOSITE_V(name, kind, base, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(name, CORTO_COMPOSITE, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, (corto_interface)&base##__o.v}

/* interface */
#define CORTO_COMPOSITE_NOBASE_V(name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(name, CORTO_COMPOSITE, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, NULL}

/* struct */
#define CORTO_STRUCT_V(name, kind, base, baseAccess, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_V(name, kind, base, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), baseAccess}

#define CORTO_STRUCT_NOBASE_V(name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_NOBASE_V(name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), CORTO_LOCAL}

/* collection */
#define CORTO_COLLECTION_V(name, kind, elementType, max) {CORTO_TYPE_V(name, CORTO_COLLECTION, FALSE, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), kind, (corto_type)&elementType##__o.v, max}

/* sequence */
#define CORTO_SEQUENCE_V(subType, length, ...) {length, (subType[]){__VA_ARGS__}}
#define CORTO_SEQUENCE_EMPTY_V(subType) {0, NULL}

/* member */
#define CORTO_MEMBER_V(type, access, state, weak) {(corto_type)&type##__o.v, access, state, weak, 0, 0}

/* object */
#define CORTO_PACKAGE_O(name, uri) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(root, #name, uri)}
#define CORTO_PACKAGE_O_SCOPE(parent, name, uri) corto_ssoo_package parent##_##name##__o = {CORTO_PACKAGE_V(parent, #name, uri)}

/* type object */
#define CORTO_TYPE_O(name, kind, reference) static sso_type name##__o = {CORTO_SSO_V(corto_lang, #name, type), CORTO_TYPE_V(name, kind, reference, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), VTABLE_V}

/* primitive object */
#define CORTO_PRIMITIVE_O(name, kind, width) sso_primitive name##__o = {CORTO_SSO_V(corto_lang, #name, primitive), CORTO_PRIMITIVE_V(name, kind, width, CORTO_NODELEGATE), VTABLE_V}

/* binary object */
#define CORTO_BINARY_O(name, width) sso_binary name##__o = {CORTO_SSO_V(corto_lang, #name, binary), {CORTO_PRIMITIVE_V(name, CORTO_BINARY, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* boolean object */
#define CORTO_BOOLEAN_O(name) sso_boolean name##__o = {CORTO_SSO_V(corto_lang, #name, boolean), {CORTO_PRIMITIVE_V(name, CORTO_BOOLEAN, CORTO_WIDTH_8, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* character object */
#define CORTO_CHARACTER_O(name, width) sso_character name##__o = {CORTO_SSO_V(corto_lang, #name, character), {CORTO_PRIMITIVE_V(name, CORTO_CHARACTER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* int object */
#define CORTO_INT_O(name, width, min, max, scopeType, scopeStateKind, DELEGATE) sso_int name##__o = {CORTO_SSO_V(corto_lang, #name, int), {CORTO_PRIMITIVE_V(name, CORTO_INTEGER, width, scopeType, scopeStateKind, DELEGATE), min, max}, VTABLE_V}

/* uint object */
#define CORTO_UINT_O(name, width, min, max) sso_uint name##__o = {CORTO_SSO_V(corto_lang, #name, uint), {CORTO_PRIMITIVE_V(name, CORTO_UINTEGER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}, VTABLE_V}

/* float object */
#define CORTO_FLOAT_O(name, width, min, max) sso_float name##__o = {CORTO_SSO_V(corto_lang, #name, float), {CORTO_PRIMITIVE_V(name, CORTO_FLOAT, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}, VTABLE_V}

/* text object */
#define CORTO_TEXT_O(name, width, length) sso_text name##__o = {CORTO_SSO_V(corto_lang, #name, text), {CORTO_PRIMITIVE_V(name, CORTO_TEXT, CORTO_WIDTH_WORD, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), width, length}, VTABLE_V}

/* enum object */
#define CORTO_ENUM_O(name) sso_enum name##__o = {CORTO_SSO_V(corto_lang, #name, enum), {CORTO_PRIMITIVE_V(name, CORTO_ENUM, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}, VTABLE_V}

/* bitmask object */
#define CORTO_BITMASK_O(name) sso_bitmask name##__o = {CORTO_SSO_V(corto_lang, #name, bitmask), {{CORTO_PRIMITIVE_V(name, CORTO_BITMASK, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}, VTABLE_V}

/* constant object */
#define CORTO_CONSTANT_O(parent, name) sso_constant parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, constant), CORTO_##name, VTABLE_V}

/* struct object */
#define CORTO_STRUCT_O(name, scopeType, scopeStateKind, defaultType, defaultProcedureType) sso_struct name##__o = \
    {CORTO_SSO_V(corto_lang, #name, struct), CORTO_STRUCT_NOBASE_V(name, CORTO_STRUCT, FALSE, scopeType, scopeStateKind, defaultType, defaultProcedureType, CORTO_NODELEGATE), VTABLE_V}

/* interface object */
#define CORTO_INTERFACE_O(name) sso_interface name##__o = \
    {CORTO_SSO_V(corto_lang, #name, interface), CORTO_COMPOSITE_NOBASE_V(name, CORTO_INTERFACE, TRUE, NULL, 0, NULL, CORTO_TYPE_ID(method), CORTO_NODELEGATE), VTABLE_V}

/* class object */
#define CORTO_CLASS_NOBASE_O(name, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) sso_class name##__o = \
    {CORTO_SSO_V(corto_lang, #name, class), {CORTO_STRUCT_NOBASE_V(name, CORTO_CLASS, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, {0,NULL}, DELEGATE##_CLASS(name)}, VTABLE_V}

#define CORTO_CLASS_O(name, base, baseAccess, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) sso_class name##__o = \
        {CORTO_SSO_V(corto_lang, #name, class), {CORTO_STRUCT_V(name, CORTO_CLASS, base, baseAccess, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, {0,NULL}, DELEGATE##_CLASS(name)}, VTABLE_V}

#define CORTO_CLASS_IMPLEMENTS_O(name, scopeType, scopeStateKind, defaultType, defaultProcedureType, interface, DELEGATE) sso_class name##__o = \
    {CORTO_SSO_V(corto_lang, #name, class), {CORTO_STRUCT_NOBASE_V(name, CORTO_CLASS, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {1,{interface}}, {0,NULL}, {0,NULL}, DELEGATE##_CLASS(name)}, VTABLE_V}

/* array object */
#define CORTO_ARRAY_O(name, elementType, size) sso_array name##__o = {CORTO_SSO_V(corto_lang, #name, array), {CORTO_COLLECTION_V(name, CORTO_ARRAY, elementType, size)}, VTABLE_V}

/* sequence object */
#define CORTO_SEQUENCE_O(name, elementType, max) sso_sequence name##__o = {CORTO_SSO_V(corto_lang, #name, sequence), {CORTO_COLLECTION_V(name, CORTO_SEQUENCE, elementType, max)}, VTABLE_V}

/* list object */
#define CORTO_LIST_O(name, elementType, max) sso_list name##__o = {CORTO_SSO_V(corto_lang, #name, list), {CORTO_COLLECTION_V(name, CORTO_LIST, elementType, max)}, VTABLE_V}

/* map object */
#define CORTO_MAP_O(name, elementType, keyType, max) sso_map name##__o = {CORTO_SSO_V(corto_lang, #name, map), {CORTO_COLLECTION_V(name, CORTO_MAP, elementType, max), (corto_type)&keyType##__o.v}, VTABLE_V}

/* procedure object */
#define CORTO_PROCEDURE_O(name, kind, base, baseAccess, scopeType, scopeStateKind, DELEGATE) sso_procedure name##__o = \
        {CORTO_SSO_V(corto_lang, #name, procedure), {CORTO_STRUCT_V(name, CORTO_PROCEDURE, base, baseAccess, TRUE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, DELEGATE##_PROC(name)}, VTABLE_V}
#define CORTO_PROCEDURE_NOBASE_O(name, kind, scopeType, scopeStateKind, DELEGATE) sso_procedure name##__o = \
        {CORTO_SSO_V(corto_lang, #name, procedure), {CORTO_STRUCT_NOBASE_V(name, CORTO_PROCEDURE, TRUE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, DELEGATE##_PROC(name)}, VTABLE_V}

/* function object */
#define CORTO_FUNCTION_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0, {0,NULL},0}, VTABLE_V}

#define CORTO_FUNCTION_OO_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_V(parent, #name args, function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0, {0,NULL},0}, VTABLE_V}

#define CORTO_FUNCTION_OVERLOAD_OO_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_V(parent, args, function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0, {0,NULL},0}, VTABLE_V}

/* method object */
#define CORTO_METHOD_O(parent, name, args, returnType, virtual, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_method parent##_##name##___o = {CORTO_SSO_PO_V(parent, #name args, method), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0,{0,NULL},0}, virtual}, VTABLE_V}

/* interface method object */
#define CORTO_IMETHOD_O(parent, name, args, returnType, virtual) \
        sso_method parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, method), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, 0, 0, NULL, 0,{0,NULL},0}, virtual}, VTABLE_V}

/* interface method object */
#define CORTO_OBSERVER_O(parent, name, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_observer parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, observer), {{(corto_type)&void##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0,{0,NULL},0}, 0}, VTABLE_V}

/* metaprocedure object */
#define CORTO_METAPROCEDURE_O(parent, name, args, returnType, referenceOnly, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0, {0,NULL},0}, referenceOnly}, VTABLE_V}

#define CORTO_METAPROCEDURE_NAME_O(parent, name, actualName, args, returnType, referenceOnly, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #actualName args, metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)__##impl, (corto_word)_##impl, NULL, 0, {0,NULL},0}, referenceOnly}, VTABLE_V}

/* member object */
#define CORTO_MEMBER_O(parent, name, type, access) sso_member parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, member), CORTO_MEMBER_V(type, access, CORTO_DECLARED | CORTO_DEFINED, FALSE), VTABLE_V}

/* member object */
#define CORTO_ALIAS_O(parent, name, member, access) sso_alias parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, alias), {CORTO_MEMBER_V(word, access, 0, FALSE), (corto_member)&member##__o.v}, VTABLE_V}

/* reference object */
#define CORTO_REFERENCE_O(parent, name, type, access, state, weak) sso_member parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, member), CORTO_MEMBER_V(type, access, state, weak), VTABLE_V}

/* Delegate type */
#define CORTO_DELEGATE_O(name, returnType) sso_delegate name##__o = \
    {CORTO_SSO_V(corto_lang, #name, delegate), {CORTO_STRUCT_NOBASE_V(name, CORTO_DELEGATE, FALSE, NULL, CORTO_DECLARED|CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), (corto_type)&returnType##__o.v, FALSE, CORTO_SEQUENCE_EMPTY_V(parameter)}, VTABLE_V}

/* Forward declarations of classes */
CORTO_FWDECL(class, type);
CORTO_FWDECL(class, template);
CORTO_FWDECL(class, primitive);
CORTO_FWDECL(class, interface);
CORTO_FWDECL(class, collection);
CORTO_FWDECL(class, iterator);
CORTO_FWDECL(class, procedure);
CORTO_FWDECL(class, binary);
CORTO_FWDECL(class, boolean);
CORTO_FWDECL(class, character);
CORTO_FWDECL(class, int);
CORTO_FWDECL(class, uint);
CORTO_FWDECL(class, float);
CORTO_FWDECL(class, text);
CORTO_FWDECL(class, enum);
CORTO_FWDECL(class, bitmask);
CORTO_FWDECL(class, struct);
CORTO_FWDECL(class, class);
CORTO_FWDECL(class, delegate);
CORTO_FWDECL(class, array);
CORTO_FWDECL(class, sequence);
CORTO_FWDECL(class, list);
CORTO_FWDECL(class, map);
CORTO_FWDECL(class, member);
CORTO_FWDECL(class, alias);
CORTO_FWDECL(class, event);
CORTO_FWDECL(class, observableEvent);
CORTO_FWDECL(class, invokeEvent);
CORTO_FWDECL(class, notifyEvent);
CORTO_FWDECL(class, package);
CORTO_FWDECL(class, query);
CORTO_FWDECL(class, replicator);
CORTO_FWDECL(struct, interfaceVector);
CORTO_FWDECL(struct, parameter);
CORTO_FWDECL(struct, delegatedata);

/* Abstract classes */
CORTO_FWDECL(interface, dispatcher);

CORTO_FWDECL(binary, octet);
CORTO_FWDECL(boolean, bool);
CORTO_FWDECL(character, char);
CORTO_FWDECL(uint, uint8);
CORTO_FWDECL(uint, uint16);
CORTO_FWDECL(uint, uint32);
CORTO_FWDECL(uint, uint64);
CORTO_FWDECL(int, int8);
CORTO_FWDECL(int, int16);
CORTO_FWDECL(int, int32);
CORTO_FWDECL(int, int64);
CORTO_FWDECL(float, float32);
CORTO_FWDECL(float, float64);
CORTO_FWDECL(text, string);
CORTO_FWDECL(binary, word);
CORTO_FWDECL(int, constant);

static CORTO_FWDECL(type, any);
static CORTO_FWDECL(type, void);
static CORTO_FWDECL(type, object);

CORTO_FWDECL(procedure, function);
CORTO_FWDECL(procedure, method);
CORTO_FWDECL(procedure, virtual);
CORTO_FWDECL(procedure, observer);
CORTO_FWDECL(procedure, metaprocedure);

CORTO_FWDECL(enum, width);
CORTO_FWDECL(enum, typeKind);
CORTO_FWDECL(enum, primitiveKind);
CORTO_FWDECL(enum, compositeKind);
CORTO_FWDECL(enum, collectionKind);
CORTO_FWDECL(enum, procedureKind);
CORTO_FWDECL(enum, scopeStateKind);
CORTO_FWDECL(enum, equalityKind);
CORTO_FWDECL(enum, operatorKind);
CORTO_FWDECL(bitmask, state);
CORTO_FWDECL(bitmask, attr);
CORTO_FWDECL(bitmask, eventMask);
CORTO_FWDECL(bitmask, modifier);

CORTO_FWDECL(sequence, objectseq);
CORTO_FWDECL(sequence, interfaceseq);
CORTO_FWDECL(sequence, memberseq);
CORTO_FWDECL(sequence, parameterseq);
CORTO_FWDECL(sequence, observerseq);
CORTO_FWDECL(sequence, vtable);
CORTO_FWDECL(sequence, interfaceVectorseq);
CORTO_FWDECL(sequence, octetseq);

CORTO_FWDECL(delegate, initAction);
CORTO_FWDECL(delegate, destructAction);
CORTO_FWDECL(delegate, notifyAction);
CORTO_FWDECL(delegate, invokeAction);

CORTO_FWDECL(observer, replicator_on_declare);
CORTO_FWDECL(observer, replicator_on_update);
CORTO_FWDECL(observer, replicator_on_delete);

/* database root */
corto_ssoo_package root__o = {CORTO_ROOT_V(), {"http://corto.io/doc"}};
corto_package root_o = CORTO_OFFSET(&root__o.o.o, sizeof(corto__object));

/* ::corto, ::corto::lang and ::corto::serialization */
CORTO_PACKAGE_O(corto, "http://corto.io/doc/corto");
CORTO_PACKAGE_O_SCOPE(corto, lang, "http://corto.io/doc/corto/lang");

corto_package corto_o = CORTO_OFFSET(&corto__o.o.o, sizeof(corto__object));

corto_package corto_lang_o = CORTO_OFFSET(&corto_lang__o.o.o, sizeof(corto__object));

/* Primitives */
CORTO_BINARY_O(octet, CORTO_WIDTH_8);
CORTO_BOOLEAN_O(bool);
CORTO_CHARACTER_O(char, CORTO_WIDTH_8);
CORTO_UINT_O(uint8, CORTO_WIDTH_8, 0, MAX_UINT8);
CORTO_UINT_O(uint16, CORTO_WIDTH_16, 0, MAX_UINT16);
CORTO_UINT_O(uint32, CORTO_WIDTH_32, 0, MAX_UINT32);
CORTO_UINT_O(uint64, CORTO_WIDTH_64, 0, MAX_UINT64);
CORTO_INT_O(int8, CORTO_WIDTH_8, MIN_INT8, MAX_INT8, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(int16, CORTO_WIDTH_16, MIN_INT16, MAX_INT16, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(int32, CORTO_WIDTH_32, MIN_INT32, MAX_INT32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_INT_O(int64, CORTO_WIDTH_64, MIN_INT64, MAX_INT64, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE);
CORTO_FLOAT_O(float32, CORTO_WIDTH_32, 0, 0);
CORTO_FLOAT_O(float64, CORTO_WIDTH_64, 0, 0);
CORTO_TEXT_O(string, CORTO_WIDTH_8, 0);
CORTO_BINARY_O(word, CORTO_WIDTH_WORD);
CORTO_FW_I(constant);
CORTO_INT_O(constant, CORTO_WIDTH_32, 0, MAX_INT32, CORTO_TYPE_ID(enum), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(constant, init, "()", int16, FALSE, corto_constant_init);

/* Any type */
CORTO_TYPE_O(any, CORTO_ANY, FALSE);

/* Void type */
CORTO_TYPE_O(void, CORTO_VOID, FALSE);

/* Object type */
CORTO_TYPE_O(object, CORTO_VOID, TRUE);

/* Package type */
CORTO_CLASS_NOBASE_O(package, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(package, url, string, CORTO_GLOBAL);

/* Enumerations */
CORTO_ENUM_O(width);
    CORTO_CONSTANT_O(width, WIDTH_8);
    CORTO_CONSTANT_O(width, WIDTH_16);
    CORTO_CONSTANT_O(width, WIDTH_32);
    CORTO_CONSTANT_O(width, WIDTH_64);
    CORTO_CONSTANT_O(width, WIDTH_WORD);

CORTO_ENUM_O(typeKind);
    CORTO_CONSTANT_O(typeKind, VOID);
    CORTO_CONSTANT_O(typeKind, ANY);
    CORTO_CONSTANT_O(typeKind, PRIMITIVE);
    CORTO_CONSTANT_O(typeKind, COMPOSITE);
    CORTO_CONSTANT_O(typeKind, COLLECTION);
    CORTO_CONSTANT_O(typeKind, ITERATOR);

CORTO_ENUM_O(primitiveKind);
    CORTO_CONSTANT_O(primitiveKind, BINARY);
    CORTO_CONSTANT_O(primitiveKind, BOOLEAN);
    CORTO_CONSTANT_O(primitiveKind, CHARACTER);
    CORTO_CONSTANT_O(primitiveKind, INTEGER);
    CORTO_CONSTANT_O(primitiveKind, UINTEGER);
    CORTO_CONSTANT_O(primitiveKind, FLOAT);
    CORTO_CONSTANT_O(primitiveKind, TEXT);
    CORTO_CONSTANT_O(primitiveKind, ENUM);
    CORTO_CONSTANT_O(primitiveKind, BITMASK);

CORTO_ENUM_O(compositeKind);
    CORTO_CONSTANT_O(compositeKind, STRUCT);
    CORTO_CONSTANT_O(compositeKind, INTERFACE);
    CORTO_CONSTANT_O(compositeKind, CLASS);
    CORTO_CONSTANT_O(compositeKind, DELEGATE);
    CORTO_CONSTANT_O(compositeKind, PROCEDURE);

CORTO_ENUM_O(collectionKind);
    CORTO_CONSTANT_O(collectionKind, ARRAY);
    CORTO_CONSTANT_O(collectionKind, SEQUENCE);
    CORTO_CONSTANT_O(collectionKind, LIST);
    CORTO_CONSTANT_O(collectionKind, MAP);

CORTO_ENUM_O(procedureKind);
    CORTO_CONSTANT_O(procedureKind, FUNCTION);
    CORTO_CONSTANT_O(procedureKind, METHOD);
    CORTO_CONSTANT_O(procedureKind, OBSERVER);
    CORTO_CONSTANT_O(procedureKind, METAPROCEDURE);

CORTO_ENUM_O(equalityKind);
    CORTO_CONSTANT_O(equalityKind, EQ);
    CORTO_CONSTANT_O(equalityKind, LT);
    CORTO_CONSTANT_O(equalityKind, GT);
    CORTO_CONSTANT_O(equalityKind, NEQ);

CORTO_ENUM_O(operatorKind);
    CORTO_CONSTANT_O(operatorKind, ASSIGN);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_ADD);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_SUB);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_MUL);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_DIV);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_MOD);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_XOR);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_OR);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_AND);
    CORTO_CONSTANT_O(operatorKind, ASSIGN_UPDATE);
    CORTO_CONSTANT_O(operatorKind, ADD);
    CORTO_CONSTANT_O(operatorKind, SUB);
    CORTO_CONSTANT_O(operatorKind, MUL);
    CORTO_CONSTANT_O(operatorKind, DIV);
    CORTO_CONSTANT_O(operatorKind, MOD);
    CORTO_CONSTANT_O(operatorKind, INC);
    CORTO_CONSTANT_O(operatorKind, DEC);
    CORTO_CONSTANT_O(operatorKind, XOR);
    CORTO_CONSTANT_O(operatorKind, OR);
    CORTO_CONSTANT_O(operatorKind, AND);
    CORTO_CONSTANT_O(operatorKind, NOT);
    CORTO_CONSTANT_O(operatorKind, COND_OR);
    CORTO_CONSTANT_O(operatorKind, COND_AND);
    CORTO_CONSTANT_O(operatorKind, COND_NOT);
    CORTO_CONSTANT_O(operatorKind, COND_EQ);
    CORTO_CONSTANT_O(operatorKind, COND_NEQ);
    CORTO_CONSTANT_O(operatorKind, COND_GT);
    CORTO_CONSTANT_O(operatorKind, COND_LT);
    CORTO_CONSTANT_O(operatorKind, COND_GTEQ);
    CORTO_CONSTANT_O(operatorKind, COND_LTEQ);
    CORTO_CONSTANT_O(operatorKind, SHIFT_LEFT);
    CORTO_CONSTANT_O(operatorKind, SHIFT_RIGHT);
    CORTO_CONSTANT_O(operatorKind, REF);

CORTO_BITMASK_O(state);
    CORTO_CONSTANT_O(state, VALID);
    CORTO_CONSTANT_O(state, DECLARED);
    CORTO_CONSTANT_O(state, DEFINED);
    CORTO_CONSTANT_O(state, DESTRUCTED);

CORTO_BITMASK_O(attr);
    CORTO_CONSTANT_O(attr, ATTR_SCOPED);
    CORTO_CONSTANT_O(attr, ATTR_WRITABLE);
    CORTO_CONSTANT_O(attr, ATTR_OBSERVABLE);
    CORTO_CONSTANT_O(attr, ATTR_PERSISTENT);
    CORTO_CONSTANT_O(attr, ATTR_DEFAULT);

CORTO_BITMASK_O(eventMask);
    CORTO_CONSTANT_O(eventMask, ON_DECLARE);
    CORTO_CONSTANT_O(eventMask, ON_DEFINE);
    CORTO_CONSTANT_O(eventMask, ON_DELETE);
    CORTO_CONSTANT_O(eventMask, ON_INVALIDATE);
    CORTO_CONSTANT_O(eventMask, ON_UPDATE);
    CORTO_CONSTANT_O(eventMask, ON_SELF);
    CORTO_CONSTANT_O(eventMask, ON_SCOPE);
    CORTO_CONSTANT_O(eventMask, ON_TREE);
    CORTO_CONSTANT_O(eventMask, ON_VALUE);
    CORTO_CONSTANT_O(eventMask, ON_METAVALUE);

CORTO_BITMASK_O(modifier);
    CORTO_CONSTANT_O(modifier, GLOBAL);
    CORTO_CONSTANT_O(modifier, LOCAL);
    CORTO_CONSTANT_O(modifier, PRIVATE);
    CORTO_CONSTANT_O(modifier, READONLY);
    CORTO_CONSTANT_O(modifier, CONST);
    CORTO_CONSTANT_O(modifier, HIDDEN);

/* Collections */
CORTO_SEQUENCE_O(objectseq, object, 0);
CORTO_SEQUENCE_O(interfaceseq, interface, 0);
CORTO_SEQUENCE_O(memberseq, member, 0);
CORTO_SEQUENCE_O(parameterseq, parameter, 0);
CORTO_SEQUENCE_O(observerseq, observer, 0);
CORTO_SEQUENCE_O(vtable, function, 0);
CORTO_SEQUENCE_O(interfaceVectorseq, interfaceVector, 0);
CORTO_SEQUENCE_O(octetseq, octet, 0);

/* Delegate types */
CORTO_DELEGATE_O(initAction, int16);
CORTO_DELEGATE_O(destructAction, void);
CORTO_DELEGATE_O(notifyAction, void);
CORTO_DELEGATE_O(invokeAction, void);

/* ::corto::lang::type */
CORTO_FW_ICD(type);
CORTO_CLASS_NOBASE_O(type, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(type, kind, typeKind, CORTO_READONLY | CORTO_LOCAL);
    CORTO_MEMBER_O(type, reference, bool, CORTO_READONLY | CORTO_LOCAL);
    CORTO_MEMBER_O(type, hasResources, bool, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(type, templateId, uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(type, size, uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(type, alignment, uint16, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_REFERENCE_O(type, parentType, type, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(type, parentState, state, CORTO_GLOBAL);
    CORTO_REFERENCE_O(type, defaultType, type, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_REFERENCE_O(type, defaultProcedureType, type, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(type, metaprocedures, vtable, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(type, init, initAction, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(type, sizeof, "()", uint32, FALSE, corto_type_sizeof);
    CORTO_METHOD_O(type, alignmentof, "()", uint16, FALSE, corto_type_alignmentof);
    CORTO_METHOD_O(type, allocSize, "()", uint32, TRUE, corto_type_allocSize_v);
    CORTO_METHOD_O(type, castable, "(type type)", bool, TRUE, corto_type_castable_v);
    CORTO_METHOD_O(type, compatible, "(type type)", bool, TRUE, corto_type_compatible_v);
    CORTO_METHOD_O(type, resolveProcedure, "(string name)", function, FALSE, corto_type_resolveProcedure);
    CORTO_METHOD_O(type, init, "()", int16, FALSE, corto_type_init);
    CORTO_METHOD_O(type, construct, "()", int16, FALSE, corto_type_construct);
    CORTO_METHOD_O(type, destruct, "()", void, FALSE, corto_type_destruct);
    CORTO_METAPROCEDURE_O(type, parentof, "()", object, TRUE, corto_type_parentof);
    CORTO_METAPROCEDURE_O(type, nameof, "()", string, TRUE, corto_type_nameof);
    CORTO_METAPROCEDURE_O(type, fullname, "()", string, TRUE, corto_type_fullname);
    CORTO_METAPROCEDURE_O(type, relname, "(object from)", string, TRUE, corto_type_relname);
    CORTO_METAPROCEDURE_O(type, declare, "(string name,type type)", object, TRUE, corto_type_declare);
    CORTO_METAPROCEDURE_O(type, define, "()", int16, TRUE, corto_type_define);
    CORTO_METAPROCEDURE_O(type, delete, "()", void, TRUE, corto_type_delete);
    CORTO_METAPROCEDURE_O(type, invalidate, "()", void, TRUE, corto_type_invalidate);
    CORTO_METAPROCEDURE_O(type, resolve, "(string name)", object, TRUE, corto_type_resolve);
    CORTO_METAPROCEDURE_O(type, lookup, "(string name)", object, TRUE, corto_type_lookup);
    CORTO_METAPROCEDURE_O(type, checkAttr, "(attr attributes)", bool, TRUE, corto_type_checkAttr);
    CORTO_METAPROCEDURE_O(type, checkState, "(state state)", bool, TRUE, corto_type_checkState);
    CORTO_METAPROCEDURE_O(type, typeof, "()", type, FALSE, corto_type_typeof);
    CORTO_METAPROCEDURE_O(type, instanceof, "(type type)", bool, TRUE, corto_type_instanceof);
    CORTO_METAPROCEDURE_O(type, compare, "(any value)", equalityKind, FALSE, corto_type_compare);
    CORTO_METAPROCEDURE_O(type, copy, "(any value)", int16, FALSE, corto_type_copy);
    CORTO_METAPROCEDURE_O(type, toString, "()", string, FALSE, corto_type_toString);

/* ::corto::lang::primitive */
CORTO_FW_IC(primitive);
CORTO_CLASS_O(primitive, type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(primitive, kind, primitiveKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(primitive, width, width, CORTO_GLOBAL);
    CORTO_MEMBER_O(primitive, convertId, uint8, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(primitive, castable, "(type type)", bool, TRUE, corto_primitive_castable_v);
    CORTO_METHOD_O(primitive, compatible, "(type type)", bool, TRUE, corto_primitive_compatible_v);
    CORTO_METHOD_O(primitive, isInteger, "()", bool, FALSE, corto_primitive_isInteger);
    CORTO_METHOD_O(primitive, isNumber, "()", bool, FALSE, corto_primitive_isNumber);
    CORTO_METHOD_O(primitive, init, "()", int16, FALSE, corto_primitive_init);
    CORTO_METHOD_O(primitive, construct, "()", int16, FALSE, corto_primitive_construct);

/* ::corto::lang::interface */
CORTO_FW_ICD(interface);
CORTO_CLASS_O(interface, type, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(member), CORTO_TYPE_ID(method), CORTO_ICD);
    CORTO_MEMBER_O(interface, kind, compositeKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(interface, nextMemberId, uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(interface, members, memberseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(interface, methods, vtable, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_REFERENCE_O(interface, base, interface, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_ALIAS_O(interface, parentType, type_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O(interface, parentState, type_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O(interface, defaultType, type_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O(interface, defaultProcedureType, type_defaultProcedureType, CORTO_HIDDEN);
    CORTO_METHOD_O(interface, init, "()", int16, FALSE, corto_interface_init);
    CORTO_METHOD_O(interface, construct, "()", int16, FALSE, corto_interface_construct);
    CORTO_METHOD_O(interface, destruct, "()", void, FALSE, corto_interface_destruct);
    CORTO_METHOD_O(interface, resolveMember, "(string name)", member, TRUE, corto_interface_resolveMember_v);
    CORTO_METHOD_O(interface, compatible, "(type type)", bool, TRUE, corto_interface_compatible_v);
    CORTO_METHOD_O(interface, resolveMethod, "(string name)", method, FALSE, corto_interface_resolveMethod);
    CORTO_METHOD_O(interface, resolveMethodId, "(string name)", uint32, FALSE, corto_interface_resolveMethodId);
    CORTO_METHOD_O(interface, resolveMethodById, "(uint32 id)", method, FALSE, corto_interface_resolveMethodById);
    CORTO_METHOD_O(interface, bindMethod, "(method method)", int16, FALSE, corto_interface_bindMethod);
    CORTO_METHOD_O(interface, baseof, "(interface type)", int16, FALSE, corto_interface_baseof);

/* ::corto::lang::collection */
CORTO_FW_I(collection);
CORTO_CLASS_O(collection, type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(collection, kind, collectionKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_REFERENCE_O(collection, elementType, type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(collection, max, uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(collection, castable, "(type type)", bool, TRUE, corto_collection_castable_v);
    CORTO_METHOD_O(collection, compatible, "(type type)", bool, TRUE, corto_collection_compatible_v);
    CORTO_METHOD_O(collection, elementRequiresAlloc, "()", bool, FALSE, corto_collection_elementRequiresAlloc);
    CORTO_METHOD_O(collection, init, "()", int16, FALSE, corto_collection_init);
    CORTO_METAPROCEDURE_O(collection, size, "()", uint32, FALSE, corto_collection_size);

/* ::corto::lang::iterator */
CORTO_FW_I(iterator);
CORTO_CLASS_O(iterator, type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_REFERENCE_O(iterator, elementType, type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(iterator, init, "()", int16, FALSE, corto_iterator_init);
    CORTO_METHOD_O(iterator, compatible, "(type type)", bool, TRUE, corto_iterator_compatible_v);
    CORTO_METHOD_O(iterator, castable, "(type type)", bool, TRUE, corto_iterator_castable_v);

/* ::corto::lang::binary */
CORTO_FW_I(binary);
CORTO_CLASS_O(binary, primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(binary, init, "()", int16, FALSE, corto_binary_init);

/* ::corto::lang::boolean */
CORTO_FW_I(boolean);
CORTO_CLASS_O(boolean, primitive, CORTO_GLOBAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(boolean, init, "()", int16, FALSE, corto_boolean_init);

/* ::corto::lang::character */
CORTO_FW_I(character);
CORTO_CLASS_O(character, primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(character, init, "()", int16, FALSE, corto_character_init);

/* ::corto::lang::int */
CORTO_FW_I(int);
CORTO_CLASS_O(int, primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(int, min, int64, CORTO_GLOBAL);
    CORTO_MEMBER_O(int, max, int64, CORTO_GLOBAL);
    CORTO_METHOD_O(int, init, "()", int16, FALSE, corto_int_init);

/* ::corto::lang::uint */
CORTO_FW_I(uint);
CORTO_CLASS_O(uint, primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(uint, min, uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(uint, max, uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(uint, init, "()", int16, FALSE, corto_uint_init);

/* ::corto::lang::float */
CORTO_FW_I(float);
CORTO_CLASS_O(float, primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(float, min, float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(float, max, float64, CORTO_GLOBAL);
    CORTO_METHOD_O(float, init, "()", int16, FALSE, corto_float_init);

/* ::corto::lang::text */
CORTO_FW_I(text);
CORTO_CLASS_O(text, primitive, CORTO_LOCAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(text, charWidth, width, CORTO_GLOBAL);
    CORTO_MEMBER_O(text, length, uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(text, init, "()", int16, FALSE, corto_text_init);

/* ::corto::lang::enum */
CORTO_FW_ICD(enum);
CORTO_CLASS_O(enum, primitive, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(constant), NULL, CORTO_ICD);
    CORTO_MEMBER_O(enum, constants, objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(enum, init, "()", int16, FALSE, corto_enum_init);
    CORTO_METHOD_O(enum, construct, "()", int16, FALSE, corto_enum_construct);
    CORTO_METHOD_O(enum, destruct, "()", void, FALSE, corto_enum_destruct);
    CORTO_METHOD_O(enum, constant, "(int32 value)", object, FALSE, corto_enum_constant);

/* ::corto::lang::bitmask */
CORTO_FW_I(bitmask);
CORTO_CLASS_O(bitmask, enum, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(constant), NULL, CORTO_I);
    CORTO_METHOD_O(bitmask, init, "()", int16, FALSE, corto_bitmask_init);

/* ::corto::lang::struct */
CORTO_FW_IC(struct);
CORTO_CLASS_O(struct, interface, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(member), CORTO_TYPE_ID(method), CORTO_IC);
    CORTO_ALIAS_O (struct, base, interface_base, CORTO_GLOBAL);
    CORTO_MEMBER_O(struct, baseAccess, modifier, CORTO_GLOBAL);
    CORTO_ALIAS_O (struct, parentType, interface_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O (struct, parentState, interface_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O (struct, defaultType, interface_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O (struct, defaultProcedureType, interface_defaultProcedureType, CORTO_HIDDEN);
    CORTO_METHOD_O(struct, compatible, "(type type)", bool, TRUE, corto_struct_compatible_v);
    CORTO_METHOD_O(struct, castable, "(type type)", bool, TRUE, corto_struct_castable_v);
    CORTO_METHOD_O(struct, resolveMember, "(string name)", member, TRUE, corto_struct_resolveMember_v);
    CORTO_METHOD_O(struct, init, "()", int16, FALSE, corto_struct_init);
    CORTO_METHOD_O(struct, construct, "()", int16, FALSE, corto_struct_construct);

/* ::corto::lang::interfaceVector */
CORTO_STRUCT_O(interfaceVector, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(interfaceVector, interface, interface, CORTO_GLOBAL);
    CORTO_MEMBER_O(interfaceVector, vector, vtable, CORTO_GLOBAL);

/* ::corto::lang::class */
CORTO_FW_ICD(class);
CORTO_CLASS_O(class, struct, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(member), CORTO_TYPE_ID(method), CORTO_ICD);
    CORTO_ALIAS_O (class, base, struct_base, CORTO_GLOBAL);
    CORTO_ALIAS_O (class, baseAccess, struct_baseAccess, CORTO_GLOBAL);
    CORTO_MEMBER_O(class, implements, interfaceseq, CORTO_GLOBAL);
    CORTO_ALIAS_O (class, parentType, struct_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O (class, parentState, struct_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O (class, defaultType, struct_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O (class, defaultProcedureType, struct_defaultProcedureType, CORTO_HIDDEN);
    CORTO_MEMBER_O(class, interfaceVector, interfaceVectorseq, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(class, observers, observerseq, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(class, construct, initAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(class, destruct, destructAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(class, init, "()", int16, FALSE, corto_class_init);
    CORTO_METHOD_O(class, construct, "()", int16, FALSE, corto_class_construct);
    CORTO_METHOD_O(class, destruct, "()", void, FALSE, corto_class_destruct);
    CORTO_METHOD_O(class, allocSize, "()", uint32, TRUE, corto_class_allocSize_v);
    CORTO_METHOD_O(class, instanceof, "(object object)", bool, FALSE, corto_class_instanceof);
    CORTO_METHOD_O(class, privateObserver, "(object object,observer observer)", observer, FALSE, corto_class_privateObserver);
    CORTO_METHOD_O(class, resolveInterfaceMethod, "(interface interface,uint32 method)", method, FALSE, corto_class_resolveInterfaceMethod);
    CORTO_METHOD_O(class, bindObserver, "(observer observer)", void, FALSE, corto_class_bindObserver);
    CORTO_METHOD_O(class, findObserver, "(object observable)", observer, FALSE, corto_class_findObserver);
    CORTO_METAPROCEDURE_O(class, listen, "(observer observer,eventMask mask,object observable,dispatcher dispatcher)", void, FALSE, corto_class_listen);
    CORTO_METAPROCEDURE_O(class, setObservable, "(observer observer,object observable)", void, FALSE, corto_class_setObservable);
    CORTO_METAPROCEDURE_O(class, setMask, "(observer observer,eventMask mask)", void, FALSE, corto_class_setMask);
    CORTO_METAPROCEDURE_O(class, setDispatcher, "(observer observer,dispatcher dispatcher", void, FALSE, corto_class_setDispatcher);
    CORTO_METAPROCEDURE_O(class, observableOf, "(observer observer)", object, FALSE, corto_class_observableOf);
    CORTO_METAPROCEDURE_O(class, eventMaskOf, "(observer observer)", eventMask, FALSE, corto_class_eventMaskOf);

/* ::corto::lang::delegatedata */
CORTO_STRUCT_O(delegatedata, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(delegatedata, instance, object, CORTO_GLOBAL);
    CORTO_MEMBER_O(delegatedata, procedure, function, CORTO_GLOBAL);

/* ::corto::lang::delegate */
CORTO_FW_I(delegate);
CORTO_CLASS_O(delegate, struct, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(member), CORTO_TYPE_ID(method), CORTO_I);
    CORTO_METHOD_O(delegate, init, "()", int16, FALSE, corto_delegate_init);
    CORTO_REFERENCE_O(delegate, returnType, type, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(delegate, returnsReference, bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(delegate, parameters, parameterseq, CORTO_GLOBAL);
    CORTO_METHOD_O(delegate, compatible, "(type type)", bool, TRUE, corto_delegate_compatible_v);
    CORTO_METHOD_O(delegate, castable, "(type type)", bool, TRUE, corto_delegate_compatible_v);
    CORTO_METHOD_O(delegate, instanceof, "(object object)", bool, FALSE, corto_delegate_instanceof);
    CORTO_FUNCTION_O(delegate, bind, "(function object)", int16, corto_delegate_bind);

/* ::corto::lang::procedure */
CORTO_FW_I(procedure);
CORTO_CLASS_O(procedure, struct, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(procedure, kind, procedureKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(procedure, bind, initAction, CORTO_LOCAL|CORTO_READONLY);
    CORTO_METHOD_O(procedure, init, "()", int16, FALSE, corto_procedure_init);
    CORTO_METHOD_O(procedure, unbind, "(function object)", void, FALSE, corto_procedure_unbind);

/* ::corto::lang::array */
CORTO_FW_ICD(array);
CORTO_CLASS_O(array, collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_REFERENCE_O(array, elementType, type, CORTO_GLOBAL|CORTO_PRIVATE, CORTO_DEFINED, FALSE);
    CORTO_METHOD_O(array, init, "()", int16, FALSE, corto_array_init);
    CORTO_METHOD_O(array, construct, "()", int16, FALSE, corto_array_construct);
    CORTO_METHOD_O(array, destruct, "()", void, FALSE, corto_array_destruct);

/* ::corto::lang::sequence */
CORTO_FW_IC(sequence);
CORTO_CLASS_O(sequence, collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(sequence, init, "()", int16, FALSE, corto_sequence_init);
    CORTO_METHOD_O(sequence, construct, "()", int16, FALSE, corto_sequence_construct);
    CORTO_METAPROCEDURE_O(sequence, size, "(uint32 size)", void, FALSE, corto_sequence_size);

/* ::corto::lang::list */
CORTO_FW_IC(list);
CORTO_CLASS_O(list, collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(list, init, "()", int16, FALSE, corto_list_init);
    CORTO_METHOD_O(list, construct, "()", int16, FALSE, corto_list_construct);
    CORTO_METAPROCEDURE_O(list, insert, "(any element)", void, FALSE, corto_list_insert_any);
    CORTO_METAPROCEDURE_O(list, append, "(any element)", void, FALSE, corto_list_append_any);
    CORTO_METAPROCEDURE_NAME_O(list, insert_, insert, "()", any, FALSE, corto_list_insert_);
    CORTO_METAPROCEDURE_NAME_O(list, append_, append, "()", any, FALSE, corto_list_append_);
    CORTO_METAPROCEDURE_O(list, reverse, "()", void, FALSE, corto_list_reverse);
    CORTO_METAPROCEDURE_O(list, clear, "()", void, FALSE, corto_list_clear);

/* ::corto::lang::map */
CORTO_FW_IC(map);
CORTO_CLASS_O(map, collection, CORTO_LOCAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    /* Duplicate members for a more convenient order in the initializer */
    CORTO_REFERENCE_O(map, elementType, type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_REFERENCE_O(map, keyType, type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(map, max, uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(map, init, "()", int16, FALSE, corto_map_init);
    CORTO_METHOD_O(map, construct, "()", int16, FALSE, corto_map_construct);

/* ::corto::lang::function */
CORTO_FW_IB(function);
CORTO_PROCEDURE_NOBASE_O(function, CORTO_FUNCTION, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_IC);
    CORTO_REFERENCE_O(function, returnType, type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(function, returnsReference, bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(function, overloaded, bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_MEMBER_O(function, kind, uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(function, impl, word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(function, implData, word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_REFERENCE_O(function, resource, object, CORTO_LOCAL|CORTO_PRIVATE, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(function, size, uint16, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(function, parameters, parameterseq, CORTO_LOCAL | CORTO_READONLY);
    CORTO_MEMBER_O(function, nextParameterId, uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(function, init, "()", int16, FALSE, corto_function_init);
    CORTO_METHOD_O(function, bind, "()", int16, FALSE, corto_function_bind);
    CORTO_FUNCTION_O(function, unbind, "(function object)", void, corto_function_unbind);
    CORTO_FUNCTION_O(function, stringToParameterSeq, "(string name,object scope)", parameterseq, corto_function_stringToParameterSeq);

/* ::corto::lang::dispatcher */
CORTO_INTERFACE_O(dispatcher);
    CORTO_IMETHOD_O(dispatcher, post, "(event e)", void, FALSE);

/* ::corto::lang::query */
CORTO_CLASS_NOBASE_O(query, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(query, from, object, CORTO_GLOBAL);
    CORTO_MEMBER_O(query, mask, eventMask, CORTO_GLOBAL);

/* ::corto::lang::replicator */
CORTO_FW_CD(replicator);
CORTO_CLASS_NOBASE_O(replicator, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(replicator, mount, object, CORTO_GLOBAL);
    CORTO_MEMBER_O(replicator, query, query, CORTO_GLOBAL);
    CORTO_METHOD_O(replicator, construct, "()", int16, FALSE, corto_replicator_construct);
    CORTO_METHOD_O(replicator, destruct, "()", void, FALSE, corto_replicator_destruct);
    CORTO_METHOD_O(replicator, post, "(event e)", void, FALSE, corto_replicator_post);
    CORTO_METHOD_O(replicator, invoke, "(object instance,function proc,octetseq args)", void, FALSE, corto_replicator_post);
    CORTO_MEMBER_O(replicator, onDeclare, notifyAction, CORTO_GLOBAL);
    CORTO_MEMBER_O(replicator, onUpdate, notifyAction, CORTO_GLOBAL);
    CORTO_MEMBER_O(replicator, onDelete, notifyAction, CORTO_GLOBAL);
    CORTO_MEMBER_O(replicator, onInvoke, invokeAction, CORTO_GLOBAL);
    CORTO_OBSERVER_O(replicator, on_declare, corto_replicator_on_declare);
    CORTO_OBSERVER_O(replicator, on_update, corto_replicator_on_update);
    CORTO_OBSERVER_O(replicator, on_delete, corto_replicator_on_delete);

/* ::corto::lang::event */
CORTO_CLASS_NOBASE_O(event, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(event, kind, uint16, CORTO_GLOBAL);
    CORTO_MEMBER_O(event, handled, bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_METHOD_O(event, handle, "()", void, TRUE, corto_event_handle_v);
    CORTO_FUNCTION_O(event, uniqueKind, "()", int16, corto_event_uniqueKind);

/* ::corto::lang::observableEvent */
CORTO_CLASS_O(observableEvent, event, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(observableEvent, observer, observer, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observableEvent, me, object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observableEvent, source, object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observableEvent, observable, object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(observableEvent, handle, "()", void, TRUE, corto_observableEvent_handle_v);

/* ::corto::lang::invokeEvent */
CORTO_CLASS_O(invokeEvent, event, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(invokeEvent, replicator, replicator, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(invokeEvent, instance, object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(invokeEvent, function, function, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(invokeEvent, args, octetseq, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(invokeEvent, handle, "()", void, TRUE, corto_invokeEvent_handle_v);

/* ::corto::lang::method */
CORTO_FW_IB(method);
CORTO_PROCEDURE_O(method, CORTO_METHOD, function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_IC);
    CORTO_MEMBER_O(method, virtual, bool, CORTO_GLOBAL);
    CORTO_METHOD_O(method, init, "()", int16, FALSE, corto_method_init);
    CORTO_METHOD_O(method, bind, "()", int16, FALSE, corto_method_bind);

CORTO_FW_I(virtual);
CORTO_PROCEDURE_O(virtual, CORTO_METHOD, method, CORTO_GLOBAL, CORTO_TYPE_ID(interface), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(virtual, init, "()", int16, FALSE, corto_virtual_init);

/* ::corto::lang::observer */
CORTO_FW_IB(observer);
CORTO_PROCEDURE_O(observer, CORTO_OBSERVER, function, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_IC);
    CORTO_MEMBER_O(observer, mask, eventMask, CORTO_GLOBAL);
    CORTO_REFERENCE_O(observer, observable, object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(observer, template, uint32, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_REFERENCE_O(observer, dispatcher, dispatcher, CORTO_GLOBAL|CORTO_HIDDEN, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observer, me, object, CORTO_GLOBAL|CORTO_HIDDEN, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observer, observing, object, CORTO_LOCAL | CORTO_PRIVATE, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(observer, delayedBinder, observer, CORTO_LOCAL | CORTO_PRIVATE, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(observer, init, "()", int16, FALSE, corto_observer_init);
    CORTO_METHOD_O(observer, bind, "()", int16, FALSE, corto_observer_bind);
    CORTO_METHOD_O(observer, listen, "(object observable,object me)", int16, FALSE, corto_observer_listen);
    CORTO_METHOD_O(observer, silence, "(object me)", int16, FALSE, corto_observer_silence);
    CORTO_METHOD_O(observer, setDispatcher, "(dispatcher dispatcher)", void, FALSE, corto_observer_setDispatcher);
    CORTO_FUNCTION_O(observer, unbind, "(observer object)", void, corto_observer_unbind);

/* ::corto::lang::metaprocedure */
CORTO_FW_B(metaprocedure);
CORTO_PROCEDURE_O(metaprocedure, CORTO_METAPROCEDURE, function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_B);
    CORTO_METHOD_O(metaprocedure, bind, "()", int16, FALSE, corto_metaprocedure_bind);
    CORTO_MEMBER_O(metaprocedure, referenceOnly, bool, CORTO_GLOBAL);

/* ::corto::lang::member */
CORTO_FW_IC(member);
CORTO_CLASS_NOBASE_O(member, CORTO_TYPE_ID(interface), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(member, type, type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(member, modifiers, modifier, CORTO_GLOBAL);
    CORTO_MEMBER_O(member, state, state, CORTO_GLOBAL);
    CORTO_MEMBER_O(member, weak, bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(member, id, uint32, CORTO_GLOBAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(member, offset, uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(member, init, "()", int16, FALSE, corto_member_init);
    CORTO_METHOD_O(member, construct, "()", int16, FALSE, corto_member_construct);

/* ::corto::lang::alias */
CORTO_FW_IC(alias);
CORTO_CLASS_O(alias, member, CORTO_HIDDEN, CORTO_TYPE_ID(struct), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(alias, member, member, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_METHOD_O(alias, init, "()", int16, FALSE, corto_alias_init);
    CORTO_METHOD_O(alias, construct, "()", int16, FALSE, corto_alias_construct);

/* ::corto::lang::parameter */
CORTO_STRUCT_O(parameter, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(parameter, name, string, CORTO_GLOBAL);
    CORTO_REFERENCE_O(parameter, type, type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(parameter, passByReference, bool, CORTO_GLOBAL);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_BOOTSTRAP_H_ */
