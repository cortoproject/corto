/*
 * db.c
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */
#define corto_lang_LIB
#include "cx__bootstrap.h"
#include "cx_util.h"
#include "cx_err.h"
#include "cx_mem.h"
#include "cx_type.h"
#include "cx__class.h"
#include "cx__meta.h"
#include "cx_convert.h"
#include "cx_operator.h"
#include "cx_memory_ser.h"
#include "cx_mm.h"
#include "cx_call.h"
#include "cx_crc.h"

#include "cx__object.h"
#include "stdlib.h"

/* Declaration of the C-binding call-handler */
void cx_call_cdecl(cx_function f, cx_void* result, void* args);

#ifdef CX_VM
void cx_call_vm(cx_function f, cx_void* result, void* args);
void cx_callDestruct_vm(cx_function f);
#endif

struct cx_exitHandler {
    void(*handler)(void*);
    void* userData;
};

#define VERSION_MAJOR "0"
#define VERSION_MINOR "2"
#define VERSION_PATCH "0"
#define VERSION_SUFFIX "alpha"

#ifdef VERSION_SUFFIX
const char* CORTO_VERSION = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH "-" VERSION_SUFFIX;
const char* CORTO_VERSION_SUFFIX = VERSION_SUFFIX;
#else
const char* CORTO_VERSION = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
const char* CORTO_VERSION_SUFFIX = "";
#endif

const char* CORTO_VERSION_MAJOR = VERSION_MAJOR;
const char* CORTO_VERSION_MINOR = VERSION_MINOR;
const char* CORTO_VERSION_PATCH = VERSION_PATCH;

cx_mutex_s cx_adminLock;
static cx_ll cx_exitHandlers = NULL;
static cx_ll cx_unloadHandlers = NULL;

cx_threadKey CX_KEY_OBSERVER_ADMIN;
cx_threadKey CX_KEY_WAIT_ADMIN;
cx_threadKey CX_KEY_ATTR;
cx_threadKey CX_KEY_SELECT;

int8_t CX_DEBUG_ENABLED = 0;

#define SSO_OP_VOID(op, type) op(cx_##type##_o, 0)
#define SSO_OP_PRIM(op, type) op(cx_##type##_o, sizeof(cx_##type))
#define SSO_OP_CLASS(op, type) op(cx_##type##_o, sizeof(struct cx_##type##_s))

/* The ordering of the lists of objects below is important to ensure correct
 * initialization\construction\destruction of objects. Especially the latter one
 * is tricky, since during destruction callback-vtables are destroyed, which in turn
 * contain the pointers to the destruct functions.
 */

/* Classes */
#define SSO_OP_CLASSTYPE(op)\
    SSO_OP_CLASS(op, type);\
    SSO_OP_CLASS(op, primitive);\
    SSO_OP_CLASS(op, interface);\
    SSO_OP_CLASS(op, collection);\
    SSO_OP_CLASS(op, iterator);\
    SSO_OP_CLASS(op, struct);\
    SSO_OP_CLASS(op, procedure);\
    SSO_OP_CLASS(op, event);\
    SSO_OP_CLASS(op, observableEvent);\
    SSO_OP_CLASS(op, invokeEvent);\
    SSO_OP_CLASS(op, binary);\
    SSO_OP_CLASS(op, boolean);\
    SSO_OP_CLASS(op, character);\
    SSO_OP_CLASS(op, int);\
    SSO_OP_CLASS(op, uint);\
    SSO_OP_CLASS(op, float);\
    SSO_OP_CLASS(op, text);\
    SSO_OP_CLASS(op, enum);\
    SSO_OP_CLASS(op, bitmask);\
    SSO_OP_CLASS(op, array);\
    SSO_OP_CLASS(op, sequence);\
    SSO_OP_CLASS(op, list);\
    SSO_OP_CLASS(op, map);\
    SSO_OP_CLASS(op, member);\
    SSO_OP_CLASS(op, alias);\
    SSO_OP_CLASS(op, class);\
    SSO_OP_CLASS(op, delegate);\
    SSO_OP_CLASS(op, package);\
    SSO_OP_CLASS(op, query);\
    SSO_OP_CLASS(op, replicator);

/* Procedures */
#define SSO_OP_PROCEDURETYPE(op)\
    SSO_OP_CLASS(op, function);\
    SSO_OP_CLASS(op, method);\
    SSO_OP_CLASS(op, virtual);\
    SSO_OP_CLASS(op, observer);\
    SSO_OP_CLASS(op, metaprocedure);

/* ::corto::lang objects (types only) */
#define SSO_OP_TYPE(op)\
    SSO_OP_PRIM(op, octet);\
    SSO_OP_PRIM(op, bool);\
    SSO_OP_PRIM(op, char);\
    SSO_OP_PRIM(op, uint8);\
    SSO_OP_PRIM(op, uint16);\
    SSO_OP_PRIM(op, uint32);\
    SSO_OP_PRIM(op, uint64);\
    SSO_OP_PRIM(op, int8);\
    SSO_OP_PRIM(op, int16);\
    SSO_OP_PRIM(op, int32);\
    SSO_OP_PRIM(op, int64);\
    SSO_OP_PRIM(op, float32);\
    SSO_OP_PRIM(op, float64);\
    SSO_OP_PRIM(op, string);\
    SSO_OP_PRIM(op, word);\
    SSO_OP_PRIM(op, constant);\
    SSO_OP_PRIM(op, any);\
    SSO_OP_VOID(op, void);\
    SSO_OP_VOID(op, object);\
    SSO_OP_PRIM(op, width);\
    SSO_OP_PRIM(op, typeKind);\
    SSO_OP_PRIM(op, primitiveKind);\
    SSO_OP_PRIM(op, compositeKind);\
    SSO_OP_PRIM(op, collectionKind);\
    SSO_OP_PRIM(op, procedureKind);\
    SSO_OP_PRIM(op, equalityKind);\
    SSO_OP_PRIM(op, operatorKind);\
    SSO_OP_PRIM(op, modifier);\
    SSO_OP_PRIM(op, eventMask);\
    SSO_OP_PRIM(op, state);\
    SSO_OP_PRIM(op, attr);\
    SSO_OP_PRIM(op, objectseq);\
    SSO_OP_PRIM(op, interfaceseq);\
    SSO_OP_PRIM(op, memberseq);\
    SSO_OP_PRIM(op, parameterseq);\
    SSO_OP_PRIM(op, observerseq);\
    SSO_OP_PRIM(op, octetseq);\
    SSO_OP_PRIM(op, vtable);\
    SSO_OP_PRIM(op, interfaceVectorseq);\
    SSO_OP_PRIM(op, interfaceVector);\
    SSO_OP_PRIM(op, parameter);\
    SSO_OP_PRIM(op, delegatedata);\
    SSO_OP_VOID(op, dispatcher);\
    SSO_OP_PRIM(op, initAction);\
    SSO_OP_PRIM(op, destructAction);\
    SSO_OP_PRIM(op, notifyAction);\
    SSO_OP_PRIM(op, invokeAction);\
    SSO_OP_PROCEDURETYPE(op);\
    SSO_OP_CLASSTYPE(op);

#define SSO_OBJECT(obj) CX_OFFSET(&obj##__o, sizeof(cx_SSO))
#define SSO_OP_OBJ(op, obj) op(SSO_OBJECT(obj))

/* 1st degree objects (members, methods and constants) */
#define SSO_OP_OBJECT(op)\
    SSO_OP_OBJ(op, class_construct_);\
    SSO_OP_OBJ(op, class_destruct_);\
    SSO_OP_OBJ(op, procedure_unbind_);\
    /* constant */\
    SSO_OP_OBJ(op, constant_init_);\
    /* function */\
    SSO_OP_OBJ(op, function_returnType);\
    SSO_OP_OBJ(op, function_returnsReference);\
    SSO_OP_OBJ(op, function_overloaded);\
    SSO_OP_OBJ(op, function_kind);\
    SSO_OP_OBJ(op, function_impl);\
    SSO_OP_OBJ(op, function_implData);\
    SSO_OP_OBJ(op, function_resource);\
    SSO_OP_OBJ(op, function_size);\
    SSO_OP_OBJ(op, function_parameters);\
    SSO_OP_OBJ(op, function_nextParameterId);\
    SSO_OP_OBJ(op, function_init_);\
    SSO_OP_OBJ(op, function_bind_);\
    SSO_OP_OBJ(op, function_unbind);\
    SSO_OP_OBJ(op, function_stringToParameterSeq);\
    /* method */\
    SSO_OP_OBJ(op, method_virtual);\
    SSO_OP_OBJ(op, method_init_);\
    SSO_OP_OBJ(op, method_bind_);\
    /* virtual */\
    SSO_OP_OBJ(op, virtual_init_);\
    /* observer */\
    SSO_OP_OBJ(op, observer_mask);\
    SSO_OP_OBJ(op, observer_observable);\
    SSO_OP_OBJ(op, observer_template);\
    SSO_OP_OBJ(op, observer_dispatcher);\
    SSO_OP_OBJ(op, observer_me);\
    SSO_OP_OBJ(op, observer_observing);\
    SSO_OP_OBJ(op, observer_delayedBinder);\
    SSO_OP_OBJ(op, observer_init_);\
    SSO_OP_OBJ(op, observer_bind_);\
    SSO_OP_OBJ(op, observer_unbind);\
    SSO_OP_OBJ(op, observer_listen_);\
    SSO_OP_OBJ(op, observer_silence_);\
    SSO_OP_OBJ(op, observer_setDispatcher_);\
    /* metaprocedure */\
    SSO_OP_OBJ(op, metaprocedure_referenceOnly);\
    SSO_OP_OBJ(op, metaprocedure_bind_);\
    /* dispatcher */\
    SSO_OP_OBJ(op, dispatcher_post);\
    /* event */\
    SSO_OP_OBJ(op, event_kind);\
    SSO_OP_OBJ(op, event_handled);\
    SSO_OP_OBJ(op, event_handle_);\
    SSO_OP_OBJ(op, event_uniqueKind);\
    /* observableEvent */\
    SSO_OP_OBJ(op, observableEvent_observer);\
    SSO_OP_OBJ(op, observableEvent_me);\
    SSO_OP_OBJ(op, observableEvent_source);\
    SSO_OP_OBJ(op, observableEvent_observable);\
    SSO_OP_OBJ(op, observableEvent_handle_);\
    /* invokeEvent */\
    SSO_OP_OBJ(op, invokeEvent_replicator);\
    SSO_OP_OBJ(op, invokeEvent_instance);\
    SSO_OP_OBJ(op, invokeEvent_function);\
    SSO_OP_OBJ(op, invokeEvent_args);\
    SSO_OP_OBJ(op, invokeEvent_handle_);\
    /* width */\
    SSO_OP_OBJ(op, width_WIDTH_8);\
    SSO_OP_OBJ(op, width_WIDTH_16);\
    SSO_OP_OBJ(op, width_WIDTH_32);\
    SSO_OP_OBJ(op, width_WIDTH_64);\
    SSO_OP_OBJ(op, width_WIDTH_WORD);\
    /* typeKind */\
    SSO_OP_OBJ(op, typeKind_VOID);\
    SSO_OP_OBJ(op, typeKind_ANY);\
    SSO_OP_OBJ(op, typeKind_PRIMITIVE);\
    SSO_OP_OBJ(op, typeKind_COMPOSITE);\
    SSO_OP_OBJ(op, typeKind_COLLECTION);\
    SSO_OP_OBJ(op, typeKind_ITERATOR);\
    /* primitiveKind */\
    SSO_OP_OBJ(op, primitiveKind_BINARY);\
    SSO_OP_OBJ(op, primitiveKind_BOOLEAN);\
    SSO_OP_OBJ(op, primitiveKind_CHARACTER);\
    SSO_OP_OBJ(op, primitiveKind_INTEGER);\
    SSO_OP_OBJ(op, primitiveKind_UINTEGER);\
    SSO_OP_OBJ(op, primitiveKind_FLOAT);\
    SSO_OP_OBJ(op, primitiveKind_TEXT);\
    SSO_OP_OBJ(op, primitiveKind_ENUM);\
    SSO_OP_OBJ(op, primitiveKind_BITMASK);\
    /* compositeKind */\
    SSO_OP_OBJ(op, compositeKind_INTERFACE);\
    SSO_OP_OBJ(op, compositeKind_STRUCT);\
    SSO_OP_OBJ(op, compositeKind_CLASS);\
    SSO_OP_OBJ(op, compositeKind_DELEGATE);\
    SSO_OP_OBJ(op, compositeKind_PROCEDURE);\
    /* collectionKind */\
    SSO_OP_OBJ(op, collectionKind_ARRAY);\
    SSO_OP_OBJ(op, collectionKind_SEQUENCE);\
    SSO_OP_OBJ(op, collectionKind_LIST);\
    SSO_OP_OBJ(op, collectionKind_MAP);\
    /* procedureKind */\
    SSO_OP_OBJ(op, procedureKind_FUNCTION);\
    SSO_OP_OBJ(op, procedureKind_METHOD);\
    SSO_OP_OBJ(op, procedureKind_OBSERVER);\
    SSO_OP_OBJ(op, procedureKind_METAPROCEDURE);\
    /* equalityKind */\
    SSO_OP_OBJ(op, equalityKind_EQ);\
    SSO_OP_OBJ(op, equalityKind_LT);\
    SSO_OP_OBJ(op, equalityKind_GT);\
    SSO_OP_OBJ(op, equalityKind_NEQ);\
    /* operatorKind */\
    SSO_OP_OBJ(op, operatorKind_ASSIGN);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_ADD);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_SUB);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_MUL);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_DIV);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_MOD);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_XOR);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_OR);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_AND);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_UPDATE);\
    SSO_OP_OBJ(op, operatorKind_ADD);\
    SSO_OP_OBJ(op, operatorKind_SUB);\
    SSO_OP_OBJ(op, operatorKind_MUL);\
    SSO_OP_OBJ(op, operatorKind_DIV);\
    SSO_OP_OBJ(op, operatorKind_MOD);\
    SSO_OP_OBJ(op, operatorKind_INC);\
    SSO_OP_OBJ(op, operatorKind_DEC);\
    SSO_OP_OBJ(op, operatorKind_XOR);\
    SSO_OP_OBJ(op, operatorKind_OR);\
    SSO_OP_OBJ(op, operatorKind_AND);\
    SSO_OP_OBJ(op, operatorKind_NOT);\
    SSO_OP_OBJ(op, operatorKind_COND_OR);\
    SSO_OP_OBJ(op, operatorKind_COND_AND);\
    SSO_OP_OBJ(op, operatorKind_COND_NOT);\
    SSO_OP_OBJ(op, operatorKind_COND_EQ);\
    SSO_OP_OBJ(op, operatorKind_COND_NEQ);\
    SSO_OP_OBJ(op, operatorKind_COND_GT);\
    SSO_OP_OBJ(op, operatorKind_COND_LT);\
    SSO_OP_OBJ(op, operatorKind_COND_GTEQ);\
    SSO_OP_OBJ(op, operatorKind_COND_LTEQ);\
    SSO_OP_OBJ(op, operatorKind_SHIFT_LEFT);\
    SSO_OP_OBJ(op, operatorKind_SHIFT_RIGHT);\
    SSO_OP_OBJ(op, operatorKind_REF);\
    /* state */\
    SSO_OP_OBJ(op, state_VALID);\
    SSO_OP_OBJ(op, state_DECLARED);\
    SSO_OP_OBJ(op, state_DEFINED);\
    SSO_OP_OBJ(op, state_DESTRUCTED);\
    /* attr */\
    SSO_OP_OBJ(op, attr_ATTR_SCOPED);\
    SSO_OP_OBJ(op, attr_ATTR_WRITABLE);\
    SSO_OP_OBJ(op, attr_ATTR_OBSERVABLE);\
    SSO_OP_OBJ(op, attr_ATTR_PERSISTENT);\
    SSO_OP_OBJ(op, attr_ATTR_DEFAULT);\
    /* eventKind */\
    SSO_OP_OBJ(op, eventMask_ON_DECLARE);\
    SSO_OP_OBJ(op, eventMask_ON_DEFINE);\
    SSO_OP_OBJ(op, eventMask_ON_DELETE);\
    SSO_OP_OBJ(op, eventMask_ON_INVALIDATE);\
    SSO_OP_OBJ(op, eventMask_ON_UPDATE);\
    SSO_OP_OBJ(op, eventMask_ON_SELF);\
    SSO_OP_OBJ(op, eventMask_ON_SCOPE);\
    SSO_OP_OBJ(op, eventMask_ON_TREE);\
    SSO_OP_OBJ(op, eventMask_ON_VALUE);\
    SSO_OP_OBJ(op, eventMask_ON_METAVALUE);\
    /* modifier */\
    SSO_OP_OBJ(op, modifier_GLOBAL);\
    SSO_OP_OBJ(op, modifier_LOCAL);\
    SSO_OP_OBJ(op, modifier_PRIVATE);\
    SSO_OP_OBJ(op, modifier_READONLY);\
    SSO_OP_OBJ(op, modifier_CONST);\
    SSO_OP_OBJ(op, modifier_HIDDEN);\
    /* type */\
    SSO_OP_OBJ(op, type_kind);\
    SSO_OP_OBJ(op, type_reference);\
    SSO_OP_OBJ(op, type_hasResources);\
    SSO_OP_OBJ(op, type_templateId);\
    SSO_OP_OBJ(op, type_size);\
    SSO_OP_OBJ(op, type_alignment);\
    SSO_OP_OBJ(op, type_parentType);\
    SSO_OP_OBJ(op, type_parentState);\
    SSO_OP_OBJ(op, type_defaultType);\
    SSO_OP_OBJ(op, type_metaprocedures);\
    SSO_OP_OBJ(op, type_init);\
    SSO_OP_OBJ(op, type_sizeof_);\
    SSO_OP_OBJ(op, type_alignmentof_);\
    SSO_OP_OBJ(op, type_allocSize_);\
    SSO_OP_OBJ(op, type_compatible_);\
    SSO_OP_OBJ(op, type_resolveProcedure_);\
    SSO_OP_OBJ(op, type_castable_);\
    SSO_OP_OBJ(op, type_init_);\
    SSO_OP_OBJ(op, type_construct_);\
    SSO_OP_OBJ(op, type_destruct_);\
    SSO_OP_OBJ(op, type_parentof);\
    SSO_OP_OBJ(op, type_nameof);\
    SSO_OP_OBJ(op, type_declare);\
    SSO_OP_OBJ(op, type_define);\
    SSO_OP_OBJ(op, type_delete);\
    SSO_OP_OBJ(op, type_invalidate);\
    SSO_OP_OBJ(op, type_resolve);\
    SSO_OP_OBJ(op, type_lookup);\
    SSO_OP_OBJ(op, type_checkAttr);\
    SSO_OP_OBJ(op, type_checkState);\
    SSO_OP_OBJ(op, type_typeof);\
    SSO_OP_OBJ(op, type_instanceof);\
    SSO_OP_OBJ(op, type_fullname);\
    SSO_OP_OBJ(op, type_relname);\
    SSO_OP_OBJ(op, type_compare);\
    SSO_OP_OBJ(op, type_copy);\
    SSO_OP_OBJ(op, type_toString);\
    /* primitive */\
    SSO_OP_OBJ(op, primitive_kind);\
    SSO_OP_OBJ(op, primitive_width);\
    SSO_OP_OBJ(op, primitive_convertId);\
    SSO_OP_OBJ(op, primitive_init_);\
    SSO_OP_OBJ(op, primitive_construct_);\
    SSO_OP_OBJ(op, primitive_compatible_);\
    SSO_OP_OBJ(op, primitive_castable_);\
    SSO_OP_OBJ(op, primitive_isInteger_);\
    SSO_OP_OBJ(op, primitive_isNumber_);\
    /* interface */\
    SSO_OP_OBJ(op, interface_kind);\
    SSO_OP_OBJ(op, interface_nextMemberId);\
    SSO_OP_OBJ(op, interface_members);\
    SSO_OP_OBJ(op, interface_methods);\
    SSO_OP_OBJ(op, interface_base);\
    SSO_OP_OBJ(op, interface_parentType);\
    SSO_OP_OBJ(op, interface_parentState);\
    SSO_OP_OBJ(op, interface_defaultType);\
    SSO_OP_OBJ(op, interface_init_);\
    SSO_OP_OBJ(op, interface_construct_);\
    SSO_OP_OBJ(op, interface_destruct_);\
    SSO_OP_OBJ(op, interface_resolveMember_);\
    SSO_OP_OBJ(op, interface_compatible_);\
    SSO_OP_OBJ(op, interface_resolveMethod_);\
    SSO_OP_OBJ(op, interface_resolveMethodId_);\
    SSO_OP_OBJ(op, interface_resolveMethodById_);\
    SSO_OP_OBJ(op, interface_bindMethod_);\
    SSO_OP_OBJ(op, interface_baseof_);\
    /* collection */\
    SSO_OP_OBJ(op, collection_kind);\
    SSO_OP_OBJ(op, collection_elementType);\
    SSO_OP_OBJ(op, collection_max);\
    SSO_OP_OBJ(op, collection_castable_);\
    SSO_OP_OBJ(op, collection_compatible_);\
    SSO_OP_OBJ(op, collection_elementRequiresAlloc_);\
    SSO_OP_OBJ(op, collection_init_);\
    SSO_OP_OBJ(op, collection_size);\
    /* iterator */\
    SSO_OP_OBJ(op, iterator_elementType);\
    SSO_OP_OBJ(op, iterator_init_);\
    SSO_OP_OBJ(op, iterator_castable_);\
    SSO_OP_OBJ(op, iterator_compatible_);\
    /* list */\
    SSO_OP_OBJ(op, list_insert);\
    SSO_OP_OBJ(op, list_append);\
    SSO_OP_OBJ(op, list_insert_);\
    SSO_OP_OBJ(op, list_append_);\
    SSO_OP_OBJ(op, list_reverse);\
    SSO_OP_OBJ(op, list_clear);\
    /* binary */\
    SSO_OP_OBJ(op, binary_init_);\
    /* boolean */\
    SSO_OP_OBJ(op, boolean_init_);\
    /* char */\
    SSO_OP_OBJ(op, character_init_);\
    /* int */\
    SSO_OP_OBJ(op, int_min);\
    SSO_OP_OBJ(op, int_max);\
    SSO_OP_OBJ(op, int_init_);\
    /* uint */\
    SSO_OP_OBJ(op, uint_min);\
    SSO_OP_OBJ(op, uint_max);\
    SSO_OP_OBJ(op, uint_init_);\
    /* float */\
    SSO_OP_OBJ(op, float_min);\
    SSO_OP_OBJ(op, float_max);\
    SSO_OP_OBJ(op, float_init_);\
    /* text */\
    SSO_OP_OBJ(op, text_charWidth);\
    SSO_OP_OBJ(op, text_length);\
    SSO_OP_OBJ(op, text_init_);\
    /* enum */\
    SSO_OP_OBJ(op, enum_constants);\
    SSO_OP_OBJ(op, enum_constant_);\
    SSO_OP_OBJ(op, enum_init_);\
    SSO_OP_OBJ(op, enum_construct_);\
    SSO_OP_OBJ(op, enum_destruct_);\
    /* bitmask */\
    SSO_OP_OBJ(op, bitmask_init_);\
    /* struct */\
    SSO_OP_OBJ(op, struct_base);\
    SSO_OP_OBJ(op, struct_baseAccess);\
    SSO_OP_OBJ(op, struct_parentType);\
    SSO_OP_OBJ(op, struct_parentState);\
    SSO_OP_OBJ(op, struct_defaultType);\
    SSO_OP_OBJ(op, struct_init_);\
    SSO_OP_OBJ(op, struct_construct_);\
    SSO_OP_OBJ(op, struct_compatible_);\
    SSO_OP_OBJ(op, struct_castable_);\
    SSO_OP_OBJ(op, struct_resolveMember_);\
    /* procedure */\
    SSO_OP_OBJ(op, procedure_kind);\
    SSO_OP_OBJ(op, procedure_bind);\
    SSO_OP_OBJ(op, procedure_init_);\
    /* interfaceVector */\
    SSO_OP_OBJ(op, interfaceVector_interface);\
    SSO_OP_OBJ(op, interfaceVector_vector);\
    /* class */\
    SSO_OP_OBJ(op, class_base);\
    SSO_OP_OBJ(op, class_baseAccess);\
    SSO_OP_OBJ(op, class_implements);\
    SSO_OP_OBJ(op, class_parentType);\
    SSO_OP_OBJ(op, class_parentState);\
    SSO_OP_OBJ(op, class_defaultType);\
    SSO_OP_OBJ(op, class_interfaceVector);\
    SSO_OP_OBJ(op, class_observers);\
    SSO_OP_OBJ(op, class_construct);\
    SSO_OP_OBJ(op, class_destruct);\
    SSO_OP_OBJ(op, class_allocSize_);\
    SSO_OP_OBJ(op, class_init_);\
    SSO_OP_OBJ(op, class_instanceof_);\
    SSO_OP_OBJ(op, class_privateObserver_);\
    SSO_OP_OBJ(op, class_resolveInterfaceMethod_);\
    SSO_OP_OBJ(op, class_bindObserver_);\
    SSO_OP_OBJ(op, class_findObserver_);\
    SSO_OP_OBJ(op, class_listen);\
    SSO_OP_OBJ(op, class_setObservable);\
    SSO_OP_OBJ(op, class_setMask);\
    SSO_OP_OBJ(op, class_setDispatcher);\
    SSO_OP_OBJ(op, class_observableOf);\
    SSO_OP_OBJ(op, class_eventMaskOf);\
    /* query */\
    SSO_OP_OBJ(op, query_from);\
    SSO_OP_OBJ(op, query_mask);\
    /* replicator */\
    SSO_OP_OBJ(op, replicator_mount);\
    SSO_OP_OBJ(op, replicator_query);\
    SSO_OP_OBJ(op, replicator_construct_);\
    SSO_OP_OBJ(op, replicator_destruct_);\
    SSO_OP_OBJ(op, replicator_invoke_);\
    SSO_OP_OBJ(op, replicator_post_);\
    SSO_OP_OBJ(op, replicator_onDeclare);\
    SSO_OP_OBJ(op, replicator_onUpdate);\
    SSO_OP_OBJ(op, replicator_onDelete);\
    SSO_OP_OBJ(op, replicator_onInvoke);\
    SSO_OP_OBJ(op, replicator_on_declare);\
    SSO_OP_OBJ(op, replicator_on_update);\
    SSO_OP_OBJ(op, replicator_on_delete);\
    /* delegatedata */\
    SSO_OP_OBJ(op, delegatedata_instance);\
    SSO_OP_OBJ(op, delegatedata_procedure);\
    /* delegate */\
    SSO_OP_OBJ(op, delegate_returnType);\
    SSO_OP_OBJ(op, delegate_returnsReference);\
    SSO_OP_OBJ(op, delegate_parameters);\
    SSO_OP_OBJ(op, delegate_init_);\
    SSO_OP_OBJ(op, delegate_compatible_);\
    SSO_OP_OBJ(op, delegate_castable_);\
    SSO_OP_OBJ(op, delegate_instanceof_);\
    SSO_OP_OBJ(op, delegate_bind);\
    /* array */\
    SSO_OP_OBJ(op, array_elementType);\
    SSO_OP_OBJ(op, array_init_);\
    SSO_OP_OBJ(op, array_construct_);\
    SSO_OP_OBJ(op, array_destruct_);\
    /* sequence */\
    SSO_OP_OBJ(op, sequence_init_);\
    SSO_OP_OBJ(op, sequence_construct_);\
    SSO_OP_OBJ(op, sequence_size);\
    /* list */\
    SSO_OP_OBJ(op, list_init_);\
    SSO_OP_OBJ(op, list_construct_);\
    /* map */\
    SSO_OP_OBJ(op, map_elementType);\
    SSO_OP_OBJ(op, map_keyType);\
    SSO_OP_OBJ(op, map_max);\
    SSO_OP_OBJ(op, map_init_);\
    SSO_OP_OBJ(op, map_construct_);\
    /* member */\
    SSO_OP_OBJ(op, member_type);\
    SSO_OP_OBJ(op, member_modifiers);\
    SSO_OP_OBJ(op, member_state);\
    SSO_OP_OBJ(op, member_weak);\
    SSO_OP_OBJ(op, member_id);\
    SSO_OP_OBJ(op, member_offset);\
    SSO_OP_OBJ(op, member_init_);\
    SSO_OP_OBJ(op, member_construct_);\
    /* alias */\
    SSO_OP_OBJ(op, alias_member);\
    SSO_OP_OBJ(op, alias_init_);\
    SSO_OP_OBJ(op, alias_construct_);\
    /* parameter */\
    SSO_OP_OBJ(op, parameter_name);\
    SSO_OP_OBJ(op, parameter_type);\
    SSO_OP_OBJ(op, parameter_passByReference);\
    /* package */\
    SSO_OP_OBJ(op, package_url);

/* 2nd degree objects (function parameters) */
#define SSO_OP_OBJECT_2ND(op) \

/* Creation and destruction of objects */
static void cx_createObject(cx_object o) {
    cx__newSSO(o);
}
static void cx_releaseObject(cx_object o) {
    cx__freeSSO(o);
}

static void cx_releaseType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx_releaseObject(o);
}

void cx_delegateDestruct(cx_type t, cx_object o);
cx_int16 cx_delegateInit(cx_type t, cx_object o);
cx_int16 cx_delegateConstruct(cx_type t, cx_object o);

/* Initialization of objects */
static void cx_initObject(cx_object o) {
    cx_createObject(o);

    cx_delegateInit(cx_typeof(o), o);
    
    if (cx_typeof(o)->kind == CX_VOID) {
        cx__setState(o, CX_DEFINED);
    }
}

/* Initialization of types */
static void cx_initType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx_initObject(o);
}

/* Define object */
static void cx_defineObject(cx_object o) {
    if (cx_define(o)) {
        cx_error("construction of builtin-object '%s' failed (%s)", cx_nameof(o), cx_lasterr());
    }
}

/* Define type */
static void cx_defineType(cx_object o, cx_uint32 size) {
    cx_defineObject(o);

    /* Size validation */
    if (cx_type(o)->size != size) {
        cx_id id;
        cx_error("bootstrap: size validation failed for type '%s' - metatype = %d, c-type = %d.", cx_fullname(o, id), cx_type(o)->size, size);
    }
}

/* Destruct object */
static void cx_deleteObject(cx_object o) {
    cx__destructor(o);
}

/* Destruct type */
static void cx_deleteType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx__destructor(o);
}

/* Update references */
static void cx_updateRef(cx_object o) {
    struct cx_serializer_s s;
    s = cx_ser_keep(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
    cx_serialize(&s, o, NULL);
}

/* Update references for type */
static void cx_updateRefType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx_updateRef(o);
}

/* Decrease references */
static void cx_decreaseRef(cx_object o) {
    struct cx_serializer_s s;
    s = cx_ser_free(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
    cx_serialize(&s, o, NULL);
}

/* Decrease references for type */
static void cx_decreaseRefType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx_decreaseRef(o);
}

static void cx_genericTlsFree(void *o) {
    cx_dealloc(o);
}

static void cx_patchSequences(void) {
    cx_replicator_o->implements.length = 1;
    cx_replicator_o->implements.buffer = cx_alloc(sizeof(cx_object));
    cx_replicator_o->implements.buffer[0] = cx_dispatcher_o;

    cx_notifyAction_o->parameters.length = 1;
    cx_notifyAction_o->parameters.buffer = cx_alloc(sizeof(cx_parameter));
    cx_notifyAction_o->parameters.buffer[0].name = "observable";
    cx_notifyAction_o->parameters.buffer[0].type = cx_object_o;
    cx_notifyAction_o->parameters.buffer[0].passByReference = 0;

    cx_invokeAction_o->parameters.length = 3;
    cx_invokeAction_o->parameters.buffer = cx_alloc(3 * sizeof(cx_parameter));
    cx_invokeAction_o->parameters.buffer[0].name = "instance";
    cx_invokeAction_o->parameters.buffer[0].type = cx_object_o;
    cx_invokeAction_o->parameters.buffer[0].passByReference = 0;

    cx_invokeAction_o->parameters.buffer[1].name = "function";
    cx_invokeAction_o->parameters.buffer[1].type = cx_type(cx_function_o);
    cx_invokeAction_o->parameters.buffer[1].passByReference = 0;

    cx_invokeAction_o->parameters.buffer[2].name = "args";
    cx_invokeAction_o->parameters.buffer[2].type = cx_type(cx_octetseq_o);
    cx_invokeAction_o->parameters.buffer[2].passByReference = 0;
}

int cx_start(void) {

    /* CORTO_BUILD is where the buildsystem is located */
    if (!cx_getenv("CORTO_BUILD")) {
        cx_setenv("CORTO_BUILD", "/usr/local/lib/corto/%s/build", CORTO_VERSION);
    }

    /* CORTO_HOME is where corto binaries are located */
    if (!cx_getenv("CORTO_HOME")) {
        cx_setenv("CORTO_HOME", "/usr/local", CORTO_VERSION);
    }

    /* CORTO_TARGET is where a project will be built */
    if (!cx_getenv("CORTO_TARGET")) {
        cx_setenv("CORTO_TARGET", "~/.corto");
    }

    /* Initialize threadkeys */
    cx_threadTlsKey(&CX_KEY_OBSERVER_ADMIN, NULL);
    cx_threadTlsKey(&CX_KEY_WAIT_ADMIN, NULL);
    cx_threadTlsKey(&CX_KEY_ATTR, cx_genericTlsFree);
    cx_threadTlsKey(&CX_KEY_SELECT, NULL);

    /* Init admin-lock */
    cx_mutexNew(&cx_adminLock);

    /* Bootstrap sizes of types used in parameters, these are used to determine
     * argument-stack sizes for functions during function::bind. */
    cx_type(cx_string_o)->size = sizeof(cx_string);
    cx_type(cx_int32_o)->size = sizeof(cx_int32);
    cx_type(cx_uint32_o)->size = sizeof(cx_uint32);
    cx_type(cx_any_o)->size = sizeof(cx_any);
    cx_type(cx_state_o)->size = sizeof(cx_state);
    cx_type(cx_attr_o)->size = sizeof(cx_attr);

    /* Initialize builtin scopes */
    cx_initObject(root_o);
    cx_initObject(corto_o);
    cx_initObject(corto_lang_o);

    /* Define builtin scopes */
    cx_defineObject(root_o);
    cx_defineObject(corto_o);
    cx_defineObject(corto_lang_o);

    /* Init objects */
    SSO_OP_TYPE(cx_initType);
    SSO_OP_OBJECT(cx_initObject);
    SSO_OP_OBJECT_2ND(cx_initObject);

    /* Patch sequences- these cannot be set statically since sequences are 
     * allocated on the heap */
    cx_patchSequences();

    /* Construct objects */
    SSO_OP_OBJECT_2ND(cx_defineObject);
    SSO_OP_OBJECT(cx_defineObject);
    SSO_OP_TYPE(cx_defineType);

    /* Update refcounts of public members */
    SSO_OP_TYPE(cx_updateRefType);
    SSO_OP_OBJECT(cx_updateRef);
    SSO_OP_OBJECT_2ND(cx_updateRef);

    /* Initialize conversions and operators */
#ifdef CX_CONVERSIONS
    cx_convertInit();
#endif
#ifdef CX_OPERATORS
    cx_operatorInit();
#endif

    /* Register C-binding and vm-binding */
    {
        cx_uint32 id;
        id = cx_callRegisterBinding(NULL, NULL, NULL, NULL);
        cx_assert(id == 1, "C-binding did not receive binding-id 1.");
    }

    /* Always randomize seed */
    srand (time(NULL));

    /* Init CRC table */
    cx_crcInit();

    /* Load packages */
    cx_loadPackages();

    return 0;
}

/* Register unloadhandler */
void cx_onunload(void(*handler)(void*), void* userData) {
    struct cx_exitHandler* h;

    h = cx_alloc(sizeof(struct cx_exitHandler));
    h->handler = handler;
    h->userData = userData;

    cx_mutexLock(&cx_adminLock);
    if (!cx_unloadHandlers) {
        cx_unloadHandlers = cx_llNew();
    }
    cx_llInsert(cx_unloadHandlers, h);
    cx_mutexUnlock(&cx_adminLock);
}

/* Register exithandler */
void cx_onexit(void(*handler)(void*), void* userData) {
    struct cx_exitHandler* h;

    h = cx_alloc(sizeof(struct cx_exitHandler));
    h->handler = handler;
    h->userData = userData;

    cx_mutexLock(&cx_adminLock);
    if (!cx_exitHandlers) {
        cx_exitHandlers = cx_llNew();
    }
    cx_llInsert(cx_exitHandlers, h);
    cx_mutexUnlock(&cx_adminLock);
}

/* Call unload-handlers */
static void cx_unload(void) {
    struct cx_exitHandler* h;

    if (cx_unloadHandlers) {
        while((h = cx_llTakeFirst(cx_unloadHandlers))) {
            h->handler(h->userData);
            cx_dealloc(h);
        }
        cx_llFree(cx_unloadHandlers);
        cx_unloadHandlers = NULL;
    }
}

/* Call exit-handlers */
static void cx_exit(void) {
    struct cx_exitHandler* h;

    if (cx_exitHandlers) {
        while((h = cx_llTakeFirst(cx_exitHandlers))) {
            h->handler(h->userData);
            cx_dealloc(h);
        }
        cx_llFree(cx_exitHandlers);
        cx_exitHandlers = NULL;
    }
}

void cx_stop(void) {

    /* Call unload handlers */
    cx_unload();

    /* Drop the rootscope. This will not actually result
     * in removing the rootscope itself, but it will result in the
     * removal of all non-static objects. */
    cx_drop(root_o);
    cx_release(root_o);

    /* Call exithandlers */
    cx_exit();

    /* Decrease refcounts of public members */
    SSO_OP_TYPE(cx_decreaseRefType);
    SSO_OP_OBJECT(cx_decreaseRef);
    SSO_OP_OBJECT_2ND(cx_decreaseRef);

    /* Destruct objects */
    SSO_OP_TYPE(cx_deleteType);
    SSO_OP_OBJECT(cx_deleteObject);
    SSO_OP_OBJECT_2ND(cx_deleteObject);

    /* Free objects */
    SSO_OP_OBJECT_2ND(cx_releaseObject);
    SSO_OP_OBJECT(cx_releaseObject);
    SSO_OP_TYPE(cx_releaseType);

    /* Deinitialize root */
    cx__freeSSO(corto_lang_o);
    cx__freeSSO(corto_o);

    cx__freeSSO(root_o);

    /* Deinit adminLock */
    cx_mutexFree(&cx_adminLock);

    /* Workaround for dlopen-leakage - with this statement the valgrind memory-logging is clean. */
    /*pthread_exit(NULL);*/

}

#define CX_CHECKBUILTIN(builtinobj)\
    if (o == builtinobj) return TRUE;

#define CX_CHECKBUILTIN_ARG(builtinobj, n)\
    if (o == builtinobj) return TRUE;

cx_bool cx_isbuiltin(cx_object o) {
    if (o == root_o) return TRUE;
    if (o == corto_o) return TRUE;
    if (o == corto_lang_o) return TRUE;
    SSO_OP_TYPE(CX_CHECKBUILTIN_ARG);
    SSO_OP_OBJECT(CX_CHECKBUILTIN);
    SSO_OP_OBJECT_2ND(CX_CHECKBUILTIN);
    return FALSE;
}
