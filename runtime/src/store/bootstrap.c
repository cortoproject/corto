/* Copyright (c) 2010-2017 the corto developers
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

/* Public headers */
#include <corto/corto.h>

/* Private headers */
#include "bootstrap.h"
#include "object.h"
#include "cdeclhandler.h"
#include "init_ser.h"
#include "memory_ser.h"
#include "lang/class.h"
#include "lang/interface.h"

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

#define VERSION_MAJOR "1"
#define VERSION_MINOR "3"
#define VERSION_PATCH "0"
#define VERSION_SUFFIX "beta"

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

/* Package loader */
static corto_loader corto_loaderInstance;

/* Actions to be run at shutdown */
static corto_ll corto_exitHandlers = NULL;

/* Application name */
char *corto_appName = NULL;

/* TLS keys */
corto_threadKey CORTO_KEY_OBSERVER_ADMIN;
corto_threadKey CORTO_KEY_DECLARED_ADMIN;
corto_threadKey CORTO_KEY_LISTEN_ADMIN;
corto_threadKey CORTO_KEY_OWNER;
corto_threadKey CORTO_KEY_ATTR;
corto_threadKey CORTO_KEY_FLUENT;
corto_threadKey CORTO_KEY_THREAD_STRING;
corto_threadKey CORTO_KEY_MOUNT_RESULT;
corto_threadKey CORTO_KEY_CONSTRUCTOR_TYPE;

/* Delegate object variables */
corto_member corto_type_init_o = NULL;
corto_member corto_type_deinit_o = NULL;
corto_member corto_class_construct_o = NULL;
corto_member corto_class_define_o = NULL;
corto_member corto_class_destruct_o = NULL;
corto_member corto_class_delete_o = NULL;
corto_member corto_class_validate_o = NULL;
corto_member corto_class_update_o = NULL;

/* variables that control verbosity of logging functions */
int8_t CORTO_DEBUG_ENABLED = 0;

/* When set, memory management traces are enabled for this object */
corto_object CORTO_TRACE_OBJECT = NULL;
corto_string CORTO_TRACE_ID = NULL;

/* When set, notifications are traced */
int8_t CORTO_TRACE_NOTIFICATIONS = 0;

/* When set, the runtime will break at specified breakpoint */
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
    SSO_OP_VALUE(lang_, equalityKind),\
    SSO_OP_VALUE(lang_, inout),\
    SSO_OP_VALUE(vstore_, operatorKind),\
    SSO_OP_VALUE(vstore_, ownership),\
    SSO_OP_VALUE(vstore_, mountMask),\
    SSO_OP_VALUE(vstore_, frameKind),\
    SSO_OP_VALUE(,secure_accessKind),\
    SSO_OP_VALUE(,secure_actionKind),\
    SSO_OP_VALUE(lang_, modifier),\
    SSO_OP_VALUE(vstore_, eventMask),\
    SSO_OP_VALUE(vstore_, resultMask),\
    SSO_OP_VALUE(lang_, state),\
    SSO_OP_VALUE(lang_, attr),\
    SSO_OP_VALUE(lang_, int32seq),\
    SSO_OP_VALUE(lang_, wordseq),\
    SSO_OP_VALUE(lang_, objectseq),\
    SSO_OP_VALUE(lang_, interfaceseq),\
    SSO_OP_VALUE(lang_, parameterseq),\
    SSO_OP_VALUE(lang_, stringseq),\
    SSO_OP_VALUE(lang_, interfaceVectorseq),\
    SSO_OP_VALUE(lang_, interfaceVector),\
    SSO_OP_VALUE(lang_, objectlist),\
    SSO_OP_VALUE(lang_, stringlist),\
    SSO_OP_VALUE(vstore_, resultList),\
    SSO_OP_VALUE(vstore_, mountSubscriptionList),\
    SSO_OP_VALUE(lang_, parameter),\
    SSO_OP_VALUE(lang_, typeOptions),\
    SSO_OP_VALUE(vstore_, time),\
    SSO_OP_VALUE(vstore_, frame),\
    SSO_OP_VALUE(vstore_, sample),\
    SSO_OP_VALUE(vstore_, sampleIter),\
    SSO_OP_VALUE(vstore_, subscriberEventIter),\
    SSO_OP_VALUE(vstore_, result),\
    SSO_OP_VALUE(vstore_, mountStats),\
    SSO_OP_VALUE(vstore_, queuePolicy),\
    SSO_OP_VALUE(vstore_, mountPolicy),\
    SSO_OP_VALUE(lang_, delegatedata),\
    SSO_OP_VOID(vstore_, dispatcher),\
    SSO_OP_VALUE(lang_, initAction),\
    SSO_OP_VALUE(lang_, nameAction),\
    SSO_OP_VALUE(lang_, destructAction),\
    SSO_OP_VALUE(vstore_, handleAction),\
    SSO_OP_VALUE(vstore_, resultIter),\
    SSO_OP_VALUE(vstore_, objectIter),\
    SSO_OP_VALUE(vstore_, query),\
    SSO_OP_VALUE(vstore_, mountSubscription),\
    SSO_OP_CLASS(lang_, function),\
    SSO_OP_CLASS(lang_, method),\
    SSO_OP_CLASS(lang_, overridable),\
    SSO_OP_CLASS(lang_, override),\
    SSO_OP_CLASS(vstore_, remote),\
    SSO_OP_CLASS(vstore_, observer),\
    SSO_OP_CLASS(vstore_, subscriber),\
    SSO_OP_CLASS(lang_, metaprocedure),\
    SSO_OP_CLASS(vstore_, route),\
    SSO_OP_CLASS(lang_, type),\
    SSO_OP_CLASS(lang_, primitive),\
    SSO_OP_CLASS(lang_, interface),\
    SSO_OP_CLASS(lang_, collection),\
    SSO_OP_CLASS(lang_, iterator),\
    SSO_OP_CLASS(lang_, struct),\
    SSO_OP_CLASS(lang_, union),\
    SSO_OP_VALUE(vstore_, event),\
    SSO_OP_VALUE(vstore_, observerEvent),\
    SSO_OP_VALUE(vstore_, subscriberEvent),\
    SSO_OP_VALUE(vstore_, invokeEvent),\
    SSO_OP_CLASS(lang_, binary),\
    SSO_OP_CLASS(lang_, boolean),\
    SSO_OP_CLASS(lang_, character),\
    SSO_OP_CLASS(lang_, int),\
    SSO_OP_CLASS(lang_, uint),\
    SSO_OP_CLASS(lang_, float),\
    SSO_OP_CLASS(lang_, text),\
    SSO_OP_CLASS(lang_, verbatim),\
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
    SSO_OP_CLASS(lang_, container),\
    SSO_OP_CLASS(lang_, leaf),\
    SSO_OP_CLASS(lang_, table),\
    SSO_OP_CLASS(lang_, tableinstance),\
    SSO_OP_CLASS(lang_, procedure),\
    SSO_OP_CLASS(lang_, delegate),\
    SSO_OP_CLASS(lang_, target),\
    SSO_OP_CLASS(lang_, quantity),\
    SSO_OP_CLASS(lang_, unit),\
    SSO_OP_CLASS(vstore_, package),\
    SSO_OP_CLASS(vstore_, application),\
    SSO_OP_CLASS(vstore_, tool),\
    SSO_OP_CLASS(vstore_, router),\
    SSO_OP_CLASS(vstore_, routerimpl),\
    SSO_OP_CLASS(vstore_, mount),\
    SSO_OP_CLASS(vstore_, loader),\
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
    SSO_OP_OBJ(lang_function_parameters),\
    SSO_OP_OBJ(lang_function_overridable),\
    SSO_OP_OBJ(lang_function_overloaded),\
    SSO_OP_OBJ(lang_function_kind),\
    SSO_OP_OBJ(lang_function_impl),\
    SSO_OP_OBJ(lang_function_fptr),\
    SSO_OP_OBJ(lang_function_fdata),\
    SSO_OP_OBJ(lang_function_size),\
    SSO_OP_OBJ(lang_function_init_),\
    SSO_OP_OBJ(lang_function_construct_),\
    SSO_OP_OBJ(lang_function_destruct_),\
    SSO_OP_OBJ(lang_function_stringToParameterSeq),\
    SSO_OP_OBJ(lang_function_parseParamString_),\
    /* method */\
    SSO_OP_OBJ(lang_method_init_),\
    SSO_OP_OBJ(lang_method_construct_),\
    /* overridable */\
    SSO_OP_OBJ(lang_overridable_init_),\
    /* override */\
    SSO_OP_OBJ(lang_override_init_),\
    /* observer */\
    SSO_OP_OBJ(vstore_observer_mask),\
    SSO_OP_OBJ(vstore_observer_observable),\
    SSO_OP_OBJ(vstore_observer_instance),\
    SSO_OP_OBJ(vstore_observer_dispatcher),\
    SSO_OP_OBJ(vstore_observer_type),\
    SSO_OP_OBJ(vstore_observer_enabled),\
    SSO_OP_OBJ(vstore_observer_active),\
    SSO_OP_OBJ(vstore_observer_init_),\
    SSO_OP_OBJ(vstore_observer_construct_),\
    SSO_OP_OBJ(vstore_observer_destruct_),\
    SSO_OP_OBJ(vstore_observer_observe_),\
    SSO_OP_OBJ(vstore_observer_unobserve_),\
    SSO_OP_OBJ(vstore_observer_observing_),\
    /* metaprocedure */\
    SSO_OP_OBJ(lang_metaprocedure_referenceOnly),\
    SSO_OP_OBJ(lang_metaprocedure_construct_),\
    /* route */\
    SSO_OP_OBJ(vstore_route_pattern),\
    SSO_OP_OBJ(vstore_route_elements),\
    SSO_OP_OBJ(vstore_route_init_),\
    SSO_OP_OBJ(vstore_route_construct_),\
    /* dispatcher */\
    SSO_OP_OBJ(vstore_dispatcher_post),\
    /* event */\
    SSO_OP_OBJ(vstore_event_kind),\
    SSO_OP_OBJ(vstore_event_handled),\
    SSO_OP_OBJ(vstore_event_handleAction),\
    SSO_OP_OBJ(vstore_event_handle_),\
    SSO_OP_OBJ(vstore_event_uniqueKind),\
    /* observerEvent */\
    SSO_OP_OBJ(vstore_observerEvent_observer),\
    SSO_OP_OBJ(vstore_observerEvent_instance),\
    SSO_OP_OBJ(vstore_observerEvent_source),\
    SSO_OP_OBJ(vstore_observerEvent_event),\
    SSO_OP_OBJ(vstore_observerEvent_data),\
    SSO_OP_OBJ(vstore_observerEvent_thread),\
    SSO_OP_OBJ(vstore_observerEvent_handle),\
    SSO_OP_OBJ(vstore_observerEvent_init_),\
    SSO_OP_OBJ(vstore_observerEvent_deinit_),\
    /* subscriberEvent */\
    SSO_OP_OBJ(vstore_subscriberEvent_subscriber),\
    SSO_OP_OBJ(vstore_subscriberEvent_instance),\
    SSO_OP_OBJ(vstore_subscriberEvent_source),\
    SSO_OP_OBJ(vstore_subscriberEvent_event),\
    SSO_OP_OBJ(vstore_subscriberEvent_data),\
    SSO_OP_OBJ(vstore_subscriberEvent_contentTypeHandle),\
    SSO_OP_OBJ(vstore_subscriberEvent_handle),\
    SSO_OP_OBJ(vstore_subscriberEvent_init_),\
    SSO_OP_OBJ(vstore_subscriberEvent_deinit_),\
    /* invokeEvent */\
    SSO_OP_OBJ(vstore_invokeEvent_mount),\
    SSO_OP_OBJ(vstore_invokeEvent_instance),\
    SSO_OP_OBJ(vstore_invokeEvent_function),\
    SSO_OP_OBJ(vstore_invokeEvent_args),\
    SSO_OP_OBJ(vstore_invokeEvent_handle_),\
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
    /* equalityKind */\
    SSO_OP_OBJ(lang_equalityKind_EQ),\
    SSO_OP_OBJ(lang_equalityKind_LT),\
    SSO_OP_OBJ(lang_equalityKind_GT),\
    SSO_OP_OBJ(lang_equalityKind_NEQ),\
    /* inout */\
    SSO_OP_OBJ(lang_inout_IN),\
    SSO_OP_OBJ(lang_inout_OUT),\
    SSO_OP_OBJ(lang_inout_INOUT),\
    /* ownership */\
    SSO_OP_OBJ(vstore_ownership_REMOTE_OWNER),\
    SSO_OP_OBJ(vstore_ownership_LOCAL_OWNER),\
    SSO_OP_OBJ(vstore_ownership_CACHE_OWNER),\
    /* readWrite */\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_QUERY),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_HISTORY_QUERY),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_NOTIFY),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_HISTORY_BATCH_NOTIFY),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_BATCH_NOTIFY),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_SUBSCRIBE),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_MOUNT),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_RESUME),\
    SSO_OP_OBJ(vstore_mountMask_MOUNT_INVOKE),\
    /* frameKind */\
    SSO_OP_OBJ(vstore_frameKind_FRAME_NOW),\
    SSO_OP_OBJ(vstore_frameKind_FRAME_TIME),\
    SSO_OP_OBJ(vstore_frameKind_FRAME_DURATION),\
    SSO_OP_OBJ(vstore_frameKind_FRAME_SAMPLE),\
    SSO_OP_OBJ(vstore_frameKind_FRAME_DEPTH),\
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
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_ADD),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_SUB),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_MUL),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_DIV),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_MOD),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_XOR),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_OR),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_AND),\
    SSO_OP_OBJ(vstore_operatorKind_ASSIGN_UPDATE),\
    SSO_OP_OBJ(vstore_operatorKind_ADD),\
    SSO_OP_OBJ(vstore_operatorKind_SUB),\
    SSO_OP_OBJ(vstore_operatorKind_MUL),\
    SSO_OP_OBJ(vstore_operatorKind_DIV),\
    SSO_OP_OBJ(vstore_operatorKind_MOD),\
    SSO_OP_OBJ(vstore_operatorKind_INC),\
    SSO_OP_OBJ(vstore_operatorKind_DEC),\
    SSO_OP_OBJ(vstore_operatorKind_XOR),\
    SSO_OP_OBJ(vstore_operatorKind_OR),\
    SSO_OP_OBJ(vstore_operatorKind_AND),\
    SSO_OP_OBJ(vstore_operatorKind_NOT),\
    SSO_OP_OBJ(vstore_operatorKind_COND_OR),\
    SSO_OP_OBJ(vstore_operatorKind_COND_AND),\
    SSO_OP_OBJ(vstore_operatorKind_COND_NOT),\
    SSO_OP_OBJ(vstore_operatorKind_COND_EQ),\
    SSO_OP_OBJ(vstore_operatorKind_COND_NEQ),\
    SSO_OP_OBJ(vstore_operatorKind_COND_GT),\
    SSO_OP_OBJ(vstore_operatorKind_COND_LT),\
    SSO_OP_OBJ(vstore_operatorKind_COND_GTEQ),\
    SSO_OP_OBJ(vstore_operatorKind_COND_LTEQ),\
    SSO_OP_OBJ(vstore_operatorKind_SHIFT_LEFT),\
    SSO_OP_OBJ(vstore_operatorKind_SHIFT_RIGHT),\
    SSO_OP_OBJ(vstore_operatorKind_REF),\
    /* state */\
    SSO_OP_OBJ(lang_state_VALID),\
    SSO_OP_OBJ(lang_state_DELETED),\
    SSO_OP_OBJ(lang_state_DECLARED),\
    /* attr */\
    SSO_OP_OBJ(lang_attr_ATTR_NAMED),\
    SSO_OP_OBJ(lang_attr_ATTR_WRITABLE),\
    SSO_OP_OBJ(lang_attr_ATTR_OBSERVABLE),\
    SSO_OP_OBJ(lang_attr_ATTR_PERSISTENT),\
    SSO_OP_OBJ(lang_attr_ATTR_DEFAULT),\
    /* eventKind */\
    SSO_OP_OBJ(vstore_eventMask_DECLARE),\
    SSO_OP_OBJ(vstore_eventMask_DEFINE),\
    SSO_OP_OBJ(vstore_eventMask_DELETE),\
    SSO_OP_OBJ(vstore_eventMask_INVALIDATE),\
    SSO_OP_OBJ(vstore_eventMask_UPDATE),\
    SSO_OP_OBJ(vstore_eventMask_RESUME),\
    SSO_OP_OBJ(vstore_eventMask_SUSPEND),\
    SSO_OP_OBJ(vstore_eventMask_ON_SELF),\
    SSO_OP_OBJ(vstore_eventMask_ON_SCOPE),\
    SSO_OP_OBJ(vstore_eventMask_ON_TREE),\
    SSO_OP_OBJ(vstore_eventMask_ON_VALUE),\
    SSO_OP_OBJ(vstore_eventMask_ON_METAVALUE),\
    SSO_OP_OBJ(vstore_eventMask_ON_ANY),\
    /* modifier */\
    SSO_OP_OBJ(lang_modifier_GLOBAL),\
    SSO_OP_OBJ(lang_modifier_LOCAL),\
    SSO_OP_OBJ(lang_modifier_PRIVATE),\
    SSO_OP_OBJ(lang_modifier_READONLY),\
    SSO_OP_OBJ(lang_modifier_CONST),\
    SSO_OP_OBJ(lang_modifier_HIDDEN),\
    SSO_OP_OBJ(lang_modifier_OPTIONAL),\
    SSO_OP_OBJ(lang_modifier_OBSERVABLE),\
    SSO_OP_OBJ(lang_modifier_KEY),\
    /* resultMask */\
    SSO_OP_OBJ(vstore_resultMask_RESULT_LEAF),\
    SSO_OP_OBJ(vstore_resultMask_RESULT_HIDDEN),\
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
    SSO_OP_OBJ(lang_type_flags),\
    SSO_OP_OBJ(lang_type_size),\
    SSO_OP_OBJ(lang_type_alignment),\
    SSO_OP_OBJ(lang_type_metaprocedures),\
    SSO_OP_OBJ(lang_type_init),\
    SSO_OP_OBJ(lang_type_deinit),\
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
    /* verbatim */\
    SSO_OP_OBJ(lang_verbatim_contentType),\
    SSO_OP_OBJ(lang_verbatim_init_),\
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
    SSO_OP_OBJ(lang_struct_keys),\
    SSO_OP_OBJ(lang_struct_keycache),\
    SSO_OP_OBJ(lang_struct_freeops),\
    SSO_OP_OBJ(lang_struct_init_),\
    SSO_OP_OBJ(lang_struct_construct_),\
    SSO_OP_OBJ(lang_struct_destruct_),\
    SSO_OP_OBJ(lang_struct_compatible_),\
    SSO_OP_OBJ(lang_struct_castable_),\
    SSO_OP_OBJ(lang_struct_resolveMember_),\
    /* union */\
    SSO_OP_OBJ(lang_union_discriminator),\
    SSO_OP_OBJ(lang_union_init_),\
    SSO_OP_OBJ(lang_union_construct_),\
    SSO_OP_OBJ(lang_union_findCase_),\
    /* procedure */\
    SSO_OP_OBJ(lang_procedure_hasThis),\
    SSO_OP_OBJ(lang_procedure_thisType),\
    SSO_OP_OBJ(lang_procedure_init_),\
    SSO_OP_OBJ(lang_procedure_construct_),\
    /* interfaceVector */\
    SSO_OP_OBJ(lang_interfaceVector_interface),\
    SSO_OP_OBJ(lang_interfaceVector_vector),\
    /* class */\
    SSO_OP_OBJ(lang_class_base),\
    SSO_OP_OBJ(lang_class_baseAccess),\
    SSO_OP_OBJ(lang_class_implements),\
    SSO_OP_OBJ(lang_class_interfaceVector),\
    SSO_OP_OBJ(lang_class_construct),\
    SSO_OP_OBJ(lang_class_define),\
    SSO_OP_OBJ(lang_class_validate),\
    SSO_OP_OBJ(lang_class_update),\
    SSO_OP_OBJ(lang_class_destruct),\
    SSO_OP_OBJ(lang_class_delete),\
    SSO_OP_OBJ(lang_class_init_),\
    SSO_OP_OBJ(lang_class_instanceof_),\
    SSO_OP_OBJ(lang_class_resolveInterfaceMethod_),\
    /* leaf */\
    SSO_OP_OBJ(lang_container_construct_),\
    SSO_OP_OBJ(lang_container_type),\
    SSO_OP_OBJ(lang_container_value),\
    /* tableinstance */\
    SSO_OP_OBJ(lang_tableinstance_type),\
    /* table */\
    SSO_OP_OBJ(lang_table_construct_),\
    /* mountStats */\
    SSO_OP_OBJ(vstore_mountStats_declares),\
    SSO_OP_OBJ(vstore_mountStats_updates),\
    SSO_OP_OBJ(vstore_mountStats_deletes),\
    /* queuePolicy */\
    SSO_OP_OBJ(vstore_queuePolicy_max),\
    /* mountPolicy */\
    SSO_OP_OBJ(vstore_mountPolicy_ownership),\
    SSO_OP_OBJ(vstore_mountPolicy_mask),\
    SSO_OP_OBJ(vstore_mountPolicy_sampleRate),\
    SSO_OP_OBJ(vstore_mountPolicy_queue),\
    SSO_OP_OBJ(vstore_mountPolicy_expiryTime),\
    /* mountSubscription */\
    SSO_OP_OBJ(vstore_mountSubscription_query),\
    SSO_OP_OBJ(vstore_mountSubscription_mountCount),\
    SSO_OP_OBJ(vstore_mountSubscription_subscriberCount),\
    SSO_OP_OBJ(vstore_mountSubscription_mountCtx),\
    SSO_OP_OBJ(vstore_mountSubscription_subscriberCtx),\
    /* query */\
    SSO_OP_OBJ(vstore_query_select),\
    SSO_OP_OBJ(vstore_query_from),\
    SSO_OP_OBJ(vstore_query_type),\
    SSO_OP_OBJ(vstore_query_member),\
    SSO_OP_OBJ(vstore_query_where),\
    SSO_OP_OBJ(vstore_query_offset),\
    SSO_OP_OBJ(vstore_query_limit),\
    SSO_OP_OBJ(vstore_query_timeBegin),\
    SSO_OP_OBJ(vstore_query_timeEnd),\
    SSO_OP_OBJ(vstore_query_content),\
    SSO_OP_OBJ(vstore_query_cardinality_),\
    /* subscriber */\
    SSO_OP_OBJ(vstore_subscriber_query),\
    SSO_OP_OBJ(vstore_subscriber_contentType),\
    SSO_OP_OBJ(vstore_subscriber_instance),\
    SSO_OP_OBJ(vstore_subscriber_dispatcher),\
    SSO_OP_OBJ(vstore_subscriber_enabled),\
    SSO_OP_OBJ(vstore_subscriber_contentTypeHandle),\
    SSO_OP_OBJ(vstore_subscriber_idmatch),\
    SSO_OP_OBJ(vstore_subscriber_init_),\
    SSO_OP_OBJ(vstore_subscriber_deinit_),\
    SSO_OP_OBJ(vstore_subscriber_construct_),\
    SSO_OP_OBJ(vstore_subscriber_destruct_),\
    SSO_OP_OBJ(vstore_subscriber_subscribe_),\
    SSO_OP_OBJ(vstore_subscriber_unsubscribe_),\
    /* router */\
    SSO_OP_OBJ(vstore_router_init_),\
    SSO_OP_OBJ(vstore_router_construct_),\
    SSO_OP_OBJ(vstore_router_match),\
    SSO_OP_OBJ(vstore_router_returnType),\
    SSO_OP_OBJ(vstore_router_paramType),\
    SSO_OP_OBJ(vstore_router_paramName),\
    SSO_OP_OBJ(vstore_router_routerDataType),\
    SSO_OP_OBJ(vstore_router_routerDataName),\
    SSO_OP_OBJ(vstore_router_elementSeparator),\
    /* routerimpl */\
    SSO_OP_OBJ(vstore_routerimpl_construct_),\
    SSO_OP_OBJ(vstore_routerimpl_destruct_),\
    SSO_OP_OBJ(vstore_routerimpl_maxArgs),\
    SSO_OP_OBJ(vstore_routerimpl_matched),\
    SSO_OP_OBJ(vstore_routerimpl_matchRoute_),\
    SSO_OP_OBJ(vstore_routerimpl_findRoute_),\
    /* mount */\
    SSO_OP_OBJ(vstore_mount_query),\
    SSO_OP_OBJ(vstore_mount_contentType),\
    SSO_OP_OBJ(vstore_mount_policy),\
    SSO_OP_OBJ(vstore_mount_mount),\
    SSO_OP_OBJ(vstore_mount_attr),\
    SSO_OP_OBJ(vstore_mount_sent),\
    SSO_OP_OBJ(vstore_mount_received),\
    SSO_OP_OBJ(vstore_mount_sentDiscarded),\
    SSO_OP_OBJ(vstore_mount_subscriptions),\
    SSO_OP_OBJ(vstore_mount_events),\
    SSO_OP_OBJ(vstore_mount_historicalEvents),\
    SSO_OP_OBJ(vstore_mount_lastPoll),\
    SSO_OP_OBJ(vstore_mount_lastPost),\
    SSO_OP_OBJ(vstore_mount_lastSleep),\
    SSO_OP_OBJ(vstore_mount_dueSleep),\
    SSO_OP_OBJ(vstore_mount_lastQueueSize),\
    SSO_OP_OBJ(vstore_mount_passThrough),\
    SSO_OP_OBJ(vstore_mount_explicitResume),\
    SSO_OP_OBJ(vstore_mount_thread),\
    SSO_OP_OBJ(vstore_mount_quit),\
    SSO_OP_OBJ(vstore_mount_contentTypeOut),\
    SSO_OP_OBJ(vstore_mount_contentTypeOutHandle),\
    SSO_OP_OBJ(vstore_mount_init_),\
    SSO_OP_OBJ(vstore_mount_construct_),\
    SSO_OP_OBJ(vstore_mount_destruct_),\
    SSO_OP_OBJ(vstore_mount_invoke_),\
    SSO_OP_OBJ(vstore_mount_id_),\
    SSO_OP_OBJ(vstore_mount_query_),\
    SSO_OP_OBJ(vstore_mount_resume_),\
    SSO_OP_OBJ(vstore_mount_subscribe_),\
    SSO_OP_OBJ(vstore_mount_unsubscribe_),\
    SSO_OP_OBJ(vstore_mount_setContentType_),\
    SSO_OP_OBJ(vstore_mount_setContentTypeIn_),\
    SSO_OP_OBJ(vstore_mount_setContentTypeOut_),\
    SSO_OP_OBJ(vstore_mount_return_),\
    SSO_OP_OBJ(vstore_mount_publish_),\
    SSO_OP_OBJ(vstore_mount_post_),\
    SSO_OP_OBJ(vstore_mount_onPoll_),\
    SSO_OP_OBJ(vstore_mount_onNotify_),\
    SSO_OP_OBJ(vstore_mount_onBatchNotify_),\
    SSO_OP_OBJ(vstore_mount_onHistoryBatchNotify_),\
    SSO_OP_OBJ(vstore_mount_onInvoke_),\
    SSO_OP_OBJ(vstore_mount_onId_),\
    SSO_OP_OBJ(vstore_mount_onQuery_),\
    SSO_OP_OBJ(vstore_mount_onHistoryQuery_),\
    SSO_OP_OBJ(vstore_mount_onResume_),\
    SSO_OP_OBJ(vstore_mount_onSubscribe_),\
    SSO_OP_OBJ(vstore_mount_onUnsubscribe_),\
    SSO_OP_OBJ(vstore_mount_onMount_),\
    SSO_OP_OBJ(vstore_mount_onUnmount_),\
    SSO_OP_OBJ(vstore_mount_onTransactionBegin_),\
    SSO_OP_OBJ(vstore_mount_onTransactionEnd_),\
    /* loader */\
    SSO_OP_OBJ(vstore_loader_autoLoad),\
    SSO_OP_OBJ(vstore_loader_construct_),\
    SSO_OP_OBJ(vstore_loader_destruct_),\
    SSO_OP_OBJ(vstore_loader_onQuery_),\
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
    SSO_OP_OBJ(lang_delegate_bind),\
    /* target */\
    SSO_OP_OBJ(lang_target_type),\
    SSO_OP_OBJ(lang_target_construct_),\
    /* quantity */\
    SSO_OP_OBJ(lang_quantity_description),\
    /* unit */\
    SSO_OP_OBJ(lang_unit_quantity),\
    SSO_OP_OBJ(lang_unit_symbol),\
    SSO_OP_OBJ(lang_unit_conversion),\
    SSO_OP_OBJ(lang_unit_type),\
    SSO_OP_OBJ(lang_unit_toQuantity),\
    SSO_OP_OBJ(lang_unit_fromQuantity),\
    SSO_OP_OBJ(lang_unit_init_),\
    SSO_OP_OBJ(lang_unit_construct_),\
    SSO_OP_OBJ(lang_unit_destruct_),\
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
    SSO_OP_OBJ(lang_member_unit),\
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
    SSO_OP_OBJ(lang_case_modifiers),\
    SSO_OP_OBJ(lang_case_construct_),\
    /* default */\
    SSO_OP_OBJ(lang_default_type),\
    SSO_OP_OBJ(lang_default_construct_),\
    /* parameter */\
    SSO_OP_OBJ(lang_parameter_name),\
    SSO_OP_OBJ(lang_parameter_type),\
    SSO_OP_OBJ(lang_parameter_inout),\
    SSO_OP_OBJ(lang_parameter_passByReference),\
    /* sample */\
    SSO_OP_OBJ(vstore_sample_timestamp),\
    SSO_OP_OBJ(vstore_sample_value),\
    /* result */\
    SSO_OP_OBJ(vstore_result_id),\
    SSO_OP_OBJ(vstore_result_name),\
    SSO_OP_OBJ(vstore_result_parent),\
    SSO_OP_OBJ(vstore_result_type),\
    SSO_OP_OBJ(vstore_result_value),\
    SSO_OP_OBJ(vstore_result_flags),\
    SSO_OP_OBJ(vstore_result_object),\
    SSO_OP_OBJ(vstore_result_history),\
    SSO_OP_OBJ(vstore_result_owner),\
    SSO_OP_OBJ(vstore_result_getText_),\
    SSO_OP_OBJ(vstore_result_fromcontent_),\
    SSO_OP_OBJ(vstore_result_contentof_),\
    /* package */\
    SSO_OP_OBJ(vstore_package_description),\
    SSO_OP_OBJ(vstore_package_version),\
    SSO_OP_OBJ(vstore_package_author),\
    SSO_OP_OBJ(vstore_package_organization),\
    SSO_OP_OBJ(vstore_package_url),\
    SSO_OP_OBJ(vstore_package_repository),\
    SSO_OP_OBJ(vstore_package_icon),\
    SSO_OP_OBJ(vstore_package_dependencies),\
    SSO_OP_OBJ(vstore_package_env),\
    SSO_OP_OBJ(vstore_package_language),\
    SSO_OP_OBJ(vstore_package_managed),\
    SSO_OP_OBJ(vstore_package_noapi),\
    SSO_OP_OBJ(vstore_package_cflags),\
    SSO_OP_OBJ(vstore_package_cxxflags),\
    SSO_OP_OBJ(vstore_package_definitions),\
    SSO_OP_OBJ(vstore_package_prefix),\
    SSO_OP_OBJ(vstore_package_cortoVersion),\
    SSO_OP_OBJ(vstore_package_local),\
    SSO_OP_OBJ(vstore_package_lib),\
    SSO_OP_OBJ(vstore_package_libpath),\
    SSO_OP_OBJ(vstore_package_include),\
    SSO_OP_OBJ(vstore_package_link),\
    SSO_OP_OBJ(vstore_package_coverage),\
    SSO_OP_OBJ(vstore_package_init_),\
    SSO_OP_OBJ(vstore_package_construct_),\
    /* time */\
    SSO_OP_OBJ(vstore_time_sec),\
    SSO_OP_OBJ(vstore_time_nanosec),\
    /* frame */\
    SSO_OP_OBJ(vstore_frame_kind),\
    SSO_OP_OBJ(vstore_frame_value),\
    SSO_OP_OBJ(vstore_frame_getTime_),\
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

/* Initialization of objects */
static void corto_initObject(corto_object o) {
    corto_createObject(o);
    corto_walk_opt s =
        corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_walk(&s, o, NULL);
    corto_type t = corto_typeof(o);
    corto_callInitDelegate(&t->init, t, o);
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
    corto_walk_opt s;
    s = corto_ser_keep(CORTO_LOCAL, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_walk(&s, o, NULL);
}

/* Decrease references */
static void corto_decreaseRef(corto_object o) {
    corto_walk_opt s;
    s = corto_ser_free(CORTO_LOCAL, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_walk(&s, o, NULL);
}

static void corto_genericTlsFree(void *o) {
    corto_dealloc(o);
}

static void corto_patchSequences(void) {
    /* Mount implements dispatcher */
    corto_mount_o->implements.length = 1;
    corto_mount_o->implements.buffer = corto_alloc(sizeof(corto_object));
    corto_mount_o->implements.buffer[0] = corto_dispatcher_o;

    /* Add parameter to handleAction */
    corto_handleAction_o->parameters.length = 1;
    corto_handleAction_o->parameters.buffer = corto_calloc(sizeof(corto_parameter));
    corto_parameter *p = &corto_handleAction_o->parameters.buffer[0];
    corto_ptr_setref(&p->type, corto_event_o);
    corto_ptr_setstr(&p->name, "event");
}

void corto_environment_init(void) {
/* Only set environment variables if library is installed as corto package */
#ifndef CORTO_REDIS
    /* CORTO_BUILD is where the buildsystem is located */
    if (!corto_getenv("CORTO_BUILD")) {
        corto_setenv("CORTO_BUILD", "/usr/local/lib/corto/%s.%s/build",
            CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
    }

    /* CORTO_HOME is where corto binaries are located */
    if (!corto_getenv("CORTO_HOME") || !strlen(corto_getenv("CORTO_HOME"))) {
        corto_setenv("CORTO_HOME", "/usr/local");
    }

    /* If there is no home directory, default to /usr/local. This should be
     * avoided in development environments. */
    if (!corto_getenv("HOME") || !strlen(corto_getenv("HOME"))) {
        corto_setenv("HOME", "/usr/local");
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
    if (traceObject && traceObject[0]) {
        CORTO_TRACE_ID = traceObject;
    }

    corto_string enableBacktrace = corto_getenv("CORTO_BACKTRACE_ENABLED");
    if (enableBacktrace) {
        CORTO_BACKTRACE_ENABLED = !strcmp(enableBacktrace, "true");
    }

    corto_string memtraceBreakpoint = corto_getenv("CORTO_MEMTRACE_BREAKPOINT");
    if (memtraceBreakpoint && memtraceBreakpoint[0]) {
        CORTO_MEMTRACE_BREAKPOINT = atoi(memtraceBreakpoint);
    }

    corto_string errfmt = corto_getenv("CORTO_ERRFMT");
    if (errfmt && errfmt[0]) {
        corto_errfmt(errfmt);
    }
}

static int corto_loadConfig(void) {
    int result = 0;
    corto_component_push("config");
    char *cfg = corto_getenv("CORTO_CONFIG");
    if (cfg) {
        if (corto_isdir(cfg)) {
            corto_trace("loading configuration");
            char *prevDir = strdup(corto_cwd());
            corto_ll cfgfiles = corto_opendir(cfg);
            corto_chdir(cfg);
            corto_iter it = corto_ll_iter(cfgfiles);
            while (corto_iter_hasNext(&it)) {
                char *file = corto_iter_next(&it);
                if (corto_load(file, 0, NULL)) {
                    corto_error("%s: %s", file, corto_lasterr());
                    result = -1;
                    /* Don't break, report all errors */
                } else {
                    corto_ok("successfuly loaded '%s'", file);
                }
            }
            corto_chdir(prevDir);
            corto_closedir(cfgfiles);
        } else if (corto_fileTest(cfg)) {
            if (corto_load(cfg, 0, NULL)) {
                corto_error("%s: %s", cfg, corto_lasterr());
                result = -1;
            }
        } else {
            corto_error(
                "$CORTO_CONFIG ('%s') does not point to an accessible path or file", 
                cfg);
            result = -1;
        }
    }
    corto_component_pop();
    return result;
}

int corto_start(char *appName) {
    CORTO_APP_STATUS = 1; /* Initializing */

    corto_appName = appName;
    if ((appName[0] == '.') && (appName[1] == '/')) {
        corto_appName += 2;
    }

    /* Initialize TLS keys */
    corto_threadTlsKey(&CORTO_KEY_OBSERVER_ADMIN, corto_observerAdminFree);
    corto_threadTlsKey(&CORTO_KEY_DECLARED_ADMIN, corto_declaredAdminFree);
    corto_threadTlsKey(&CORTO_KEY_LISTEN_ADMIN, NULL);
    corto_threadTlsKey(&CORTO_KEY_OWNER, NULL);
    corto_threadTlsKey(&CORTO_KEY_ATTR, corto_genericTlsFree);
    corto_threadTlsKey(&CORTO_KEY_FLUENT, NULL);
    void corto_threadStringDealloc(void *data);
    corto_threadTlsKey(&CORTO_KEY_THREAD_STRING, corto_threadStringDealloc);
    corto_threadTlsKey(&CORTO_KEY_MOUNT_RESULT, NULL);
    corto_threadTlsKey(&CORTO_KEY_CONSTRUCTOR_TYPE, NULL);
    corto_threadTlsKey(&corto_subscriber_admin.key, corto_entityAdmin_free);
    corto_threadTlsKey(&corto_mount_admin.key, corto_entityAdmin_free);

    /* Push init component for logging */
    corto_component_push("init");

    corto_trace("initializing...");

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
    corto_environment_init();

    /* Now that environment is initialized, set paths for loader */
    corto_load_init(
        corto_getenv("CORTO_TARGET"),
        corto_getenv("CORTO_HOME"),
        corto_getenv("/usr/local")
        CORTO_VERSION_MAJOR,
        CORTO_VERSION_MINOR);

    /* Initialize security */
    corto_secure_init();

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

    /* Bootstrap offsets of delegates. These are required to pull forward 
     * delegates from base classes */
    lang_type_init__o.v.offset = offsetof(struct corto_type_s, init);
    lang_type_deinit__o.v.offset = offsetof(struct corto_type_s, deinit);
    lang_class_construct__o.v.offset = offsetof(struct corto_class_s, construct);
    lang_class_define__o.v.offset = offsetof(struct corto_class_s, define);
    lang_class_destruct__o.v.offset = offsetof(struct corto_class_s, destruct);
    lang_class_delete__o.v.offset = offsetof(struct corto_class_s, _delete);
    lang_class_update__o.v.offset = offsetof(struct corto_class_s, update);
    lang_class_validate__o.v.offset = offsetof(struct corto_class_s, validate);

    /* Assign delegates to global variables, so they can be used by other code
     * without having to do expensive lookups */
    corto_type_init_o = &lang_type_init__o.v;
    corto_type_deinit_o = &lang_type_deinit__o.v;
    corto_class_construct_o = &lang_class_construct__o.v;
    corto_class_define_o = &lang_class_define__o.v;
    corto_class_destruct_o = &lang_class_destruct__o.v;
    corto_class_delete_o = &lang_class_delete__o.v;
    corto_class_validate_o = &lang_class_validate__o.v;
    corto_class_update_o = &lang_class_update__o.v;

    /* Set version of builtin packages */
    corto_o->version = (char*)CORTO_VERSION;
    corto_lang_o->version = (char*)CORTO_VERSION;
    corto_vstore_o->version = (char*)CORTO_VERSION;
    corto_secure_o->version = (char*)CORTO_VERSION;
    corto_native_o->version = (char*)CORTO_VERSION;

    /* Initialize builtin scopes */
    corto_initObject(root_o);
    corto_initObject(corto_o);
    corto_initObject(corto_lang_o);
    corto_initObject(corto_vstore_o);
    corto_initObject(corto_native_o);
    corto_initObject(corto_secure_o);

    /* Define builtin scopes */
    corto_defineObject(root_o);
    corto_defineObject(corto_o);
    corto_defineObject(corto_lang_o);
    corto_defineObject(corto_vstore_o);
    corto_defineObject(corto_native_o);
    corto_defineObject(corto_secure_o);

    /* Because at this point the construct/destruct & init/deinit delegates are
     * not yet propagated from base classes to sub classes, type construction
     * can't begin yet. First, delegates need to be properly initialized for
     * all types. This only affects types that support inheritance, so all
     * types that inherit from interface. */

    corto_int32 i = 0;
    corto_object o;
    for (i = 0; (o = types[i].o); i++) {
        if (corto_instanceof(corto_interface_o, o)) {
            if (corto_interface_pullDelegate(o, &lang_type_init__o.v)) {
                ((corto_type)o)->flags |= CORTO_TYPE_HAS_INIT;
            }
            if (corto_interface_pullDelegate(o, &lang_type_deinit__o.v)) {
                ((corto_type)o)->flags |= CORTO_TYPE_HAS_DEINIT;
            }
            if (corto_instanceof(corto_class_o, o)) {
                if (corto_interface_pullDelegate(o, &lang_class_construct__o.v)) {
                    ((corto_type)o)->flags |= CORTO_TYPE_HAS_CONSTRUCT;
                }
                if (corto_interface_pullDelegate(o, &lang_class_destruct__o.v)) {
                    ((corto_type)o)->flags |= CORTO_TYPE_HAS_DESTRUCT;
                }

                /* Other delegates are not relevant for construction of types */
            }
        }
    }

    /* Init objects */
    for (i = 0; (o = types[i].o); i++) corto_initObject(o);
    for (i = 0; (o = objects[i].o); i++) corto_initObject(o);

    /* Patch sequences- these aren't set statically since sequences are
     * allocated on the heap */
    corto_patchSequences();

    /* Manually assign two function objects that are used as delegate callbacks */
    corto_observerEvent_handle_o = &vstore_observerEvent_handle__o.v;
    corto_subscriberEvent_handle_o = &vstore_subscriberEvent_handle__o.v;

    /* Construct objects */
    for (i = 0; (o = objects[i].o); i++) corto_defineObject(o);
    for (i = 0; (o = types[i].o); i++) corto_defineType(o, types[i].size);

    /* Update refcounts of public members */
    for (i = 0; (o = types[i].o); i++) corto_updateRef(o);
    for (i = 0; (o = objects[i].o); i++) corto_updateRef(o);

    /* Now that types are defined, update refs on scopes */
    corto_updateRef(root_o);
    corto_updateRef(corto_o);
    corto_updateRef(corto_lang_o);
    corto_updateRef(corto_vstore_o);
    corto_updateRef(corto_native_o);
    corto_updateRef(corto_secure_o);

    /* Initialize conversions and operators */
#ifdef CORTO_CONVERSIONS
    corto_ptr_castInit();
#endif
#ifdef CORTO_OPERATORS
    corto_operatorInit();
#endif

    /* Register exit-handler */
    void corto_loaderOnExit(void* ctx);
    corto_onexit(corto_loaderOnExit, NULL);

    /* Register library-binding */
    int corto_loadLibraryAction(corto_string file, int argc, char* argv[], void *data);
    corto_load_register("so", corto_loadLibraryAction, NULL);

    int corto_fileLoader(corto_string file, int argc, char* argv[], void *data);
    corto_load_register("", corto_fileLoader, NULL);

    /* Always randomize seed */
    srand (time(NULL));

    CORTO_APP_STATUS = 0; /* Running */

/* Only create package mount for non-redistributable version of corto, where
 * packages are installed in a common location */
#ifndef CORTO_REDIS
    corto_loaderInstance = corto_create(corto_loader_o);

    if (corto_loaderInstance) {
        corto_loaderInstance->autoLoad = TRUE;
    }
    else {
        corto_trace("init: autoloading of packages disabled: %s", 
            corto_lasterr());
        corto_lasterr();
    }
#endif

    /* Create builtin root scopes */
    corto_createChild(root_o, "config", corto_void_o);
    corto_createChild(root_o, "data", corto_void_o);
    corto_createChild(root_o, "home", corto_void_o);

    /* Load configuration, if available */
    corto_loadConfig();
    
    corto_ok("initialized");

    /* Pop init log component */
    corto_component_pop();

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
        corto_exitHandlers = corto_ll_new();
    }
    corto_ll_insert(corto_exitHandlers, h);
    corto_mutexUnlock(&corto_adminLock);
}

/* Call exit-handlers */
static void corto_exit(void) {
    struct corto_exitHandler* h;

    if (corto_exitHandlers) {
        while((h = corto_ll_takeFirst(corto_exitHandlers))) {
            h->handler(h->userData);
            corto_dealloc(h);
        }
        corto_ll_free(corto_exitHandlers);
        corto_exitHandlers = NULL;
    }
}

int corto_stop(void) {

    CORTO_APP_STATUS = 2; /* Shutting down */

    corto_trace("init: shutting down");

    if (corto_getOwner()) {
        corto_error("owner has not been reset to NULL before shutting down");
        abort();
    }

#ifndef CORTO_REDIS
    if (corto_loaderInstance) {
        corto_delete(corto_loaderInstance);
    }
#endif

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

    /* Deinitialize vstore loader */
    if (corto__freeSSO(corto_native_o)) goto error;
    if (corto__freeSSO(corto_vstore_o)) goto error;
    if (corto__freeSSO(corto_lang_o)) goto error;
    if (corto__freeSSO(corto_o)) goto error;
    if (corto__freeSSO(root_o)) goto error;

    /* Deinit adminLock */
    corto_mutexFree(&corto_adminLock);

    CORTO_APP_STATUS = 3; /* Shut down */

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

bool corto_autoload(corto_bool autoload) {
    bool prev = false;

    if (corto_loaderInstance) {
        prev = corto_loaderInstance->autoLoad;
        corto_loaderInstance->autoLoad = autoload;
    }
    
    return prev;
}

corto_bool corto_enableload(corto_bool enable) {
    corto_bool prev = FALSE;
    if (!enable) {
        if (corto_loaderInstance) {
            corto_delete(corto_loaderInstance);
            corto_loaderInstance = NULL;
            prev = TRUE;
        }
    } else {
        if (!corto_loaderInstance) {
            corto_loaderInstance = corto_create(corto_loader_o);
        } else {
            prev = TRUE;
        }
    }

    return prev;
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
