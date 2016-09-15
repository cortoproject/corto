/*
 * corto.c
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#include "_bootstrap.h"
#include "lang/_class.h"
#include "_object.h"

#include "corto/corto.h"
#include "corto/cdeclhandler.h"

void corto_secure_init(void);

/* Declaration of the C-binding call-handler */
void corto_call_cdecl(corto_function f, corto_void* result, void* args);

/* TLS callback to cleanup observer administration */
void corto_observerAdminFree(void *admin);
void corto_declaredAdminFree(void *admin);

#ifdef CORTO_VM
void corto_call_vm(corto_function f, corto_void* result, void* args);
void corto_callDestruct_vm(corto_function f);
#endif

struct corto_exitHandler {
    void(*handler)(void*);
    void* userData;
};

#define VERSION_MAJOR "0"
#define VERSION_MINOR "2"
#define VERSION_PATCH "15"
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

/* Single lock to protect infrequent actions on global corto data */
corto_mutex_s corto_adminLock;

/* Actions to be run at shutdown */
static corto_ll corto_exitHandlers = NULL;

/* TLS keys */
corto_threadKey CORTO_KEY_OBSERVER_ADMIN;
corto_threadKey CORTO_KEY_DECLARED_ADMIN;
corto_threadKey CORTO_KEY_WAIT_ADMIN;
corto_threadKey CORTO_KEY_ATTR;
corto_threadKey CORTO_KEY_FLOW;
corto_threadKey CORTO_KEY_THREAD_STRING;
corto_threadKey CORTO_KEY_MOUNT_RESULT;

/* OLS keys */
corto_int8 CORTO_OLS_REPLICATOR;
corto_int8 CORTO_OLS_AUGMENT;

/* variables that control verbosity of logging functions */
int8_t CORTO_DEBUG_ENABLED = 0;

/* When set, the core traces memory management information for this object */
corto_string CORTO_TRACE_OBJECT = NULL;

/* When set, the core traces notifications */
int8_t CORTO_TRACE_NOTIFICATIONS = 0;

/* When set, the core adds backtraces to memory tracing */
int8_t CORTO_BACKTRACE_ENABLED = 0;

/* When set, the core will break at the specified id */
int32_t CORTO_MEMTRACE_BREAKPOINT;

/*
 * Indicator for whether corto is operational
 * 0 = running
 * 1 = initializing
 * 2 = deinitializing
 * 3 = stopped
 */

int8_t CORTO_OPERATIONAL = 3;

static corto_string CORTO_BUILD = __DATE__ " " __TIME__;

#define SSO_OP_VOID(op, type) op(corto_##type##_o, 0)
#define SSO_OP_VALUE(op, type) op(corto_##type##_o, sizeof(corto_##type))
#define SSO_OP_CLASS(op, type) op(corto_##type##_o, sizeof(struct corto_##type##_s))

#define SSO_OP_CORE_VOID(op, type) op(corto_##type##_o, 0)
#define SSO_OP_CORE_VALUE(op, type) op(corto_##type##_o, sizeof(corto_##type))
#define SSO_OP_CORE_CLASS(op, type) op(corto_#type##_o, sizeof(struct corto_##type##_s))

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
    SSO_OP_CLASS(op, union);\
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
    SSO_OP_CLASS(op, case);\
    SSO_OP_CLASS(op, default);\
    SSO_OP_CLASS(op, alias);\
    SSO_OP_CLASS(op, class);\
    SSO_OP_CLASS(op, procedure);\
    SSO_OP_CLASS(op, delegate);\
    SSO_OP_CLASS(op, package);\
    SSO_OP_CLASS(op, subscriber);\
    SSO_OP_CLASS(op, mount);\
    SSO_OP_CLASS(op, loader);\
    SSO_OP_CLASS(op, native_type);\
    SSO_OP_CLASS(op, secure_key);\
    SSO_OP_CLASS(op, secure_lock);\

/* Procedures */
#define SSO_OP_PROCEDURETYPE(op)\
    SSO_OP_CLASS(op, function);\
    SSO_OP_CLASS(op, method);\
    SSO_OP_CLASS(op, virtual);\
    SSO_OP_CLASS(op, remote);\
    SSO_OP_CLASS(op, observer);\
    SSO_OP_CLASS(op, metaprocedure);

/* ::corto::lang objects */
#define SSO_OP_TYPE(op)\
    SSO_OP_VALUE(op, octet);\
    SSO_OP_VALUE(op, bool);\
    SSO_OP_VALUE(op, char);\
    SSO_OP_VALUE(op, uint8);\
    SSO_OP_VALUE(op, uint16);\
    SSO_OP_VALUE(op, uint32);\
    SSO_OP_VALUE(op, uint64);\
    SSO_OP_VALUE(op, int8);\
    SSO_OP_VALUE(op, int16);\
    SSO_OP_VALUE(op, int32);\
    SSO_OP_VALUE(op, int64);\
    SSO_OP_VALUE(op, float32);\
    SSO_OP_VALUE(op, float64);\
    SSO_OP_VALUE(op, string);\
    SSO_OP_VALUE(op, word);\
    SSO_OP_VALUE(op, constant);\
    SSO_OP_VALUE(op, any);\
    SSO_OP_VOID(op, void);\
    SSO_OP_VALUE(op, object);\
    SSO_OP_VALUE(op, width);\
    SSO_OP_VALUE(op, typeKind);\
    SSO_OP_VALUE(op, primitiveKind);\
    SSO_OP_VALUE(op, compositeKind);\
    SSO_OP_VALUE(op, collectionKind);\
    SSO_OP_VALUE(op, procedureKind);\
    SSO_OP_VALUE(op, equalityKind);\
    SSO_OP_VALUE(op, operatorKind);\
    SSO_OP_VALUE(op, mountKind);\
    SSO_OP_VALUE(op, frameKind);\
    SSO_OP_VALUE(op, secure_accessKind);\
    SSO_OP_VALUE(op, secure_actionKind);\
    SSO_OP_VALUE(op, modifier);\
    SSO_OP_VALUE(op, eventMask);\
    SSO_OP_VALUE(op, state);\
    SSO_OP_VALUE(op, attr);\
    SSO_OP_VALUE(op, int32seq);\
    SSO_OP_VALUE(op, wordseq);\
    SSO_OP_VALUE(op, objectseq);\
    SSO_OP_VALUE(op, interfaceseq);\
    SSO_OP_VALUE(op, memberseq);\
    SSO_OP_VALUE(op, parameterseq);\
    SSO_OP_CORE_VALUE(op, observerseq);\
    SSO_OP_VALUE(op, octetseq);\
    SSO_OP_CORE_VALUE(op, augmentseq);\
    SSO_OP_VALUE(op, vtable);\
    SSO_OP_VALUE(op, interfaceVectorseq);\
    SSO_OP_VALUE(op, interfaceVector);\
    SSO_OP_VALUE(op, objectlist);\
    SSO_OP_VALUE(op, resultList);\
    SSO_OP_CORE_VALUE(op, mountSubscriptionList);\
    SSO_OP_VALUE(op, typespec);\
    SSO_OP_VALUE(op, parameter);\
    SSO_OP_VALUE(op, augmentData);\
    SSO_OP_VALUE(op, frame);\
    SSO_OP_VALUE(op, result);\
    SSO_OP_VALUE(op, request);\
    SSO_OP_VALUE(op, mountStats);\
    SSO_OP_VALUE(op, mountPolicy);\
    SSO_OP_VALUE(op, mountSubscription);\
    SSO_OP_VALUE(op, delegatedata);\
    SSO_OP_CORE_VOID(op, dispatcher);\
    SSO_OP_VALUE(op, initAction);\
    SSO_OP_VALUE(op, nameAction);\
    SSO_OP_VALUE(op, destructAction);\
    SSO_OP_VALUE(op, notifyAction);\
    SSO_OP_VALUE(op, resultIter);\
    SSO_OP_VALUE(op, time);\
    SSO_OP_VALUE(op, position);\
    SSO_OP_PROCEDURETYPE(op);\
    SSO_OP_CLASSTYPE(op);

#define SSO_OBJECT(obj) CORTO_OFFSET(&obj##__o, sizeof(corto_SSO))
#define SSO_OP_OBJ(op, obj) op(SSO_OBJECT(lang_##obj))
#define SSO_OP_OBJ_CORE(op, obj) op(SSO_OBJECT(core_##obj))
#define SSO_OP_OBJ_NATIVE(op, obj) op(SSO_OBJECT(native_##obj))
#define SSO_OP_OBJ_SECURE(op, obj) op(SSO_OBJECT(secure_##obj))

/* 1st degree objects (members, methods and constants) */
#define SSO_OP_OBJECT(op)\
    SSO_OP_OBJ(op, class_construct_);\
    SSO_OP_OBJ(op, class_destruct_);\
    /* constant */\
    SSO_OP_OBJ(op, constant_init_);\
    /* function */\
    SSO_OP_OBJ(op, function_returnType);\
    SSO_OP_OBJ(op, function_returnsReference);\
    SSO_OP_OBJ(op, function_overloaded);\
    SSO_OP_OBJ(op, function_kind);\
    SSO_OP_OBJ(op, function_impl);\
    SSO_OP_OBJ(op, function_fptr);\
    SSO_OP_OBJ(op, function_fdata);\
    SSO_OP_OBJ(op, function_resource);\
    SSO_OP_OBJ(op, function_size);\
    SSO_OP_OBJ(op, function_parameters);\
    SSO_OP_OBJ(op, function_nextParameterId);\
    SSO_OP_OBJ(op, function_init_);\
    SSO_OP_OBJ(op, function_construct_);\
    SSO_OP_OBJ(op, function_destruct);\
    SSO_OP_OBJ(op, function_stringToParameterSeq);\
    SSO_OP_OBJ(op, function_parseParamString_);\
    /* method */\
    SSO_OP_OBJ(op, method_virtual);\
    SSO_OP_OBJ(op, method_init_);\
    SSO_OP_OBJ(op, method_construct_);\
    /* virtual */\
    SSO_OP_OBJ(op, virtual_init_);\
    /* observer */\
    SSO_OP_OBJ_CORE(op, observer_mask);\
    SSO_OP_OBJ_CORE(op, observer_observable);\
    SSO_OP_OBJ_CORE(op, observer_me);\
    SSO_OP_OBJ_CORE(op, observer_dispatcher);\
    SSO_OP_OBJ_CORE(op, observer_template);\
    SSO_OP_OBJ_CORE(op, observer_init_);\
    SSO_OP_OBJ_CORE(op, observer_construct_);\
    SSO_OP_OBJ_CORE(op, observer_destruct);\
    SSO_OP_OBJ_CORE(op, observer_listen_);\
    SSO_OP_OBJ_CORE(op, observer_silence_);\
    SSO_OP_OBJ_CORE(op, observer_setDispatcher_);\
    /* metaprocedure */\
    SSO_OP_OBJ(op, metaprocedure_referenceOnly);\
    SSO_OP_OBJ(op, metaprocedure_construct_);\
    /* dispatcher */\
    SSO_OP_OBJ_CORE(op, dispatcher_post);\
    /* event */\
    SSO_OP_OBJ_CORE(op, event_kind);\
    SSO_OP_OBJ_CORE(op, event_handled);\
    SSO_OP_OBJ_CORE(op, event_handle_);\
    SSO_OP_OBJ_CORE(op, event_uniqueKind);\
    /* observableEvent */\
    SSO_OP_OBJ_CORE(op, observableEvent_observer);\
    SSO_OP_OBJ_CORE(op, observableEvent_me);\
    SSO_OP_OBJ_CORE(op, observableEvent_source);\
    SSO_OP_OBJ_CORE(op, observableEvent_observable);\
    SSO_OP_OBJ_CORE(op, observableEvent_mask);\
    SSO_OP_OBJ_CORE(op, observableEvent_thread);\
    SSO_OP_OBJ_CORE(op, observableEvent_handle_);\
    /* invokeEvent */\
    SSO_OP_OBJ_CORE(op, invokeEvent_mount);\
    SSO_OP_OBJ_CORE(op, invokeEvent_instance);\
    SSO_OP_OBJ_CORE(op, invokeEvent_function);\
    SSO_OP_OBJ_CORE(op, invokeEvent_args);\
    SSO_OP_OBJ_CORE(op, invokeEvent_handle_);\
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
    SSO_OP_OBJ(op, compositeKind_UNION);\
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
    /* mountKind */\
    SSO_OP_OBJ_CORE(op, mountKind_SOURCE);\
    SSO_OP_OBJ_CORE(op, mountKind_SINK);\
    SSO_OP_OBJ_CORE(op, mountKind_CACHE);\
    SSO_OP_OBJ_CORE(op, mountKind_HISTORIAN);\
    /* frameKind */\
    SSO_OP_OBJ_CORE(op, frameKind_FRAME_NOW);\
    SSO_OP_OBJ_CORE(op, frameKind_FRAME_TIME);\
    SSO_OP_OBJ_CORE(op, frameKind_FRAME_DURATION);\
    SSO_OP_OBJ_CORE(op, frameKind_FRAME_SAMPLE);\
    SSO_OP_OBJ_CORE(op, frameKind_FRAME_DEPTH);\
    /* accessKind */\
    SSO_OP_OBJ_SECURE(op, accessKind_SECURE_ACCESS_GRANTED);\
    SSO_OP_OBJ_SECURE(op, accessKind_SECURE_ACCESS_DENIED);\
    SSO_OP_OBJ_SECURE(op, accessKind_SECURE_ACCESS_UNDEFINED);\
    /* actionKind */\
    SSO_OP_OBJ_SECURE(op, actionKind_SECURE_ACTION_CREATE);\
    SSO_OP_OBJ_SECURE(op, actionKind_SECURE_ACTION_READ);\
    SSO_OP_OBJ_SECURE(op, actionKind_SECURE_ACTION_UPDATE);\
    SSO_OP_OBJ_SECURE(op, actionKind_SECURE_ACTION_DELETE);\
    /* operatorKind */\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_ADD);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_SUB);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_MUL);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_DIV);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_MOD);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_XOR);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_OR);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_AND);\
    SSO_OP_OBJ_CORE(op, operatorKind_ASSIGN_UPDATE);\
    SSO_OP_OBJ_CORE(op, operatorKind_ADD);\
    SSO_OP_OBJ_CORE(op, operatorKind_SUB);\
    SSO_OP_OBJ_CORE(op, operatorKind_MUL);\
    SSO_OP_OBJ_CORE(op, operatorKind_DIV);\
    SSO_OP_OBJ_CORE(op, operatorKind_MOD);\
    SSO_OP_OBJ_CORE(op, operatorKind_INC);\
    SSO_OP_OBJ_CORE(op, operatorKind_DEC);\
    SSO_OP_OBJ_CORE(op, operatorKind_XOR);\
    SSO_OP_OBJ_CORE(op, operatorKind_OR);\
    SSO_OP_OBJ_CORE(op, operatorKind_AND);\
    SSO_OP_OBJ_CORE(op, operatorKind_NOT);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_OR);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_AND);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_NOT);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_EQ);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_NEQ);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_GT);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_LT);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_GTEQ);\
    SSO_OP_OBJ_CORE(op, operatorKind_COND_LTEQ);\
    SSO_OP_OBJ_CORE(op, operatorKind_SHIFT_LEFT);\
    SSO_OP_OBJ_CORE(op, operatorKind_SHIFT_RIGHT);\
    SSO_OP_OBJ_CORE(op, operatorKind_REF);\
    /* state */\
    SSO_OP_OBJ(op, state_VALID);\
    SSO_OP_OBJ(op, state_DECLARED);\
    SSO_OP_OBJ(op, state_DEFINED);\
    SSO_OP_OBJ(op, state_DESTRUCTED);\
    /* attr */\
    SSO_OP_OBJ_CORE(op, attr_ATTR_SCOPED);\
    SSO_OP_OBJ_CORE(op, attr_ATTR_WRITABLE);\
    SSO_OP_OBJ_CORE(op, attr_ATTR_OBSERVABLE);\
    SSO_OP_OBJ_CORE(op, attr_ATTR_PERSISTENT);\
    SSO_OP_OBJ_CORE(op, attr_ATTR_DEFAULT);\
    /* eventKind */\
    SSO_OP_OBJ_CORE(op, eventMask_ON_DECLARE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_DEFINE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_DELETE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_INVALIDATE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_UPDATE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_RESUME);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_SUSPEND);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_SELF);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_SCOPE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_TREE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_VALUE);\
    SSO_OP_OBJ_CORE(op, eventMask_ON_METAVALUE);\
    /* modifier */\
    SSO_OP_OBJ(op, modifier_GLOBAL);\
    SSO_OP_OBJ(op, modifier_LOCAL);\
    SSO_OP_OBJ(op, modifier_PRIVATE);\
    SSO_OP_OBJ(op, modifier_READONLY);\
    SSO_OP_OBJ(op, modifier_CONST);\
    SSO_OP_OBJ(op, modifier_HIDDEN);\
    SSO_OP_OBJ(op, modifier_OPTIONAL);\
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
    SSO_OP_OBJ(op, type_defaultProcedureType);\
    SSO_OP_OBJ(op, type_metaprocedures);\
    SSO_OP_OBJ(op, type_init);\
    SSO_OP_OBJ(op, type_nameof);\
    SSO_OP_OBJ(op, type_sizeof_);\
    SSO_OP_OBJ(op, type_alignmentof_);\
    SSO_OP_OBJ(op, type_compatible_);\
    SSO_OP_OBJ(op, type_resolveProcedure_);\
    SSO_OP_OBJ(op, type_castable_);\
    SSO_OP_OBJ(op, type_init_);\
    SSO_OP_OBJ(op, type_construct_);\
    SSO_OP_OBJ(op, type_destruct_);\
    SSO_OP_OBJ(op, type_parent);\
    SSO_OP_OBJ(op, type_name);\
    SSO_OP_OBJ(op, type_declare);\
    SSO_OP_OBJ(op, type_define);\
    SSO_OP_OBJ(op, type_delete);\
    SSO_OP_OBJ(op, type_invalidate);\
    SSO_OP_OBJ(op, type_resolve);\
    SSO_OP_OBJ(op, type_lookup);\
    SSO_OP_OBJ(op, type_checkAttr);\
    SSO_OP_OBJ(op, type_checkState);\
    SSO_OP_OBJ(op, type_type);\
    SSO_OP_OBJ(op, type_instanceof);\
    SSO_OP_OBJ(op, type_fullpath);\
    SSO_OP_OBJ(op, type_path);\
    SSO_OP_OBJ(op, type_compare);\
    SSO_OP_OBJ(op, type_copy);\
    SSO_OP_OBJ(op, type_str);\
    /* typespec */\
    SSO_OP_OBJ(op, typespec_type);\
    SSO_OP_OBJ(op, typespec_reference);\
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
    SSO_OP_OBJ(op, interface_defaultProcedureType);\
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
    SSO_OP_OBJ(op, collection_requiresAlloc);\
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
    SSO_OP_OBJ(op, struct_defaultProcedureType);\
    SSO_OP_OBJ(op, struct_init_);\
    SSO_OP_OBJ(op, struct_construct_);\
    SSO_OP_OBJ(op, struct_compatible_);\
    SSO_OP_OBJ(op, struct_castable_);\
    SSO_OP_OBJ(op, struct_resolveMember_);\
    /* union */\
    SSO_OP_OBJ(op, union_discriminator);\
    SSO_OP_OBJ(op, union_parentType);\
    SSO_OP_OBJ(op, union_parentState);\
    SSO_OP_OBJ(op, union_defaultType);\
    SSO_OP_OBJ(op, union_defaultProcedureType);\
    SSO_OP_OBJ(op, union_init_);\
    SSO_OP_OBJ(op, union_construct_);\
    SSO_OP_OBJ(op, union_findCase_);\
    /* procedure */\
    SSO_OP_OBJ(op, procedure_kind);\
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
    SSO_OP_OBJ(op, class_defaultProcedureType);\
    SSO_OP_OBJ(op, class_interfaceVector);\
    SSO_OP_OBJ(op, class_construct);\
    SSO_OP_OBJ(op, class_destruct);\
    SSO_OP_OBJ(op, class_init_);\
    SSO_OP_OBJ(op, class_instanceof_);\
    SSO_OP_OBJ(op, class_resolveInterfaceMethod_);\
    /* mountStats */\
    SSO_OP_OBJ_CORE(op, mountStats_declares);\
    SSO_OP_OBJ_CORE(op, mountStats_updates);\
    SSO_OP_OBJ_CORE(op, mountStats_deletes);\
    /* mountPolicy */\
    SSO_OP_OBJ_CORE(op, mountPolicy_sampleRate);\
    /* mountSubscription */\
    SSO_OP_OBJ_CORE(op, mountSubscription_parent);\
    SSO_OP_OBJ_CORE(op, mountSubscription_expr);\
    SSO_OP_OBJ_CORE(op, mountSubscription_mask);\
    SSO_OP_OBJ_CORE(op, mountSubscription_count);\
    SSO_OP_OBJ_CORE(op, mountSubscription_userData);\
    /* subscriber */\
    SSO_OP_OBJ_CORE(op, subscriber_parent);\
    SSO_OP_OBJ_CORE(op, subscriber_expr);\
    SSO_OP_OBJ_CORE(op, subscriber_mask);\
    SSO_OP_OBJ_CORE(op, subscriber_observer);\
    SSO_OP_OBJ_CORE(op, subscriber_construct_);\
    SSO_OP_OBJ_CORE(op, subscriber_destruct_);\
    /* mount */\
    SSO_OP_OBJ_CORE(op, mount_mount);\
    SSO_OP_OBJ_CORE(op, mount_mask);\
    SSO_OP_OBJ_CORE(op, mount_type);\
    SSO_OP_OBJ_CORE(op, mount_attr);\
    SSO_OP_OBJ_CORE(op, mount_kind);\
    SSO_OP_OBJ_CORE(op, mount_contentType);\
    SSO_OP_OBJ_CORE(op, mount_policy);\
    SSO_OP_OBJ_CORE(op, mount_sent);\
    SSO_OP_OBJ_CORE(op, mount_received);\
    SSO_OP_OBJ_CORE(op, mount_sentDiscarded);\
    SSO_OP_OBJ_CORE(op, mount_policies);\
    SSO_OP_OBJ_CORE(op, mount_subscriptions);\
    SSO_OP_OBJ_CORE(op, mount_events);\
    SSO_OP_OBJ_CORE(op, mount_passThrough);\
    SSO_OP_OBJ_CORE(op, mount_contentTypeHandle);\
    SSO_OP_OBJ_CORE(op, mount_thread);\
    SSO_OP_OBJ_CORE(op, mount_quit);\
    SSO_OP_OBJ_CORE(op, mount_hasNotify);\
    SSO_OP_OBJ_CORE(op, mount_hasResume);\
    SSO_OP_OBJ_CORE(op, mount_init_);\
    SSO_OP_OBJ_CORE(op, mount_construct_);\
    SSO_OP_OBJ_CORE(op, mount_destruct_);\
    SSO_OP_OBJ_CORE(op, mount_invoke_);\
    SSO_OP_OBJ_CORE(op, mount_request_);\
    SSO_OP_OBJ_CORE(op, mount_resume_);\
    SSO_OP_OBJ_CORE(op, mount_subscribe_);\
    SSO_OP_OBJ_CORE(op, mount_unsubscribe_);\
    SSO_OP_OBJ_CORE(op, mount_setContentType_);\
    SSO_OP_OBJ_CORE(op, mount_return_);\
    SSO_OP_OBJ_CORE(op, mount_post_);\
    SSO_OP_OBJ_CORE(op, mount_onPoll_);\
    SSO_OP_OBJ_CORE(op, mount_onDeclare_);\
    SSO_OP_OBJ_CORE(op, mount_onUpdate_);\
    SSO_OP_OBJ_CORE(op, mount_onDelete_);\
    SSO_OP_OBJ_CORE(op, mount_onNotify_);\
    SSO_OP_OBJ_CORE(op, mount_onInvoke_);\
    SSO_OP_OBJ_CORE(op, mount_onRequest_);\
    SSO_OP_OBJ_CORE(op, mount_onResume_);\
    SSO_OP_OBJ_CORE(op, mount_onSubscribe_);\
    SSO_OP_OBJ_CORE(op, mount_onUnsubscribe_);\
    SSO_OP_OBJ_CORE(op, mount_on_declare);\
    SSO_OP_OBJ_CORE(op, mount_on_update);\
    SSO_OP_OBJ_CORE(op, mount_on_delete);\
    /* loader */\
    SSO_OP_OBJ_CORE(op, loader_construct_);\
    SSO_OP_OBJ_CORE(op, loader_destruct_);\
    SSO_OP_OBJ_CORE(op, loader_onResume_);\
    SSO_OP_OBJ_CORE(op, loader_onRequest_);\
    SSO_OP_OBJ_CORE(op, loader_onDeclare_);\
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
    SSO_OP_OBJ(op, delegate_construct);\
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
    /* case */\
    SSO_OP_OBJ(op, case_discriminator);\
    SSO_OP_OBJ(op, case_type);\
    SSO_OP_OBJ(op, case_construct_);\
    /* default */\
    SSO_OP_OBJ(op, default_type);\
    SSO_OP_OBJ(op, default_construct_);\
    /* parameter */\
    SSO_OP_OBJ(op, parameter_name);\
    SSO_OP_OBJ(op, parameter_type);\
    SSO_OP_OBJ(op, parameter_passByReference);\
    /* augmentData */\
    SSO_OP_OBJ_CORE(op, augmentData_id);\
    SSO_OP_OBJ_CORE(op, augmentData_data);\
    /* result */\
    SSO_OP_OBJ_CORE(op, result_id);\
    SSO_OP_OBJ_CORE(op, result_name);\
    SSO_OP_OBJ_CORE(op, result_parent);\
    SSO_OP_OBJ_CORE(op, result_type);\
    SSO_OP_OBJ_CORE(op, result_value);\
    SSO_OP_OBJ_CORE(op, result_crawl);\
    SSO_OP_OBJ_CORE(op, result_history);\
    SSO_OP_OBJ_CORE(op, result_augments);\
    SSO_OP_OBJ_CORE(op, result_mount);\
    SSO_OP_OBJ_CORE(op, result_getText_);\
    /* request */\
    SSO_OP_OBJ_CORE(op, request_parent);\
    SSO_OP_OBJ_CORE(op, request_expr);\
    SSO_OP_OBJ_CORE(op, request_type);\
    SSO_OP_OBJ_CORE(op, request_offset);\
    SSO_OP_OBJ_CORE(op, request_limit);\
    SSO_OP_OBJ_CORE(op, request_content);\
    SSO_OP_OBJ_CORE(op, request_from);\
    SSO_OP_OBJ_CORE(op, request_to);\
    SSO_OP_OBJ_CORE(op, request_param);\
    /* package */\
    SSO_OP_OBJ_CORE(op, package_url);\
    /* time */\
    SSO_OP_OBJ_CORE(op, time_sec);\
    SSO_OP_OBJ_CORE(op, time_nanosec);\
    /* position */\
    SSO_OP_OBJ_CORE(op, position_latitude);\
    SSO_OP_OBJ_CORE(op, position_longitude);\
    /* frame */\
    SSO_OP_OBJ_CORE(op, frame_kind);\
    SSO_OP_OBJ_CORE(op, frame_value);\
    /* native/type */\
    SSO_OP_OBJ_NATIVE(op, type_name);\
    SSO_OP_OBJ_NATIVE(op, type_init_);\
    /* secure/key */\
    SSO_OP_OBJ_SECURE(op, key_construct_);\
    SSO_OP_OBJ_SECURE(op, key_destruct_);\
    SSO_OP_OBJ_SECURE(op, key_authenticate_);\
    /* secure/lock */\
    SSO_OP_OBJ_SECURE(op, lock_mount);\
    SSO_OP_OBJ_SECURE(op, lock_expr);\
    SSO_OP_OBJ_SECURE(op, lock_priority);\
    SSO_OP_OBJ_SECURE(op, lock_construct_);\
    SSO_OP_OBJ_SECURE(op, lock_destruct_);\
    SSO_OP_OBJ_SECURE(op, lock_authorize_);\


/* 2nd degree objects (function parameters) */
#define SSO_OP_OBJECT_2ND(op) \

/* Creation and destruction of objects */
static void corto_createObject(corto_object o) {
    corto__newSSO(o);
}
static void corto_releaseObject(corto_object o) {
    corto__freeSSO(o);
}

static void corto_releaseType(corto_object o, corto_uint32 size) {
    CORTO_UNUSED(size);
    corto_releaseObject(o);
}

void corto_delegateDestruct(corto_type t, corto_object o);
corto_int16 corto_delegateInit(corto_type t, corto_object o);
corto_int16 corto_delegateConstruct(corto_type t, corto_object o);

/* Initialization of objects */
static void corto_initObject(corto_object o) {
    corto_createObject(o);

    corto_delegateInit(corto_typeof(o), o);
}

/* Initialization of types */
static void corto_initType(corto_object o, corto_uint32 size) {
    CORTO_UNUSED(size);
    corto_initObject(o);
}

/* Define object */
static void corto_defineObject(corto_object o) {
    if (corto_define(o)) {
        corto_error("construction of builtin-object '%s' failed (%s)", corto_idof(o), corto_lasterr());
    }
}

/* Define type */
static void corto_defineType(corto_object o, corto_uint32 size) {
    corto_defineObject(o);

    /* Size validation */
    if (corto_type(o)->size != size) {
        corto_error(
          "bootstrap: size validation failed for type '%s' - metatype = %d, c-type = %d.",
          corto_fullpath(NULL, o), corto_type(o)->size, size);
    }
}

/* Destruct object */
static void corto_deleteObject(corto_object o) {
    corto_destruct(o, FALSE);
}

/* Destruct type */
static void corto_deleteType(corto_object o, corto_uint32 size) {
    CORTO_UNUSED(size);
    corto_destruct(o, FALSE);
}

/* Update references */
static void corto_updateRef(corto_object o) {
    struct corto_serializer_s s;
    s = corto_ser_keep(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_serialize(&s, o, NULL);
}

/* Update references for type */
static void corto_updateRefType(corto_object o, corto_uint32 size) {
    CORTO_UNUSED(size);
    corto_updateRef(o);
}

/* Decrease references */
static void corto_decreaseRef(corto_object o) {
    struct corto_serializer_s s;
    s = corto_ser_free(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_serialize(&s, o, NULL);
}

/* Decrease references for type */
static void corto_decreaseRefType(corto_object o, corto_uint32 size) {
    CORTO_UNUSED(size);
    corto_decreaseRef(o);
}

static void corto_genericTlsFree(void *o) {
    corto_dealloc(o);
}

static void corto_patchSequences(void) {
    /* Replicator implements table */
    corto_mount_o->implements.length = 1;
    corto_mount_o->implements.buffer = corto_alloc(sizeof(corto_object));
    corto_mount_o->implements.buffer[0] = corto_dispatcher_o;

    /* notifyAction delegate parameters */
    corto_notifyAction_o->parameters.length = 1;
    corto_notifyAction_o->parameters.buffer = corto_alloc(sizeof(corto_parameter));
    corto_notifyAction_o->parameters.buffer[0].name = "observable";
    corto_notifyAction_o->parameters.buffer[0].type = corto_object_o;
    corto_notifyAction_o->parameters.buffer[0].passByReference = 0;

}

int corto_start(void) {
    corto_secure_init();

    CORTO_OPERATIONAL = 1; /* Initializing */

    /* CORTO_BUILD is where the buildsystem is located */
    if (!corto_getenv("CORTO_BUILD")) {
        corto_setenv("CORTO_BUILD", "/usr/local/lib/corto/%s.%s/build",
            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
    }

    /* CORTO_HOME is where corto binaries are located */
    if (!corto_getenv("CORTO_HOME")) {
        corto_setenv("CORTO_HOME", "/usr/local");
    }

    /* CORTO_TARGET is where a project will be built */
    if (!corto_getenv("CORTO_TARGET")) {
        corto_setenv("CORTO_TARGET", "~/.corto");
    }

    corto_string verbosity = corto_getenv("CORTO_VERBOSITY");
    if (verbosity) {
        if (!strcmp(verbosity, "DEBUG")) {
            corto_verbosity(CORTO_DEBUG);
        }
        if (!strcmp(verbosity, "TRACE")) {
            corto_verbosity(CORTO_TRACE);
        }
        if (!strcmp(verbosity, "OK")) {
            corto_verbosity(CORTO_OK);
        }
        if (!strcmp(verbosity, "INFO")) {
            corto_verbosity(CORTO_INFO);
        }
        if (!strcmp(verbosity, "WARNING")) {
            corto_verbosity(CORTO_WARNING);
        }
        if (!strcmp(verbosity, "ERROR")) {
            corto_verbosity(CORTO_ERROR);
        }
        if (!strcmp(verbosity, "CRITICAL")) {
            corto_verbosity(CORTO_CRITICAL);
        }
        if (!strcmp(verbosity, "ASSERT")) {
            corto_verbosity(CORTO_ASSERT);
        }
    }

    /* Initialize TLS keys */
    corto_threadTlsKey(&CORTO_KEY_OBSERVER_ADMIN, corto_observerAdminFree);
    corto_threadTlsKey(&CORTO_KEY_DECLARED_ADMIN, corto_declaredAdminFree);
    corto_threadTlsKey(&CORTO_KEY_WAIT_ADMIN, NULL);
    corto_threadTlsKey(&CORTO_KEY_ATTR, corto_genericTlsFree);
    corto_threadTlsKey(&CORTO_KEY_FLOW, NULL);
    void corto_threadStringDealloc(void *data);
    corto_threadTlsKey(&CORTO_KEY_THREAD_STRING, corto_threadStringDealloc);
    corto_threadTlsKey(&CORTO_KEY_MOUNT_RESULT, NULL);

    /* Initialize OLS keys */
    CORTO_OLS_REPLICATOR = corto_olsKey(NULL);
    CORTO_OLS_AUGMENT = corto_olsKey(NULL);

    /* Register CDECL as first binding */
    if (corto_callRegister(corto_cdeclInit, corto_cdeclDeinit) != CORTO_PROCEDURE_CDECL) {
        /* Sanity check */
        corto_critical("CDECL binding did not register with id 1");
    }

    /* Init admin-lock */
    corto_mutexNew(&corto_adminLock);

    /* Bootstrap sizes of types used in parameters, these are used to determine
     * argument-stack sizes for functions during function::construct. */
    corto_type(corto_string_o)->size = sizeof(corto_string);
    corto_type(corto_int32_o)->size = sizeof(corto_int32);
    corto_type(corto_uint32_o)->size = sizeof(corto_uint32);
    corto_type(corto_any_o)->size = sizeof(corto_any);
    corto_type(corto_state_o)->size = sizeof(corto_state);
    corto_type(corto_attr_o)->size = sizeof(corto_attr);

    /* Initialize builtin scopes */
    corto_initObject(root_o);
    corto_initObject(corto_o);
    corto_initObject(corto_lang_o);
    corto_initObject(corto_core_o);
    corto_initObject(corto_native_o);
    corto_initObject(corto_secure_o);

    /* Define builtin scopes */
    corto_defineObject(root_o);
    corto_defineObject(corto_o);
    corto_defineObject(corto_lang_o);
    corto_defineObject(corto_core_o);
    corto_defineObject(corto_native_o);
    corto_defineObject(corto_secure_o);

    /* Init objects */
    SSO_OP_TYPE(corto_initType);
    SSO_OP_OBJECT(corto_initObject);
    SSO_OP_OBJECT_2ND(corto_initObject);

    /* Patch sequences- these aren't set statically since sequences are
     * allocated on the heap */
    corto_patchSequences();

    /* Construct objects */
    SSO_OP_OBJECT_2ND(corto_defineObject);
    SSO_OP_OBJECT(corto_defineObject);
    SSO_OP_TYPE(corto_defineType);

    /* Update refcounts of public members */
    SSO_OP_TYPE(corto_updateRefType);
    SSO_OP_OBJECT(corto_updateRef);
    SSO_OP_OBJECT_2ND(corto_updateRef);

    /* Initialize conversions and operators */
#ifdef CORTO_CONVERSIONS
    corto_convertInit();
#endif
#ifdef CORTO_OPERATORS
    corto_operatorInit();
#endif

    /* Register exit-handler */
    void corto_loaderOnExit(void* udata);
    corto_onexit(corto_loaderOnExit, NULL);

    /* Register library-binding */
    int corto_loadLibraryAction(corto_string file, int argc, char* argv[], void *data);
    corto_loaderRegister("so", corto_loadLibraryAction, NULL);

    int corto_fileLoader(corto_string file, int argc, char* argv[], void *data);
    corto_loaderRegister("", corto_fileLoader, NULL);

    /* Always randomize seed */
    srand (time(NULL));

    /* Init CRC table */
    corto_crcInit();

    CORTO_OPERATIONAL = 0; /* Running */

    return 0;
}

/* Register exithandler */
void corto_onexit(void(*handler)(void*), void* userData) {
    struct corto_exitHandler* h;

    h = corto_alloc(sizeof(struct corto_exitHandler));
    h->handler = handler;
    h->userData = userData;

    corto_mutexLock(&corto_adminLock);
    if (!corto_exitHandlers) {
        corto_exitHandlers = corto_llNew();
    }
    corto_llInsert(corto_exitHandlers, h);
    corto_mutexUnlock(&corto_adminLock);
}

/* Call exit-handlers */
static void corto_exit(void) {
    struct corto_exitHandler* h;

    if (corto_exitHandlers) {
        while((h = corto_llTakeFirst(corto_exitHandlers))) {
            h->handler(h->userData);
            corto_dealloc(h);
        }
        corto_llFree(corto_exitHandlers);
        corto_exitHandlers = NULL;
    }
}

int corto_stop(void) {

    CORTO_OPERATIONAL = 2; /* Shutting down */

    /* Drop the rootscope. This will not actually result
     * in removing the rootscope itself, but it will result in the
     * removal of all non-static objects. */
    corto_drop(root_o, FALSE);
    corto_release(root_o);

    /* Call exithandlers */
    corto_exit();

    /* Decrease refcounts of public members */
    SSO_OP_TYPE(corto_decreaseRefType);
    SSO_OP_OBJECT(corto_decreaseRef);
    SSO_OP_OBJECT_2ND(corto_decreaseRef);

    /* Destruct objects */
    SSO_OP_TYPE(corto_deleteType);
    SSO_OP_OBJECT(corto_deleteObject);
    SSO_OP_OBJECT_2ND(corto_deleteObject);
    corto_destruct(corto_o, FALSE);

    /* Free objects */
    SSO_OP_OBJECT_2ND(corto_releaseObject);
    SSO_OP_OBJECT(corto_releaseObject);
    SSO_OP_TYPE(corto_releaseType);

    /* Deinitialize core loader */
    if (corto__freeSSO(corto_native_o)) goto error;
    if (corto__freeSSO(corto_core_o)) goto error;
    if (corto__freeSSO(corto_lang_o)) goto error;
    if (corto__freeSSO(corto_o)) goto error;
    if (corto__freeSSO(root_o)) goto error;

    /* Deinit adminLock */
    corto_mutexFree(&corto_adminLock);

    /* Workaround for dlopen-leakage - with this statement the valgrind memory-logging is clean. */
    /*pthread_exit(NULL);*/

    CORTO_OPERATIONAL = 3; /* Shut down */

    return 0;
error:
    return -1;
}

corto_string corto_getBuild(void) {
    return CORTO_BUILD;
}

#define CORTO_CHECKBUILTIN(builtinobj)\
    if (o == builtinobj) return TRUE;

#define CORTO_CHECKBUILTIN_ARG(builtinobj, n)\
    if (o == builtinobj) return TRUE;

corto_bool corto_isbuiltin(corto_object o) {
    if (o == root_o) return TRUE;
    if (o == corto_o) return TRUE;
    if (o == corto_lang_o) return TRUE;
    SSO_OP_TYPE(CORTO_CHECKBUILTIN_ARG);
    SSO_OP_OBJECT(CORTO_CHECKBUILTIN);
    SSO_OP_OBJECT_2ND(CORTO_CHECKBUILTIN);
    return FALSE;
}
