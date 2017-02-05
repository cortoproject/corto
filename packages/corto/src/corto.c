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
void corto_subscriberAdminFree(void *admin);
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
#define VERSION_PATCH "16"
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
corto_rwmutex_s corto_subscriberLock;

/* Actions to be run at shutdown */
static corto_ll corto_exitHandlers = NULL;

/* TLS keys */
corto_threadKey CORTO_KEY_OBSERVER_ADMIN;
corto_threadKey CORTO_KEY_SUBSCRIBER_ADMIN;
corto_threadKey CORTO_KEY_DECLARED_ADMIN;
corto_threadKey CORTO_KEY_LISTEN_ADMIN;
corto_threadKey CORTO_KEY_OWNER;
corto_threadKey CORTO_KEY_ATTR;
corto_threadKey CORTO_KEY_FLUENT;
corto_threadKey CORTO_KEY_THREAD_STRING;
corto_threadKey CORTO_KEY_MOUNT_RESULT;

/* OLS keys */
corto_int8 CORTO_OLS_REPLICATOR;
corto_int8 CORTO_OLS_AUGMENT;

/* variables that control verbosity of logging functions */
int8_t CORTO_DEBUG_ENABLED = 0;

/* When set, the core traces memory management information for this object */
corto_object CORTO_TRACE_OBJECT = NULL;
corto_string CORTO_TRACE_ID = NULL;

/* When set, the core traces notifications */
int8_t CORTO_TRACE_NOTIFICATIONS = 0;

/* When set, the core adds backtraces to memory tracing */
int8_t CORTO_BACKTRACE_ENABLED = 0;

/* When set, the core will break at the specified id */
int32_t CORTO_MEMTRACE_BREAKPOINT;

/* Benchmark tags */
int CORTO_BENCHMARK_DECLARE;
int CORTO_BENCHMARK_DECLARECHILD;
int CORTO_BENCHMARK_INIT;
int CORTO_BENCHMARK_FUNCTION_INIT;
int CORTO_BENCHMARK_METHOD_INIT;
int CORTO_BENCHMARK_DEFINE;
int CORTO_BENCHMARK_DELETE;
int CORTO_BENCHMARK_RESOLVE;

int S_B_NOTIFY;
int S_B_INIT;
int S_B_FINI;
int S_B_MATCH;
int S_B_PATHID;
int S_B_INVOKE;
int S_B_MATCHPARENT;
int S_B_CONTENTTYPE;

/*
 * Indicator for whether corto is operational
 * 0 = running
 * 1 = initializing
 * 2 = deinitializing
 * 3 = stopped
 */

int8_t CORTO_OPERATIONAL = 3;

static corto_string CORTO_BUILD = __DATE__ " " __TIME__;

#define SSO_OBJECT(obj) CORTO_OFFSET(&obj##__o, sizeof(corto_SSO))
#define SSO_OP_VOID(parent, obj) {SSO_OBJECT(parent##obj), 0}
#define SSO_OP_VALUE(parent, obj) {SSO_OBJECT(parent##obj), sizeof(corto_##obj)}
#define SSO_OP_CLASS(parent, obj) {SSO_OBJECT(parent##obj), sizeof(struct corto_##obj##_s)}
#define SSO_OP_OBJ(obj) {SSO_OBJECT(obj), 0}

/* The ordering of the lists of objects below is important to ensure correct
 * initialization\construction\destruction of objects. Especially the latter one
 * is tricky, since during destruction callback-vtables are destroyed, which in turn
 * contain the pointers to the destruct functions.
 */

/* Tier 1 objects */
#define SSO_OP_TYPE()\
    SSO_OP_VALUE(lang_, octet),\
    SSO_OP_VALUE(lang_, bool),\
    SSO_OP_VALUE(lang_, char),\
    SSO_OP_VALUE(lang_, uint8),\
    SSO_OP_VALUE(lang_, uint16),\
    SSO_OP_VALUE(lang_, uint32),\
    SSO_OP_VALUE(lang_, uint64),\
    SSO_OP_VALUE(lang_, int8),\
    SSO_OP_VALUE(lang_, int16),\
    SSO_OP_VALUE(lang_, int32),\
    SSO_OP_VALUE(lang_, int64),\
    SSO_OP_VALUE(lang_, float32),\
    SSO_OP_VALUE(lang_, float64),\
    SSO_OP_VALUE(lang_, string),\
    SSO_OP_VALUE(lang_, word),\
    SSO_OP_VALUE(lang_, constant),\
    SSO_OP_VALUE(lang_, any),\
    SSO_OP_VOID(lang_, void),\
    SSO_OP_VALUE(lang_, object),\
    SSO_OP_VALUE(lang_, width),\
    SSO_OP_VALUE(lang_, typeKind),\
    SSO_OP_VALUE(lang_, primitiveKind),\
    SSO_OP_VALUE(lang_, compositeKind),\
    SSO_OP_VALUE(lang_, collectionKind),\
    SSO_OP_VALUE(lang_, procedureKind),\
    SSO_OP_VALUE(lang_, equalityKind),\
    SSO_OP_VALUE(core_, operatorKind),\
    SSO_OP_VALUE(core_, mountKind),\
    SSO_OP_VALUE(core_, frameKind),\
    SSO_OP_VALUE(,secure_accessKind),\
    SSO_OP_VALUE(,secure_actionKind),\
    SSO_OP_VALUE(lang_, modifier),\
    SSO_OP_VALUE(core_, eventMask),\
    SSO_OP_VALUE(lang_, state),\
    SSO_OP_VALUE(lang_, attr),\
    SSO_OP_VALUE(lang_, int32seq),\
    SSO_OP_VALUE(lang_, wordseq),\
    SSO_OP_VALUE(lang_, objectseq),\
    SSO_OP_VALUE(lang_, interfaceseq),\
    SSO_OP_VALUE(lang_, parameterseq),\
    SSO_OP_VALUE(lang_, stringseq),\
    SSO_OP_VALUE(core_, augmentseq),\
    SSO_OP_VALUE(lang_, interfaceVectorseq),\
    SSO_OP_VALUE(lang_, interfaceVector),\
    SSO_OP_VALUE(lang_, objectlist),\
    SSO_OP_VALUE(lang_, stringlist),\
    SSO_OP_VALUE(core_, resultList),\
    SSO_OP_VALUE(core_, mountSubscriptionList),\
    SSO_OP_VALUE(lang_, parameter),\
    SSO_OP_VALUE(lang_, typeOptions),\
    SSO_OP_VALUE(core_, augmentData),\
    SSO_OP_VALUE(core_, frame),\
    SSO_OP_VALUE(core_, result),\
    SSO_OP_VALUE(core_, request),\
    SSO_OP_VALUE(core_, mountStats),\
    SSO_OP_VALUE(core_, mountPolicy),\
    SSO_OP_VALUE(core_, mountSubscription),\
    SSO_OP_VALUE(lang_, delegatedata),\
    SSO_OP_VOID(core_, dispatcher),\
    SSO_OP_VALUE(lang_, initAction),\
    SSO_OP_VALUE(lang_, nameAction),\
    SSO_OP_VALUE(lang_, destructAction),\
    SSO_OP_VALUE(core_, resultIter),\
    SSO_OP_VALUE(core_, objectIter),\
    SSO_OP_VALUE(core_, time),\
    SSO_OP_VALUE(core_, position),\
    SSO_OP_CLASS(lang_, function),\
    SSO_OP_CLASS(lang_, method),\
    SSO_OP_CLASS(lang_, virtual),\
    SSO_OP_CLASS(core_, remote),\
    SSO_OP_CLASS(core_, observer),\
    SSO_OP_CLASS(core_, subscriber),\
    SSO_OP_CLASS(lang_, metaprocedure),\
    SSO_OP_CLASS(core_, route),\
    SSO_OP_CLASS(lang_, type),\
    SSO_OP_CLASS(lang_, primitive),\
    SSO_OP_CLASS(lang_, interface),\
    SSO_OP_CLASS(lang_, collection),\
    SSO_OP_CLASS(lang_, iterator),\
    SSO_OP_CLASS(lang_, struct),\
    SSO_OP_CLASS(lang_, union),\
    SSO_OP_CLASS(core_, event),\
    SSO_OP_CLASS(core_, observableEvent),\
    SSO_OP_CLASS(core_, subscriberEvent),\
    SSO_OP_CLASS(core_, invokeEvent),\
    SSO_OP_CLASS(lang_, binary),\
    SSO_OP_CLASS(lang_, boolean),\
    SSO_OP_CLASS(lang_, character),\
    SSO_OP_CLASS(lang_, int),\
    SSO_OP_CLASS(lang_, uint),\
    SSO_OP_CLASS(lang_, float),\
    SSO_OP_CLASS(lang_, text),\
    SSO_OP_CLASS(lang_, enum),\
    SSO_OP_CLASS(lang_, bitmask),\
    SSO_OP_CLASS(lang_, array),\
    SSO_OP_CLASS(lang_, sequence),\
    SSO_OP_CLASS(lang_, list),\
    SSO_OP_CLASS(lang_, map),\
    SSO_OP_CLASS(lang_, member),\
    SSO_OP_CLASS(lang_, case),\
    SSO_OP_CLASS(lang_, default),\
    SSO_OP_CLASS(lang_, alias),\
    SSO_OP_CLASS(lang_, class),\
    SSO_OP_CLASS(lang_, procedure),\
    SSO_OP_CLASS(lang_, delegate),\
    SSO_OP_CLASS(lang_, target),\
    SSO_OP_CLASS(core_, package),\
    SSO_OP_CLASS(core_, application),\
    SSO_OP_CLASS(core_, router),\
    SSO_OP_CLASS(core_, routerimpl),\
    SSO_OP_CLASS(core_, mount),\
    SSO_OP_CLASS(core_, stager),\
    SSO_OP_CLASS(core_, loader),\
    SSO_OP_CLASS(,native_type),\
    SSO_OP_CLASS(,secure_key),\
    SSO_OP_CLASS(,secure_lock)

/* Tier 2 objects */
#define SSO_OP_OBJECT()\
    SSO_OP_OBJ(lang_class_construct_),\
    SSO_OP_OBJ(lang_class_destruct_),\
    /* constant */\
    SSO_OP_OBJ(lang_constant_init_),\
    /* function */\
    SSO_OP_OBJ(lang_function_returnType),\
    SSO_OP_OBJ(lang_function_returnsReference),\
    SSO_OP_OBJ(lang_function_overloaded),\
    SSO_OP_OBJ(lang_function_kind),\
    SSO_OP_OBJ(lang_function_impl),\
    SSO_OP_OBJ(lang_function_fptr),\
    SSO_OP_OBJ(lang_function_fdata),\
    SSO_OP_OBJ(lang_function_resource),\
    SSO_OP_OBJ(lang_function_size),\
    SSO_OP_OBJ(lang_function_parameters),\
    SSO_OP_OBJ(lang_function_nextParameterId),\
    SSO_OP_OBJ(lang_function_init_),\
    SSO_OP_OBJ(lang_function_construct_),\
    SSO_OP_OBJ(lang_function_destruct_),\
    SSO_OP_OBJ(lang_function_stringToParameterSeq),\
    SSO_OP_OBJ(lang_function_parseParamString_),\
    /* method */\
    SSO_OP_OBJ(lang_method_virtual),\
    SSO_OP_OBJ(lang_method_init_),\
    SSO_OP_OBJ(lang_method_construct_),\
    /* virtual */\
    SSO_OP_OBJ(lang_virtual_init_),\
    /* observer */\
    SSO_OP_OBJ(core_observer_mask),\
    SSO_OP_OBJ(core_observer_observable),\
    SSO_OP_OBJ(core_observer_instance),\
    SSO_OP_OBJ(core_observer_dispatcher),\
    SSO_OP_OBJ(core_observer_type),\
    SSO_OP_OBJ(core_observer_enabled),\
    SSO_OP_OBJ(core_observer_active),\
    SSO_OP_OBJ(core_observer_typeReference),\
    SSO_OP_OBJ(core_observer_init_),\
    SSO_OP_OBJ(core_observer_construct_),\
    SSO_OP_OBJ(core_observer_destruct_),\
    SSO_OP_OBJ(core_observer_observe_),\
    SSO_OP_OBJ(core_observer_unobserve_),\
    SSO_OP_OBJ(core_observer_observing_),\
    /* metaprocedure */\
    SSO_OP_OBJ(lang_metaprocedure_referenceOnly),\
    SSO_OP_OBJ(lang_metaprocedure_construct_),\
    /* route */\
    SSO_OP_OBJ(core_route_pattern),\
    SSO_OP_OBJ(core_route_elements),\
    SSO_OP_OBJ(core_route_init_),\
    SSO_OP_OBJ(core_route_construct_),\
    /* dispatcher */\
    SSO_OP_OBJ(core_dispatcher_post),\
    /* event */\
    SSO_OP_OBJ(core_event_kind),\
    SSO_OP_OBJ(core_event_handled),\
    SSO_OP_OBJ(core_event_handle_),\
    SSO_OP_OBJ(core_event_uniqueKind),\
    /* observableEvent */\
    SSO_OP_OBJ(core_observableEvent_observer),\
    SSO_OP_OBJ(core_observableEvent_me),\
    SSO_OP_OBJ(core_observableEvent_source),\
    SSO_OP_OBJ(core_observableEvent_observable),\
    SSO_OP_OBJ(core_observableEvent_mask),\
    SSO_OP_OBJ(core_observableEvent_thread),\
    SSO_OP_OBJ(core_observableEvent_handle_),\
    /* subscriberEvent */\
    SSO_OP_OBJ(core_subscriberEvent_result),\
    SSO_OP_OBJ(core_subscriberEvent_contentTypeHandle),\
    SSO_OP_OBJ(core_subscriberEvent_handle_),\
    SSO_OP_OBJ(core_subscriberEvent_construct_),\
    SSO_OP_OBJ(core_subscriberEvent_destruct_),\
    /* invokeEvent */\
    SSO_OP_OBJ(core_invokeEvent_mount),\
    SSO_OP_OBJ(core_invokeEvent_instance),\
    SSO_OP_OBJ(core_invokeEvent_function),\
    SSO_OP_OBJ(core_invokeEvent_args),\
    SSO_OP_OBJ(core_invokeEvent_handle_),\
    /* width */\
    SSO_OP_OBJ(lang_width_WIDTH_8),\
    SSO_OP_OBJ(lang_width_WIDTH_16),\
    SSO_OP_OBJ(lang_width_WIDTH_32),\
    SSO_OP_OBJ(lang_width_WIDTH_64),\
    SSO_OP_OBJ(lang_width_WIDTH_WORD),\
    /* typeKind */\
    SSO_OP_OBJ(lang_typeKind_VOID),\
    SSO_OP_OBJ(lang_typeKind_ANY),\
    SSO_OP_OBJ(lang_typeKind_PRIMITIVE),\
    SSO_OP_OBJ(lang_typeKind_COMPOSITE),\
    SSO_OP_OBJ(lang_typeKind_COLLECTION),\
    SSO_OP_OBJ(lang_typeKind_ITERATOR),\
    /* primitiveKind */\
    SSO_OP_OBJ(lang_primitiveKind_BINARY),\
    SSO_OP_OBJ(lang_primitiveKind_BOOLEAN),\
    SSO_OP_OBJ(lang_primitiveKind_CHARACTER),\
    SSO_OP_OBJ(lang_primitiveKind_INTEGER),\
    SSO_OP_OBJ(lang_primitiveKind_UINTEGER),\
    SSO_OP_OBJ(lang_primitiveKind_FLOAT),\
    SSO_OP_OBJ(lang_primitiveKind_TEXT),\
    SSO_OP_OBJ(lang_primitiveKind_ENUM),\
    SSO_OP_OBJ(lang_primitiveKind_BITMASK),\
    /* compositeKind */\
    SSO_OP_OBJ(lang_compositeKind_INTERFACE),\
    SSO_OP_OBJ(lang_compositeKind_STRUCT),\
    SSO_OP_OBJ(lang_compositeKind_UNION),\
    SSO_OP_OBJ(lang_compositeKind_CLASS),\
    SSO_OP_OBJ(lang_compositeKind_DELEGATE),\
    SSO_OP_OBJ(lang_compositeKind_PROCEDURE),\
    /* collectionKind */\
    SSO_OP_OBJ(lang_collectionKind_ARRAY),\
    SSO_OP_OBJ(lang_collectionKind_SEQUENCE),\
    SSO_OP_OBJ(lang_collectionKind_LIST),\
    SSO_OP_OBJ(lang_collectionKind_MAP),\
    /* procedureKind */\
    SSO_OP_OBJ(lang_procedureKind_FUNCTION),\
    SSO_OP_OBJ(lang_procedureKind_METHOD),\
    SSO_OP_OBJ(lang_procedureKind_OBSERVER),\
    SSO_OP_OBJ(lang_procedureKind_METAPROCEDURE),\
    /* equalityKind */\
    SSO_OP_OBJ(lang_equalityKind_EQ),\
    SSO_OP_OBJ(lang_equalityKind_LT),\
    SSO_OP_OBJ(lang_equalityKind_GT),\
    SSO_OP_OBJ(lang_equalityKind_NEQ),\
    /* mountKind */\
    SSO_OP_OBJ(core_mountKind_SOURCE),\
    SSO_OP_OBJ(core_mountKind_SINK),\
    SSO_OP_OBJ(core_mountKind_CACHE),\
    SSO_OP_OBJ(core_mountKind_HISTORIAN),\
    /* frameKind */\
    SSO_OP_OBJ(core_frameKind_FRAME_NOW),\
    SSO_OP_OBJ(core_frameKind_FRAME_TIME),\
    SSO_OP_OBJ(core_frameKind_FRAME_DURATION),\
    SSO_OP_OBJ(core_frameKind_FRAME_SAMPLE),\
    SSO_OP_OBJ(core_frameKind_FRAME_DEPTH),\
    /* accessKind */\
    SSO_OP_OBJ(secure_accessKind_SECURE_ACCESS_GRANTED),\
    SSO_OP_OBJ(secure_accessKind_SECURE_ACCESS_DENIED),\
    SSO_OP_OBJ(secure_accessKind_SECURE_ACCESS_UNDEFINED),\
    /* actionKind */\
    SSO_OP_OBJ(secure_actionKind_SECURE_ACTION_CREATE),\
    SSO_OP_OBJ(secure_actionKind_SECURE_ACTION_READ),\
    SSO_OP_OBJ(secure_actionKind_SECURE_ACTION_UPDATE),\
    SSO_OP_OBJ(secure_actionKind_SECURE_ACTION_DELETE),\
    /* operatorKind */\
    SSO_OP_OBJ(core_operatorKind_ASSIGN),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_ADD),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_SUB),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_MUL),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_DIV),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_MOD),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_XOR),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_OR),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_AND),\
    SSO_OP_OBJ(core_operatorKind_ASSIGN_UPDATE),\
    SSO_OP_OBJ(core_operatorKind_ADD),\
    SSO_OP_OBJ(core_operatorKind_SUB),\
    SSO_OP_OBJ(core_operatorKind_MUL),\
    SSO_OP_OBJ(core_operatorKind_DIV),\
    SSO_OP_OBJ(core_operatorKind_MOD),\
    SSO_OP_OBJ(core_operatorKind_INC),\
    SSO_OP_OBJ(core_operatorKind_DEC),\
    SSO_OP_OBJ(core_operatorKind_XOR),\
    SSO_OP_OBJ(core_operatorKind_OR),\
    SSO_OP_OBJ(core_operatorKind_AND),\
    SSO_OP_OBJ(core_operatorKind_NOT),\
    SSO_OP_OBJ(core_operatorKind_COND_OR),\
    SSO_OP_OBJ(core_operatorKind_COND_AND),\
    SSO_OP_OBJ(core_operatorKind_COND_NOT),\
    SSO_OP_OBJ(core_operatorKind_COND_EQ),\
    SSO_OP_OBJ(core_operatorKind_COND_NEQ),\
    SSO_OP_OBJ(core_operatorKind_COND_GT),\
    SSO_OP_OBJ(core_operatorKind_COND_LT),\
    SSO_OP_OBJ(core_operatorKind_COND_GTEQ),\
    SSO_OP_OBJ(core_operatorKind_COND_LTEQ),\
    SSO_OP_OBJ(core_operatorKind_SHIFT_LEFT),\
    SSO_OP_OBJ(core_operatorKind_SHIFT_RIGHT),\
    SSO_OP_OBJ(core_operatorKind_REF),\
    /* state */\
    SSO_OP_OBJ(lang_state_VALID),\
    SSO_OP_OBJ(lang_state_DECLARED),\
    SSO_OP_OBJ(lang_state_DEFINED),\
    SSO_OP_OBJ(lang_state_DESTRUCTED),\
    /* attr */\
    SSO_OP_OBJ(lang_attr_ATTR_SCOPED),\
    SSO_OP_OBJ(lang_attr_ATTR_WRITABLE),\
    SSO_OP_OBJ(lang_attr_ATTR_OBSERVABLE),\
    SSO_OP_OBJ(lang_attr_ATTR_PERSISTENT),\
    SSO_OP_OBJ(lang_attr_ATTR_DEFAULT),\
    /* eventKind */\
    SSO_OP_OBJ(core_eventMask_ON_DECLARE),\
    SSO_OP_OBJ(core_eventMask_ON_DEFINE),\
    SSO_OP_OBJ(core_eventMask_ON_DELETE),\
    SSO_OP_OBJ(core_eventMask_ON_INVALIDATE),\
    SSO_OP_OBJ(core_eventMask_ON_UPDATE),\
    SSO_OP_OBJ(core_eventMask_ON_RESUME),\
    SSO_OP_OBJ(core_eventMask_ON_SUSPEND),\
    SSO_OP_OBJ(core_eventMask_ON_SELF),\
    SSO_OP_OBJ(core_eventMask_ON_SCOPE),\
    SSO_OP_OBJ(core_eventMask_ON_TREE),\
    SSO_OP_OBJ(core_eventMask_ON_VALUE),\
    SSO_OP_OBJ(core_eventMask_ON_METAVALUE),\
    /* modifier */\
    SSO_OP_OBJ(lang_modifier_GLOBAL),\
    SSO_OP_OBJ(lang_modifier_LOCAL),\
    SSO_OP_OBJ(lang_modifier_PRIVATE),\
    SSO_OP_OBJ(lang_modifier_READONLY),\
    SSO_OP_OBJ(lang_modifier_CONST),\
    SSO_OP_OBJ(lang_modifier_HIDDEN),\
    SSO_OP_OBJ(lang_modifier_OPTIONAL),\
    SSO_OP_OBJ(lang_modifier_OBSERVABLE),\
    /* typeOptions */\
    SSO_OP_OBJ(lang_typeOptions_parentType),\
    SSO_OP_OBJ(lang_typeOptions_parentState),\
    SSO_OP_OBJ(lang_typeOptions_defaultType),\
    SSO_OP_OBJ(lang_typeOptions_defaultProcedureType),\
    /* type */\
    SSO_OP_OBJ(lang_type_kind),\
    SSO_OP_OBJ(lang_type_reference),\
    SSO_OP_OBJ(lang_type_attr),\
    SSO_OP_OBJ(lang_type_options),\
    SSO_OP_OBJ(lang_type_hasResources),\
    SSO_OP_OBJ(lang_type_hasTarget),\
    SSO_OP_OBJ(lang_type_size),\
    SSO_OP_OBJ(lang_type_alignment),\
    SSO_OP_OBJ(lang_type_metaprocedures),\
    SSO_OP_OBJ(lang_type_init),\
    SSO_OP_OBJ(lang_type_nameof),\
    SSO_OP_OBJ(lang_type_sizeof_),\
    SSO_OP_OBJ(lang_type_alignmentof_),\
    SSO_OP_OBJ(lang_type_compatible_),\
    SSO_OP_OBJ(lang_type_resolveProcedure_),\
    SSO_OP_OBJ(lang_type_castable_),\
    SSO_OP_OBJ(lang_type_init_),\
    SSO_OP_OBJ(lang_type_construct_),\
    SSO_OP_OBJ(lang_type_destruct_),\
    /* primitive */\
    SSO_OP_OBJ(lang_primitive_kind),\
    SSO_OP_OBJ(lang_primitive_width),\
    SSO_OP_OBJ(lang_primitive_convertId),\
    SSO_OP_OBJ(lang_primitive_init_),\
    SSO_OP_OBJ(lang_primitive_construct_),\
    SSO_OP_OBJ(lang_primitive_compatible_),\
    SSO_OP_OBJ(lang_primitive_castable_),\
    SSO_OP_OBJ(lang_primitive_isInteger_),\
    SSO_OP_OBJ(lang_primitive_isNumber_),\
    /* interface */\
    SSO_OP_OBJ(lang_interface_kind),\
    SSO_OP_OBJ(lang_interface_nextMemberId),\
    SSO_OP_OBJ(lang_interface_members),\
    SSO_OP_OBJ(lang_interface_methods),\
    SSO_OP_OBJ(lang_interface_base),\
    SSO_OP_OBJ(lang_interface_init_),\
    SSO_OP_OBJ(lang_interface_construct_),\
    SSO_OP_OBJ(lang_interface_destruct_),\
    SSO_OP_OBJ(lang_interface_resolveMember_),\
    SSO_OP_OBJ(lang_interface_compatible_),\
    SSO_OP_OBJ(lang_interface_resolveMethod_),\
    SSO_OP_OBJ(lang_interface_resolveMethodId_),\
    SSO_OP_OBJ(lang_interface_resolveMethodById_),\
    SSO_OP_OBJ(lang_interface_bindMethod_),\
    SSO_OP_OBJ(lang_interface_baseof_),\
    /* collection */\
    SSO_OP_OBJ(lang_collection_kind),\
    SSO_OP_OBJ(lang_collection_elementType),\
    SSO_OP_OBJ(lang_collection_max),\
    SSO_OP_OBJ(lang_collection_castable_),\
    SSO_OP_OBJ(lang_collection_compatible_),\
    SSO_OP_OBJ(lang_collection_requiresAlloc),\
    SSO_OP_OBJ(lang_collection_init_),\
    /* iterator */\
    SSO_OP_OBJ(lang_iterator_elementType),\
    SSO_OP_OBJ(lang_iterator_init_),\
    SSO_OP_OBJ(lang_iterator_castable_),\
    SSO_OP_OBJ(lang_iterator_compatible_),\
    /* binary */\
    SSO_OP_OBJ(lang_binary_init_),\
    /* boolean */\
    SSO_OP_OBJ(lang_boolean_init_),\
    /* char */\
    SSO_OP_OBJ(lang_character_init_),\
    /* int */\
    SSO_OP_OBJ(lang_int_min),\
    SSO_OP_OBJ(lang_int_max),\
    SSO_OP_OBJ(lang_int_init_),\
    /* uint */\
    SSO_OP_OBJ(lang_uint_min),\
    SSO_OP_OBJ(lang_uint_max),\
    SSO_OP_OBJ(lang_uint_init_),\
    /* float */\
    SSO_OP_OBJ(lang_float_min),\
    SSO_OP_OBJ(lang_float_max),\
    SSO_OP_OBJ(lang_float_init_),\
    /* text */\
    SSO_OP_OBJ(lang_text_charWidth),\
    SSO_OP_OBJ(lang_text_length),\
    SSO_OP_OBJ(lang_text_init_),\
    /* enum */\
    SSO_OP_OBJ(lang_enum_constants),\
    SSO_OP_OBJ(lang_enum_constant_),\
    SSO_OP_OBJ(lang_enum_init_),\
    SSO_OP_OBJ(lang_enum_construct_),\
    SSO_OP_OBJ(lang_enum_destruct_),\
    /* bitmask */\
    SSO_OP_OBJ(lang_bitmask_init_),\
    /* struct */\
    SSO_OP_OBJ(lang_struct_base),\
    SSO_OP_OBJ(lang_struct_baseAccess),\
    SSO_OP_OBJ(lang_struct_init_),\
    SSO_OP_OBJ(lang_struct_construct_),\
    SSO_OP_OBJ(lang_struct_compatible_),\
    SSO_OP_OBJ(lang_struct_castable_),\
    SSO_OP_OBJ(lang_struct_resolveMember_),\
    /* union */\
    SSO_OP_OBJ(lang_union_discriminator),\
    SSO_OP_OBJ(lang_union_init_),\
    SSO_OP_OBJ(lang_union_construct_),\
    SSO_OP_OBJ(lang_union_findCase_),\
    /* procedure */\
    SSO_OP_OBJ(lang_procedure_kind),\
    SSO_OP_OBJ(lang_procedure_init_),\
    /* interfaceVector */\
    SSO_OP_OBJ(lang_interfaceVector_interface),\
    SSO_OP_OBJ(lang_interfaceVector_vector),\
    /* class */\
    SSO_OP_OBJ(lang_class_base),\
    SSO_OP_OBJ(lang_class_baseAccess),\
    SSO_OP_OBJ(lang_class_implements),\
    SSO_OP_OBJ(lang_class_interfaceVector),\
    SSO_OP_OBJ(lang_class_construct),\
    SSO_OP_OBJ(lang_class_destruct),\
    SSO_OP_OBJ(lang_class_init_),\
    SSO_OP_OBJ(lang_class_instanceof_),\
    SSO_OP_OBJ(lang_class_resolveInterfaceMethod_),\
    /* mountStats */\
    SSO_OP_OBJ(core_mountStats_declares),\
    SSO_OP_OBJ(core_mountStats_updates),\
    SSO_OP_OBJ(core_mountStats_deletes),\
    /* mountPolicy */\
    SSO_OP_OBJ(core_mountPolicy_sampleRate),\
    /* mountSubscription */\
    SSO_OP_OBJ(core_mountSubscription_parent),\
    SSO_OP_OBJ(core_mountSubscription_expr),\
    SSO_OP_OBJ(core_mountSubscription_mask),\
    SSO_OP_OBJ(core_mountSubscription_count),\
    SSO_OP_OBJ(core_mountSubscription_userData),\
    /* subscriber */\
    SSO_OP_OBJ(core_subscriber_mask),\
    SSO_OP_OBJ(core_subscriber_parent),\
    SSO_OP_OBJ(core_subscriber_expr),\
    SSO_OP_OBJ(core_subscriber_contentType),\
    SSO_OP_OBJ(core_subscriber_instance),\
    SSO_OP_OBJ(core_subscriber_dispatcher),\
    SSO_OP_OBJ(core_subscriber_type),\
    SSO_OP_OBJ(core_subscriber_enabled),\
    SSO_OP_OBJ(core_subscriber_contentTypeHandle),\
    SSO_OP_OBJ(core_subscriber_matchProgram),\
    SSO_OP_OBJ(core_subscriber_init_),\
    SSO_OP_OBJ(core_subscriber_construct_),\
    SSO_OP_OBJ(core_subscriber_destruct_),\
    SSO_OP_OBJ(core_subscriber_subscribe_),\
    SSO_OP_OBJ(core_subscriber_unsubscribe_),\
    /* router */\
    SSO_OP_OBJ(core_router_init_),\
    SSO_OP_OBJ(core_router_construct_),\
    SSO_OP_OBJ(core_router_match),\
    SSO_OP_OBJ(core_router_returnType),\
    SSO_OP_OBJ(core_router_paramType),\
    SSO_OP_OBJ(core_router_paramName),\
    SSO_OP_OBJ(core_router_elementSeparator),\
    /* routerimpl */\
    SSO_OP_OBJ(core_routerimpl_construct_),\
    SSO_OP_OBJ(core_routerimpl_destruct_),\
    SSO_OP_OBJ(core_routerimpl_maxArgs),\
    SSO_OP_OBJ(core_routerimpl_matchRoute_),\
    /* mount */\
    SSO_OP_OBJ(core_mount_kind),\
    SSO_OP_OBJ(core_mount_parent),\
    SSO_OP_OBJ(core_mount_expr),\
    SSO_OP_OBJ(core_mount_type),\
    SSO_OP_OBJ(core_mount_contentType),\
    SSO_OP_OBJ(core_mount_policy),\
    SSO_OP_OBJ(core_mount_mount),\
    SSO_OP_OBJ(core_mount_attr),\
    SSO_OP_OBJ(core_mount_sent),\
    SSO_OP_OBJ(core_mount_received),\
    SSO_OP_OBJ(core_mount_sentDiscarded),\
    SSO_OP_OBJ(core_mount_policies),\
    SSO_OP_OBJ(core_mount_subscriptions),\
    SSO_OP_OBJ(core_mount_events),\
    SSO_OP_OBJ(core_mount_passThrough),\
    SSO_OP_OBJ(core_mount_thread),\
    SSO_OP_OBJ(core_mount_quit),\
    SSO_OP_OBJ(core_mount_hasNotify),\
    SSO_OP_OBJ(core_mount_hasResume),\
    SSO_OP_OBJ(core_mount_hasSubscribe),\
    SSO_OP_OBJ(core_mount_contentTypeOut),\
    SSO_OP_OBJ(core_mount_contentTypeOutHandle),\
    SSO_OP_OBJ(core_mount_init_),\
    SSO_OP_OBJ(core_mount_construct_),\
    SSO_OP_OBJ(core_mount_destruct_),\
    SSO_OP_OBJ(core_mount_invoke_),\
    SSO_OP_OBJ(core_mount_request_),\
    SSO_OP_OBJ(core_mount_resume_),\
    SSO_OP_OBJ(core_mount_subscribe_),\
    SSO_OP_OBJ(core_mount_unsubscribe_),\
    SSO_OP_OBJ(core_mount_setContentType_),\
    SSO_OP_OBJ(core_mount_setContentTypeIn_),\
    SSO_OP_OBJ(core_mount_setContentTypeOut_),\
    SSO_OP_OBJ(core_mount_return_),\
    SSO_OP_OBJ(core_mount_post_),\
    SSO_OP_OBJ(core_mount_onPoll_),\
    SSO_OP_OBJ(core_mount_onNotify_),\
    SSO_OP_OBJ(core_mount_onInvoke_),\
    SSO_OP_OBJ(core_mount_onRequest_),\
    SSO_OP_OBJ(core_mount_onResume_),\
    SSO_OP_OBJ(core_mount_onSubscribe_),\
    SSO_OP_OBJ(core_mount_onUnsubscribe_),\
    /* loader */\
    SSO_OP_OBJ(core_loader_construct_),\
    SSO_OP_OBJ(core_loader_destruct_),\
    SSO_OP_OBJ(core_loader_onRequest_),\
    /* stager */\
    SSO_OP_OBJ(core_stager_resolver),\
    SSO_OP_OBJ(core_stager_add_),\
    SSO_OP_OBJ(core_stager_construct_),\
    SSO_OP_OBJ(core_stager_destruct_),\
    /* delegatedata */\
    SSO_OP_OBJ(lang_delegatedata_instance),\
    SSO_OP_OBJ(lang_delegatedata_procedure),\
    /* delegate */\
    SSO_OP_OBJ(lang_delegate_returnType),\
    SSO_OP_OBJ(lang_delegate_returnsReference),\
    SSO_OP_OBJ(lang_delegate_parameters),\
    SSO_OP_OBJ(lang_delegate_init_),\
    SSO_OP_OBJ(lang_delegate_compatible_),\
    SSO_OP_OBJ(lang_delegate_castable_),\
    SSO_OP_OBJ(lang_delegate_instanceof_),\
    SSO_OP_OBJ(lang_delegate_construct),\
    /* target */\
    SSO_OP_OBJ(lang_target_type),\
    SSO_OP_OBJ(lang_target_construct_),\
    /* array */\
    SSO_OP_OBJ(lang_array_elementType),\
    SSO_OP_OBJ(lang_array_init_),\
    SSO_OP_OBJ(lang_array_construct_),\
    SSO_OP_OBJ(lang_array_destruct_),\
    /* sequence */\
    SSO_OP_OBJ(lang_sequence_init_),\
    SSO_OP_OBJ(lang_sequence_construct_),\
    /* list */\
    SSO_OP_OBJ(lang_list_init_),\
    SSO_OP_OBJ(lang_list_construct_),\
    /* map */\
    SSO_OP_OBJ(lang_map_elementType),\
    SSO_OP_OBJ(lang_map_keyType),\
    SSO_OP_OBJ(lang_map_max),\
    SSO_OP_OBJ(lang_map_init_),\
    SSO_OP_OBJ(lang_map_construct_),\
    /* member */\
    SSO_OP_OBJ(lang_member_type),\
    SSO_OP_OBJ(lang_member_modifiers),\
    SSO_OP_OBJ(lang_member_state),\
    SSO_OP_OBJ(lang_member_stateCondExpr),\
    SSO_OP_OBJ(lang_member_weak),\
    SSO_OP_OBJ(lang_member_id),\
    SSO_OP_OBJ(lang_member_offset),\
    SSO_OP_OBJ(lang_member_init_),\
    SSO_OP_OBJ(lang_member_construct_),\
    /* alias */\
    SSO_OP_OBJ(lang_alias_member),\
    SSO_OP_OBJ(lang_alias_init_),\
    SSO_OP_OBJ(lang_alias_construct_),\
    /* case */\
    SSO_OP_OBJ(lang_case_discriminator),\
    SSO_OP_OBJ(lang_case_type),\
    SSO_OP_OBJ(lang_case_construct_),\
    /* default */\
    SSO_OP_OBJ(lang_default_type),\
    SSO_OP_OBJ(lang_default_construct_),\
    /* parameter */\
    SSO_OP_OBJ(lang_parameter_name),\
    SSO_OP_OBJ(lang_parameter_type),\
    SSO_OP_OBJ(lang_parameter_passByReference),\
    /* augmentData */\
    SSO_OP_OBJ(core_augmentData_id),\
    SSO_OP_OBJ(core_augmentData_data),\
    /* result */\
    SSO_OP_OBJ(core_result_id),\
    SSO_OP_OBJ(core_result_name),\
    SSO_OP_OBJ(core_result_parent),\
    SSO_OP_OBJ(core_result_type),\
    SSO_OP_OBJ(core_result_value),\
    SSO_OP_OBJ(core_result_leaf),\
    SSO_OP_OBJ(core_result_object),\
    SSO_OP_OBJ(core_result_history),\
    SSO_OP_OBJ(core_result_augments),\
    SSO_OP_OBJ(core_result_owner),\
    SSO_OP_OBJ(core_result_getText_),\
    SSO_OP_OBJ(core_result_fromcontent_),\
    SSO_OP_OBJ(core_result_contentof_),\
    /* request */\
    SSO_OP_OBJ(core_request_parent),\
    SSO_OP_OBJ(core_request_expr),\
    SSO_OP_OBJ(core_request_type),\
    SSO_OP_OBJ(core_request_offset),\
    SSO_OP_OBJ(core_request_limit),\
    SSO_OP_OBJ(core_request_content),\
    SSO_OP_OBJ(core_request_from),\
    SSO_OP_OBJ(core_request_to),\
    /* package */\
    SSO_OP_OBJ(core_package_url),\
    SSO_OP_OBJ(core_package_version),\
    SSO_OP_OBJ(core_package_author),\
    SSO_OP_OBJ(core_package_description),\
    SSO_OP_OBJ(core_package_env),\
    SSO_OP_OBJ(core_package_nocorto),\
    SSO_OP_OBJ(core_package_cflags),\
    SSO_OP_OBJ(core_package_dependencies),\
    SSO_OP_OBJ(core_package_prefix),\
    SSO_OP_OBJ(core_package_cortoVersion),\
    SSO_OP_OBJ(core_package_local),\
    SSO_OP_OBJ(core_package_lib),\
    SSO_OP_OBJ(core_package_libpath),\
    SSO_OP_OBJ(core_package_include),\
    SSO_OP_OBJ(core_package_link),\
    SSO_OP_OBJ(core_package_construct_),\
    /* time */\
    SSO_OP_OBJ(core_time_sec),\
    SSO_OP_OBJ(core_time_nanosec),\
    /* position */\
    SSO_OP_OBJ(core_position_latitude),\
    SSO_OP_OBJ(core_position_longitude),\
    /* frame */\
    SSO_OP_OBJ(core_frame_kind),\
    SSO_OP_OBJ(core_frame_value),\
    SSO_OP_OBJ(core_frame_getTime_),\
    /* native/type */\
    SSO_OP_OBJ(native_type_name),\
    SSO_OP_OBJ(native_type_init_),\
    /* secure/key */\
    SSO_OP_OBJ(secure_key_construct_),\
    SSO_OP_OBJ(secure_key_destruct_),\
    SSO_OP_OBJ(secure_key_authenticate_),\
    /* secure/lock */\
    SSO_OP_OBJ(secure_lock_mount),\
    SSO_OP_OBJ(secure_lock_expr),\
    SSO_OP_OBJ(secure_lock_priority),\
    SSO_OP_OBJ(secure_lock_construct_),\
    SSO_OP_OBJ(secure_lock_destruct_),\
    SSO_OP_OBJ(secure_lock_authorize_)\


typedef struct corto_bootstrapElement {
    corto_object o;
    size_t size;
} corto_bootstrapElement;

corto_bootstrapElement types[] = {
    SSO_OP_TYPE(),
    {NULL, 0}
};

corto_bootstrapElement objects[] = {
    SSO_OP_OBJECT(),
    {NULL, 0}
};

/* Creation and destruction of objects */
static void corto_createObject(corto_object o) {
    corto__newSSO(o);
}

void corto_delegateDestruct(corto_type t, corto_object o);
corto_int16 corto_delegateInit(corto_type t, corto_object o);
corto_int16 corto_delegateConstruct(corto_type t, corto_object o);

/* Initialization of objects */
static void corto_initObject(corto_object o) {
    corto_createObject(o);
    corto_delegateInit(corto_typeof(o), o);
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

/* Update references */
static void corto_updateRef(corto_object o) {
    struct corto_serializer_s s;
    s = corto_ser_keep(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_serialize(&s, o, NULL);
}

/* Decrease references */
static void corto_decreaseRef(corto_object o) {
    struct corto_serializer_s s;
    s = corto_ser_free(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_serialize(&s, o, NULL);
}

static void corto_genericTlsFree(void *o) {
    corto_dealloc(o);
}

static void corto_patchSequences(void) {
    /* Replicator implements table */
    corto_mount_o->implements.length = 1;
    corto_mount_o->implements.buffer = corto_alloc(sizeof(corto_object));
    corto_mount_o->implements.buffer[0] = corto_dispatcher_o;
}

void corto_initEnvironment(void) {
/* Only set environment variables if library is installed as corto package */
#ifndef CORTO_REDIS
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

    /* CORTO_VERSION points to the current major-minor version */
    if (!corto_getenv("CORTO_VERSION")) {
        corto_setenv("CORTO_VERSION", VERSION_MAJOR "." VERSION_MINOR);
    }
#endif

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

    corto_string traceObject = corto_getenv("CORTO_TRACE_ID");
    if (traceObject) {
        CORTO_TRACE_ID = traceObject;
    }

    corto_string enableBacktrace = corto_getenv("CORTO_BACKTRACE_ENABLED");
    if (enableBacktrace) {
        CORTO_BACKTRACE_ENABLED = !strcmp(enableBacktrace, "true");
    }
}

int corto_start(void) {
    CORTO_OPERATIONAL = 1; /* Initializing */

    /* Initialize benchmark constants */
    CORTO_BENCHMARK_DECLARE = corto_benchmark_init("corto_declare");
    CORTO_BENCHMARK_DECLARECHILD = corto_benchmark_init("corto_declareChild");
    CORTO_BENCHMARK_INIT = corto_benchmark_init("corto_init");
    CORTO_BENCHMARK_FUNCTION_INIT = corto_benchmark_init("corto_function_init");
    CORTO_BENCHMARK_METHOD_INIT = corto_benchmark_init("corto_method_init");
    CORTO_BENCHMARK_DEFINE = corto_benchmark_init("corto_define");
    CORTO_BENCHMARK_DELETE = corto_benchmark_init("corto_delete");
    CORTO_BENCHMARK_RESOLVE = corto_benchmark_init("corto_resolve");

    S_B_NOTIFY = corto_benchmark_init("S_B_NOTIFY");
    S_B_INIT = corto_benchmark_init("S_B_INIT");
    S_B_FINI = corto_benchmark_init("S_B_FINI");
    S_B_MATCH = corto_benchmark_init("S_B_MATCH");
    S_B_PATHID = corto_benchmark_init("S_B_PATHID");
    S_B_INVOKE = corto_benchmark_init("S_B_INVOKE");
    S_B_MATCHPARENT = corto_benchmark_init("S_B_MATCHPARENT");
    S_B_CONTENTTYPE = corto_benchmark_init("S_B_CONTENTTYPE");

    /* Initialize operating system environment */
    corto_initEnvironment();

    /* Initialize security */
    corto_secure_init();

    /* Initialize TLS keys */
    corto_threadTlsKey(&CORTO_KEY_OBSERVER_ADMIN, corto_observerAdminFree);
    corto_threadTlsKey(&CORTO_KEY_SUBSCRIBER_ADMIN, corto_subscriberAdminFree);
    corto_threadTlsKey(&CORTO_KEY_DECLARED_ADMIN, corto_declaredAdminFree);
    corto_threadTlsKey(&CORTO_KEY_LISTEN_ADMIN, NULL);
    corto_threadTlsKey(&CORTO_KEY_OWNER, NULL);
    corto_threadTlsKey(&CORTO_KEY_ATTR, corto_genericTlsFree);
    corto_threadTlsKey(&CORTO_KEY_FLUENT, NULL);
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
    corto_rwmutexNew(&corto_subscriberLock);

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

    corto_int32 i = 0;
    corto_object o;

    /* Init objects */
    for (i = 0; (o = types[i].o); i++) corto_initObject(o);
    for (i = 0; (o = objects[i].o); i++) corto_initObject(o);

    /* Patch sequences- these aren't set statically since sequences are
     * allocated on the heap */
    corto_patchSequences();

    /* Construct objects */
    for (i = 0; (o = objects[i].o); i++) corto_defineObject(o);
    for (i = 0; (o = types[i].o); i++) corto_defineType(o, types[i].size);

    /* Update refcounts of public members */
    for (i = 0; (o = types[i].o); i++) corto_updateRef(o);
    for (i = 0; (o = objects[i].o); i++) corto_updateRef(o);

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

    if (corto_getOwner()) {
        corto_error("owner has not been reset to NULL before shutting down");
        abort();
    }

    /* Drop the rootscope. This will not actually result
     * in removing the rootscope itself, but it will result in the
     * removal of all non-static objects. */
    corto_drop(root_o, FALSE);
    corto_release(root_o);

    /* This function calls all destructors for registered TLS keys for the main
     * thread */
    corto_threadTlsKeysDestruct();

    /* Call exithandlers */
    corto_exit();

    corto_int32 i;
    corto_object o;

    /* Decrease refcounts of public members */
    for (i = 0; (o = types[i].o); i++) corto_decreaseRef(o);
    for (i = 0; (o = objects[i].o); i++) corto_decreaseRef(o);

    /* Destruct objects */
    for (i = 0; (o = types[i].o); i++) corto_destruct(o, FALSE);
    for (i = 0; (o = objects[i].o); i++) corto_destruct(o, FALSE);

    corto_destruct(corto_o, FALSE);

    /* Free objects */
    for (i = 0; (o = objects[i].o); i++) corto__freeSSO(o);
    for (i = 0; (o = types[i].o); i++) corto__freeSSO(o);

    /* Deinitialize core loader */
    if (corto__freeSSO(corto_native_o)) goto error;
    if (corto__freeSSO(corto_core_o)) goto error;
    if (corto__freeSSO(corto_lang_o)) goto error;
    if (corto__freeSSO(corto_o)) goto error;
    if (corto__freeSSO(root_o)) goto error;

    /* Deinit adminLock */
    corto_mutexFree(&corto_adminLock);

    CORTO_OPERATIONAL = 3; /* Shut down */

    corto_benchmark_fini(CORTO_BENCHMARK_DECLARE);
    corto_benchmark_fini(CORTO_BENCHMARK_DECLARECHILD);
    corto_benchmark_fini(CORTO_BENCHMARK_INIT);
    corto_benchmark_fini(CORTO_BENCHMARK_FUNCTION_INIT);
    corto_benchmark_fini(CORTO_BENCHMARK_METHOD_INIT);
    corto_benchmark_fini(CORTO_BENCHMARK_DEFINE);
    corto_benchmark_fini(CORTO_BENCHMARK_DELETE);
    corto_benchmark_fini(CORTO_BENCHMARK_RESOLVE);

    corto_benchmark_fini(S_B_NOTIFY);
    corto_benchmark_fini(S_B_INIT);
    corto_benchmark_fini(S_B_MATCHPARENT);
    corto_benchmark_fini(S_B_MATCH);
    corto_benchmark_fini(S_B_PATHID);
    corto_benchmark_fini(S_B_CONTENTTYPE);
    corto_benchmark_fini(S_B_INVOKE);
    corto_benchmark_fini(S_B_FINI);


    return 0;
error:
    return -1;
}

corto_string corto_getBuild(void) {
    return CORTO_BUILD;
}

corto_string corto_getLibrary(void) {
    return CORTO_OBJECT_NAME;
}

#define CORTO_CHECKBUILTIN(builtinobj)\
    if (o == builtinobj) return TRUE;

#define CORTO_CHECKBUILTIN_ARG(builtinobj, n)\
    if (o == builtinobj) return TRUE;

corto_bool corto_isbuiltin(corto_object o) {
    if (o == root_o) return TRUE;
    if (o == corto_o) return TRUE;
    if (o == corto_lang_o) return TRUE;
    //SSO_OP_TYPE(CORTO_CHECKBUILTIN_ARG);
    //SSO_OP_OBJECT(CORTO_CHECKBUILTIN);
    return FALSE;
}

#ifndef NDEBUG
void corto_assertObject(corto_object o) {
    if (o) {
        corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
        if (_o->magic != CORTO_MAGIC) {
            if (_o->magic == CORTO_MAGIC_DESTRUCT) {
                corto_critical("address <%p> points to an object that is already deleted", o);
            } else {
                corto_critical("address <%p> does not point to an object", o);
            }
        }
    }
}
#endif

