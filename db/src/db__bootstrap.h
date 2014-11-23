/*
 * db_bootstrap.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_BOOTSTRAP_H_
#define DB_BOOTSTRAP_H_

#include "db__object.h"
#include "db__equals.h"
#include "db_typedef.h"
#include "db_util.h"

#include "db_type.h"
#include "db_primitive.h"
#include "db_interface.h"
#include "db_collection.h"
#include "db_struct.h"
#include "db_procedure.h"
#include "db_class.h"
#include "db_member.h"
#include "db_dispatcher.h"
#include "db_serializer.h"

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
 *     forwarded to the db_function_unbind function. Because procedures are destructed after the destruction of
 *     all classes, the vtable of db_procedure_o does no longer exist, so the callback lookup would crash.
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

/* Implementations of virtual functions */
extern db_equalityKind db_type_compare_v(db_type _this, db_any o1, db_any o2);
extern db_uint32 db_type_allocSize_v(db_type _this);
extern db_bool db_type_compatible_v(db_type _this, db_type type);
extern db_bool db_type_castable_v(db_type _this, db_type type);
extern db_member db_interface_resolveMember_v(db_interface _this, db_string name);
extern db_member db_interface_bindMethod_v(db_interface _this, db_string name);

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_UINT8  ((int8_t)-1)
#define MAX_UINT16 ((int16_t)-1)
#define MAX_UINT32 ((int32_t)-1)
#define MAX_UINT64 ((int64_t)-1)
#define MAX_INT8  ((MAX_UINT8/2-1))
#define MAX_INT16 ((MAX_UINT16/2-1))
#define MAX_INT32 ((MAX_UINT32/2-1))
#define MAX_INT64 ((MAX_UINT64/2-1))
#define MIN_INT8 (-(MAX_UINT8/2+1))
#define MIN_INT16 (-(MAX_UINT16/2+1))
#define MIN_INT32 (-(MAX_UINT32/2+1))
#define MIN_INT64 (-(MAX_UINT64/2+1))

#define DB_STATIC_SCOPED_OBJECT(type)\
typedef struct sso_##type {\
    db_SSO o;\
    db_##type v;\
    struct { /* vtable */\
        db_uint32 length;\
        void* buffer;\
    }vtable;\
    db_object vbuff[16];\
}sso_##type

#define DB_STATIC_SCOPED_REFOBJECT(type)\
typedef struct sso_##type {\
    db_SSO o;\
    struct db_##type##_s v;\
    struct { /* vtable */\
        db_uint32 length;\
        void* buffer;\
    }vtable;\
    db_object vbuff[16];\
}sso_##type

/* Static Scoped Object */
typedef struct db_SSO {
    db__scope s;
    db__object o;
}db_SSO;

/* Static Scoped Observable Object */
typedef struct db_SSOO {
	db__observable v;
    db__scope s;
    db__object o;
}db_SSOO;

/* Static Scoped Observable Object (used for scopes) */
typedef struct db_SSOO_object {
    db_SSOO o;
}db_SSOO_object;

DB_STATIC_SCOPED_REFOBJECT(typedef);
DB_STATIC_SCOPED_REFOBJECT(type);
DB_STATIC_SCOPED_REFOBJECT(primitive);
DB_STATIC_SCOPED_REFOBJECT(collection);
DB_STATIC_SCOPED_REFOBJECT(procedure);
DB_STATIC_SCOPED_REFOBJECT(binary);
DB_STATIC_SCOPED_REFOBJECT(boolean);
DB_STATIC_SCOPED_REFOBJECT(character);
DB_STATIC_SCOPED_REFOBJECT(int);
DB_STATIC_SCOPED_REFOBJECT(uint);
DB_STATIC_SCOPED_REFOBJECT(float);
DB_STATIC_SCOPED_REFOBJECT(text);
DB_STATIC_SCOPED_REFOBJECT(enum);
DB_STATIC_SCOPED_REFOBJECT(bitmask);
DB_STATIC_SCOPED_REFOBJECT(interface);
DB_STATIC_SCOPED_REFOBJECT(struct);
DB_STATIC_SCOPED_REFOBJECT(class);
DB_STATIC_SCOPED_REFOBJECT(array);
DB_STATIC_SCOPED_REFOBJECT(sequence);
DB_STATIC_SCOPED_REFOBJECT(list);
DB_STATIC_SCOPED_REFOBJECT(map);
DB_STATIC_SCOPED_REFOBJECT(function);
DB_STATIC_SCOPED_REFOBJECT(method);
DB_STATIC_SCOPED_REFOBJECT(delegate);
DB_STATIC_SCOPED_REFOBJECT(callback);
DB_STATIC_SCOPED_REFOBJECT(metaprocedure);
DB_STATIC_SCOPED_REFOBJECT(member);
DB_STATIC_SCOPED_OBJECT(parameter);

DB_STATIC_SCOPED_OBJECT(constant);

#define VTABLE_V {16,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
#define DB_FWDECL_SSO(type, name) sso_##type name##__o
#define DB_FWDECL(type, name) DB_FWDECL_SSO(type, name); db_##type db_##name##_o = &name##__o.v

/* SSO */
#define DB_ATTR_SSOO {1,0,1,DB_VALID | DB_DECLARED}
#define DB_ATTR_SSO {1,0,0,DB_VALID | DB_DECLARED}
#define DB_ATTR_SO {0,0,0,DB_VALID | DB_DECLARED}
#define DB_ROOT_V() {{NULL,NULL,DB_RWMUTEX_INITIALIZER,DB_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE,FALSE,NULL},{NULL, NULL, _(scope)NULL, _(scopeLock)DB_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{DB_ATTR_SSOO, 2, (db_typedef)&object__o.v, DB_MMNODE_INIT}}
#define DB_OBJECT_V(parent, name) {{NULL,NULL,DB_RWMUTEX_INITIALIZER,DB_RWMUTEX_INITIALIZER,NULL,NULL,FALSE,FALSE,FALSE,NULL},{DB_OFFSET(&parent##__o, sizeof(db_SSOO)), name, _(scope)NULL, _(scopeLock)DB_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{DB_ATTR_SSOO, 2, (db_typedef)&object__o.v, DB_MMNODE_INIT}}
#define DB_SSO_V(parent, name, type) {{DB_OFFSET(&parent##__o, sizeof(db_SSOO)), name, _(scope)NULL, _(scopeLock)DB_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{DB_ATTR_SSO, 2, (db_typedef)&type##__o.v, DB_MMNODE_INIT}}
#define DB_SSO_PO_V(parent, name, type) {{DB_OFFSET(&parent##__o, sizeof(db_SSO)), name, _(scope)NULL, _(scopeLock)DB_RWMUTEX_INITIALIZER, _(attached)NULL, _(orphaned)0},{DB_ATTR_SSO, 2, (db_typedef)&type##__o.v, DB_MMNODE_INIT}}

/* SSO identifier */
#define DB_SSO_TYPE_ID(name) (db_typedef)&name##__o.v

/* typedef */
#define DB_TYPEDEF_V(name) {DB_OFFSET(&name##__o, sizeof(db_SSO)),DB_OFFSET(&name##__o, sizeof(db_SSO))}

/* type */
#define DB_TYPE_V(name, kind, reference, scopeType, scopeTypeKind) {DB_TYPEDEF_V(name), kind, reference, FALSE, 0, 0, 0, NULL, scopeType, scopeTypeKind,{0,NULL}}

/* primitive */
#define DB_PRIMITIVE_V(name, kind, width, scopeType, scopeStateKind) {DB_TYPE_V(name, DB_PRIMITIVE, FALSE, scopeType, scopeStateKind), kind, width, 0}

/* interface */
#define DB_COMPOSITE_V(name, kind, base, reference, scopeType, scopeStateKind) {DB_TYPE_V(name, DB_COMPOSITE, reference, scopeType, scopeStateKind), kind, 0, {0, NULL}, {0,NULL}, db_interface(&base##__o.v)}

/* interface */
#define DB_COMPOSITE_NOBASE_V(name, kind, reference, scopeType, scopeStateKind) {DB_TYPE_V(name, DB_COMPOSITE, reference, scopeType, scopeStateKind), kind, 0, {0, NULL}, {0,NULL}, NULL}

/* struct */
#define DB_STRUCT_V(name, kind, base, baseAccess, reference, scopeType, scopeStateKind) \
	{DB_COMPOSITE_V(name, kind, base, reference, scopeType, scopeStateKind), baseAccess, 0}

#define DB_STRUCT_NOBASE_V(name, kind, reference, scopeType, scopeStateKind) \
	{DB_COMPOSITE_NOBASE_V(name, kind, reference, scopeType, scopeStateKind), DB_LOCAL, 0}

/* collection */
#define DB_COLLECTION_V(name, kind, elementType, max) {DB_TYPE_V(name, DB_COLLECTION, FALSE, NULL, DB_DECLARED | DB_DEFINED), kind, (db_typedef)&elementType##__o.v, max}

/* sequence */
#define DB_SEQUENCE_V(subType, length, ...) {length, (subType[]){__VA_ARGS__}}
#define DB_SEQUENCE_EMPTY_V(subType) {0, NULL}

/* member */
#define DB_MEMBER_V(type, access, state, weak) {(db_typedef)&type##__o.v, access, state, weak, 0, 0}

/* object */
#define DB_OBJECT_O(name) db_SSOO_object name##__o = {DB_OBJECT_V(root, #name)}
#define DB_OBJECT_O_SCOPE(parent, name) db_SSOO_object parent##_##name##__o = {DB_OBJECT_V(parent, #name)}

/* type object */
#define DB_TYPE_O(name, kind, reference) static sso_type name##__o = {DB_SSO_V(hyve_lang, #name, type), DB_TYPE_V(name, kind, reference, NULL, DB_DECLARED | DB_DEFINED), VTABLE_V}

/* primitive object */
#define DB_PRIMITIVE_O(name, kind, width) sso_primitive name##__o = {DB_SSO_V(hyve_lang, #name, primitive), DB_PRIMITIVE_V(name, kind, width), VTABLE_V}

/* binary object */
#define DB_BINARY_O(name, width) sso_binary name##__o = {DB_SSO_V(hyve_lang, #name, binary), {DB_PRIMITIVE_V(name, DB_BINARY, width, NULL, DB_DECLARED | DB_DEFINED)}, VTABLE_V}

/* boolean object */
#define DB_BOOLEAN_O(name) sso_boolean name##__o = {DB_SSO_V(hyve_lang, #name, boolean), {DB_PRIMITIVE_V(name, DB_BOOLEAN, DB_WIDTH_8, NULL, DB_DECLARED | DB_DEFINED)}, VTABLE_V}

/* character object */
#define DB_CHARACTER_O(name, width) sso_character name##__o = {DB_SSO_V(hyve_lang, #name, character), {DB_PRIMITIVE_V(name, DB_CHARACTER, width, NULL, DB_DECLARED | DB_DEFINED)}, VTABLE_V}

/* int object */
#define DB_INT_O(name, width, min, max, scopeType, scopeStateKind) sso_int name##__o = {DB_SSO_V(hyve_lang, #name, int), {DB_PRIMITIVE_V(name, DB_INTEGER, width, scopeType, scopeStateKind), min, max}, VTABLE_V}

/* uint object */
#define DB_UINT_O(name, width, min, max) sso_uint name##__o = {DB_SSO_V(hyve_lang, #name, uint), {DB_PRIMITIVE_V(name, DB_UINTEGER, width, NULL, DB_DECLARED | DB_DEFINED), min, max}, VTABLE_V}

/* float object */
#define DB_FLOAT_O(name, width, min, max) sso_float name##__o = {DB_SSO_V(hyve_lang, #name, float), {DB_PRIMITIVE_V(name, DB_FLOAT, width, NULL, DB_DECLARED | DB_DEFINED), min, max}, VTABLE_V}

/* text object */
#define DB_TEXT_O(name, width, length) sso_text name##__o = {DB_SSO_V(hyve_lang, #name, text), {DB_PRIMITIVE_V(name, DB_TEXT, DB_WIDTH_WORD, NULL, DB_DECLARED | DB_DEFINED), width, length}, VTABLE_V}

/* enum object */
#define DB_ENUM_O(name) sso_enum name##__o = {DB_SSO_V(hyve_lang, #name, enum), {DB_PRIMITIVE_V(name, DB_ENUM, DB_WIDTH_32, NULL, DB_DECLARED | DB_DEFINED), DB_SEQUENCE_EMPTY_V(constant)}, VTABLE_V}

/* bitmask object */
#define DB_BITMASK_O(name) sso_bitmask name##__o = {DB_SSO_V(hyve_lang, #name, bitmask), {{DB_PRIMITIVE_V(name, DB_BITMASK, DB_WIDTH_32, NULL, DB_DECLARED | DB_DEFINED), DB_SEQUENCE_EMPTY_V(constant)}}, VTABLE_V}

/* constant object */
#define DB_CONSTANT_O(parent, name) sso_constant parent##_##name##__o = {DB_SSO_PO_V(parent, #name, constant), DB_##name, VTABLE_V}

/* struct object */
#define DB_STRUCT_O(name, scopeType, scopeStateKind) sso_struct name##__o = \
    {DB_SSO_V(hyve_lang, #name, struct), DB_STRUCT_NOBASE_V(name, DB_STRUCT, FALSE, scopeType, scopeStateKind), VTABLE_V}

/* interface object */
#define DB_INTERFACE_O(name) sso_interface name##__o = \
    {DB_SSO_V(hyve_lang, #name, interface), DB_COMPOSITE_NOBASE_V(name, DB_INTERFACE, TRUE, NULL, 0), VTABLE_V}

/* class object */
#define DB_CLASS_NOBASE_O(name, implements, scopeType, scopeStateKind) sso_class name##__o = \
    {DB_SSO_V(hyve_lang, #name, class), {DB_STRUCT_NOBASE_V(name, DB_CLASS, TRUE, scopeType, scopeStateKind), {0,NULL}, {0,NULL}, {0,NULL}}, VTABLE_V}

#define DB_CLASS_O(name, base, baseAccess, implements, scopeType, scopeStateKind) sso_class name##__o = \
		{DB_SSO_V(hyve_lang, #name, class), {DB_STRUCT_V(name, DB_CLASS, base, baseAccess, TRUE, scopeType, scopeStateKind), implements, {0,NULL}, {0,NULL}}, VTABLE_V}

/* array object */
#define DB_ARRAY_O(name, elementType, size) sso_array name##__o = {DB_SSO_V(hyve_lang, #name, array), {DB_COLLECTION_V(name, DB_ARRAY, elementType, size)}, VTABLE_V}

/* sequence object */
#define DB_SEQUENCE_O(name, elementType, max) sso_sequence name##__o = {DB_SSO_V(hyve_lang, #name, sequence), {DB_COLLECTION_V(name, DB_SEQUENCE, elementType, max)}, VTABLE_V}

/* list object */
#define DB_LIST_O(name, elementType, max) sso_list name##__o = {DB_SSO_V(hyve_lang, #name, list), {DB_COLLECTION_V(name, DB_LIST, elementType, max)}, VTABLE_V}

/* map object */
#define DB_MAP_O(name, elementType, keyType, max) sso_map name##__o = {DB_SSO_V(hyve_lang, #name, map), {DB_COLLECTION_V(name, DB_MAP, elementType, max), (db_typedef)&keyType##__o.v}, VTABLE_V}

/* procedure object */
#define DB_PROCEDURE_O(name, kind, base, baseAccess, scopeType, scopeStateKind) sso_procedure name##__o = \
		{DB_SSO_V(hyve_lang, #name, procedure), {DB_STRUCT_V(name, DB_PROCEDURE, base, baseAccess, TRUE, scopeType, scopeStateKind), kind}, VTABLE_V}
#define DB_PROCEDURE_NOBASE_O(name, kind, scopeType, scopeStateKind) sso_procedure name##__o = \
		{DB_SSO_V(hyve_lang, #name, procedure), {DB_STRUCT_NOBASE_V(name, DB_PROCEDURE, TRUE, scopeType, scopeStateKind), kind}, VTABLE_V}

/* function object */
#define DB_FUNCTION_O(parent, name, args, returnType, impl) sso_function parent##_##name##__o = {DB_SSO_PO_V(parent, #name args, function), {(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}

#define DB_FUNCTION_OO_O(parent, name, args, returnType, impl) sso_function parent##_##name##__o = {DB_SSO_V(parent, #name args, function), {(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}
#define DB_FUNCTION_OVERLOAD_OO_O(parent, name, args, returnType, impl) sso_function parent##_##name##__o = {DB_SSO_V(parent, args, function), {(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}, VTABLE_V}

/* method object */
#define DB_METHOD_O(parent, name, args, returnType, virtual, impl) sso_method parent##_##name##__o = {DB_SSO_PO_V(parent, #name args, method), {{(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0,{0,NULL},0}, virtual}, VTABLE_V}

/* delegate object */
#define DB_DELEGATE_O(parent, name, args, returnType) sso_delegate parent##_##name##__o = {DB_SSO_PO_V(parent, #name args, delegate), {{(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)0, 0, NULL, 0, {0,NULL},0}, 0}, VTABLE_V}

/* callback object */
#define DB_CALLBACK_O(parent, name, args, delegate, returnType, impl) sso_callback parent##_##name##__o = {DB_SSO_PO_V(parent, #name args, callback), {{(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}, (db_delegate)&delegate##__o.v}, VTABLE_V}

/* metaprocedure object */
#define DB_METAPROCEDURE_O(parent, name, args, returnType, impl) sso_metaprocedure parent##_##name##__o = {DB_SSO_PO_V(parent, #name args, metaprocedure), {{(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}}, VTABLE_V}

#define DB_METAPROCEDURE_NAME_O(parent, name, actualName, args, returnType, impl) sso_metaprocedure parent##_##name##__o = {DB_SSO_PO_V(parent, #actualName args, metaprocedure), {{(db_typedef)&returnType##__o.v, FALSE, FALSE, DB_PROCEDURE_CDECL, (db_word)impl, 0, NULL, 0, {0,NULL},0}}, VTABLE_V}
    
/* member object */
#define DB_MEMBER_O(parent, name, type, access) sso_member parent##_##name##__o = {DB_SSO_PO_V(parent, #name, member), DB_MEMBER_V(type, access, DB_DECLARED | DB_DEFINED, FALSE), VTABLE_V}

/* reference object */
#define DB_REFERENCE_O(parent, name, type, access, state, weak) sso_member parent##_##name##__o = {DB_SSO_PO_V(parent, #name, member), DB_MEMBER_V(type, access, state, weak), VTABLE_V}

/* Forward declarations of classes */
DB_FWDECL(class, typedef);
DB_FWDECL(class, type);
DB_FWDECL(class, template);
DB_FWDECL(class, primitive);
DB_FWDECL(class, interface);
DB_FWDECL(class, collection);
DB_FWDECL(class, procedure);
DB_FWDECL(class, binary);
DB_FWDECL(class, boolean);
DB_FWDECL(class, character);
DB_FWDECL(class, int);
DB_FWDECL(class, uint);
DB_FWDECL(class, float);
DB_FWDECL(class, text);
DB_FWDECL(class, enum);
DB_FWDECL(class, bitmask);
DB_FWDECL(class, alias);
DB_FWDECL(class, struct);
DB_FWDECL(class, class);
DB_FWDECL(class, array);
DB_FWDECL(class, sequence);
DB_FWDECL(class, list);
DB_FWDECL(class, map);
DB_FWDECL(class, member);
DB_FWDECL(class, reference);
DB_FWDECL(class, event);
DB_FWDECL(class, observableEvent);
DB_FWDECL(struct, interfaceVector);
DB_FWDECL(struct, parameter);

/* Abstract classes */
DB_FWDECL(interface, dispatcher);

DB_FWDECL(binary, octet);
DB_FWDECL(boolean, bool);
DB_FWDECL(character, char);
DB_FWDECL(uint, uint8);
DB_FWDECL(uint, uint16);
DB_FWDECL(uint, uint32);
DB_FWDECL(uint, uint64);
DB_FWDECL(int, int8);
DB_FWDECL(int, int16);
DB_FWDECL(int, int32);
DB_FWDECL(int, int64);
DB_FWDECL(float, float32);
DB_FWDECL(float, float64);
DB_FWDECL(text, string);
DB_FWDECL(binary, word);
DB_FWDECL(int, constant);

static DB_FWDECL(type, any);
static DB_FWDECL(type, void);
static DB_FWDECL(type, object);

DB_FWDECL(procedure, function);
DB_FWDECL(procedure, method);
DB_FWDECL(procedure, virtual);
DB_FWDECL(procedure, delegate);
DB_FWDECL(procedure, callback);
DB_FWDECL(procedure, observer);
DB_FWDECL(procedure, metaprocedure);

DB_FWDECL(enum, width);
DB_FWDECL(enum, typeKind);
DB_FWDECL(enum, primitiveKind);
DB_FWDECL(enum, compositeKind);
DB_FWDECL(enum, collectionKind);
DB_FWDECL(enum, procedureKind);
DB_FWDECL(enum, scopeStateKind);
DB_FWDECL(enum, equalityKind);
DB_FWDECL(enum, operatorKind);
DB_FWDECL(bitmask, state);
DB_FWDECL(bitmask, attr);
DB_FWDECL(bitmask, eventMask);
DB_FWDECL(bitmask, modifier);

DB_FWDECL(sequence, objectSeq);
DB_FWDECL(sequence, interfaceSeq);
DB_FWDECL(sequence, memberSeq);
DB_FWDECL(sequence, parameterSeq);
DB_FWDECL(sequence, observerSeq);
DB_FWDECL(sequence, vtable);
DB_FWDECL(sequence, interfaceVectorSeq);

/* ::hyve::serialization module */
DB_FWDECL(class, serializer);
DB_FWDECL(enum, serializerTraceKind);

/* Forward declare static delegate objects */
DB_FWDECL_SSO(delegate, type_init);
DB_FWDECL_SSO(delegate, class_construct);
DB_FWDECL_SSO(delegate, class_destruct);

/* database root */
db_SSOO_object root__o = {DB_ROOT_V()};
db_object root_o = DB_OFFSET(&root__o.o.o, sizeof(db__object));

/* ::hyve, ::hyve::lang and ::hyve::serialization */
DB_OBJECT_O(hyve);
DB_OBJECT_O_SCOPE(hyve, lang);
DB_OBJECT_O_SCOPE(hyve, serialization);

db_object hyve_o = DB_OFFSET(&hyve__o.o.o, sizeof(db__object));
db_object hyve_lang_o = DB_OFFSET(&hyve_lang__o.o.o, sizeof(db__object));

/* Primitives */
DB_BINARY_O(octet, DB_WIDTH_8);
DB_BOOLEAN_O(bool);
DB_CHARACTER_O(char, DB_WIDTH_8);
DB_UINT_O(uint8, DB_WIDTH_8, 0, MAX_UINT8);
DB_UINT_O(uint16, DB_WIDTH_16, 0, MAX_UINT16);
DB_UINT_O(uint32, DB_WIDTH_32, 0, MAX_UINT32);
DB_UINT_O(uint64, DB_WIDTH_64, 0, MAX_UINT64);
DB_INT_O(int8, DB_WIDTH_8, MIN_INT8, MAX_INT8, NULL, DB_DECLARED | DB_DEFINED);
DB_INT_O(int16, DB_WIDTH_16, MIN_INT16, MAX_INT16, NULL, DB_DECLARED | DB_DEFINED);
DB_INT_O(int32, DB_WIDTH_32, MIN_INT32, MAX_INT32, NULL, DB_DECLARED | DB_DEFINED);
DB_INT_O(int64, DB_WIDTH_64, MIN_INT64, MAX_INT64, NULL, DB_DECLARED | DB_DEFINED);
DB_FLOAT_O(float32, DB_WIDTH_32, 0, 0);
DB_FLOAT_O(float64, DB_WIDTH_64, 0, 0);
DB_TEXT_O(string, DB_WIDTH_8, 0);
DB_BINARY_O(word, DB_WIDTH_WORD);
DB_INT_O(constant, DB_WIDTH_32, 0, MAX_INT32, DB_SSO_TYPE_ID(enum), DB_DECLARED);
	DB_CALLBACK_O(constant, init, "(constant object)", type_init, int16, db_constant_init);

/* Any type */
DB_TYPE_O(any, DB_ANY, FALSE);

/* Void type */
DB_TYPE_O(void, DB_VOID, FALSE);

/* Object type */
DB_TYPE_O(object, DB_VOID, TRUE);

/* Enumerations */
DB_ENUM_O(width);
    DB_CONSTANT_O(width, WIDTH_8);
    DB_CONSTANT_O(width, WIDTH_16);
    DB_CONSTANT_O(width, WIDTH_32);
    DB_CONSTANT_O(width, WIDTH_64);
    DB_CONSTANT_O(width, WIDTH_WORD);

DB_ENUM_O(typeKind);
    DB_CONSTANT_O(typeKind, VOID);
    DB_CONSTANT_O(typeKind, ANY);
    DB_CONSTANT_O(typeKind, PRIMITIVE);
    DB_CONSTANT_O(typeKind, COMPOSITE);
    DB_CONSTANT_O(typeKind, COLLECTION);

DB_ENUM_O(primitiveKind);
    DB_CONSTANT_O(primitiveKind, BINARY);
    DB_CONSTANT_O(primitiveKind, BOOLEAN);
    DB_CONSTANT_O(primitiveKind, CHARACTER);
    DB_CONSTANT_O(primitiveKind, INTEGER);
    DB_CONSTANT_O(primitiveKind, UINTEGER);
    DB_CONSTANT_O(primitiveKind, FLOAT);
    DB_CONSTANT_O(primitiveKind, TEXT);
    DB_CONSTANT_O(primitiveKind, ENUM);
    DB_CONSTANT_O(primitiveKind, BITMASK);
    DB_CONSTANT_O(primitiveKind, ALIAS);

DB_ENUM_O(compositeKind);
    DB_CONSTANT_O(compositeKind, STRUCT);
    DB_CONSTANT_O(compositeKind, INTERFACE);
    DB_CONSTANT_O(compositeKind, CLASS);
    DB_CONSTANT_O(compositeKind, PROCEDURE);

DB_ENUM_O(collectionKind);
    DB_CONSTANT_O(collectionKind, ARRAY);
    DB_CONSTANT_O(collectionKind, SEQUENCE);
    DB_CONSTANT_O(collectionKind, LIST);
    DB_CONSTANT_O(collectionKind, MAP);

DB_ENUM_O(procedureKind);
    DB_CONSTANT_O(procedureKind, FUNCTION);
    DB_CONSTANT_O(procedureKind, METHOD);
    DB_CONSTANT_O(procedureKind, DELEGATE);
    DB_CONSTANT_O(procedureKind, CALLBACK);
    DB_CONSTANT_O(procedureKind, OBSERVER);
    DB_CONSTANT_O(procedureKind, METAPROCEDURE);

DB_ENUM_O(equalityKind);
    DB_CONSTANT_O(equalityKind, EQ);
    DB_CONSTANT_O(equalityKind, LT);
    DB_CONSTANT_O(equalityKind, GT);
    DB_CONSTANT_O(equalityKind, NEQ);

DB_ENUM_O(operatorKind);
    DB_CONSTANT_O(operatorKind, ASSIGN);
    DB_CONSTANT_O(operatorKind, ADD);
    DB_CONSTANT_O(operatorKind, SUB);
    DB_CONSTANT_O(operatorKind, MUL);
    DB_CONSTANT_O(operatorKind, DIV);
    DB_CONSTANT_O(operatorKind, MOD);
    DB_CONSTANT_O(operatorKind, INC);
    DB_CONSTANT_O(operatorKind, DEC);
    DB_CONSTANT_O(operatorKind, XOR);
    DB_CONSTANT_O(operatorKind, OR);
    DB_CONSTANT_O(operatorKind, AND);
    DB_CONSTANT_O(operatorKind, NOT);
    DB_CONSTANT_O(operatorKind, ASSIGN_ADD);
    DB_CONSTANT_O(operatorKind, ASSIGN_SUB);
    DB_CONSTANT_O(operatorKind, ASSIGN_MUL);
    DB_CONSTANT_O(operatorKind, ASSIGN_DIV);
    DB_CONSTANT_O(operatorKind, ASSIGN_MOD);
    DB_CONSTANT_O(operatorKind, ASSIGN_XOR);
    DB_CONSTANT_O(operatorKind, ASSIGN_OR);
    DB_CONSTANT_O(operatorKind, ASSIGN_AND);
    DB_CONSTANT_O(operatorKind, COND_OR);
    DB_CONSTANT_O(operatorKind, COND_AND);
    DB_CONSTANT_O(operatorKind, COND_NOT);
    DB_CONSTANT_O(operatorKind, COND_EQ);
    DB_CONSTANT_O(operatorKind, COND_NEQ);
    DB_CONSTANT_O(operatorKind, COND_GT);
    DB_CONSTANT_O(operatorKind, COND_LT);
    DB_CONSTANT_O(operatorKind, COND_GTEQ);
    DB_CONSTANT_O(operatorKind, COND_LTEQ);
    DB_CONSTANT_O(operatorKind, SHIFT_LEFT);
    DB_CONSTANT_O(operatorKind, SHIFT_RIGHT);
    DB_CONSTANT_O(operatorKind, COMMA);
    DB_CONSTANT_O(operatorKind, REF);
    DB_CONSTANT_O(operatorKind, MEMBER_RESOLVE);
    DB_CONSTANT_O(operatorKind, ELEMENT_OPEN);
    DB_CONSTANT_O(operatorKind, ELEMENT_CLOSE);
    DB_CONSTANT_O(operatorKind, BRACKET_OPEN);
    DB_CONSTANT_O(operatorKind, BRACKET_CLOSE);

DB_BITMASK_O(state);
    DB_CONSTANT_O(state, VALID);
    DB_CONSTANT_O(state, DECLARED);
    DB_CONSTANT_O(state, DEFINED);

DB_BITMASK_O(attr);
	DB_CONSTANT_O(attr, ATTR_SCOPED);
	DB_CONSTANT_O(attr, ATTR_WRITABLE);
	DB_CONSTANT_O(attr, ATTR_OBSERVABLE);

DB_BITMASK_O(eventMask);
	DB_CONSTANT_O(eventMask, ON_DECLARE);
	DB_CONSTANT_O(eventMask, ON_DEFINE);
	DB_CONSTANT_O(eventMask, ON_DESTRUCT);
	DB_CONSTANT_O(eventMask, ON_INVALIDATE);
	DB_CONSTANT_O(eventMask, ON_UPDATE);
	DB_CONSTANT_O(eventMask, ON_SELF);
	DB_CONSTANT_O(eventMask, ON_SCOPE);
	DB_CONSTANT_O(eventMask, ON_VALUE);
	DB_CONSTANT_O(eventMask, ON_METAVALUE);

DB_BITMASK_O(modifier);
	DB_CONSTANT_O(modifier, GLOBAL);
    DB_CONSTANT_O(modifier, LOCAL);
    DB_CONSTANT_O(modifier, PRIVATE);
    DB_CONSTANT_O(modifier, READONLY);
    DB_CONSTANT_O(modifier, CONST);

/* Collections */
DB_SEQUENCE_O(objectSeq, object, 0);
DB_SEQUENCE_O(interfaceSeq, interface, 0);
DB_SEQUENCE_O(memberSeq, member, 0);
DB_SEQUENCE_O(parameterSeq, parameter, 0);
DB_SEQUENCE_O(observerSeq, observer, 0);
DB_SEQUENCE_O(vtable, function, 0);
DB_SEQUENCE_O(interfaceVectorSeq, interfaceVector, 0);

/* ::hyve::lang::typedef */
DB_CLASS_NOBASE_O(typedef, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_REFERENCE_O(typedef, type, typedef, DB_GLOBAL, DB_DEFINED, FALSE);
    DB_REFERENCE_O(typedef, real, type, DB_LOCAL, DB_DEFINED, FALSE);
    DB_METHOD_O(typedef, realType, "()", type, FALSE, db_typedef_realType);
    DB_CALLBACK_O(typedef, init, "(lang::typedef object)", type_init, int16, db_typedef_init);
    DB_CALLBACK_O(typedef, construct, "(lang::typedef object)", class_construct, int16, db_typedef_construct);
    DB_CALLBACK_O(typedef, destruct, "(lang::typedef object)", class_destruct, void, db_typedef_destruct);

/* ::hyve::lang::type */
DB_CLASS_O(type, typedef, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(type, kind, typeKind, DB_READONLY | DB_LOCAL);
    DB_MEMBER_O(type, reference, bool, DB_READONLY | DB_LOCAL);
    DB_MEMBER_O(type, hasResources, bool, DB_READONLY | DB_LOCAL);
    DB_MEMBER_O(type, templateId, uint32, DB_READONLY | DB_LOCAL);
    DB_MEMBER_O(type, size, uint32, DB_PRIVATE | DB_LOCAL);
    DB_MEMBER_O(type, alignment, uint16, DB_PRIVATE | DB_LOCAL);
    DB_REFERENCE_O(type, defaultType, typedef, DB_GLOBAL, DB_DEFINED, FALSE);
    DB_REFERENCE_O(type, parentType, typedef, DB_GLOBAL, DB_DEFINED, FALSE);
    DB_MEMBER_O(type, parentState, state, DB_GLOBAL);
    DB_MEMBER_O(type, metaprocedures, vtable, DB_LOCAL | DB_PRIVATE);
    DB_METHOD_O(type, sizeof, "()", uint32, FALSE, db_type_sizeof);
    DB_METHOD_O(type, alignmentof, "()", uint16, FALSE, db_type_alignmentof);
    DB_METHOD_O(type, allocSize, "()", uint32, TRUE, db_type_allocSize_v);
    DB_METHOD_O(type, castable, "(lang::type type)", bool, TRUE, db_type_castable_v);
    DB_METHOD_O(type, compatible, "(lang::type type)", bool, TRUE, db_type_compatible_v);
    DB_METHOD_O(type, resolveProcedure, "(lang::string name)", function, FALSE, db_type_resolveProcedure);
    DB_METHOD_O(type, bindMetaprocedure, "(lang::metaprocedure)", int16, FALSE, db_type_bindMetaprocedure);
    DB_DELEGATE_O(type, init, "(lang::object object)", int16);
    DB_CALLBACK_O(type, _init, "(lang::type object)", type_init, int16, db_type__init);
    DB_CALLBACK_O(type, construct, "(lang::type object)", class_construct, int16, db_type_construct);
    DB_CALLBACK_O(type, destruct, "(lang::type object)", class_destruct, void, db_type_destruct);
    DB_METAPROCEDURE_O(type, parentof, "()", object, db_type_parentof);
    DB_METAPROCEDURE_O(type, nameof, "()", string, db_type_nameof);
    DB_METAPROCEDURE_O(type, fullname, "()", string, db_type_fullname);
    DB_METAPROCEDURE_O(type, relname, "(lang::object from)", string, db_type_relname);
    DB_METAPROCEDURE_O(type, typeof, "()", type, db_type_typeof);
    DB_METAPROCEDURE_O(type, compare, "(lang::any value)", equalityKind, db_type_compare);
    DB_METAPROCEDURE_O(type, copy, "(lang::any value)", int16, db_type_copy);
    DB_METAPROCEDURE_O(type, toString, "()", string, db_type_toString);

/* ::hyve::lang::primitive */
DB_CLASS_O(primitive, type, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(primitive, kind, primitiveKind, DB_LOCAL|DB_READONLY);
    DB_MEMBER_O(primitive, width, width, DB_GLOBAL);
    DB_MEMBER_O(primitive, convertId, uint8, DB_LOCAL | DB_PRIVATE);
    DB_METHOD_O(primitive, castable, "(lang::type type)", bool, TRUE, db_primitive_castable);
    DB_METHOD_O(primitive, compatible, "(lang::type type)", bool, TRUE, db_primitive_compatible);
    DB_CALLBACK_O(primitive, init, "(lang::primitive object)", type_init, int16, db_primitive_init);
    DB_CALLBACK_O(primitive, construct, "(lang::primitive object)", class_construct, int16, db_primitive_construct);

/* ::hyve::lang::interface */
DB_CLASS_O(interface, type, DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(interface, kind, compositeKind, DB_LOCAL|DB_READONLY);
    DB_MEMBER_O(interface, nextMemberId, uint32, DB_LOCAL | DB_PRIVATE);
    DB_MEMBER_O(interface, members, memberSeq, DB_LOCAL | DB_PRIVATE);
    DB_MEMBER_O(interface, methods, vtable, DB_LOCAL | DB_PRIVATE);
	DB_REFERENCE_O(interface, base, interface, DB_GLOBAL, DB_DEFINED, FALSE);
    DB_CALLBACK_O(interface, init, "(lang::interface object)", type_init, int16, db_interface_init);
    DB_CALLBACK_O(interface, construct, "(lang::interface object)", class_construct, int16, db_interface_construct);
    DB_CALLBACK_O(interface, destruct, "(lang::interface object)", class_destruct, void, db_interface_destruct);
    DB_METHOD_O(interface, resolveMember, "(lang::string name)", member, TRUE, db_interface_resolveMember_v);
    DB_METHOD_O(interface, compatible, "(lang::type type)", bool, TRUE, db_interface_compatible);
    DB_METHOD_O(interface, resolveMethod, "(lang::string name)", method, FALSE, db_interface_resolveMethod);
    DB_METHOD_O(interface, resolveMethodId, "(lang::string name)", uint32, FALSE, db_interface_resolveMethodId);
    DB_METHOD_O(interface, resolveMethodById, "(lang::uint32 id)", method, FALSE, db_interface_resolveMethodById);
    DB_METHOD_O(interface, bindMethod, "(lang::method method)", int16, TRUE, db_interface_bindMethod_v);

/* ::hyve::lang::collection */
DB_CLASS_O(collection, type, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(collection, kind, collectionKind, DB_LOCAL|DB_READONLY);
    DB_REFERENCE_O(collection, elementType, typedef, DB_GLOBAL, DB_DECLARED, FALSE);
	DB_MEMBER_O(collection, max, uint32, DB_GLOBAL);
    DB_METHOD_O(collection, castable, "(lang::type type)", bool, TRUE, db_collection_castable);
    DB_CALLBACK_O(collection, init, "(lang::collection object)", type_init, int16, db_collection_init);
    DB_METAPROCEDURE_O(collection, size, "()", uint32, db_collection_size);

/* ::hyve::lang::binary */
DB_CLASS_O(binary, primitive, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(binary, init, "(lang::binary object)", type_init, int16, db_binary_init);

/* ::hyve::lang::boolean */
DB_CLASS_O(boolean, primitive, DB_GLOBAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(boolean, init, "(lang::boolean object)", type_init, int16, db_boolean_init);

/* ::hyve::lang::character */
DB_CLASS_O(character, primitive, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(character, init, "(lang::character object)", type_init, int16, db_character_init);

/* ::hyve::lang::int */
DB_CLASS_O(int, primitive, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(int, min, int64, DB_GLOBAL);
    DB_MEMBER_O(int, max, int64, DB_GLOBAL);
    DB_CALLBACK_O(int, init, "(lang::int object)", type_init, int16, db_int_init);

/* ::hyve::lang::uint */
DB_CLASS_O(uint, primitive, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(uint, min, uint64, DB_GLOBAL);
    DB_MEMBER_O(uint, max, uint64, DB_GLOBAL);
    DB_CALLBACK_O(uint, init, "(lang::uint object)", type_init, int16, db_uint_init);

/* ::hyve::lang::float */
DB_CLASS_O(float, primitive, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(float, min, float64, DB_GLOBAL);
    DB_MEMBER_O(float, max, float64, DB_GLOBAL);
    DB_CALLBACK_O(float, init, "(lang::float object)", type_init, int16, db_float_init);

/* ::hyve::lang::text */
DB_CLASS_O(text, primitive, DB_LOCAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(text, charWidth, width, DB_GLOBAL);
    DB_MEMBER_O(text, length, uint64, DB_GLOBAL);
    DB_CALLBACK_O(text, init, "(lang::text object)", type_init, int16, db_text_init);

/* ::hyve::lang::enum */
DB_CLASS_O(enum, primitive, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	DB_MEMBER_O(enum, constants, objectSeq, DB_LOCAL | DB_PRIVATE);
    DB_CALLBACK_O(enum, init, "(lang::enum object)", type_init, int16, db_enum_init);
    DB_CALLBACK_O(enum, destruct, "(lang::enum object)", class_destruct, void, db_enum_destruct);
    DB_CALLBACK_O(enum, construct, "(lang::enum object)", class_construct, int16, db_enum_construct);
    DB_METHOD_O(enum, constant, "(lang::int32 value)", object, FALSE, db_enum_constant);

/* ::hyve::lang::bitmask */
DB_CLASS_O(bitmask, enum, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(bitmask, init, "(lang::bitmask object)", type_init, int16, db_bitmask_init);

/* ::hyve::lang::bitmask */
DB_CLASS_O(alias, primitive, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(alias, init, "(lang::alias object)", type_init, int16, db_alias_init);
	DB_MEMBER_O(alias, typeName, string, DB_GLOBAL);

/* ::hyve::lang::struct */
DB_CLASS_O(struct, interface, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	DB_MEMBER_O(struct, baseAccess, modifier, DB_GLOBAL);
    DB_MEMBER_O(struct, delegateCount, uint16, DB_LOCAL|DB_PRIVATE);
	DB_METHOD_O(struct, compatible, "(lang::type type)", bool, TRUE, db_struct_compatible);
	DB_METHOD_O(struct, castable, "(lang::type type)", bool, TRUE, db_struct_castable);
	DB_METHOD_O(struct, resolveMember, "(lang::string name)", member, TRUE, db_struct_resolveMember);
	DB_CALLBACK_O(struct, init, "(lang::struct object)", type_init, int16, db_struct_init);
	DB_CALLBACK_O(struct, construct, "(lang::struct object)", class_construct, int16, db_struct_construct);

/* ::hyve::lang::interfaceVector */
DB_STRUCT_O(interfaceVector, NULL, DB_DECLARED | DB_DEFINED);
	DB_MEMBER_O(interfaceVector, interface, word, DB_GLOBAL);
	DB_MEMBER_O(interfaceVector, vector, vtable, DB_GLOBAL);

/* ::hyve::lang::class */
DB_CLASS_O(class, struct, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(class, implements, interfaceSeq, DB_GLOBAL);
    DB_MEMBER_O(class, interfaceVector, interfaceVectorSeq, DB_LOCAL|DB_PRIVATE);
    DB_MEMBER_O(class, observers, observerSeq, DB_LOCAL|DB_PRIVATE);
    DB_DELEGATE_O(class, construct, "(lang::object object)", int16);
    DB_DELEGATE_O(class, destruct, "(lang::object object)", void);
    DB_CALLBACK_O(class, init, "(lang::class object)", type_init, int16, db_class_init);
    DB_CALLBACK_O(class, _construct, "(lang::class object)", class_construct, int16, db_class__construct);
    DB_CALLBACK_O(class, _destruct, "(lang::class object)", class_destruct, void, db_class__destruct);
    DB_METHOD_O(class, bindMethod, "(lang::method method)", int16, TRUE, db_class_bindMethod);
    DB_METHOD_O(class, allocSize, "()", uint32, TRUE, db_class_allocSize);
    DB_METHOD_O(class, instanceof, "(lang::object object)", bool, FALSE, db_class_instanceof);
    DB_METHOD_O(class, privateObserver, "(lang::object object,lang::observer observer)", observer, FALSE, db_class_privateObserver);

/* ::hyve::lang::procedure */
DB_CLASS_O(procedure, struct, DB_LOCAL | DB_READONLY, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	DB_MEMBER_O(procedure, kind, procedureKind, DB_GLOBAL);
	DB_CALLBACK_O(procedure, init, "(lang::procedure object)", type_init, int16, db_procedure_init);
	DB_DELEGATE_O(procedure, bind, "(lang::object object)", int16);
	DB_DELEGATE_O(procedure, unbind, "(lang::object object)", void);

/* ::hyve::lang::array */
DB_CLASS_O(array, collection, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_REFERENCE_O(array, elementType, typedef, DB_GLOBAL|DB_PRIVATE, DB_DEFINED, FALSE);
    DB_CALLBACK_O(array, init, "(lang::array object)", type_init, int16, db_array_init);
    DB_CALLBACK_O(array, construct, "(lang::array object)", class_construct, int16, db_array_construct);
    DB_CALLBACK_O(array, destruct, "(lang::array object)", class_destruct, void, db_array_destruct);

/* ::hyve::lang::sequence */
DB_CLASS_O(sequence, collection, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(sequence, init, "(lang::sequence object)", type_init, int16, db_sequence_init);
    DB_CALLBACK_O(sequence, construct, "(lang::sequence object)", class_construct, int16, db_sequence_construct);
    DB_METAPROCEDURE_O(sequence, size, "(lang::uint32 size)", void, db_sequence_size);

/* ::hyve::lang::list */
DB_CLASS_O(list, collection, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
    DB_CALLBACK_O(list, init, "(lang::list object)", type_init, int16, db_list_init);
    DB_CALLBACK_O(list, construct, "(lang::list object)", class_construct, int16, db_list_construct);
    DB_METAPROCEDURE_O(list, insert, "(lang::any element)", void, db_list_insert);
    DB_METAPROCEDURE_O(list, append, "(lang::any element)", void, db_list_append);
    DB_METAPROCEDURE_NAME_O(list, insert_, insert, "()", any, db_list_insert_);
    DB_METAPROCEDURE_NAME_O(list, append_, append, "()", any, db_list_append_);
    DB_METAPROCEDURE_O(list, reverse, "()", void, db_list_reverse);
    DB_METAPROCEDURE_O(list, clear, "()", void, db_list_clear);

/* ::hyve::lang::map */
DB_CLASS_O(map, collection, DB_LOCAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	/* Duplicate members for a more convenient order in the initializer */
	DB_REFERENCE_O(map, elementType, typedef, DB_GLOBAL, DB_DECLARED | DB_DEFINED, FALSE);
    DB_REFERENCE_O(map, keyType, typedef, DB_GLOBAL, DB_DECLARED | DB_DEFINED, FALSE);
    DB_MEMBER_O(map, max, uint32, DB_GLOBAL);
    DB_CALLBACK_O(map, init, "(lang::map object)", type_init, int16, db_map_init);
    DB_CALLBACK_O(map, construct, "(lang::map object)", class_construct, int16, db_map_construct);

/* ::hyve::lang::function */
DB_PROCEDURE_NOBASE_O(function, DB_FUNCTION, NULL, DB_DECLARED | DB_DEFINED);
    DB_REFERENCE_O(function, returnType, typedef, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
    DB_MEMBER_O(function, returnsReference, bool, DB_GLOBAL);
    DB_MEMBER_O(function, overloaded, bool, DB_LOCAL | DB_READONLY);
    DB_MEMBER_O(function, kind, uint32, DB_LOCAL | DB_PRIVATE);
    DB_MEMBER_O(function, impl, word, DB_LOCAL|DB_PRIVATE);
    DB_MEMBER_O(function, impludata, word, DB_LOCAL|DB_PRIVATE);
    DB_REFERENCE_O(function, resource, object, DB_LOCAL|DB_PRIVATE, DB_DEFINED | DB_DECLARED, FALSE);
    DB_MEMBER_O(function, size, int16, DB_LOCAL|DB_PRIVATE);
    DB_MEMBER_O(function, parameters, parameterSeq, DB_LOCAL | DB_READONLY);
    DB_MEMBER_O(function, nextParameterId, uint32, DB_LOCAL | DB_PRIVATE);
    DB_CALLBACK_O(function, init, "(lang::function object)", type_init, int16, db_function_init);
    DB_CALLBACK_O(function, bind, "(lang::function object)", procedure_bind, int16, db_function_bind);
    DB_CALLBACK_O(function, unbind, "(lang::function object)", procedure_unbind, void, db_function_unbind);

/* ::hyve::lang::dispatcher */
DB_INTERFACE_O(dispatcher);
	DB_METHOD_O(dispatcher, post, "(lang::event event)", void, FALSE, NULL);
	DB_METHOD_O(dispatcher, getEvent, "(lang::observer observer,lang::object me,lang::object observable,lang::object src)", observableEvent, FALSE, NULL);

/* ::hyve::lang::event */
DB_CLASS_NOBASE_O(event, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	DB_MEMBER_O(event, kind, uint16, DB_GLOBAL);
	DB_MEMBER_O(event, handled, bool, DB_LOCAL | DB_READONLY);
	DB_METHOD_O(event, processed, "()", void, FALSE, db_event_processed);
	DB_FUNCTION_O(event, uniqueKind, "()", int16, db_event_uniqueKind);

/* ::hyve::lang::observableEvent */
DB_CLASS_O(observableEvent, event, DB_GLOBAL, DB_SEQUENCE_EMPTY_V(interface), NULL, DB_DECLARED | DB_DEFINED);
	DB_REFERENCE_O(observableEvent, observer, observer, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observableEvent, me, object, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observableEvent, source, object, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observableEvent, observable, object, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);

/* ::hyve::lang::method */
DB_PROCEDURE_O(method, DB_METHOD, function, DB_GLOBAL, DB_SSO_TYPE_ID(interface), DB_DECLARED);
    DB_MEMBER_O(method, virtual, bool, DB_GLOBAL);
    DB_CALLBACK_O(method, init, "(lang::method object)", type_init, int16, db_method_init);
    DB_CALLBACK_O(method, bind, "(lang::method object)", procedure_bind, int16, db_method_bind);

DB_PROCEDURE_O(virtual, DB_METHOD, method, DB_GLOBAL, DB_SSO_TYPE_ID(interface), DB_DECLARED);
    DB_CALLBACK_O(virtual, init, "(lang::virtual object)", type_init, int16, db_virtual_init);
    
/* ::hyve::lang::delegate */
DB_PROCEDURE_O(delegate, DB_DELEGATE, function, DB_GLOBAL, NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(delegate, id, uint32, DB_LOCAL);
    DB_CALLBACK_O(delegate, init, "(lang::delegate object)", type_init, int16, db_delegate_init);

/* ::hyve::lang::callback */
DB_PROCEDURE_O(callback, DB_CALLBACK, function, DB_GLOBAL, NULL, DB_DECLARED);
	DB_REFERENCE_O(callback, delegate, delegate, DB_GLOBAL, DB_DEFINED, FALSE);
	DB_CALLBACK_O(callback, init, "(lang::callback object)", type_init, int16, db_callback_init);
    DB_CALLBACK_O(callback, bind, "(lang::callback object)", procedure_bind, int16, db_callback_bind);

/* ::hyve::lang::observer */
DB_PROCEDURE_O(observer, DB_OBSERVER, function, DB_LOCAL | DB_READONLY, NULL, DB_DECLARED | DB_DEFINED);
	DB_REFERENCE_O(observer, observable, object, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_MEMBER_O(observer, mask, eventMask, DB_GLOBAL);
	DB_MEMBER_O(observer, expression, string, DB_GLOBAL);
	DB_MEMBER_O(observer, template, uint32, DB_GLOBAL);
	DB_REFERENCE_O(observer, dispatcher, dispatcher, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observer, me, object, DB_GLOBAL, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observer, observing, object, DB_LOCAL | DB_PRIVATE, DB_DEFINED | DB_DECLARED, FALSE);
	DB_REFERENCE_O(observer, delayedBinder, observer, DB_LOCAL | DB_PRIVATE, DB_DEFINED | DB_DECLARED, FALSE);
	DB_CALLBACK_O(observer, init, "(lang::observer object)", type_init, int16, db_observer_init);
	DB_CALLBACK_O(observer, bind, "(lang::observer object)", procedure_bind, int16, db_observer_bind);
	DB_CALLBACK_O(observer, unbind, "(lang::observer object)", procedure_unbind, void, db_observer_unbind);
	DB_METHOD_O(observer, listen, "(lang::object observable,lang::object me)", int16, FALSE, db_observer_listen);
	DB_METHOD_O(observer, silence, "(lang::object me)", int16, FALSE, db_observer_silence);
	DB_METHOD_O(observer, setDispatcher, "(lang::dispatcher dispatcher)", void, FALSE, db_observer_setDispatcher);

/* ::hyve::lang::metaprocedure */
DB_PROCEDURE_O(metaprocedure, DB_METAPROCEDURE, function, DB_GLOBAL, NULL, DB_DECLARED);
    DB_CALLBACK_O(metaprocedure, bind, "(lang::metaprocedure object)", procedure_bind, int16, db_metaprocedure_bind);

/* ::hyve::lang::member */
DB_CLASS_NOBASE_O(member, DB_SEQUENCE_EMPTY_V(interface), DB_SSO_TYPE_ID(interface), DB_DECLARED);
    DB_REFERENCE_O(member, type, typedef, DB_GLOBAL, DB_DECLARED | DB_DEFINED, FALSE);
    DB_MEMBER_O(member, modifiers, modifier, DB_GLOBAL);
    DB_MEMBER_O(member, state, state, DB_GLOBAL);
    DB_MEMBER_O(member, weak, bool, DB_GLOBAL);
    DB_MEMBER_O(member, id, uint32, DB_GLOBAL | DB_PRIVATE);
    DB_MEMBER_O(member, offset, uint32, DB_LOCAL | DB_PRIVATE);
    DB_CALLBACK_O(member, init, "(lang::member object)", type_init, int16, db_member_init);
    DB_CALLBACK_O(member, construct, "(lang::member object)", class_construct, int16, db_member_construct);

/* ::hyve::lang::parameter */
DB_STRUCT_O(parameter, NULL, DB_DECLARED | DB_DEFINED);
    DB_MEMBER_O(parameter, name, string, DB_GLOBAL);
    DB_REFERENCE_O(parameter, type, typedef, DB_GLOBAL, DB_DECLARED | DB_DEFINED, FALSE);
    DB_MEMBER_O(parameter, passByReference, bool, DB_GLOBAL);

#ifdef __cplusplus
}
#endif

#endif /* DB_BOOTSTRAP_H_ */
