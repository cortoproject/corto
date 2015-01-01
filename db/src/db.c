/*
 * db.c
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#include "db__bootstrap.h"
#include "db_util.h"
#include "db_err.h"
#include "db_mem.h"
#include "db_type.h"
#include "db__class.h"
#include "db__meta.h"
#include "db_convert.h"
#include "db_operator.h"
#include "db_memory_ser.h"
#include "db_mm.h"
#include "db_call.h"
#include "db_vm.h"

#include "db__object.h"
#include "stdlib.h"

/* Declaration of the C-binding call-handler */
void db_call_cdecl(db_function f, db_void* result, void* args);
void db_call_vm(db_function f, db_void* result, void* args);
void db_callDestruct_vm(db_function f);

struct db_exitHandler {
	void(*handler)(void*);
	void* userData;
};

static db_mutex_s db_adminLock;
static db_ll db_exitHandlers = NULL;
static db_ll db_unloadHandlers = NULL;

db_threadKey DB_KEY_OBSERVER_ADMIN;
db_threadKey DB_KEY_WAIT_ADMIN;

#define SSO_OP_VOID(op, type) op(db_##type##_o, 0)
#define SSO_OP_PRIM(op, type) op(db_##type##_o, sizeof(db_##type))
#define SSO_OP_CLASS(op, type) op(db_##type##_o, sizeof(struct db_##type##_s))

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

#define SSO_OBJECT(obj) DB_OFFSET(&obj##__o, sizeof(db_SSO))
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
    SSO_OP_OBJ(op, collection_elementRequiresAlloc);\
    SSO_OP_OBJ(op, collection_init);\
    SSO_OP_OBJ(op, collection_size);\
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
static void db_newObject(db_object o) {
    db__newSSO(o);
}
static void db_freeObject(db_object o) {
    db__freeSSO(o);
}

static void db_freeType(db_object o, db_uint32 size) {
    DB_UNUSED(size);
    db_freeObject(o);
}

/* Initialization of objects */
static void db_initObject(db_object o) {
	db_newObject(o);
    if(db_type_init_hasCallback(db_typeof(o)->real)) {
        db_type_init(db_typeof(o)->real, o);
    }
    if (db_typeof(o)->real->kind == DB_VOID) {
        db__setState(o, DB_DEFINED);
    }
}

/* Initialization of types */
static void db_initType(db_object o, db_uint32 size) {
    DB_UNUSED(size);
    db_initObject(o);
}

/* Define object */
static void db_defineObject(db_object o) {
    if (db_define(o)) {
        db_error("construction of builtin-object '%s' failed.", db_nameof(o));
    }
}

/* Define type */
static void db_defineType(db_object o, db_uint32 size) {
    db_defineObject(o);

    /* Size validation */
    if (db_type(o)->size != size) {
        db_id id;
    	db_error("bootstrap: size validation failed for type '%s' - metatype = %d, c-type = %d.", db_fullname(o, id), db_type(o)->size, size);
    }
}

/* Destruct object */
static void db_destructObject(db_object o) {
    db_vtable* vtable;

    db__destructor(o);

    /* Free callback-vtable */
    if ((vtable = db_class_getCallbackVtable(o))) {
    	db_uint32 i;
    	for(i=0; i<vtable->length; i++) {
    		if (vtable->buffer && vtable->buffer[i]) {
    			db_free_ext(o, vtable->buffer[i], "Free callback from builtin-object.");
    		}
    	}
    }
}

/* Destruct type */
static void db_destructType(db_object o, db_uint32 size) {
    db_vtable* vtable;
    DB_UNUSED(size);

    db__destructor(o);

    /* Restore 'real' pointer */
    db_typedef(o)->real = o;

    /* Free callback-vtable */
    if ((vtable = db_class_getCallbackVtable(o))) {
    	db_uint32 i;
    	for(i=0; i<vtable->length; i++) {
    		if (vtable->buffer && vtable->buffer[i]) {
    			db_free_ext(o, vtable->buffer[i], "Free callback from builtin-object.");
    		}
    	}
    }
}

/* Update references */
static void db_updateRef(db_object o) {
	struct db_serializer_s s;
	s = db_ser_keep(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
	db_serialize(&s, o, NULL);
}

/* Update references for type */
static void db_updateRefType(db_object o, db_uint32 size) {
	DB_UNUSED(size);
	db_updateRef(o);
}

/* Decrease references */
static void db_decreaseRef(db_object o) {
	struct db_serializer_s s;
	s = db_ser_free(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
	db_serialize(&s, o, NULL);
}

/* Decrease references for type */
static void db_decreaseRefType(db_object o, db_uint32 size) {
	DB_UNUSED(size);
	db_decreaseRef(o);
}

void db_bindMethods(void) {
    /* Bind init delegate. This delegate object will be used to invoke the type-specific initializer callbacks. */
    db_class_bindDelegate(db_type_o, SSO_OBJECT(type_init));

    /* typedef, type, primitive, interface */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_typedef_o), SSO_OBJECT(typedef_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_type_o), SSO_OBJECT(type__init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_primitive_o), SSO_OBJECT(primitive_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_interface_o), SSO_OBJECT(interface_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_collection_o), SSO_OBJECT(collection_init));

    /* binary, boolean, character, int, uint, float, text, enum, bitmask, alias */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_binary_o), SSO_OBJECT(binary_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_boolean_o), SSO_OBJECT(boolean_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_character_o), SSO_OBJECT(character_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_int_o), SSO_OBJECT(int_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_uint_o), SSO_OBJECT(uint_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_float_o), SSO_OBJECT(float_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_text_o), SSO_OBJECT(text_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_enum_o), SSO_OBJECT(enum_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_bitmask_o), SSO_OBJECT(bitmask_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_alias_o), SSO_OBJECT(alias_init));

    /* interface, struct, class, procedure */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_struct_o), SSO_OBJECT(struct_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_interface_o), SSO_OBJECT(interface_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_class_o), SSO_OBJECT(class_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_procedure_o), SSO_OBJECT(procedure_init));

    /* array, sequence, list, map */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_array_o), SSO_OBJECT(array_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_sequence_o), SSO_OBJECT(sequence_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_list_o), SSO_OBJECT(list_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_map_o), SSO_OBJECT(map_init));

    /* method, delegate, callback, parameter */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_function_o), SSO_OBJECT(function_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_method_o), SSO_OBJECT(method_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_delegate_o), SSO_OBJECT(delegate_init));
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_callback_o), SSO_OBJECT(callback_init));

    /* member */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_member_o), SSO_OBJECT(member_init));

    /* constant */
    db_class_bindCallback(db_type_o, SSO_OBJECT(type_init), db_type(db_constant_o), SSO_OBJECT(constant_init));

    /* class::construct and class::destruct are assigned hard-coded delegateId's so constructor and destructor
     * callbacks can be binded. We can't actually bind these objects yet, as this would prematurely create a
     * vtable on the class object, which would contain only a subset of the methods in his inheritance hierarchy.
     * This in effect would make it impossible for 'class' to correctly resolve all of it's (virtual) methods.
     *
     * The values below can be deduced from the fact that in the whole inheritance tree of a class only 'type'
     * has delegates ('init' and 'compare') which have obtained id 1 and 2. These numbers are asserted on later in the
     * bootstrap, so if at a later time additional delegates are added, the bootstrap will fail, which is a good thing.
     *
     * The same goes for the procedure::bind function, which fulfills the same purpose for procedure objects
     * as the class::construct does for class objects.
     */
    ((db_delegate)SSO_OBJECT(class_construct))->id = 2;
    ((db_delegate)SSO_OBJECT(class_destruct))->id = 3;
    ((db_delegate)SSO_OBJECT(procedure_bind))->id = 2;

    /* ::function */
    db_class_bindCallback(db_procedure_o, SSO_OBJECT(procedure_bind), db_type(db_function_o), SSO_OBJECT(function_bind));
}

int db_start(void) {

	/* Initialize threadkeys */
	db_threadTlsKey(&DB_KEY_OBSERVER_ADMIN, NULL);
	db_threadTlsKey(&DB_KEY_WAIT_ADMIN, NULL);

	/* Init admin-lock */
	db_adminLock = db_mutexNew();

    /* Bootstrap sizes. This is necessary because otherwise the callback-vtables which
     * are located after the object's value won't be accessible. */
    db_type(db_type_o)->size = sizeof(struct db_type_s);
    db_type(db_procedure_o)->size = sizeof(struct db_procedure_s);
    db_type(db_class_o)->size = sizeof(struct db_class_s);
    db_type(db_binary_o)->size = sizeof(struct db_binary_s);
    db_type(db_boolean_o)->size = sizeof(struct db_boolean_s);
    db_type(db_character_o)->size = sizeof(struct db_character_s);
    db_type(db_int_o)->size = sizeof(struct db_int_s);
    db_type(db_uint_o)->size = sizeof(struct db_uint_s);
    db_type(db_float_o)->size = sizeof(struct db_float_s);
    db_type(db_text_o)->size = sizeof(struct db_text_s);

    /* Bootstrap sizes of types used in parameters, these are used to determine
     * argument-stack sizes for functions during function::bind. */
    db_type(db_string_o)->size = sizeof(db_string);
    db_type(db_int32_o)->size = sizeof(db_int32);
    db_type(db_uint32_o)->size = sizeof(db_uint32);
    db_type(db_any_o)->size = sizeof(db_any);
    db_type(db_state_o)->size = sizeof(db_state);
    db_type(db_attr_o)->size = sizeof(db_attr);

    /* We need to bind the methods required for initialization now because the next
     * bootstrap step will use them. */
    db_bindMethods();

    /* Initialize builtin scopes */
    db_initObject(root_o);
    db_initObject(cortex_o);
    db_initObject(cortex_lang_o);

    /* Init objects */
    SSO_OP_TYPE(db_initType);
    SSO_OP_OBJECT(db_initObject);
    SSO_OP_OBJECT_2ND(db_initObject);

    /* Validate that class::construct, class::destruct and procedure::bind received correct delegateId's */
    db_assert(((db_delegate)SSO_OBJECT(class_construct))->id == 2, "class::construct did not receive expected delegateId.");
    db_assert(((db_delegate)SSO_OBJECT(class_destruct))->id == 3, "class::destruct did not receive expected delegateId.");
    db_assert(((db_delegate)SSO_OBJECT(procedure_bind))->id == 2, "procedure::bind did not receive expected delegateId.");
 
    /* Construct objects */
    SSO_OP_OBJECT_2ND(db_defineObject);
    SSO_OP_OBJECT(db_defineObject);
    SSO_OP_TYPE(db_defineType);

    /* Update refcounts of public members */
    SSO_OP_TYPE(db_updateRefType);
    SSO_OP_OBJECT(db_updateRef);
    SSO_OP_OBJECT_2ND(db_updateRef);

    /* Initialize conversions and operators */
    db_convertInit();
    db_operatorInit();

    /* Register C-binding and vm-binding */
    {
        db_uint32 id;
        id = db_callRegisterBinding(NULL, NULL, NULL, NULL);
        db_assert(id == 1, "C-binding did not receive binding-id 1.");

        id = db_callRegisterBinding(db_call_vm, NULL, NULL, (db_callDestructHandler)db_callDestruct_vm);
        db_assert(id == 2, "Vm-binding did not receive binding-id 2.");
    }
   
    /* Always randomize seed */
    srand (time(NULL));

    return 0;
}

/* Register unloadhandler */
void db_onunload(void(*handler)(void*), void* userData) {
    struct db_exitHandler* h;

    h = db_malloc(sizeof(struct db_exitHandler));
    h->handler = handler;
    h->userData = userData;

    db_mutexLock(&db_adminLock);
    if (!db_unloadHandlers) {
        db_unloadHandlers = db_llNew();
    }
    db_llInsert(db_unloadHandlers, h);
    db_mutexUnlock(&db_adminLock);
}

/* Register exithandler */
void db_onexit(void(*handler)(void*), void* userData) {
	struct db_exitHandler* h;

	h = db_malloc(sizeof(struct db_exitHandler));
	h->handler = handler;
	h->userData = userData;

	db_mutexLock(&db_adminLock);
	if (!db_exitHandlers) {
		db_exitHandlers = db_llNew();
	}
	db_llInsert(db_exitHandlers, h);
	db_mutexUnlock(&db_adminLock);
}

/* Call unload-handlers */
static void db_unload(void) {
    struct db_exitHandler* h;

    if (db_unloadHandlers) {
        while((h = db_llTakeFirst(db_unloadHandlers))) {
            h->handler(h->userData);
            db_dealloc(h);
        }
        db_llFree(db_unloadHandlers);
        db_unloadHandlers = NULL;
    }
}

/* Call exit-handlers */
static void db_exit(void) {
	struct db_exitHandler* h;

	if (db_exitHandlers) {
		while((h = db_llTakeFirst(db_exitHandlers))) {
			h->handler(h->userData);
			db_dealloc(h);
		}
		db_llFree(db_exitHandlers);
		db_exitHandlers = NULL;
	}
}

void db_stop(void) {

    /* Call unload handlers */
    db_unload();

	/* Drop the rootscope. This will not actually result
	 * in removing the rootscope itself, but it will result in the
	 * removal of all non-static objects. */
	db_drop(root_o);
	db_free(root_o);

	/* Call exithandlers */
	db_exit();

    /* Decrease refcounts of public members */
	SSO_OP_TYPE(db_decreaseRefType);
	SSO_OP_OBJECT(db_decreaseRef);
    SSO_OP_OBJECT_2ND(db_decreaseRef);

    /* Destruct objects */
    SSO_OP_TYPE(db_destructType);
    SSO_OP_OBJECT(db_destructObject);
    SSO_OP_OBJECT_2ND(db_destructObject);

    /* Free objects */
    SSO_OP_OBJECT_2ND(db_freeObject);
    SSO_OP_OBJECT(db_freeObject);
    SSO_OP_TYPE(db_freeType);

    /* Deinitialize root */
    db__freeSSO(cortex_lang_o);
    db__freeSSO(cortex_o);

    db__freeSSO(root_o);

    /* Deinit adminLock */
    db_mutexFree(&db_adminLock);

    /* Workaround for dlopen-leakage - with this statement the valgrind memory-logging is clean. */
    /*pthread_exit(NULL);*/
}

