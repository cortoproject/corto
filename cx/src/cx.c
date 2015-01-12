/*
 * db.c
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

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
#include "cx_vm.h"

#include "cx__object.h"
#include "stdlib.h"

/* Declaration of the C-binding call-handler */
void cx_call_cdecl(cx_function f, cx_void* result, void* args);
void cx_call_vm(cx_function f, cx_void* result, void* args);
void cx_callDestruct_vm(cx_function f);

struct cx_exitHandler {
    void(*handler)(void*);
    void* userData;
};

static cx_mutex_s cx_adminLock;
static cx_ll cx_exitHandlers = NULL;
static cx_ll cx_unloadHandlers = NULL;

cx_threadKey CX_KEY_OBSERVER_ADMIN;
cx_threadKey CX_KEY_WAIT_ADMIN;

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
    SSO_OP_CLASS(op, typedef);\
    SSO_OP_CLASS(op, type);\
    SSO_OP_CLASS(op, primitive);\
    SSO_OP_CLASS(op, interface);\
    SSO_OP_CLASS(op, collection);\
    SSO_OP_CLASS(op, iterator);\
    SSO_OP_CLASS(op, struct);\
    SSO_OP_CLASS(op, procedure);\
    SSO_OP_CLASS(op, event);\
    SSO_OP_CLASS(op, observableEvent);\
    SSO_OP_CLASS(op, binary);\
    SSO_OP_CLASS(op, boolean);\
    SSO_OP_CLASS(op, character);\
    SSO_OP_CLASS(op, int);\
    SSO_OP_CLASS(op, uint);\
    SSO_OP_CLASS(op, float);\
    SSO_OP_CLASS(op, text);\
    SSO_OP_CLASS(op, enum);\
    SSO_OP_CLASS(op, bitmask);\
    SSO_OP_CLASS(op, alias);\
    SSO_OP_CLASS(op, array);\
    SSO_OP_CLASS(op, sequence);\
    SSO_OP_CLASS(op, list);\
    SSO_OP_CLASS(op, map);\
    SSO_OP_CLASS(op, member);\
    SSO_OP_CLASS(op, class);\
    SSO_OP_CLASS(op, procptr);

/* Procedures */
#define SSO_OP_PROCEDURETYPE(op)\
    SSO_OP_CLASS(op, function);\
    SSO_OP_CLASS(op, method);\
    SSO_OP_CLASS(op, virtual);\
    SSO_OP_CLASS(op, delegate);\
    SSO_OP_CLASS(op, callback);\
    SSO_OP_CLASS(op, observer);\
    SSO_OP_CLASS(op, metaprocedure);

/* ::cortex::lang objects (types only) */
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
    SSO_OP_PRIM(op, objectSeq);\
    SSO_OP_PRIM(op, interfaceSeq);\
    SSO_OP_PRIM(op, memberSeq);\
    SSO_OP_PRIM(op, parameterSeq);\
    SSO_OP_PRIM(op, observerSeq);\
    SSO_OP_PRIM(op, vtable);\
    SSO_OP_PRIM(op, interfaceVectorSeq);\
    SSO_OP_PRIM(op, interfaceVector);\
    SSO_OP_PRIM(op, parameter);\
    SSO_OP_PRIM(op, procptrdata);\
    SSO_OP_VOID(op, dispatcher);\
    SSO_OP_PROCEDURETYPE(op);\
    SSO_OP_CLASSTYPE(op);

#define SSO_OBJECT(obj) CX_OFFSET(&obj##__o, sizeof(cx_SSO))
#define SSO_OP_OBJ(op, obj) op(SSO_OBJECT(obj))

/* 1st degree objects (members, methods and constants) */
#define SSO_OP_OBJECT(op)\
    SSO_OP_OBJ(op, cortex_new);\
    SSO_OP_OBJ(op, cortex__new);\
    SSO_OP_OBJ(op, type_init);\
    SSO_OP_OBJ(op, class_construct);\
    SSO_OP_OBJ(op, class_destruct);\
    SSO_OP_OBJ(op, procedure_bind);\
    SSO_OP_OBJ(op, procedure_unbind);\
    /* constant */\
    SSO_OP_OBJ(op, constant_init);\
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
    SSO_OP_OBJ(op, function_init);\
    SSO_OP_OBJ(op, function_bind);\
    SSO_OP_OBJ(op, function_unbind);\
    SSO_OP_OBJ(op, function_stringToParameterSeq);\
    /* method */\
    SSO_OP_OBJ(op, method_virtual);\
    SSO_OP_OBJ(op, method_init);\
    SSO_OP_OBJ(op, method_bind);\
    /* virtual */\
    SSO_OP_OBJ(op, virtual_init);\
    /* delegate */\
    SSO_OP_OBJ(op, delegate_id);\
    SSO_OP_OBJ(op, delegate_init);\
    /* callback */\
    SSO_OP_OBJ(op, callback_delegate);\
    SSO_OP_OBJ(op, callback_init);\
    SSO_OP_OBJ(op, callback_bind);\
    /* observer */\
    SSO_OP_OBJ(op, observer_observable);\
    SSO_OP_OBJ(op, observer_mask);\
    SSO_OP_OBJ(op, observer_expression);\
    SSO_OP_OBJ(op, observer_template);\
    SSO_OP_OBJ(op, observer_dispatcher);\
    SSO_OP_OBJ(op, observer_me);\
    SSO_OP_OBJ(op, observer_observing);\
    SSO_OP_OBJ(op, observer_delayedBinder);\
    SSO_OP_OBJ(op, observer_init);\
    SSO_OP_OBJ(op, observer_bind);\
    SSO_OP_OBJ(op, observer_unbind);\
    SSO_OP_OBJ(op, observer_listen);\
    SSO_OP_OBJ(op, observer_silence);\
    SSO_OP_OBJ(op, observer_setDispatcher);\
    /* metaprocedure */\
    SSO_OP_OBJ(op, metaprocedure_referenceOnly);\
    SSO_OP_OBJ(op, metaprocedure_bind);\
    /* dispatcher */\
    SSO_OP_OBJ(op, dispatcher_post);\
    SSO_OP_OBJ(op, dispatcher_getEvent);\
    /* event */\
    SSO_OP_OBJ(op, event_kind);\
    SSO_OP_OBJ(op, event_handled);\
    SSO_OP_OBJ(op, event_processed);\
    SSO_OP_OBJ(op, event_uniqueKind);\
    /* observableEvent */\
    SSO_OP_OBJ(op, observableEvent_observer);\
    SSO_OP_OBJ(op, observableEvent_me);\
    SSO_OP_OBJ(op, observableEvent_source);\
    SSO_OP_OBJ(op, observableEvent_observable);\
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
    SSO_OP_OBJ(op, primitiveKind_ALIAS);\
    /* compositeKind */\
    SSO_OP_OBJ(op, compositeKind_INTERFACE);\
    SSO_OP_OBJ(op, compositeKind_STRUCT);\
    SSO_OP_OBJ(op, compositeKind_CLASS);\
    SSO_OP_OBJ(op, compositeKind_PROCPTR);\
    SSO_OP_OBJ(op, compositeKind_PROCEDURE);\
    /* collectionKind */\
    SSO_OP_OBJ(op, collectionKind_ARRAY);\
    SSO_OP_OBJ(op, collectionKind_SEQUENCE);\
    SSO_OP_OBJ(op, collectionKind_LIST);\
    SSO_OP_OBJ(op, collectionKind_MAP);\
    /* procedureKind */\
    SSO_OP_OBJ(op, procedureKind_FUNCTION);\
    SSO_OP_OBJ(op, procedureKind_METHOD);\
    SSO_OP_OBJ(op, procedureKind_DELEGATE);\
    SSO_OP_OBJ(op, procedureKind_CALLBACK);\
    SSO_OP_OBJ(op, procedureKind_OBSERVER);\
    SSO_OP_OBJ(op, procedureKind_METAPROCEDURE);\
    /* equalityKind */\
    SSO_OP_OBJ(op, equalityKind_EQ);\
    SSO_OP_OBJ(op, equalityKind_LT);\
    SSO_OP_OBJ(op, equalityKind_GT);\
    SSO_OP_OBJ(op, equalityKind_NEQ);\
    /* operatorKind */\
    SSO_OP_OBJ(op, operatorKind_ASSIGN);\
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
    SSO_OP_OBJ(op, operatorKind_ASSIGN_ADD);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_SUB);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_MUL);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_DIV);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_MOD);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_XOR);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_OR);\
    SSO_OP_OBJ(op, operatorKind_ASSIGN_AND);\
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
    SSO_OP_OBJ(op, operatorKind_COMMA);\
    SSO_OP_OBJ(op, operatorKind_REF);\
    SSO_OP_OBJ(op, operatorKind_MEMBER_RESOLVE);\
    SSO_OP_OBJ(op, operatorKind_ELEMENT_OPEN);\
    SSO_OP_OBJ(op, operatorKind_ELEMENT_CLOSE);\
    SSO_OP_OBJ(op, operatorKind_BRACKET_OPEN);\
    SSO_OP_OBJ(op, operatorKind_BRACKET_CLOSE);\
    /* state */\
    SSO_OP_OBJ(op, state_VALID);\
    SSO_OP_OBJ(op, state_DECLARED);\
    SSO_OP_OBJ(op, state_DEFINED);\
    /* attr */\
    SSO_OP_OBJ(op, attr_ATTR_SCOPED);\
    SSO_OP_OBJ(op, attr_ATTR_WRITABLE);\
    SSO_OP_OBJ(op, attr_ATTR_OBSERVABLE);\
    /* eventKind */\
    SSO_OP_OBJ(op, eventMask_ON_DECLARE);\
    SSO_OP_OBJ(op, eventMask_ON_DEFINE);\
    SSO_OP_OBJ(op, eventMask_ON_DESTRUCT);\
    SSO_OP_OBJ(op, eventMask_ON_INVALIDATE);\
    SSO_OP_OBJ(op, eventMask_ON_UPDATE);\
    SSO_OP_OBJ(op, eventMask_ON_SELF);\
    SSO_OP_OBJ(op, eventMask_ON_SCOPE);\
    SSO_OP_OBJ(op, eventMask_ON_VALUE);\
    SSO_OP_OBJ(op, eventMask_ON_METAVALUE);\
    /* modifier */\
    SSO_OP_OBJ(op, modifier_GLOBAL);\
    SSO_OP_OBJ(op, modifier_LOCAL);\
    SSO_OP_OBJ(op, modifier_PRIVATE);\
    SSO_OP_OBJ(op, modifier_READONLY);\
    SSO_OP_OBJ(op, modifier_CONST);\
    /* typedef */\
    SSO_OP_OBJ(op, typedef_type);\
    SSO_OP_OBJ(op, typedef_real);\
    SSO_OP_OBJ(op, typedef_realType);\
    SSO_OP_OBJ(op, typedef_init);\
    SSO_OP_OBJ(op, typedef_construct);\
    SSO_OP_OBJ(op, typedef_destruct);\
    /* type */\
    SSO_OP_OBJ(op, type_kind);\
    SSO_OP_OBJ(op, type_reference);\
    SSO_OP_OBJ(op, type_hasResources);\
    SSO_OP_OBJ(op, type_templateId);\
    SSO_OP_OBJ(op, type_size);\
    SSO_OP_OBJ(op, type_alignment);\
    SSO_OP_OBJ(op, type_defaultType);\
    SSO_OP_OBJ(op, type_parentType);\
    SSO_OP_OBJ(op, type_parentState);\
    SSO_OP_OBJ(op, type_metaprocedures);\
    SSO_OP_OBJ(op, type_sizeof);\
    SSO_OP_OBJ(op, type_alignmentof);\
    SSO_OP_OBJ(op, type_allocSize);\
    SSO_OP_OBJ(op, type_compatible);\
    SSO_OP_OBJ(op, type_resolveProcedure);\
    SSO_OP_OBJ(op, type_castable);\
    /* The extra '_' disambiguates between the type::init delegate and this callback */\
    SSO_OP_OBJ(op, type__init);\
    SSO_OP_OBJ(op, type_construct);\
    /* The extra '_' disambiguates between the type::destruct metaprocedure and this callback */\
    SSO_OP_OBJ(op, type__destruct);\
    SSO_OP_OBJ(op, type_parentof);\
    SSO_OP_OBJ(op, type_nameof);\
    SSO_OP_OBJ(op, type_declare);\
    SSO_OP_OBJ(op, type_destruct);\
    SSO_OP_OBJ(op, type_define);\
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
    SSO_OP_OBJ(op, primitive_init);\
    SSO_OP_OBJ(op, primitive_construct);\
    SSO_OP_OBJ(op, primitive_compatible);\
    SSO_OP_OBJ(op, primitive_castable);\
    /* interface */\
    SSO_OP_OBJ(op, interface_kind);\
    SSO_OP_OBJ(op, interface_nextMemberId);\
    SSO_OP_OBJ(op, interface_members);\
    SSO_OP_OBJ(op, interface_methods);\
    SSO_OP_OBJ(op, interface_base);\
    SSO_OP_OBJ(op, interface_init);\
    SSO_OP_OBJ(op, interface_construct);\
    SSO_OP_OBJ(op, interface_destruct);\
    SSO_OP_OBJ(op, interface_resolveMember);\
    SSO_OP_OBJ(op, interface_compatible);\
    SSO_OP_OBJ(op, interface_resolveMethod);\
    SSO_OP_OBJ(op, interface_resolveMethodId);\
    SSO_OP_OBJ(op, interface_resolveMethodById);\
    SSO_OP_OBJ(op, interface_bindMethod);\
    SSO_OP_OBJ(op, interface_baseof);\
    /* collection */\
    SSO_OP_OBJ(op, collection_kind);\
    SSO_OP_OBJ(op, collection_elementType);\
    SSO_OP_OBJ(op, collection_max);\
    SSO_OP_OBJ(op, collection_castable);\
    SSO_OP_OBJ(op, collection_compatible);\
    SSO_OP_OBJ(op, collection_elementRequiresAlloc);\
    SSO_OP_OBJ(op, collection_init);\
    SSO_OP_OBJ(op, collection_size);\
    /* iterator */\
    SSO_OP_OBJ(op, iterator_elementType);\
    SSO_OP_OBJ(op, iterator_init);\
    SSO_OP_OBJ(op, iterator_next);\
    SSO_OP_OBJ(op, iterator_hasNext);\
    /* list */\
    SSO_OP_OBJ(op, list_insert);\
    SSO_OP_OBJ(op, list_insert_);\
    SSO_OP_OBJ(op, list_append);\
    SSO_OP_OBJ(op, list_append_);\
    SSO_OP_OBJ(op, list_reverse);\
    SSO_OP_OBJ(op, list_clear);\
    /* binary */\
    SSO_OP_OBJ(op, binary_init);\
    /* boolean */\
    SSO_OP_OBJ(op, boolean_init);\
    /* char */\
    SSO_OP_OBJ(op, character_init);\
    /* int */\
    SSO_OP_OBJ(op, int_min);\
    SSO_OP_OBJ(op, int_max);\
    SSO_OP_OBJ(op, int_init);\
    /* uint */\
    SSO_OP_OBJ(op, uint_min);\
    SSO_OP_OBJ(op, uint_max);\
    SSO_OP_OBJ(op, uint_init);\
    /* float */\
    SSO_OP_OBJ(op, float_min);\
    SSO_OP_OBJ(op, float_max);\
    SSO_OP_OBJ(op, float_init);\
    /* text */\
    SSO_OP_OBJ(op, text_charWidth);\
    SSO_OP_OBJ(op, text_length);\
    SSO_OP_OBJ(op, text_init);\
    /* enum */\
    SSO_OP_OBJ(op, enum_constants);\
    SSO_OP_OBJ(op, enum_constant);\
    SSO_OP_OBJ(op, enum_init);\
    SSO_OP_OBJ(op, enum_construct);\
    SSO_OP_OBJ(op, enum_destruct);\
    /* bitmask */\
    SSO_OP_OBJ(op, bitmask_init);\
    /* alias */\
    SSO_OP_OBJ(op, alias_init);\
    SSO_OP_OBJ(op, alias_typeName);\
    /* struct */\
    SSO_OP_OBJ(op, struct_init);\
    SSO_OP_OBJ(op, struct_construct);\
    SSO_OP_OBJ(op, struct_baseAccess);\
    SSO_OP_OBJ(op, struct_delegateCount);\
    SSO_OP_OBJ(op, struct_compatible);\
    SSO_OP_OBJ(op, struct_castable);\
    SSO_OP_OBJ(op, struct_resolveMember);\
    /* procedure */\
    SSO_OP_OBJ(op, procedure_kind);\
    SSO_OP_OBJ(op, procedure_init);\
    /* interfaceVector */\
    SSO_OP_OBJ(op, interfaceVector_interface);\
    SSO_OP_OBJ(op, interfaceVector_vector);\
    /* class */\
    SSO_OP_OBJ(op, class_implements);\
    SSO_OP_OBJ(op, class_interfaceVector);\
    SSO_OP_OBJ(op, class_observers);\
    SSO_OP_OBJ(op, class__construct);\
    SSO_OP_OBJ(op, class__destruct);\
    SSO_OP_OBJ(op, class_bindMethod);\
    SSO_OP_OBJ(op, class_allocSize);\
    SSO_OP_OBJ(op, class_init);\
    SSO_OP_OBJ(op, class_instanceof);\
    SSO_OP_OBJ(op, class_privateObserver);\
    SSO_OP_OBJ(op, class_resolveDelegate);\
    SSO_OP_OBJ(op, class_resolveInterfaceMethod);\
    SSO_OP_OBJ(op, class_resolveCallback);\
    SSO_OP_OBJ(op, class_bindCallback);\
    SSO_OP_OBJ(op, class_bindDelegate);\
    SSO_OP_OBJ(op, class_bindObserver);\
    SSO_OP_OBJ(op, class_findObserver);\
    /* procptrdata */\
    SSO_OP_OBJ(op, procptrdata_instance);\
    SSO_OP_OBJ(op, procptrdata_procedure);\
    /* procptr */\
    SSO_OP_OBJ(op, procptr_init);\
    SSO_OP_OBJ(op, procptr_compatible);\
    SSO_OP_OBJ(op, procptr_castable);\
    SSO_OP_OBJ(op, procptr_returnType);\
    SSO_OP_OBJ(op, procptr_returnsReference);\
    SSO_OP_OBJ(op, procptr_parameters);\
    /* array */\
    SSO_OP_OBJ(op, array_elementType);\
    SSO_OP_OBJ(op, array_init);\
    SSO_OP_OBJ(op, array_construct);\
    SSO_OP_OBJ(op, array_destruct);\
    /* sequence */\
    SSO_OP_OBJ(op, sequence_init);\
    SSO_OP_OBJ(op, sequence_construct);\
    SSO_OP_OBJ(op, sequence_size);\
    /* list */\
    SSO_OP_OBJ(op, list_init);\
    SSO_OP_OBJ(op, list_construct);\
    /* map */\
    SSO_OP_OBJ(op, map_elementType);\
    SSO_OP_OBJ(op, map_keyType);\
    SSO_OP_OBJ(op, map_max);\
    SSO_OP_OBJ(op, map_init);\
    SSO_OP_OBJ(op, map_construct);\
    /* member */\
    SSO_OP_OBJ(op, member_type);\
    SSO_OP_OBJ(op, member_modifiers);\
    SSO_OP_OBJ(op, member_state);\
    SSO_OP_OBJ(op, member_weak);\
    SSO_OP_OBJ(op, member_id);\
    SSO_OP_OBJ(op, member_offset);\
    SSO_OP_OBJ(op, member_init);\
    SSO_OP_OBJ(op, member_construct);\
    /* parameter */\
    SSO_OP_OBJ(op, parameter_name);\
    SSO_OP_OBJ(op, parameter_type);\
    SSO_OP_OBJ(op, parameter_passByReference);\

/* 2nd degree objects (function parameters) */
#define SSO_OP_OBJECT_2ND(op) \

/* Creation and destruction of objects */
static void cx_newObject(cx_object o) {
    cx__newSSO(o);
}
static void cx_freeObject(cx_object o) {
    cx__freeSSO(o);
}

static void cx_freeType(cx_object o, cx_uint32 size) {
    CX_UNUSED(size);
    cx_freeObject(o);
}

/* Initialization of objects */
static void cx_initObject(cx_object o) {
    cx_newObject(o);
    if(cx_type_init_hasCallback(cx_typeof(o)->real)) {
        cx_type_init(cx_typeof(o)->real, o);
    }
    if (cx_typeof(o)->real->kind == CX_VOID) {
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
        cx_error("construction of builtin-object '%s' failed.", cx_nameof(o));
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
static void cx_destructObject(cx_object o) {
    cx_vtable* vtable;

    cx__destructor(o);

    /* Free callback-vtable */
    if ((vtable = cx_class_getCallbackVtable(o))) {
        cx_uint32 i;
        for(i=0; i<vtable->length; i++) {
            if (vtable->buffer && vtable->buffer[i]) {
                cx_free_ext(o, vtable->buffer[i], "Free callback from builtin-object.");
            }
        }
    }
}

/* Destruct type */
static void cx_destructType(cx_object o, cx_uint32 size) {
    cx_vtable* vtable;
    CX_UNUSED(size);

    cx__destructor(o);

    /* Restore 'real' pointer */
    cx_typedef(o)->real = o;

    /* Free callback-vtable */
    if ((vtable = cx_class_getCallbackVtable(o))) {
        cx_uint32 i;
        for(i=0; i<vtable->length; i++) {
            if (vtable->buffer && vtable->buffer[i]) {
                cx_free_ext(o, vtable->buffer[i], "Free callback from builtin-object.");
            }
        }
    }
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

void cx_bindMethods(void) {
    /* Bind init delegate. This delegate object will be used to invoke the type-specific initializer callbacks. */
    cx_class_bindDelegate(cx_type_o, SSO_OBJECT(type_init));

    /* typedef, type, primitive, interface */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_typedef_o), SSO_OBJECT(typedef_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_type_o), SSO_OBJECT(type__init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_primitive_o), SSO_OBJECT(primitive_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_interface_o), SSO_OBJECT(interface_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_collection_o), SSO_OBJECT(collection_init));

    /* binary, boolean, character, int, uint, float, text, enum, bitmask, alias */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_binary_o), SSO_OBJECT(binary_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_boolean_o), SSO_OBJECT(boolean_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_character_o), SSO_OBJECT(character_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_int_o), SSO_OBJECT(int_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_uint_o), SSO_OBJECT(uint_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_float_o), SSO_OBJECT(float_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_text_o), SSO_OBJECT(text_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_enum_o), SSO_OBJECT(enum_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_bitmask_o), SSO_OBJECT(bitmask_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_alias_o), SSO_OBJECT(alias_init));

    /* interface, struct, class, procedure */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_struct_o), SSO_OBJECT(struct_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_interface_o), SSO_OBJECT(interface_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_class_o), SSO_OBJECT(class_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_procedure_o), SSO_OBJECT(procedure_init));

    /* array, sequence, list, map */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_array_o), SSO_OBJECT(array_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_sequence_o), SSO_OBJECT(sequence_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_list_o), SSO_OBJECT(list_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_map_o), SSO_OBJECT(map_init));

    /* method, delegate, callback, parameter */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_function_o), SSO_OBJECT(function_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_method_o), SSO_OBJECT(method_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_delegate_o), SSO_OBJECT(delegate_init));
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_callback_o), SSO_OBJECT(callback_init));

    /* member */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_member_o), SSO_OBJECT(member_init));

    /* constant */
    cx_class_bindCallback(cx_type_o, SSO_OBJECT(type_init), cx_type(cx_constant_o), SSO_OBJECT(constant_init));

    /* class::construct and class::destruct are assigned hard-coded delegateId's so constructor and destructor
     * callbacks can be binded. We can't actually bind these objects yet, as this would prematurely create a
     * vtable on the class object, which would contain only a subset of the methods in his inheritance hierarchy.
     * This in effect would make it impossible for 'class' to correctly resolve all of it's (virtual) methods.
     *
     * The values below can be deduced from the fact that in the whole inheritance tree of a class only 'type'
     * has delegatee ('init') which has obtained id 1. These numbers are asserted on later in the
     * bootstrap, so if at a later time additional delegates are added, the bootstrap will fail, which is a good thing.
     *
     * The same goes for the procedure::bind function, which fulfills the same purpose for procedure objects
     * as the class::construct does for class objects.
     */
    ((cx_delegate)SSO_OBJECT(class_construct))->id = 2;
    ((cx_delegate)SSO_OBJECT(class_destruct))->id = 3;
    ((cx_delegate)SSO_OBJECT(procedure_bind))->id = 2;

    /* ::function */
    cx_class_bindCallback(cx_procedure_o, SSO_OBJECT(procedure_bind), cx_type(cx_function_o), SSO_OBJECT(function_bind));
}

int cx_start(void) {

    /* Initialize threadkeys */
    cx_threadTlsKey(&CX_KEY_OBSERVER_ADMIN, NULL);
    cx_threadTlsKey(&CX_KEY_WAIT_ADMIN, NULL);

    /* Init admin-lock */
    cx_adminLock = cx_mutexNew();

    /* Bootstrap sizes. This is necessary because otherwise the callback-vtables which
     * are located after the object's value won't be accessible. */
    cx_type(cx_type_o)->size = sizeof(struct cx_type_s);
    cx_type(cx_procedure_o)->size = sizeof(struct cx_procedure_s);
    cx_type(cx_class_o)->size = sizeof(struct cx_class_s);
    cx_type(cx_binary_o)->size = sizeof(struct cx_binary_s);
    cx_type(cx_boolean_o)->size = sizeof(struct cx_boolean_s);
    cx_type(cx_character_o)->size = sizeof(struct cx_character_s);
    cx_type(cx_int_o)->size = sizeof(struct cx_int_s);
    cx_type(cx_uint_o)->size = sizeof(struct cx_uint_s);
    cx_type(cx_float_o)->size = sizeof(struct cx_float_s);
    cx_type(cx_text_o)->size = sizeof(struct cx_text_s);

    /* Bootstrap sizes of types used in parameters, these are used to determine
     * argument-stack sizes for functions during function::bind. */
    cx_type(cx_string_o)->size = sizeof(cx_string);
    cx_type(cx_int32_o)->size = sizeof(cx_int32);
    cx_type(cx_uint32_o)->size = sizeof(cx_uint32);
    cx_type(cx_any_o)->size = sizeof(cx_any);
    cx_type(cx_state_o)->size = sizeof(cx_state);
    cx_type(cx_attr_o)->size = sizeof(cx_attr);

    /* We need to bind the methods required for initialization now because the next
     * bootstrap step will use them. */
    cx_bindMethods();

    /* Initialize builtin scopes */
    cx_initObject(root_o);
    cx_initObject(cortex_o);
    cx_initObject(cortex_lang_o);

    /* Init objects */
    SSO_OP_TYPE(cx_initType);
    SSO_OP_OBJECT(cx_initObject);
    SSO_OP_OBJECT_2ND(cx_initObject);

    /* Validate that class::construct, class::destruct and procedure::bind received correct delegateId's */
    cx_assert(((cx_delegate)SSO_OBJECT(class_construct))->id == 2, "class::construct did not receive expected delegateId.");
    cx_assert(((cx_delegate)SSO_OBJECT(class_destruct))->id == 3, "class::destruct did not receive expected delegateId.");
    cx_assert(((cx_delegate)SSO_OBJECT(procedure_bind))->id == 2, "procedure::bind did not receive expected delegateId.");

    /* Construct objects */
    SSO_OP_OBJECT_2ND(cx_defineObject);
    SSO_OP_OBJECT(cx_defineObject);
    SSO_OP_TYPE(cx_defineType);

    /* Update refcounts of public members */
    SSO_OP_TYPE(cx_updateRefType);
    SSO_OP_OBJECT(cx_updateRef);
    SSO_OP_OBJECT_2ND(cx_updateRef);

    /* Initialize conversions and operators */
    cx_convertInit();
    cx_operatorInit();

    /* Register C-binding and vm-binding */
    {
        cx_uint32 id;
        id = cx_callRegisterBinding(NULL, NULL, NULL, NULL);
        cx_assert(id == 1, "C-binding did not receive binding-id 1.");

        id = cx_callRegisterBinding(cx_call_vm, NULL, NULL, (cx_callDestructHandler)cx_callDestruct_vm);
        cx_assert(id == 2, "Vm-binding did not receive binding-id 2.");
    }

    /* Always randomize seed */
    srand (time(NULL));

    return 0;
}

/* Register unloadhandler */
void cx_onunload(void(*handler)(void*), void* userData) {
    struct cx_exitHandler* h;

    h = cx_malloc(sizeof(struct cx_exitHandler));
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

    h = cx_malloc(sizeof(struct cx_exitHandler));
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
    cx_free(root_o);

    /* Call exithandlers */
    cx_exit();

    /* Decrease refcounts of public members */
    SSO_OP_TYPE(cx_decreaseRefType);
    SSO_OP_OBJECT(cx_decreaseRef);
    SSO_OP_OBJECT_2ND(cx_decreaseRef);

    /* Destruct objects */
    SSO_OP_TYPE(cx_destructType);
    SSO_OP_OBJECT(cx_destructObject);
    SSO_OP_OBJECT_2ND(cx_destructObject);

    /* Free objects */
    SSO_OP_OBJECT_2ND(cx_freeObject);
    SSO_OP_OBJECT(cx_freeObject);
    SSO_OP_TYPE(cx_freeType);

    /* Deinitialize root */
    cx__freeSSO(cortex_lang_o);
    cx__freeSSO(cortex_o);

    cx__freeSSO(root_o);

    /* Deinit adminLock */
    cx_mutexFree(&cx_adminLock);

    /* Workaround for dlopen-leakage - with this statement the valgrind memory-logging is clean. */
    /*pthread_exit(NULL);*/
}
