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
 *     Because lang/function is the only object with an unbind this is a safe workaround. Consequence is that
 *     end-users won't be able to use the procedure/unbind delegate, which is acceptable.
 *
 *  7. The virtual method 'interface/bindMethod' is required to bind methods to classes and interfaces. However,
 *     there is a bootstrap issue here (who binds bindMethod) which cannot be easily solved by a hard-coded
 *     bind of bindMethod. Since virtual methods are looked-up by methodId's, and methodId's are only stable
 *     after the parent of a method is defined, bindMethod can only be looked up after both 'interface' and
 *     'class' are defined. To get defined though, these classes need to bind all their methods, hence the
 *     bootstrap. This issue is solved by calling the method/init initializer call the implementations of the
 *     virtual method 'interface/bindMethod' directly, so no methodId lookup is required.
 *     For delegate functions this is the same, but here the implementation is easier, since the delegate/init
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
    } vtable;\
    corto_object vbuff[16];\
}sso_##type

/* Static Scoped Object */
typedef struct corto_SSO {
    corto__scope s;
    corto__object o;
}corto_SSO;

/* Static Scoped Observable Object */
typedef struct corto_SSOO {
    corto__persistent p;
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
CORTO_STATIC_SCOPED_REFOBJECT(iterator);
CORTO_STATIC_SCOPED_OBJECT(parameter);

CORTO_STATIC_SCOPED_OBJECT(constant);

#define VTABLE_V {16,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
#define CORTO_FWDECL_SSO(type, name) sso_##type name##__o
#define CORTO_FWDECL(type, name) CORTO_FWDECL_SSO(type, lang_##name); corto_##type corto_##name##_o = &lang_##name##__o.v
#define CORTO_FWDECL_CORE(type, name) CORTO_FWDECL_SSO(type, core_##name); corto_##type corto_##name##_o = &core_##name##__o.v
#define CORTO_FWDECL_NATIVE(type, name) CORTO_FWDECL_SSO(type, native_##name); corto_##type corto_native_##name##_o = &native_##name##__o.v

/* SSO */
#define CORTO_ATTR_SSOO {1, 0, 1, 1, CORTO_VALID | CORTO_DECLARED}
#define CORTO_ATTR_SSO {1, 0, 0, 0, CORTO_VALID | CORTO_DECLARED}
#define CORTO_ATTR_SO {0, 0, 0, 0, CORTO_VALID | CORTO_DECLARED}
#define CORTO_ROOT_V() {{NULL},{NULL,NULL,CORTO_RWMUTEX_INITIALIZER,CORTO_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE},{NULL, NULL, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(extensions)NULL},{CORTO_ATTR_SSOO, 2, (corto_type)&core_package__o.v}}
#define CORTO_PACKAGE_V(parent, name, uri) {{NULL},{NULL,NULL,CORTO_RWMUTEX_INITIALIZER,CORTO_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE},{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(extensions)NULL},{CORTO_ATTR_SSOO, 2, (corto_type)&core_package__o.v}}, {uri}
#define CORTO_SSO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSOO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(extensions)NULL},{CORTO_ATTR_SSO, 2, (corto_type)&type##__o.v}}
#define CORTO_SSO_PO_V(parent, name, type) {{CORTO_OFFSET(&parent##__o, sizeof(corto_SSO)), name, _(scope)NULL, _(scopeLock)CORTO_RWMUTEX_INITIALIZER, _(extensions)NULL},{CORTO_ATTR_SSO, 2, (corto_type)&type##__o.v}}

/* SSO identifier */
#define CORTO_ID(name) name##__o
#define CORTO_TYPE_ID(name) (corto_type)&CORTO_ID(name).v

/* Forward declarations of delegates */
#define CORTO_FW_I(parent, name) sso_method CORTO_ID(parent##_##name##_init_)
#define CORTO_FW_IC(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_)
#define CORTO_FW_ICD(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)
#define CORTO_FW_IB(parent, name) sso_method CORTO_ID(parent##_##name##_init_), CORTO_ID(parent##_##name##_bind_)
#define CORTO_FW_B(parent, name) sso_method CORTO_ID(parent##_##name##_bind_)
#define CORTO_FW_CD(parent, name) sso_method CORTO_ID(parent##_##name##_construct_), CORTO_ID(parent##_##name##_destruct_)

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
#define CORTO_TYPE_V(parent, name, kind, reference, scopeType, scopeTypeKind, defaultType, defaultProcedureType, DELEGATE) \
  {kind, reference, FALSE, 0, 0, 0, scopeType, scopeTypeKind, defaultType, defaultProcedureType, {0,NULL}, DELEGATE##_TYPE(parent##_##name)}

/* primitive */
#define CORTO_PRIMITIVE_V(parent, name, kind, width, scopeType, scopeStateKind, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_PRIMITIVE, FALSE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, width, 0}

/* interface */
#define CORTO_COMPOSITE_V(parent, name, kind, base, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_COMPOSITE, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, (corto_interface)&base##__o.v}

/* interface */
#define CORTO_COMPOSITE_NOBASE_V(parent, name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
  {CORTO_TYPE_V(parent, name, CORTO_COMPOSITE, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), kind, 0, {0, NULL}, {0,NULL}, NULL}

/* struct */
#define CORTO_STRUCT_V(parent, name, kind, base, baseAccess, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_V(parent, name, kind, base, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), baseAccess}

#define CORTO_STRUCT_NOBASE_V(parent, name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) \
    {CORTO_COMPOSITE_NOBASE_V(parent, name, kind, reference, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), CORTO_LOCAL}

/* collection */
#define CORTO_COLLECTION_V(parent, name, kind, elementType, max) {CORTO_TYPE_V(parent, name, CORTO_COLLECTION, FALSE, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), kind, (corto_type)&elementType##__o.v, max}

/* sequence */
#define CORTO_SEQUENCE_V(subType, length, ...) {length, (subType[]){__VA_ARGS__}}
#define CORTO_SEQUENCE_EMPTY_V(subType) {0, NULL}

/* member */
#define CORTO_MEMBER_V(type, access, state, weak) {(corto_type)&type##__o.v, access, state, weak, 0, 0}

/* object */
#define CORTO_PACKAGE_O(name, uri) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(root, #name, uri)}
#define CORTO_PACKAGE_O_SCOPE(parent, name, uri) corto_ssoo_package name##__o = {CORTO_PACKAGE_V(parent, #name, uri)}

/* type object */
#define CORTO_TYPE_O(parent, name, kind, reference) static sso_type parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_type), CORTO_TYPE_V(parent, name, kind, reference, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), VTABLE_V}

/* primitive object */
#define CORTO_PRIMITIVE_O(parent, name, kind, width) sso_primitive parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_primitive), CORTO_PRIMITIVE_V(parent, name, kind, width, CORTO_NODELEGATE), VTABLE_V}

/* binary object */
#define CORTO_BINARY_O(parent, name, width) sso_binary parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_binary), {CORTO_PRIMITIVE_V(parent, name, CORTO_BINARY, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* boolean object */
#define CORTO_BOOLEAN_O(parent, name) sso_boolean parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_boolean), {CORTO_PRIMITIVE_V(parent, name, CORTO_BOOLEAN, CORTO_WIDTH_8, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* character object */
#define CORTO_CHARACTER_O(parent, name, width) sso_character parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_character), {CORTO_PRIMITIVE_V(parent, name, CORTO_CHARACTER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE)}, VTABLE_V}

/* int object */
#define CORTO_INT_O(parent, name, width, min, max, scopeType, scopeStateKind, DELEGATE) sso_int parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_int), {CORTO_PRIMITIVE_V(parent, name, CORTO_INTEGER, width, scopeType, scopeStateKind, DELEGATE), min, max}, VTABLE_V}

/* uint object */
#define CORTO_UINT_O(parent, name, width, min, max) sso_uint parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_uint), {CORTO_PRIMITIVE_V(parent, name, CORTO_UINTEGER, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}, VTABLE_V}

/* float object */
#define CORTO_FLOAT_O(parent, name, width, min, max) sso_float parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_float), {CORTO_PRIMITIVE_V(parent, name, CORTO_FLOAT, width, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), min, max}, VTABLE_V}

/* text object */
#define CORTO_TEXT_O(parent, name, width, length) sso_text parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_text), {CORTO_PRIMITIVE_V(parent, name, CORTO_TEXT, CORTO_WIDTH_WORD, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), width, length}, VTABLE_V}

/* enum object */
#define CORTO_ENUM_O(parent, name) sso_enum parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_enum), {CORTO_PRIMITIVE_V(parent, name, CORTO_ENUM, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}, VTABLE_V}

/* bitmask object */
#define CORTO_BITMASK_O(parent, name) sso_bitmask parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_bitmask), {{CORTO_PRIMITIVE_V(parent, name, CORTO_BITMASK, CORTO_WIDTH_32, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_NODELEGATE), CORTO_SEQUENCE_EMPTY_V(constant)}}, VTABLE_V}

/* constant object */
#define CORTO_CONSTANT_O(parent, name) sso_constant parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, lang_constant), CORTO_##name, VTABLE_V}

/* struct object */
#define CORTO_STRUCT_O(parent, name, scopeType, scopeStateKind, defaultType, defaultProcedureType) sso_struct parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_struct), CORTO_STRUCT_NOBASE_V(parent, name, CORTO_STRUCT, FALSE, scopeType, scopeStateKind, defaultType, defaultProcedureType, CORTO_NODELEGATE), VTABLE_V}

/* interface object */
#define CORTO_INTERFACE_O(parent, name) sso_interface parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_interface), CORTO_COMPOSITE_NOBASE_V(parent, name, CORTO_INTERFACE, TRUE, NULL, 0, NULL, CORTO_TYPE_ID(lang_method), CORTO_NODELEGATE), VTABLE_V}

/* class object */
#define CORTO_CLASS_NOBASE_O(parent, name, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) sso_class parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_CLASS, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}, VTABLE_V}

#define CORTO_CLASS_O(parent, name, base, baseAccess, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE) sso_class parent##_##name##__o = \
        {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_V(parent, name, CORTO_CLASS, base, baseAccess, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {0,NULL}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}, VTABLE_V}

#define CORTO_CLASS_IMPLEMENTS_O(parent, name, scopeType, scopeStateKind, defaultType, defaultProcedureType, interface, DELEGATE) sso_class parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_class), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_CLASS, TRUE, scopeType, scopeStateKind, defaultType, defaultProcedureType, DELEGATE), {1,{interface}}, {0,NULL}, DELEGATE##_CLASS(parent##_##name)}, VTABLE_V}

/* array object */
#define CORTO_ARRAY_O(parent, name, elementType, size) sso_array parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_array), {CORTO_COLLECTION_V(parent, name, CORTO_ARRAY, elementType, size)}, VTABLE_V}

/* sequence object */
#define CORTO_SEQUENCE_O(parent, name, elementType, max) sso_sequence parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_sequence), {CORTO_COLLECTION_V(parent, name, CORTO_SEQUENCE, elementType, max)}, VTABLE_V}

/* list object */
#define CORTO_LIST_O(parent, name, elementType, max) sso_list parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_list), {CORTO_COLLECTION_V(parent, name, CORTO_LIST, elementType, max)}, VTABLE_V}

/* map object */
#define CORTO_MAP_O(parent, name, elementType, keyType, max) sso_map parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_map), {CORTO_COLLECTION_V(parent, name, CORTO_MAP, elementType, max), (corto_type)&keyType##__o.v}, VTABLE_V}

/* procedure object */
#define CORTO_PROCEDURE_O(parent, name, kind, base, baseAccess, scopeType, scopeStateKind, DELEGATE) sso_procedure parent##_##name##__o = \
        {CORTO_SSO_V(parent, #name, lang_procedure), {CORTO_STRUCT_V(parent, name, CORTO_PROCEDURE, base, baseAccess, TRUE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, DELEGATE##_PROC(parent##_##name)}, VTABLE_V}
#define CORTO_PROCEDURE_NOBASE_O(parent, name, kind, scopeType, scopeStateKind, DELEGATE) sso_procedure parent##_##name##__o = \
        {CORTO_SSO_V(parent, #name, lang_procedure), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_PROCEDURE, TRUE, scopeType, scopeStateKind, NULL, NULL, DELEGATE), kind, DELEGATE##_PROC(parent##_##name)}, VTABLE_V}

/* function object */
#define CORTO_FUNCTION_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, lang_function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}

#define CORTO_FUNCTION_OO_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_V(parent, #name args, lang_function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}

#define CORTO_FUNCTION_OVERLOAD_OO_O(parent, name, args, returnType, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_function parent##_##name##__o = {CORTO_SSO_V(parent, args, lang_function), {(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}

/* method object */
#define CORTO_METHOD_O(parent, name, args, returnType, virtual, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_method parent##_##name##___o = {CORTO_SSO_PO_V(parent, #name args, lang_method), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0,{0,NULL},0}, virtual}, VTABLE_V}

/* interface method object */
#define CORTO_IMETHOD_O(parent, name, args, returnType, virtual) \
        sso_method parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, lang_method), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, 0, 0, 0, NULL, 0,{0,NULL},0}, virtual}, VTABLE_V}

/* interface method object */
#define CORTO_OBSERVER_O(parent, name, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_observer parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, core_observer), {{(corto_type)&lang_void##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0,{0,NULL},0}, 0}, VTABLE_V}

/* metaprocedure object */
#define CORTO_METAPROCEDURE_O(parent, name, args, returnType, referenceOnly, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name args, lang_metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0, {0,NULL},0}, referenceOnly}, VTABLE_V}

#define CORTO_METAPROCEDURE_NAME_O(parent, name, actualName, args, returnType, referenceOnly, impl) \
        void __##impl(void *f, void *r, void *a); \
        sso_metaprocedure parent##_##name##__o = {CORTO_SSO_PO_V(parent, #actualName args, lang_metaprocedure), {{(corto_type)&returnType##__o.v, FALSE, FALSE, CORTO_PROCEDURE_CDECL, (corto_word)ffi_call, (corto_word)_##impl, 0, NULL, 0, {0,NULL},0}, referenceOnly}, VTABLE_V}

/* member object */
#define CORTO_MEMBER_O(parent, name, type, access) sso_member parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, lang_member), CORTO_MEMBER_V(type, access, CORTO_DECLARED | CORTO_DEFINED, FALSE), VTABLE_V}

/* member object */
#define CORTO_ALIAS_O(parent, name, member, access) sso_alias parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, lang_alias), {CORTO_MEMBER_V(lang_word, access, 0, FALSE), (corto_member)&member##__o.v}, VTABLE_V}

/* reference object */
#define CORTO_REFERENCE_O(parent, name, type, access, state, weak) sso_member parent##_##name##__o = {CORTO_SSO_PO_V(parent, #name, lang_member), CORTO_MEMBER_V(type, access, state, weak), VTABLE_V}

/* Delegate type */
#define CORTO_DELEGATE_O(parent, name, returnType) sso_delegate parent##_##name##__o = \
    {CORTO_SSO_V(parent, #name, lang_delegate), {CORTO_STRUCT_NOBASE_V(parent, name, CORTO_DELEGATE, FALSE, NULL, CORTO_DECLARED|CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), (corto_type)&returnType##__o.v, FALSE, CORTO_SEQUENCE_EMPTY_V(parameter)}, VTABLE_V}

#define CORTO_ITERATOR_O(parent, name, elementType) sso_iterator parent##_##name##__o = {CORTO_SSO_V(parent, #name, lang_iterator), {CORTO_TYPE_V(parent, name, CORTO_ITERATOR, FALSE, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE), (corto_type)&elementType##__o.v}, VTABLE_V}


/* Forward declarations of classes */
CORTO_FWDECL(class, alias);
CORTO_FWDECL(class, array);
CORTO_FWDECL(class, binary);
CORTO_FWDECL(class, bitmask);
CORTO_FWDECL(class, boolean);
CORTO_FWDECL(class, class);
CORTO_FWDECL(class, delegate);
CORTO_FWDECL_CORE(class, event);
CORTO_FWDECL(class, character);
CORTO_FWDECL(class, collection);
CORTO_FWDECL(class, enum);
CORTO_FWDECL(class, int);
CORTO_FWDECL(class, float);
CORTO_FWDECL(class, interface);
CORTO_FWDECL_CORE(class, invokeEvent);
CORTO_FWDECL(class, iterator);
CORTO_FWDECL(class, list);
CORTO_FWDECL(class, map);
CORTO_FWDECL(class, member);
CORTO_FWDECL_CORE(class, notifyEvent);
CORTO_FWDECL_CORE(class, observableEvent);
CORTO_FWDECL_CORE(class, package);
CORTO_FWDECL_CORE(class, loader);
CORTO_FWDECL(class, primitive);
CORTO_FWDECL(class, procedure);
CORTO_FWDECL_CORE(class, mount);
CORTO_FWDECL(class, sequence);
CORTO_FWDECL(class, struct);
CORTO_FWDECL(class, text);
CORTO_FWDECL(class, type);
CORTO_FWDECL(class, uint);
CORTO_FWDECL_NATIVE(class, type);


CORTO_FWDECL(struct, delegatedata);
CORTO_FWDECL(struct, interfaceVector);
CORTO_FWDECL(struct, parameter);
CORTO_FWDECL_CORE(struct, augmentData);
CORTO_FWDECL_CORE(struct, result);
CORTO_FWDECL_CORE(struct, request);

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
CORTO_FWDECL_CORE(procedure, observer);
CORTO_FWDECL(procedure, virtual);

CORTO_FWDECL(enum, collectionKind);
CORTO_FWDECL(enum, compositeKind);
CORTO_FWDECL(enum, equalityKind);
CORTO_FWDECL(enum, primitiveKind);
CORTO_FWDECL_CORE(enum, operatorKind);
CORTO_FWDECL(enum, procedureKind);
CORTO_FWDECL_CORE(enum, mountKind);
CORTO_FWDECL(enum, scopeStateKind);
CORTO_FWDECL(enum, typeKind);
CORTO_FWDECL(enum, width);

CORTO_FWDECL_CORE(bitmask, attr);
CORTO_FWDECL_CORE(bitmask, eventMask);
CORTO_FWDECL(bitmask, modifier);
CORTO_FWDECL(bitmask, state);

CORTO_FWDECL(sequence, interfaceseq);
CORTO_FWDECL(sequence, interfaceVectorseq);
CORTO_FWDECL(sequence, memberseq);
CORTO_FWDECL(sequence, objectseq);
CORTO_FWDECL_CORE(sequence, observerseq);
CORTO_FWDECL(sequence, octetseq);
CORTO_FWDECL(sequence, parameterseq);
CORTO_FWDECL(sequence, vtable);
CORTO_FWDECL_CORE(sequence, augmentseq);

CORTO_FWDECL_CORE(list, resultList);

CORTO_FWDECL(delegate, destructAction);
CORTO_FWDECL(delegate, initAction);
CORTO_FWDECL(delegate, nameAction);
CORTO_FWDECL_CORE(delegate, notifyAction);
CORTO_FWDECL_CORE(delegate, requestAction);
CORTO_FWDECL_CORE(delegate, invokeAction);

CORTO_FWDECL_CORE(observer, mount_on_declare);
CORTO_FWDECL_CORE(observer, mount_on_update);
CORTO_FWDECL_CORE(observer, mount_on_delete);

CORTO_FWDECL_CORE(iterator, resultIter);

CORTO_FWDECL_CORE(struct, time);
CORTO_FWDECL_CORE(struct, position);

/* database root */
corto_ssoo_package root__o = {CORTO_ROOT_V(), {"http://corto.io/doc"}};
corto_package root_o = CORTO_OFFSET(&root__o.o.o, sizeof(corto__object));

/* /corto, /corto/lang, /corto/core */
CORTO_PACKAGE_O(corto, "http://corto.io/doc/corto");
CORTO_PACKAGE_O_SCOPE(corto, lang, "http://corto.io/doc/corto/lang");
CORTO_PACKAGE_O_SCOPE(corto, core, "http://corto.io/doc/corto/core");
CORTO_PACKAGE_O_SCOPE(corto, native, "http://corto.io/doc/corto/native");

corto_package corto_o = CORTO_OFFSET(&corto__o.o.o, sizeof(corto__object));
corto_package corto_lang_o = CORTO_OFFSET(&lang__o.o.o, sizeof(corto__object));
corto_package corto_core_o = CORTO_OFFSET(&core__o.o.o, sizeof(corto__object));
corto_package corto_native_o = CORTO_OFFSET(&native__o.o.o, sizeof(corto__object));

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
    CORTO_METHOD_O(lang_constant, init, "()", lang_int16, FALSE, corto_constant_init);

/* Any type */
CORTO_TYPE_O(lang, any, CORTO_ANY, FALSE);

/* Void type */
CORTO_TYPE_O(lang, void, CORTO_VOID, FALSE);

/* Object type */
CORTO_TYPE_O(lang, object, CORTO_VOID, TRUE);

/* Package type */
CORTO_CLASS_NOBASE_O(core, package, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(core_package, url, lang_string, CORTO_GLOBAL);

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
    CORTO_CONSTANT_O(lang_compositeKind, STRUCT);
    CORTO_CONSTANT_O(lang_compositeKind, INTERFACE);
    CORTO_CONSTANT_O(lang_compositeKind, CLASS);
    CORTO_CONSTANT_O(lang_compositeKind, DELEGATE);
    CORTO_CONSTANT_O(lang_compositeKind, PROCEDURE);

CORTO_ENUM_O(lang, collectionKind);
    CORTO_CONSTANT_O(lang_collectionKind, ARRAY);
    CORTO_CONSTANT_O(lang_collectionKind, SEQUENCE);
    CORTO_CONSTANT_O(lang_collectionKind, LIST);
    CORTO_CONSTANT_O(lang_collectionKind, MAP);

CORTO_ENUM_O(lang, procedureKind);
    CORTO_CONSTANT_O(lang_procedureKind, FUNCTION);
    CORTO_CONSTANT_O(lang_procedureKind, METHOD);
    CORTO_CONSTANT_O(lang_procedureKind, OBSERVER);
    CORTO_CONSTANT_O(lang_procedureKind, METAPROCEDURE);

CORTO_ENUM_O(lang, equalityKind);
    CORTO_CONSTANT_O(lang_equalityKind, EQ);
    CORTO_CONSTANT_O(lang_equalityKind, LT);
    CORTO_CONSTANT_O(lang_equalityKind, GT);
    CORTO_CONSTANT_O(lang_equalityKind, NEQ);

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

CORTO_BITMASK_O(lang, state);
    CORTO_CONSTANT_O(lang_state, VALID);
    CORTO_CONSTANT_O(lang_state, DECLARED);
    CORTO_CONSTANT_O(lang_state, DEFINED);
    CORTO_CONSTANT_O(lang_state, DESTRUCTED);

CORTO_BITMASK_O(core, attr);
    CORTO_CONSTANT_O(core_attr, ATTR_SCOPED);
    CORTO_CONSTANT_O(core_attr, ATTR_WRITABLE);
    CORTO_CONSTANT_O(core_attr, ATTR_OBSERVABLE);
    CORTO_CONSTANT_O(core_attr, ATTR_PERSISTENT);
    CORTO_CONSTANT_O(core_attr, ATTR_DEFAULT);

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

CORTO_BITMASK_O(lang, modifier);
    CORTO_CONSTANT_O(lang_modifier, GLOBAL);
    CORTO_CONSTANT_O(lang_modifier, LOCAL);
    CORTO_CONSTANT_O(lang_modifier, PRIVATE);
    CORTO_CONSTANT_O(lang_modifier, READONLY);
    CORTO_CONSTANT_O(lang_modifier, CONST);
    CORTO_CONSTANT_O(lang_modifier, HIDDEN);

/* Collections */
CORTO_SEQUENCE_O(core, augmentseq, core_augmentData, 0);
CORTO_SEQUENCE_O(lang, interfaceseq, lang_interface, 0);
CORTO_SEQUENCE_O(lang, interfaceVectorseq, lang_interfaceVector, 0);
CORTO_SEQUENCE_O(lang, memberseq, lang_member, 0);
CORTO_SEQUENCE_O(core, observerseq, core_observer, 0);
CORTO_SEQUENCE_O(lang, objectseq, lang_object, 0);
CORTO_SEQUENCE_O(lang, octetseq, lang_octet, 0);
CORTO_SEQUENCE_O(lang, parameterseq, lang_parameter, 0);
CORTO_LIST_O(core, resultList, core_result, 0);
CORTO_SEQUENCE_O(lang, vtable, lang_function, 0);

/* Delegate types */
CORTO_DELEGATE_O(lang, initAction, lang_int16);
CORTO_DELEGATE_O(lang, nameAction, lang_string);
CORTO_DELEGATE_O(lang, destructAction, lang_void);
CORTO_DELEGATE_O(core, notifyAction, lang_void);
CORTO_DELEGATE_O(core, invokeAction, lang_void);
CORTO_DELEGATE_O(core, requestAction, core_resultIter);

/* Iterator types */
CORTO_ITERATOR_O(core, resultIter, core_result);

/* /corto/lang/type */
CORTO_FW_ICD(lang, type);
CORTO_CLASS_NOBASE_O(lang, type, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_type, kind, lang_typeKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, reference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_type, hasResources, lang_bool, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, templateId, lang_uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, size, lang_uint32, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_MEMBER_O(lang_type, alignment, lang_uint16, CORTO_PRIVATE | CORTO_LOCAL);
    CORTO_REFERENCE_O(lang_type, parentType, lang_type, CORTO_HIDDEN, CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(lang_type, parentState, lang_state, CORTO_HIDDEN);
    CORTO_REFERENCE_O(lang_type, defaultType, lang_type, CORTO_HIDDEN, CORTO_DEFINED, FALSE);
    CORTO_REFERENCE_O(lang_type, defaultProcedureType, lang_type, CORTO_HIDDEN, CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(lang_type, metaprocedures, lang_vtable, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, init, lang_initAction, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_type, nameof, lang_nameAction, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_type, sizeof, "()", lang_uint32, FALSE, corto_type_sizeof);
    CORTO_METHOD_O(lang_type, alignmentof, "()", lang_uint16, FALSE, corto_type_alignmentof);
    CORTO_METHOD_O(lang_type, castable, "(type type)", lang_bool, TRUE, corto_type_castable_v);
    CORTO_METHOD_O(lang_type, compatible, "(type type)", lang_bool, TRUE, corto_type_compatible_v);
    CORTO_METHOD_O(lang_type, resolveProcedure, "(string name)", lang_function, FALSE, corto_type_resolveProcedure);
    CORTO_METHOD_O(lang_type, init, "()", lang_int16, FALSE, corto_type_init);
    CORTO_METHOD_O(lang_type, construct, "()", lang_int16, FALSE, corto_type_construct);
    CORTO_METHOD_O(lang_type, destruct, "()", lang_void, FALSE, corto_type_destruct);
    CORTO_METAPROCEDURE_O(lang_type, parent, "()", lang_object, TRUE, corto_type_parent);
    CORTO_METAPROCEDURE_O(lang_type, name, "()", lang_string, TRUE, corto_type_name);
    CORTO_METAPROCEDURE_O(lang_type, fullpath, "()", lang_string, TRUE, corto_type_fullpath);
    CORTO_METAPROCEDURE_O(lang_type, path, "(object from)", lang_string, TRUE, corto_type_path);
    CORTO_METAPROCEDURE_O(lang_type, declare, "(string name,type type)", lang_object, TRUE, corto_type_declare);
    CORTO_METAPROCEDURE_O(lang_type, define, "()", lang_int16, TRUE, corto_type_define);
    CORTO_METAPROCEDURE_O(lang_type, delete, "()", lang_void, TRUE, corto_type_delete);
    CORTO_METAPROCEDURE_O(lang_type, invalidate, "()", lang_void, TRUE, corto_type_invalidate);
    CORTO_METAPROCEDURE_O(lang_type, resolve, "(string name)", lang_object, TRUE, corto_type_resolve);
    CORTO_METAPROCEDURE_O(lang_type, lookup, "(string name)", lang_object, TRUE, corto_type_lookup);
    CORTO_METAPROCEDURE_O(lang_type, checkAttr, "(attr attributes)", lang_bool, TRUE, corto_type_checkAttr);
    CORTO_METAPROCEDURE_O(lang_type, checkState, "(state state)", lang_bool, TRUE, corto_type_checkState);
    CORTO_METAPROCEDURE_O(lang_type, type, "()", lang_type, FALSE, corto_type_type);
    CORTO_METAPROCEDURE_O(lang_type, instanceof, "(type type)", lang_bool, TRUE, corto_type_instanceof);
    CORTO_METAPROCEDURE_O(lang_type, compare, "(any value)", lang_equalityKind, FALSE, corto_type_compare);
    CORTO_METAPROCEDURE_O(lang_type, copy, "(any value)", lang_int16, FALSE, corto_type_copy);
    CORTO_METAPROCEDURE_O(lang_type, str, "()", lang_string, FALSE, corto_type_str);

/* /corto/lang/primitive */
CORTO_FW_IC(lang, primitive);
CORTO_CLASS_O(lang, primitive, lang_type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_MEMBER_O(lang_primitive, kind, lang_primitiveKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_primitive, width, lang_width, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_primitive, convertId, lang_uint8, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_primitive, castable, "(type type)", lang_bool, TRUE, corto_primitive_castable_v);
    CORTO_METHOD_O(lang_primitive, compatible, "(type type)", lang_bool, TRUE, corto_primitive_compatible_v);
    CORTO_METHOD_O(lang_primitive, isInteger, "()", lang_bool, FALSE, corto_primitive_isInteger);
    CORTO_METHOD_O(lang_primitive, isNumber, "()", lang_bool, FALSE, corto_primitive_isNumber);
    CORTO_METHOD_O(lang_primitive, init, "()", lang_int16, FALSE, corto_primitive_init);
    CORTO_METHOD_O(lang_primitive, construct, "()", lang_int16, FALSE, corto_primitive_construct);

/* /corto/lang/interface */
CORTO_FW_ICD(lang, interface);
CORTO_CLASS_O(lang, interface, lang_type, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_MEMBER_O(lang_interface, kind, lang_compositeKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_MEMBER_O(lang_interface, nextMemberId, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, members, lang_memberseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_interface, methods, lang_vtable, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_REFERENCE_O(lang_interface, base, lang_interface, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_ALIAS_O(lang_interface, parentType, lang_type_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O(lang_interface, parentState, lang_type_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O(lang_interface, defaultType, lang_type_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O(lang_interface, defaultProcedureType, lang_type_defaultProcedureType, CORTO_HIDDEN);
    CORTO_METHOD_O(lang_interface, init, "()", lang_int16, FALSE, corto_interface_init);
    CORTO_METHOD_O(lang_interface, construct, "()", lang_int16, FALSE, corto_interface_construct);
    CORTO_METHOD_O(lang_interface, destruct, "()", lang_void, FALSE, corto_interface_destruct);
    CORTO_METHOD_O(lang_interface, resolveMember, "(string name)", lang_member, TRUE, corto_interface_resolveMember_v);
    CORTO_METHOD_O(lang_interface, compatible, "(type type)", lang_bool, TRUE, corto_interface_compatible_v);
    CORTO_METHOD_O(lang_interface, resolveMethod, "(string name)", lang_method, FALSE, corto_interface_resolveMethod);
    CORTO_METHOD_O(lang_interface, resolveMethodId, "(string name)", lang_uint32, FALSE, corto_interface_resolveMethodId);
    CORTO_METHOD_O(lang_interface, resolveMethodById, "(uint32 id)", lang_method, FALSE, corto_interface_resolveMethodById);
    CORTO_METHOD_O(lang_interface, bindMethod, "(method method)", lang_int16, FALSE, corto_interface_bindMethod);
    CORTO_METHOD_O(lang_interface, baseof, "(interface type)", lang_int16, FALSE, corto_interface_baseof);

/* /corto/lang/collection */
CORTO_FW_I(lang, collection);
CORTO_CLASS_O(lang, collection, lang_type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_collection, kind, lang_collectionKind, CORTO_LOCAL|CORTO_READONLY);
    CORTO_REFERENCE_O(lang_collection, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(lang_collection, max, lang_uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_collection, castable, "(type type)", lang_bool, TRUE, corto_collection_castable_v);
    CORTO_METHOD_O(lang_collection, compatible, "(type type)", lang_bool, TRUE, corto_collection_compatible_v);
    CORTO_FUNCTION_O(lang_collection, requiresAlloc, "(type elementType)", lang_bool, corto_collection_requiresAlloc);
    CORTO_METHOD_O(lang_collection, init, "()", lang_int16, FALSE, corto_collection_init);
    CORTO_METAPROCEDURE_O(lang_collection, size, "()", lang_uint32, FALSE, corto_collection_size);

/* /corto/lang/iterator */
CORTO_FW_I(lang, iterator);
CORTO_CLASS_O(lang, iterator, lang_type, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_REFERENCE_O(lang_iterator, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(lang_iterator, init, "()", lang_int16, FALSE, corto_iterator_init);
    CORTO_METHOD_O(lang_iterator, compatible, "(type type)", lang_bool, TRUE, corto_iterator_compatible_v);
    CORTO_METHOD_O(lang_iterator, castable, "(type type)", lang_bool, TRUE, corto_iterator_castable_v);

/* /corto/lang/binary */
CORTO_FW_I(lang, binary);
CORTO_CLASS_O(lang, binary, lang_primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_binary, init, "()", lang_int16, FALSE, corto_binary_init);

/* /corto/lang/boolean */
CORTO_FW_I(lang, boolean);
CORTO_CLASS_O(lang, boolean, lang_primitive, CORTO_GLOBAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_boolean, init, "()", lang_int16, FALSE, corto_boolean_init);

/* /corto/lang/character */
CORTO_FW_I(lang, character);
CORTO_CLASS_O(lang, character, lang_primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_METHOD_O(lang_character, init, "()", lang_int16, FALSE, corto_character_init);

/* /corto/lang/int */
CORTO_FW_I(lang, int);
CORTO_CLASS_O(lang, int, lang_primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_int, min, lang_int64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_int, max, lang_int64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_int, init, "()", lang_int16, FALSE, corto_int_init);

/* /corto/lang/uint */
CORTO_FW_I(lang, uint);
CORTO_CLASS_O(lang, uint, lang_primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_uint, min, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_uint, max, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_uint, init, "()", lang_int16, FALSE, corto_uint_init);

/* /corto/lang/float */
CORTO_FW_I(lang, float);
CORTO_CLASS_O(lang, float, lang_primitive, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_float, min, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_float, max, lang_float64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_float, init, "()", lang_int16, FALSE, corto_float_init);

/* /corto/lang/text */
CORTO_FW_I(lang, text);
CORTO_CLASS_O(lang, text, lang_primitive, CORTO_LOCAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_text, charWidth, lang_width, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_text, length, lang_uint64, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_text, init, "()", lang_int16, FALSE, corto_text_init);

/* /corto/lang/enum */
CORTO_FW_ICD(lang, enum);
CORTO_CLASS_O(lang, enum, lang_primitive, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_constant), NULL, CORTO_ICD);
    CORTO_MEMBER_O(lang_enum, constants, lang_objectseq, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_enum, init, "()", lang_int16, FALSE, corto_enum_init);
    CORTO_METHOD_O(lang_enum, construct, "()", lang_int16, FALSE, corto_enum_construct);
    CORTO_METHOD_O(lang_enum, destruct, "()", lang_void, FALSE, corto_enum_destruct);
    CORTO_METHOD_O(lang_enum, constant, "(int32 value)", lang_object, FALSE, corto_enum_constant);

/* /corto/lang/bitmask */
CORTO_FW_I(lang, bitmask);
CORTO_CLASS_O(lang, bitmask, lang_enum, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_constant), NULL, CORTO_I);
    CORTO_METHOD_O(lang_bitmask, init, "()", lang_int16, FALSE, corto_bitmask_init);

/* /corto/lang/struct */
CORTO_FW_IC(lang, struct);
CORTO_CLASS_O(lang, struct, lang_interface, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_IC);
    CORTO_ALIAS_O (lang_struct, base, lang_interface_base, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_struct, baseAccess, lang_modifier, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_struct, parentType, lang_interface_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_struct, parentState, lang_interface_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_struct, defaultType, lang_interface_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_struct, defaultProcedureType, lang_interface_defaultProcedureType, CORTO_HIDDEN);
    CORTO_METHOD_O(lang_struct, compatible, "(type type)", lang_bool, TRUE, corto_struct_compatible_v);
    CORTO_METHOD_O(lang_struct, castable, "(type type)", lang_bool, TRUE, corto_struct_castable_v);
    CORTO_METHOD_O(lang_struct, resolveMember, "(string name)", lang_member, TRUE, corto_struct_resolveMember_v);
    CORTO_METHOD_O(lang_struct, init, "()", lang_int16, FALSE, corto_struct_init);
    CORTO_METHOD_O(lang_struct, construct, "()", lang_int16, FALSE, corto_struct_construct);

/* /corto/lang/interfaceVector */
CORTO_STRUCT_O(lang, interfaceVector, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_interfaceVector, interface, lang_interface, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_interfaceVector, vector, lang_vtable, CORTO_GLOBAL);

/* /corto/lang/class */
CORTO_FW_ICD(lang, class);
CORTO_CLASS_O(lang, class, lang_struct, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_ICD);
    CORTO_ALIAS_O (lang_class, base, lang_struct_base, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_class, baseAccess, lang_struct_baseAccess, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_class, implements, lang_interfaceseq, CORTO_GLOBAL);
    CORTO_ALIAS_O (lang_class, parentType, lang_struct_parentType, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_class, parentState, lang_struct_parentState, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_class, defaultType, lang_struct_defaultType, CORTO_HIDDEN);
    CORTO_ALIAS_O (lang_class, defaultProcedureType, lang_struct_defaultProcedureType, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_class, interfaceVector, lang_interfaceVectorseq, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, construct, lang_initAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_class, destruct, lang_destructAction, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_METHOD_O(lang_class, init, "()", lang_int16, FALSE, corto_class_init);
    CORTO_METHOD_O(lang_class, construct, "()", lang_int16, FALSE, corto_class_construct);
    CORTO_METHOD_O(lang_class, destruct, "()", lang_void, FALSE, corto_class_destruct);
    CORTO_METHOD_O(lang_class, instanceof, "(object object)", lang_bool, FALSE, corto_class_instanceof);
    CORTO_METHOD_O(lang_class, resolveInterfaceMethod, "(interface interface,uint32 method)", lang_method, FALSE, corto_class_resolveInterfaceMethod);

/* /corto/lang/delegatedata */
CORTO_STRUCT_O(lang, delegatedata, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_delegatedata, instance, lang_object, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegatedata, procedure, lang_function, CORTO_GLOBAL);

/* /corto/lang/delegate */
CORTO_FW_I(lang, delegate);
CORTO_CLASS_O(lang, delegate, lang_struct, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_TYPE_ID(lang_member), CORTO_TYPE_ID(lang_method), CORTO_I);
    CORTO_METHOD_O(lang_delegate, init, "()", lang_int16, FALSE, corto_delegate_init);
    CORTO_REFERENCE_O(lang_delegate, returnType, lang_type, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(lang_delegate, returnsReference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_delegate, parameters, lang_parameterseq, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_delegate, compatible, "(type type)", lang_bool, TRUE, corto_delegate_compatible_v);
    CORTO_METHOD_O(lang_delegate, castable, "(type type)", lang_bool, TRUE, corto_delegate_compatible_v);
    CORTO_METHOD_O(lang_delegate, instanceof, "(object object)", lang_bool, FALSE, corto_delegate_instanceof);
    CORTO_FUNCTION_O(lang_delegate, bind, "(function object)", lang_int16, corto_delegate_bind);

/* /corto/lang/procedure */
CORTO_FW_I(lang, procedure);
CORTO_CLASS_O(lang, procedure, lang_struct, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(lang_procedure, kind, lang_procedureKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_procedure, bind, lang_initAction, CORTO_LOCAL|CORTO_READONLY);
    CORTO_METHOD_O(lang_procedure, init, "()", lang_int16, FALSE, corto_procedure_init);
    CORTO_METHOD_O(lang_procedure, unbind, "(function object)", lang_void, FALSE, corto_procedure_unbind);

/* /corto/lang/array */
CORTO_FW_ICD(lang, array);
CORTO_CLASS_O(lang, array, lang_collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_ICD);
    CORTO_REFERENCE_O(lang_array, elementType, lang_type, CORTO_GLOBAL|CORTO_PRIVATE, CORTO_DEFINED, FALSE);
    CORTO_METHOD_O(lang_array, init, "()", lang_int16, FALSE, corto_array_init);
    CORTO_METHOD_O(lang_array, construct, "()", lang_int16, FALSE, corto_array_construct);
    CORTO_METHOD_O(lang_array, destruct, "()", lang_void, FALSE, corto_array_destruct);

/* /corto/lang/sequence */
CORTO_FW_IC(lang, sequence);
CORTO_CLASS_O(lang, sequence, lang_collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_sequence, init, "()", lang_int16, FALSE, corto_sequence_init);
    CORTO_METHOD_O(lang_sequence, construct, "()", lang_int16, FALSE, corto_sequence_construct);
    CORTO_METAPROCEDURE_O(lang_sequence, size, "(uint32 size)", lang_void, FALSE, corto_sequence_size);

/* /corto/lang/list */
CORTO_FW_IC(lang, list);
CORTO_CLASS_O(lang, list, lang_collection, CORTO_GLOBAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    CORTO_METHOD_O(lang_list, init, "()", lang_int16, FALSE, corto_list_init);
    CORTO_METHOD_O(lang_list, construct, "()", lang_int16, FALSE, corto_list_construct);
    CORTO_METAPROCEDURE_O(lang_list, insert, "(any element)", lang_void, FALSE, corto_list_insert_any);
    CORTO_METAPROCEDURE_O(lang_list, append, "(any element)", lang_void, FALSE, corto_list_append_any);
    CORTO_METAPROCEDURE_NAME_O(lang_list, insert_, insert, "()", lang_any, FALSE, corto_list_insert_);
    CORTO_METAPROCEDURE_NAME_O(lang_list, append_, append, "()", lang_any, FALSE, corto_list_append_);
    CORTO_METAPROCEDURE_O(lang_list, reverse, "()", lang_void, FALSE, corto_list_reverse);
    CORTO_METAPROCEDURE_O(lang_list, clear, "()", lang_void, FALSE, corto_list_clear);

/* /corto/lang/map */
CORTO_FW_IC(lang, map);
CORTO_CLASS_O(lang, map, lang_collection, CORTO_LOCAL, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_IC);
    /* Duplicate members for a more convenient order in the initializer */
    CORTO_REFERENCE_O(lang_map, elementType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_REFERENCE_O(lang_map, keyType, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(lang_map, max, lang_uint32, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_map, init, "()", lang_int16, FALSE, corto_map_init);
    CORTO_METHOD_O(lang_map, construct, "()", lang_int16, FALSE, corto_map_construct);

/* /corto/lang/function */
CORTO_FW_IB(lang, function);
CORTO_PROCEDURE_NOBASE_O(lang, function, CORTO_FUNCTION, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_IC);
    CORTO_REFERENCE_O(lang_function, returnType, lang_type, CORTO_GLOBAL, CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(lang_function, returnsReference, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_function, overloaded, lang_bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_MEMBER_O(lang_function, kind, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, impl, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, fptr, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, fdata, lang_word, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_REFERENCE_O(lang_function, resource, lang_object, CORTO_LOCAL|CORTO_PRIVATE, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(lang_function, size, lang_uint16, CORTO_LOCAL|CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_function, parameters, lang_parameterseq, CORTO_LOCAL | CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_function, nextParameterId, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_function, init, "()", lang_int16, FALSE, corto_function_init);
    CORTO_METHOD_O(lang_function, bind, "()", lang_int16, FALSE, corto_function_bind);
    CORTO_FUNCTION_O(lang_function, unbind, "(function object)", lang_void, corto_function_unbind);
    CORTO_FUNCTION_O(lang_function, stringToParameterSeq, "(string name,object scope)", lang_parameterseq, corto_function_stringToParameterSeq);
    CORTO_METHOD_O(lang_function, parseParamString, "(string params)", lang_int16, FALSE, corto_function_parseParamString);

/* /corto/core/augmentData */
CORTO_STRUCT_O(core, augmentData, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_augmentData, id, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_augmentData, data, lang_word, CORTO_GLOBAL);

/* /corto/core/result */
CORTO_STRUCT_O(core, result, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_result, id, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, name, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, value, lang_word, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_result, augments, core_augmentseq, CORTO_HIDDEN);
    CORTO_METHOD_O(core_result, getText, "()", lang_string, FALSE, corto_result_getText);

/* /corto/core/request */
CORTO_STRUCT_O(core, request, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_request, parent, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, expr, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, offset, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, limit, lang_uint64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, content, lang_bool, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_request, param, lang_string, CORTO_GLOBAL);

/* /corto/lang/dispatcher */
CORTO_INTERFACE_O(core, dispatcher);
    CORTO_IMETHOD_O(core_dispatcher, post, "(event e)", lang_void, FALSE);

/* /corto/core/mount */
CORTO_FW_CD(core, mount);
CORTO_CLASS_NOBASE_O(core, mount, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_MEMBER_O(core_mount, mount, lang_object, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, type, lang_string, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, kind, core_mountKind, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_mount, contentType, lang_string, CORTO_GLOBAL);
    CORTO_METHOD_O(core_mount, init, "()", lang_int16, FALSE, corto_mount_construct);
    CORTO_METHOD_O(core_mount, construct, "()", lang_int16, FALSE, corto_mount_construct);
    CORTO_METHOD_O(core_mount, destruct, "()", lang_void, FALSE, corto_mount_destruct);
    CORTO_METHOD_O(core_mount, post, "(event e)", lang_void, FALSE, corto_mount_post);
    CORTO_METHOD_O(core_mount, setContentType, "(string type)", lang_int16, FALSE, corto_mount_setContentType);
    CORTO_METHOD_O(core_mount, invoke, "(object instance,function proc,word argptrs)", lang_void, FALSE, corto_mount_invoke);
    CORTO_METHOD_O(core_mount, request, "(core/request request)", core_resultIter, FALSE, corto_mount_request);
    CORTO_METHOD_O(core_mount, resume, "(string parent,string name,object o)", lang_object, FALSE, corto_mount_resume);
    CORTO_METHOD_O(core_mount, onInvoke, "(object instance,function proc,word argptrs)", lang_void, TRUE, corto_mount_onInvoke_v);
    CORTO_METHOD_O(core_mount, onRequest, "(core/request request)", core_resultIter, TRUE, corto_mount_onRequest_v);
    CORTO_METHOD_O(core_mount, onResume, "(string parent,string name,object o)", lang_object, TRUE, corto_mount_onResume_v);
    CORTO_METHOD_O(core_mount, onDeclare, "(object observable)", lang_void, TRUE, corto_mount_onDeclare_v);
    CORTO_METHOD_O(core_mount, onUpdate, "(object observable)", lang_void, TRUE, corto_mount_onUpdate_v);
    CORTO_METHOD_O(core_mount, onDelete, "(object observable)", lang_void, TRUE, corto_mount_onDelete_v);
    CORTO_OBSERVER_O(core_mount, on_declare, corto_mount_on_declare);
    CORTO_OBSERVER_O(core_mount, on_update, corto_mount_on_update);
    CORTO_OBSERVER_O(core_mount, on_delete, corto_mount_on_delete);

/* /corto/core/loader */
CORTO_FW_CD(core, loader);
CORTO_CLASS_O(core, loader, core_mount, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_CD);
    CORTO_METHOD_O(core_loader, construct, "()", lang_int16, FALSE, corto_loader_construct);
    CORTO_METHOD_O(core_loader, destruct, "()", lang_void, FALSE, corto_loader_destruct);
    CORTO_METHOD_O(core_loader, onRequest, "(core/request request)", core_resultIter, TRUE, corto_loader_onRequest_v);
    CORTO_METHOD_O(core_loader, onResume, "(string parent,string name,object o)", lang_object, TRUE, corto_loader_onResume_v);

/* /corto/lang/event */
CORTO_CLASS_NOBASE_O(core, event, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_MEMBER_O(core_event, kind, lang_uint16, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_event, handled, lang_bool, CORTO_LOCAL | CORTO_READONLY);
    CORTO_METHOD_O(core_event, handle, "()", lang_void, TRUE, corto_event_handle_v);
    CORTO_FUNCTION_O(core_event, uniqueKind, "()", lang_int16, corto_event_uniqueKind);

/* /corto/lang/observableEvent */
CORTO_CLASS_O(core, observableEvent, core_event, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(core_observableEvent, observer, core_observer, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, me, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, source, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_observableEvent, observable, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(core_observableEvent, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_observableEvent, thread, lang_word, CORTO_GLOBAL);
    CORTO_METHOD_O(core_observableEvent, handle, "()", lang_void, TRUE, corto_observableEvent_handle_v);

/* /corto/lang/invokeEvent */
CORTO_CLASS_O(core, invokeEvent, core_event, CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_NODELEGATE);
    CORTO_REFERENCE_O(core_invokeEvent, mount, core_mount, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, instance, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, function, lang_function, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_invokeEvent, args, lang_word, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_METHOD_O(core_invokeEvent, handle, "()", lang_void, TRUE, corto_invokeEvent_handle_v);

/* /corto/lang/method */
CORTO_FW_IB(lang, method);
CORTO_PROCEDURE_O(lang, method, CORTO_METHOD, lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_IC);
    CORTO_MEMBER_O(lang_method, virtual, lang_bool, CORTO_GLOBAL);
    CORTO_METHOD_O(lang_method, init, "()", lang_int16, FALSE, corto_method_init);
    CORTO_METHOD_O(lang_method, bind, "()", lang_int16, FALSE, corto_method_bind);

CORTO_FW_I(lang, virtual);
CORTO_PROCEDURE_O(lang, virtual, CORTO_METHOD, lang_method, CORTO_GLOBAL, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, CORTO_I);
    CORTO_METHOD_O(lang_virtual, init, "()", lang_int16, FALSE, corto_virtual_init);

/* /corto/lang/observer */
CORTO_FW_IB(core, observer);
CORTO_PROCEDURE_O(core, observer, CORTO_OBSERVER, lang_function, CORTO_LOCAL | CORTO_READONLY, NULL, CORTO_DECLARED | CORTO_DEFINED, CORTO_IC);
    CORTO_MEMBER_O(core_observer, mask, core_eventMask, CORTO_GLOBAL);
    CORTO_REFERENCE_O(core_observer, observable, lang_object, CORTO_GLOBAL, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_observer, me, lang_object, CORTO_GLOBAL|CORTO_HIDDEN, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_REFERENCE_O(core_observer, dispatcher, core_dispatcher, CORTO_GLOBAL|CORTO_HIDDEN, CORTO_DEFINED | CORTO_DECLARED, FALSE);
    CORTO_MEMBER_O(core_observer, template, lang_uint32, CORTO_GLOBAL|CORTO_READONLY);
    CORTO_METHOD_O(core_observer, init, "()", lang_int16, FALSE, corto_observer_init);
    CORTO_METHOD_O(core_observer, bind, "()", lang_int16, FALSE, corto_observer_bind);
    CORTO_METHOD_O(core_observer, listen, "(object observable,object me)", lang_int16, FALSE, corto_observer_listen);
    CORTO_METHOD_O(core_observer, silence, "(object me)", lang_int16, FALSE, corto_observer_silence);
    CORTO_METHOD_O(core_observer, setDispatcher, "(core/dispatcher dispatcher)", lang_void, FALSE, corto_observer_setDispatcher);
    CORTO_FUNCTION_O(core_observer, unbind, "(observer object)", lang_void, corto_observer_unbind);

/* /corto/lang/metaprocedure */
CORTO_FW_B(lang, metaprocedure);
CORTO_PROCEDURE_O(lang, metaprocedure, CORTO_METAPROCEDURE, lang_function, CORTO_GLOBAL, NULL, CORTO_DECLARED, CORTO_B);
    CORTO_METHOD_O(lang_metaprocedure, bind, "()", lang_int16, FALSE, corto_metaprocedure_bind);
    CORTO_MEMBER_O(lang_metaprocedure, referenceOnly, lang_bool, CORTO_GLOBAL);

/* /corto/lang/member */
CORTO_FW_IC(lang, member);
CORTO_CLASS_NOBASE_O(lang, member, CORTO_TYPE_ID(lang_interface), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(lang_member, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(lang_member, modifiers, lang_modifier, CORTO_GLOBAL);
    CORTO_MEMBER_O(lang_member, state, lang_state, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, weak, lang_bool, CORTO_HIDDEN);
    CORTO_MEMBER_O(lang_member, id, lang_uint32, CORTO_GLOBAL | CORTO_PRIVATE);
    CORTO_MEMBER_O(lang_member, offset, lang_uint32, CORTO_LOCAL | CORTO_PRIVATE);
    CORTO_METHOD_O(lang_member, init, "()", lang_int16, FALSE, corto_member_init);
    CORTO_METHOD_O(lang_member, construct, "()", lang_int16, FALSE, corto_member_construct);

/* /corto/lang/alias */
CORTO_FW_IC(lang, alias);
CORTO_CLASS_O(lang, alias, lang_member, CORTO_HIDDEN, CORTO_TYPE_ID(lang_struct), CORTO_DECLARED, NULL, NULL, CORTO_IC);
    CORTO_REFERENCE_O(lang_alias, member, lang_member, CORTO_GLOBAL, CORTO_DEFINED, FALSE);
    CORTO_METHOD_O(lang_alias, init, "()", lang_int16, FALSE, corto_alias_init);
    CORTO_METHOD_O(lang_alias, construct, "()", lang_int16, FALSE, corto_alias_construct);

/* /corto/lang/parameter */
CORTO_STRUCT_O(lang, parameter, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(lang_parameter, name, lang_string, CORTO_GLOBAL);
    CORTO_REFERENCE_O(lang_parameter, type, lang_type, CORTO_GLOBAL, CORTO_DECLARED | CORTO_DEFINED, FALSE);
    CORTO_MEMBER_O(lang_parameter, passByReference, lang_bool, CORTO_GLOBAL);

/* /corto/core/time */
CORTO_STRUCT_O(core, time, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_time, sec, lang_int32, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_time, nanosec, lang_int32, CORTO_GLOBAL);

/* /corto/core/position */
CORTO_STRUCT_O(core, position, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL);
    CORTO_MEMBER_O(core_position, latitude, lang_float64, CORTO_GLOBAL);
    CORTO_MEMBER_O(core_position, longitude, lang_float64, CORTO_GLOBAL);

/* /corto/native/type */
CORTO_FW_I(native, type);
CORTO_CLASS_O(native, type, lang_binary, CORTO_HIDDEN, NULL, CORTO_DECLARED | CORTO_DEFINED, NULL, NULL, CORTO_I);
    CORTO_MEMBER_O(native_type, name, lang_string, CORTO_GLOBAL);
    CORTO_METHOD_O(native_type, init, "()", lang_int16, FALSE, corto_native_type_init);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_BOOTSTRAP_H_ */
