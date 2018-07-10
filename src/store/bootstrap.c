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

/* Public headers */
#include <corto/corto.h>

/* Private headers */
#include "bootstrap.h"
#include "object.h"
#include "cdeclhandler.h"
#include "init_ser.h"
#include "memory_ser.h"
#include "src/lang/class.h"
#include "src/lang/interface.h"

void corto_secure_init(void);

/* Declaration of the C-binding call-handler */
void corto_invoke_cdecl(corto_function f, corto_void* result, void* args);

/* TLS callback to cleanup observer administration */
void corto_observerAdminFree(void *admin);
void corto_declaredByMeFree(void *admin);

struct corto_exitHandler {
    void(*handler)(void*);
    void* userData;
};

#define VERSION_MAJOR "2"
#define VERSION_MINOR "1"
#define VERSION_PATCH "0"
#define VERSION_SUFFIX "beta"

#ifdef VERSION_SUFFIX
const char* BAKE_VERSION = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH "-" VERSION_SUFFIX;
const char* BAKE_VERSION_SUFFIX = VERSION_SUFFIX;
#else
const char* BAKE_VERSION = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
const char* BAKE_VERSION_SUFFIX = "";
#endif

const char* BAKE_VERSION_MAJOR = VERSION_MAJOR;
const char* BAKE_VERSION_MINOR = VERSION_MINOR;
const char* BAKE_VERSION_PATCH = VERSION_PATCH;

/* Single lock to protect infrequent actions on global corto data */
corto_mutex_s corto_adminLock;
corto_rwmutex_s corto_subscriberLock;

/* Application name */
char *corto_appName = NULL;

/* TLS keys */
corto_tls CORTO_KEY_OBSERVER_ADMIN;
corto_tls CORTO_KEY_DECLARED_ADMIN;
corto_tls CORTO_KEY_LISTEN_ADMIN;
corto_tls CORTO_KEY_OWNER;
corto_tls CORTO_KEY_ATTR;
corto_tls CORTO_KEY_FLUENT;
corto_tls CORTO_KEY_MOUNT_RESULT;
corto_tls CORTO_KEY_CONSTRUCTOR_TYPE;

/* Delegate object variables */
corto_member corto_type_init_o = NULL;
corto_member corto_type_deinit_o = NULL;
corto_member corto_class_construct_o = NULL;
corto_member corto_class_define_o = NULL;
corto_member corto_class_destruct_o = NULL;
corto_member corto_class_delete_o = NULL;
corto_member corto_class_validate_o = NULL;
corto_member corto_class_update_o = NULL;

/* Turn on or off extensive memory tracing */
bool CORTO_TRACE_MEM = 0;
bool CORTO_COLLECT_CYCLES = 0;
bool CORTO_COLLECT_TLS = 0;

/* Package loader mount */
static corto_loader corto_loaderInstance;

/* Actions to be run at shutdown */
static corto_ll corto_exitHandlers = NULL;

/* String identifying current corto build */
static corto_string CORTO_BUILD = __DATE__ " " __TIME__;

/* Builtin variables to automatically created objects */
corto_object data_o = NULL;
corto_object config_o = NULL;
corto_object home_o = NULL;

/* Helper macro's for building list of to be initialized objects */
#define SSO_OBJECT(obj) CORTO_OFFSET(&obj##__o, sizeof(corto_SSO))
#define BUILTIN_VOID(parent, obj) {SSO_OBJECT(parent##obj), 0}
#define BUILTIN_VALUE(parent, obj) {SSO_OBJECT(parent##obj), sizeof(corto_##obj)}
#define BUILTIN_CLASS(parent, obj) {SSO_OBJECT(parent##obj), sizeof(struct corto_##obj##_s)}
#define BUILTIN_OBJ(obj) {SSO_OBJECT(obj), 0}

/* The ordering of the lists of objects below is important to ensure that the
 * lifecycle hooks of the builtin objects are called in the right order.
 *
 * During intiialization, objects are added to the hierarchy, and their
 * init/construct hooks are called. This will (for types) calculate the type
 * sizes, which will then be verified to be the same as the generated C type.
 *
 * The definitions of these objects are located in bootstrap.h. For an object
 * defined in bootstrap.h to be visible in the store, it needs to be added to
 * the list of to be initialized objects.
 *
 * The generated C types can be found in <builtin package>/_type.h. For example
 * all the types that make up the typesystem can be found in lang/_type.h
 */

/* Tier 1 objects */
#define BUILTIN_TYPE()\
    BUILTIN_VALUE(lang_, octet),\
    BUILTIN_VALUE(lang_, bool),\
    BUILTIN_VALUE(lang_, char),\
    BUILTIN_VALUE(lang_, uint8),\
    BUILTIN_VALUE(lang_, uint16),\
    BUILTIN_VALUE(lang_, uint32),\
    BUILTIN_VALUE(lang_, uint64),\
    BUILTIN_VALUE(lang_, int8),\
    BUILTIN_VALUE(lang_, int16),\
    BUILTIN_VALUE(lang_, int32),\
    BUILTIN_VALUE(lang_, int64),\
    BUILTIN_VALUE(lang_, float32),\
    BUILTIN_VALUE(lang_, float64),\
    BUILTIN_VALUE(lang_, string),\
    BUILTIN_VALUE(lang_, word),\
    BUILTIN_VALUE(lang_, constant),\
    BUILTIN_VALUE(lang_, any),\
    BUILTIN_VOID(lang_, void),\
    BUILTIN_VOID(lang_, unknown),\
    BUILTIN_VALUE(lang_, object),\
    BUILTIN_VALUE(lang_, width),\
    BUILTIN_VALUE(lang_, typeKind),\
    BUILTIN_VALUE(lang_, primitiveKind),\
    BUILTIN_VALUE(lang_, compositeKind),\
    BUILTIN_VALUE(lang_, collectionKind),\
    BUILTIN_VALUE(lang_, equalityKind),\
    BUILTIN_VALUE(lang_, inout),\
    BUILTIN_VALUE(lang_, ref_kind),\
    BUILTIN_VALUE(vstore_, operatorKind),\
    BUILTIN_VALUE(vstore_, ownership),\
    BUILTIN_VALUE(vstore_, mountCallbackMask),\
    BUILTIN_VALUE(vstore_, frameKind),\
    BUILTIN_VALUE(,secure_accessKind),\
    BUILTIN_VALUE(,secure_actionKind),\
    BUILTIN_VALUE(lang_, modifierMask),\
    BUILTIN_VALUE(vstore_, eventMask),\
    BUILTIN_VALUE(vstore_, resultMask),\
    BUILTIN_VALUE(lang_, state),\
    BUILTIN_VALUE(lang_, attr),\
    BUILTIN_VALUE(lang_, int32seq),\
    BUILTIN_VALUE(lang_, wordseq),\
    BUILTIN_VALUE(lang_, objectseq),\
    BUILTIN_VALUE(lang_, interfaceseq),\
    BUILTIN_VALUE(lang_, parameterseq),\
    BUILTIN_VALUE(lang_, stringseq),\
    BUILTIN_VALUE(lang_, interfaceVectorseq),\
    BUILTIN_VALUE(lang_, interfaceVector),\
    BUILTIN_VALUE(lang_, objectlist),\
    BUILTIN_VALUE(lang_, taglist),\
    BUILTIN_VALUE(lang_, stringlist),\
    BUILTIN_VALUE(vstore_, resultlist),\
    BUILTIN_VALUE(vstore_, mount_subscriptionList),\
    BUILTIN_VALUE(lang_, parameter),\
    BUILTIN_VALUE(vstore_, time),\
    BUILTIN_VALUE(vstore_, frame),\
    BUILTIN_VALUE(vstore_, sample),\
    BUILTIN_VALUE(vstore_, sampleIter),\
    BUILTIN_VALUE(vstore_, subscriber_eventIter),\
    BUILTIN_VALUE(vstore_, result),\
    BUILTIN_VALUE(lang_, delegatedata),\
    BUILTIN_VOID(vstore_, dispatcher),\
    BUILTIN_VALUE(lang_, pre_action),\
    BUILTIN_VALUE(lang_, name_action),\
    BUILTIN_VALUE(lang_, post_action),\
    BUILTIN_VALUE(vstore_, handleAction),\
    BUILTIN_VALUE(vstore_, resultIter),\
    BUILTIN_VALUE(vstore_, objectIter),\
    BUILTIN_VALUE(vstore_, query),\
    BUILTIN_VALUE(vstore_, mount_subscription),\
    BUILTIN_CLASS(lang_, function),\
    BUILTIN_CLASS(lang_, method),\
    BUILTIN_CLASS(lang_, overridable),\
    BUILTIN_CLASS(lang_, override),\
    BUILTIN_CLASS(vstore_, remote),\
    BUILTIN_CLASS(vstore_, observer),\
    BUILTIN_CLASS(vstore_, subscriber),\
    BUILTIN_CLASS(lang_, metaprocedure),\
    BUILTIN_CLASS(vstore_, route),\
    BUILTIN_CLASS(lang_, type),\
    BUILTIN_CLASS(lang_, primitive),\
    BUILTIN_CLASS(lang_, interface),\
    BUILTIN_CLASS(lang_, collection),\
    BUILTIN_CLASS(lang_, iterator),\
    BUILTIN_CLASS(lang_, struct),\
    BUILTIN_CLASS(lang_, union),\
    BUILTIN_VALUE(vstore_, event),\
    BUILTIN_VALUE(vstore_, fmt_data),\
    BUILTIN_VALUE(vstore_, observer_event),\
    BUILTIN_VALUE(vstore_, subscriber_event),\
    BUILTIN_VALUE(vstore_, invoke_event),\
    BUILTIN_CLASS(lang_, binary),\
    BUILTIN_CLASS(lang_, boolean),\
    BUILTIN_CLASS(lang_, character),\
    BUILTIN_CLASS(lang_, int),\
    BUILTIN_CLASS(lang_, uint),\
    BUILTIN_CLASS(lang_, float),\
    BUILTIN_CLASS(lang_, text),\
    BUILTIN_CLASS(lang_, verbatim),\
    BUILTIN_CLASS(lang_, enum),\
    BUILTIN_CLASS(lang_, bitmask),\
    BUILTIN_CLASS(lang_, array),\
    BUILTIN_CLASS(lang_, sequence),\
    BUILTIN_CLASS(lang_, list),\
    BUILTIN_CLASS(lang_, map),\
    BUILTIN_CLASS(lang_, member),\
    BUILTIN_CLASS(lang_, case),\
    BUILTIN_CLASS(lang_, default),\
    BUILTIN_CLASS(lang_, alias),\
    BUILTIN_CLASS(lang_, class),\
    BUILTIN_CLASS(lang_, container),\
    BUILTIN_CLASS(lang_, leaf),\
    BUILTIN_CLASS(lang_, table),\
    BUILTIN_CLASS(lang_, tableinstance),\
    BUILTIN_CLASS(lang_, procedure),\
    BUILTIN_CLASS(lang_, delegate),\
    BUILTIN_CLASS(lang_, target),\
    BUILTIN_CLASS(lang_, quantity),\
    BUILTIN_CLASS(lang_, unit),\
    BUILTIN_CLASS(lang_, tag),\
    BUILTIN_CLASS(lang_, package),\
    BUILTIN_CLASS(lang_, application),\
    BUILTIN_CLASS(lang_, tool),\
    BUILTIN_CLASS(vstore_, router),\
    BUILTIN_CLASS(vstore_, routerimpl),\
    BUILTIN_CLASS(vstore_, mount),\
    BUILTIN_CLASS(vstore_, loader),\
    BUILTIN_CLASS(,native_type),\
    BUILTIN_CLASS(,secure_key),\
    BUILTIN_CLASS(,secure_lock)

/* Tier 2 objects */
#define BUILTIN_OBJECT()\
    BUILTIN_OBJ(lang_class_construct_),\
    BUILTIN_OBJ(lang_class_destruct_),\
    /* constant */\
    BUILTIN_OBJ(lang_constant_init_),\
    /* function */\
    BUILTIN_OBJ(lang_function_return_type),\
    BUILTIN_OBJ(lang_function_is_reference),\
    BUILTIN_OBJ(lang_function_parameters),\
    BUILTIN_OBJ(lang_function_overridable),\
    BUILTIN_OBJ(lang_function_overloaded),\
    BUILTIN_OBJ(lang_function_kind),\
    BUILTIN_OBJ(lang_function_impl),\
    BUILTIN_OBJ(lang_function_fptr),\
    BUILTIN_OBJ(lang_function_fdata),\
    BUILTIN_OBJ(lang_function_size),\
    BUILTIN_OBJ(lang_function_init_),\
    BUILTIN_OBJ(lang_function_construct_),\
    BUILTIN_OBJ(lang_function_destruct_),\
    BUILTIN_OBJ(lang_function_stringToParameterSeq),\
    BUILTIN_OBJ(lang_function_parseParamString_),\
    /* method */\
    BUILTIN_OBJ(lang_method_index),\
    /* overridable */\
    BUILTIN_OBJ(lang_overridable_init_),\
    /* observer */\
    BUILTIN_OBJ(vstore_observer_mask),\
    BUILTIN_OBJ(vstore_observer_observable),\
    BUILTIN_OBJ(vstore_observer_instance),\
    BUILTIN_OBJ(vstore_observer_dispatcher),\
    BUILTIN_OBJ(vstore_observer_type),\
    BUILTIN_OBJ(vstore_observer_enabled),\
    BUILTIN_OBJ(vstore_observer_active),\
    BUILTIN_OBJ(vstore_observer_init_),\
    BUILTIN_OBJ(vstore_observer_construct_),\
    BUILTIN_OBJ(vstore_observer_destruct_),\
    BUILTIN_OBJ(vstore_observer_observe_),\
    BUILTIN_OBJ(vstore_observer_unobserve_),\
    BUILTIN_OBJ(vstore_observer_observing_),\
    /* metaprocedure */\
    BUILTIN_OBJ(lang_metaprocedure_referenceOnly),\
    BUILTIN_OBJ(lang_metaprocedure_construct_),\
    /* route */\
    BUILTIN_OBJ(vstore_route_pattern),\
    BUILTIN_OBJ(vstore_route_elements),\
    BUILTIN_OBJ(vstore_route_init_),\
    BUILTIN_OBJ(vstore_route_construct_),\
    /* dispatcher */\
    BUILTIN_OBJ(vstore_dispatcher_post),\
    /* event */\
    BUILTIN_OBJ(vstore_event_handleAction),\
    BUILTIN_OBJ(vstore_event_handle_),\
    /* fmt_data */\
    BUILTIN_OBJ(vstore_fmt_data_ptr),\
    BUILTIN_OBJ(vstore_fmt_data_handle),\
    BUILTIN_OBJ(vstore_fmt_data_shared_count),\
    BUILTIN_OBJ(vstore_fmt_data_deinit_),\
    /* observer_event */\
    BUILTIN_OBJ(vstore_observer_event_observer),\
    BUILTIN_OBJ(vstore_observer_event_instance),\
    BUILTIN_OBJ(vstore_observer_event_source),\
    BUILTIN_OBJ(vstore_observer_event_event),\
    BUILTIN_OBJ(vstore_observer_event_data),\
    BUILTIN_OBJ(vstore_observer_event_thread),\
    BUILTIN_OBJ(vstore_observer_event_handle),\
    BUILTIN_OBJ(vstore_observer_event_init_),\
    BUILTIN_OBJ(vstore_observer_event_deinit_),\
    /* subscriber_event */\
    BUILTIN_OBJ(vstore_subscriber_event_subscriber),\
    BUILTIN_OBJ(vstore_subscriber_event_instance),\
    BUILTIN_OBJ(vstore_subscriber_event_source),\
    BUILTIN_OBJ(vstore_subscriber_event_event),\
    BUILTIN_OBJ(vstore_subscriber_event_data),\
    BUILTIN_OBJ(vstore_subscriber_event_fmt),\
    BUILTIN_OBJ(vstore_subscriber_event_handle),\
    BUILTIN_OBJ(vstore_subscriber_event_init_),\
    BUILTIN_OBJ(vstore_subscriber_event_deinit_),\
    /* invoke_event */\
    BUILTIN_OBJ(vstore_invoke_event_mount),\
    BUILTIN_OBJ(vstore_invoke_event_instance),\
    BUILTIN_OBJ(vstore_invoke_event_function),\
    BUILTIN_OBJ(vstore_invoke_event_args),\
    BUILTIN_OBJ(vstore_invoke_event_handle_),\
    /* width */\
    BUILTIN_OBJ(lang_width_WIDTH_8),\
    BUILTIN_OBJ(lang_width_WIDTH_16),\
    BUILTIN_OBJ(lang_width_WIDTH_32),\
    BUILTIN_OBJ(lang_width_WIDTH_64),\
    BUILTIN_OBJ(lang_width_WIDTH_WORD),\
    /* typeKind */\
    BUILTIN_OBJ(lang_typeKind_VOID),\
    BUILTIN_OBJ(lang_typeKind_ANY),\
    BUILTIN_OBJ(lang_typeKind_PRIMITIVE),\
    BUILTIN_OBJ(lang_typeKind_COMPOSITE),\
    BUILTIN_OBJ(lang_typeKind_COLLECTION),\
    BUILTIN_OBJ(lang_typeKind_ITERATOR),\
    /* primitiveKind */\
    BUILTIN_OBJ(lang_primitiveKind_BINARY),\
    BUILTIN_OBJ(lang_primitiveKind_BOOLEAN),\
    BUILTIN_OBJ(lang_primitiveKind_CHARACTER),\
    BUILTIN_OBJ(lang_primitiveKind_INTEGER),\
    BUILTIN_OBJ(lang_primitiveKind_UINTEGER),\
    BUILTIN_OBJ(lang_primitiveKind_FLOAT),\
    BUILTIN_OBJ(lang_primitiveKind_TEXT),\
    BUILTIN_OBJ(lang_primitiveKind_ENUM),\
    BUILTIN_OBJ(lang_primitiveKind_BITMASK),\
    /* compositeKind */\
    BUILTIN_OBJ(lang_compositeKind_INTERFACE),\
    BUILTIN_OBJ(lang_compositeKind_STRUCT),\
    BUILTIN_OBJ(lang_compositeKind_UNION),\
    BUILTIN_OBJ(lang_compositeKind_CLASS),\
    BUILTIN_OBJ(lang_compositeKind_DELEGATE),\
    BUILTIN_OBJ(lang_compositeKind_PROCEDURE),\
    /* collectionKind */\
    BUILTIN_OBJ(lang_collectionKind_ARRAY),\
    BUILTIN_OBJ(lang_collectionKind_SEQUENCE),\
    BUILTIN_OBJ(lang_collectionKind_LIST),\
    BUILTIN_OBJ(lang_collectionKind_MAP),\
    /* equalityKind */\
    BUILTIN_OBJ(lang_equalityKind_EQ),\
    BUILTIN_OBJ(lang_equalityKind_LT),\
    BUILTIN_OBJ(lang_equalityKind_GT),\
    BUILTIN_OBJ(lang_equalityKind_NEQ),\
    /* inout */\
    BUILTIN_OBJ(lang_inout_IN),\
    BUILTIN_OBJ(lang_inout_OUT),\
    BUILTIN_OBJ(lang_inout_INOUT),\
    /* ref_kind */\
    BUILTIN_OBJ(lang_ref_kind_BY_TYPE),\
    BUILTIN_OBJ(lang_ref_kind_BY_VALUE),\
    BUILTIN_OBJ(lang_ref_kind_BY_REFERENCE),\
    /* ownership */\
    BUILTIN_OBJ(vstore_ownership_REMOTE_SOURCE),\
    BUILTIN_OBJ(vstore_ownership_LOCAL_SOURCE),\
    BUILTIN_OBJ(vstore_ownership_CACHE_OWNER),\
    /* readWrite */\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_QUERY),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_HISTORY_QUERY),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_NOTIFY),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_HISTORY_BATCH_NOTIFY),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_BATCH_NOTIFY),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_SUBSCRIBE),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_MOUNT),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_RESUME),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_INVOKE),\
    BUILTIN_OBJ(vstore_mountCallbackMask_MOUNT_ID),\
    /* frameKind */\
    BUILTIN_OBJ(vstore_frameKind_FRAME_NOW),\
    BUILTIN_OBJ(vstore_frameKind_FRAME_TIME),\
    BUILTIN_OBJ(vstore_frameKind_FRAME_DURATION),\
    /* accessKind */\
    BUILTIN_OBJ(secure_accessKind_SECURE_ACCESS_GRANTED),\
    BUILTIN_OBJ(secure_accessKind_SECURE_ACCESS_DENIED),\
    BUILTIN_OBJ(secure_accessKind_SECURE_ACCESS_UNDEFINED),\
    /* actionKind */\
    BUILTIN_OBJ(secure_actionKind_SECURE_ACTION_CREATE),\
    BUILTIN_OBJ(secure_actionKind_SECURE_ACTION_READ),\
    BUILTIN_OBJ(secure_actionKind_SECURE_ACTION_UPDATE),\
    BUILTIN_OBJ(secure_actionKind_SECURE_ACTION_DELETE),\
    BUILTIN_OBJ(secure_actionKind_SECURE_ACTION_ANY),\
    /* operatorKind */\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_ADD),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_SUB),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_MUL),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_DIV),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_MOD),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_XOR),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_OR),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_AND),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_SHIFT_LEFT),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_SHIFT_RIGHT),\
    BUILTIN_OBJ(vstore_operatorKind_ASSIGN_UPDATE),\
    BUILTIN_OBJ(vstore_operatorKind_ADD),\
    BUILTIN_OBJ(vstore_operatorKind_SUB),\
    BUILTIN_OBJ(vstore_operatorKind_MUL),\
    BUILTIN_OBJ(vstore_operatorKind_DIV),\
    BUILTIN_OBJ(vstore_operatorKind_MOD),\
    BUILTIN_OBJ(vstore_operatorKind_INC),\
    BUILTIN_OBJ(vstore_operatorKind_DEC),\
    BUILTIN_OBJ(vstore_operatorKind_XOR),\
    BUILTIN_OBJ(vstore_operatorKind_OR),\
    BUILTIN_OBJ(vstore_operatorKind_AND),\
    BUILTIN_OBJ(vstore_operatorKind_NOT),\
    BUILTIN_OBJ(vstore_operatorKind_COND_OR),\
    BUILTIN_OBJ(vstore_operatorKind_COND_AND),\
    BUILTIN_OBJ(vstore_operatorKind_COND_NOT),\
    BUILTIN_OBJ(vstore_operatorKind_COND_EQ),\
    BUILTIN_OBJ(vstore_operatorKind_COND_NEQ),\
    BUILTIN_OBJ(vstore_operatorKind_COND_GT),\
    BUILTIN_OBJ(vstore_operatorKind_COND_LT),\
    BUILTIN_OBJ(vstore_operatorKind_COND_GTEQ),\
    BUILTIN_OBJ(vstore_operatorKind_COND_LTEQ),\
    BUILTIN_OBJ(vstore_operatorKind_SHIFT_LEFT),\
    BUILTIN_OBJ(vstore_operatorKind_SHIFT_RIGHT),\
    BUILTIN_OBJ(vstore_operatorKind_REF),\
    /* state */\
    BUILTIN_OBJ(lang_state_VALID),\
    BUILTIN_OBJ(lang_state_DELETED),\
    BUILTIN_OBJ(lang_state_DECLARED),\
    /* attr */\
    BUILTIN_OBJ(lang_attr_ATTR_NAMED),\
    BUILTIN_OBJ(lang_attr_ATTR_WRITABLE),\
    BUILTIN_OBJ(lang_attr_ATTR_OBSERVABLE),\
    BUILTIN_OBJ(lang_attr_ATTR_PERSISTENT),\
    BUILTIN_OBJ(lang_attr_ATTR_DEFAULT),\
    /* eventKind */\
    BUILTIN_OBJ(vstore_eventMask_DECLARE),\
    BUILTIN_OBJ(vstore_eventMask_DEFINE),\
    BUILTIN_OBJ(vstore_eventMask_DELETE),\
    BUILTIN_OBJ(vstore_eventMask_INVALIDATE),\
    BUILTIN_OBJ(vstore_eventMask_UPDATE),\
    BUILTIN_OBJ(vstore_eventMask_RESUME),\
    BUILTIN_OBJ(vstore_eventMask_SUSPEND),\
    BUILTIN_OBJ(vstore_eventMask_ON_SELF),\
    BUILTIN_OBJ(vstore_eventMask_ON_SCOPE),\
    BUILTIN_OBJ(vstore_eventMask_ON_TREE),\
    BUILTIN_OBJ(vstore_eventMask_ON_VALUE),\
    BUILTIN_OBJ(vstore_eventMask_ON_METAVALUE),\
    BUILTIN_OBJ(vstore_eventMask_ON_ANY),\
    /* modifierMask */\
    BUILTIN_OBJ(lang_modifierMask_GLOBAL),\
    BUILTIN_OBJ(lang_modifierMask_LOCAL),\
    BUILTIN_OBJ(lang_modifierMask_PRIVATE),\
    BUILTIN_OBJ(lang_modifierMask_READONLY),\
    BUILTIN_OBJ(lang_modifierMask_CONST),\
    BUILTIN_OBJ(lang_modifierMask_NOT_NULL),\
    BUILTIN_OBJ(lang_modifierMask_HIDDEN),\
    BUILTIN_OBJ(lang_modifierMask_OPTIONAL),\
    BUILTIN_OBJ(lang_modifierMask_OBSERVABLE),\
    BUILTIN_OBJ(lang_modifierMask_KEY),\
    /* resultMask */\
    BUILTIN_OBJ(vstore_resultMask_RESULT_LEAF),\
    BUILTIN_OBJ(vstore_resultMask_RESULT_HIDDEN),\
    /* type */\
    BUILTIN_OBJ(lang_type_kind),\
    BUILTIN_OBJ(lang_type_reference),\
    BUILTIN_OBJ(lang_type_attr),\
    BUILTIN_OBJ(lang_type_parent_type),\
    BUILTIN_OBJ(lang_type_parent_state),\
    BUILTIN_OBJ(lang_type_scope_type),\
    BUILTIN_OBJ(lang_type_scope_procedure_type),\
    BUILTIN_OBJ(lang_type_flags),\
    BUILTIN_OBJ(lang_type_size),\
    BUILTIN_OBJ(lang_type_alignment),\
    BUILTIN_OBJ(lang_type_metaprocedures),\
    BUILTIN_OBJ(lang_type_typecache),\
    BUILTIN_OBJ(lang_type_init),\
    BUILTIN_OBJ(lang_type_deinit),\
    BUILTIN_OBJ(lang_type_nameof),\
    BUILTIN_OBJ(lang_type_sizeof_),\
    BUILTIN_OBJ(lang_type_alignmentof_),\
    BUILTIN_OBJ(lang_type_compatible_),\
    BUILTIN_OBJ(lang_type_resolve_procedure_),\
    BUILTIN_OBJ(lang_type_castable_),\
    BUILTIN_OBJ(lang_type_init_),\
    BUILTIN_OBJ(lang_type_deinit_),\
    BUILTIN_OBJ(lang_type_construct_),\
    BUILTIN_OBJ(lang_type_destruct_),\
    /* primitive */\
    BUILTIN_OBJ(lang_primitive_kind),\
    BUILTIN_OBJ(lang_primitive_width),\
    BUILTIN_OBJ(lang_primitive_convert_id),\
    BUILTIN_OBJ(lang_primitive_init_),\
    BUILTIN_OBJ(lang_primitive_construct_),\
    BUILTIN_OBJ(lang_primitive_compatible_),\
    BUILTIN_OBJ(lang_primitive_castable_),\
    BUILTIN_OBJ(lang_primitive_isInteger_),\
    BUILTIN_OBJ(lang_primitive_isNumber_),\
    /* interface */\
    BUILTIN_OBJ(lang_interface_kind),\
    BUILTIN_OBJ(lang_interface_next_member_id),\
    BUILTIN_OBJ(lang_interface_members),\
    BUILTIN_OBJ(lang_interface_methods),\
    BUILTIN_OBJ(lang_interface_base),\
    BUILTIN_OBJ(lang_interface_init_),\
    BUILTIN_OBJ(lang_interface_construct_),\
    BUILTIN_OBJ(lang_interface_destruct_),\
    BUILTIN_OBJ(lang_interface_deinit_),\
    BUILTIN_OBJ(lang_interface_resolve_member_),\
    BUILTIN_OBJ(lang_interface_resolve_member_by_tag_),\
    BUILTIN_OBJ(lang_interface_compatible_),\
    BUILTIN_OBJ(lang_interface_resolve_method_),\
    BUILTIN_OBJ(lang_interface_resolve_method_id_),\
    BUILTIN_OBJ(lang_interface_resolve_method_by_id_),\
    BUILTIN_OBJ(lang_interface_baseof_),\
    /* collection */\
    BUILTIN_OBJ(lang_collection_kind),\
    BUILTIN_OBJ(lang_collection_element_type),\
    BUILTIN_OBJ(lang_collection_max),\
    BUILTIN_OBJ(lang_collection_castable_),\
    BUILTIN_OBJ(lang_collection_compatible_),\
    BUILTIN_OBJ(lang_collection_requires_alloc),\
    BUILTIN_OBJ(lang_collection_init_),\
    /* iterator */\
    BUILTIN_OBJ(lang_iterator_element_type),\
    BUILTIN_OBJ(lang_iterator_init_),\
    BUILTIN_OBJ(lang_iterator_castable_),\
    BUILTIN_OBJ(lang_iterator_compatible_),\
    /* binary */\
    BUILTIN_OBJ(lang_binary_init_),\
    /* boolean */\
    BUILTIN_OBJ(lang_boolean_init_),\
    /* char */\
    BUILTIN_OBJ(lang_character_init_),\
    /* int */\
    BUILTIN_OBJ(lang_int_min),\
    BUILTIN_OBJ(lang_int_max),\
    BUILTIN_OBJ(lang_int_init_),\
    /* uint */\
    BUILTIN_OBJ(lang_uint_min),\
    BUILTIN_OBJ(lang_uint_max),\
    BUILTIN_OBJ(lang_uint_init_),\
    /* float */\
    BUILTIN_OBJ(lang_float_min),\
    BUILTIN_OBJ(lang_float_max),\
    BUILTIN_OBJ(lang_float_init_),\
    /* text */\
    BUILTIN_OBJ(lang_text_char_width),\
    BUILTIN_OBJ(lang_text_length),\
    BUILTIN_OBJ(lang_text_init_),\
    /* verbatim */\
    BUILTIN_OBJ(lang_verbatim_format),\
    BUILTIN_OBJ(lang_verbatim_init_),\
    /* enum */\
    BUILTIN_OBJ(lang_enum_constants),\
    BUILTIN_OBJ(lang_enum_constant_from_value_),\
    BUILTIN_OBJ(lang_enum_constant_from_id_),\
    BUILTIN_OBJ(lang_enum_init_),\
    BUILTIN_OBJ(lang_enum_construct_),\
    BUILTIN_OBJ(lang_enum_destruct_),\
    /* bitmask */\
    BUILTIN_OBJ(lang_bitmask_init_),\
    /* struct */\
    BUILTIN_OBJ(lang_struct_base),\
    BUILTIN_OBJ(lang_struct_base_modifiers),\
    BUILTIN_OBJ(lang_struct_keys),\
    BUILTIN_OBJ(lang_struct_keycache),\
    BUILTIN_OBJ(lang_struct_init_),\
    BUILTIN_OBJ(lang_struct_construct_),\
    BUILTIN_OBJ(lang_struct_compatible_),\
    BUILTIN_OBJ(lang_struct_castable_),\
    BUILTIN_OBJ(lang_struct_resolve_member_),\
    /* union */\
    BUILTIN_OBJ(lang_union_discriminator),\
    BUILTIN_OBJ(lang_union_init_),\
    BUILTIN_OBJ(lang_union_construct_),\
    BUILTIN_OBJ(lang_union_findCase_),\
    /* procedure */\
    BUILTIN_OBJ(lang_procedure_has_this),\
    BUILTIN_OBJ(lang_procedure_this_type),\
    BUILTIN_OBJ(lang_procedure_init_),\
    BUILTIN_OBJ(lang_procedure_construct_),\
    /* interfaceVector */\
    BUILTIN_OBJ(lang_interfaceVector_interface),\
    BUILTIN_OBJ(lang_interfaceVector_vector),\
    /* class */\
    BUILTIN_OBJ(lang_class_base),\
    BUILTIN_OBJ(lang_class_base_modifiers),\
    BUILTIN_OBJ(lang_class_implements),\
    BUILTIN_OBJ(lang_class_interfaceVector),\
    BUILTIN_OBJ(lang_class_construct),\
    BUILTIN_OBJ(lang_class_define),\
    BUILTIN_OBJ(lang_class_validate),\
    BUILTIN_OBJ(lang_class_update),\
    BUILTIN_OBJ(lang_class_destruct),\
    BUILTIN_OBJ(lang_class_delete),\
    BUILTIN_OBJ(lang_class_init_),\
    BUILTIN_OBJ(lang_class_instanceof_),\
    BUILTIN_OBJ(lang_class_resolve_interface_method_),\
    /* leaf */\
    BUILTIN_OBJ(lang_container_construct_),\
    BUILTIN_OBJ(lang_container_type),\
    BUILTIN_OBJ(lang_container_value),\
    /* tableinstance */\
    BUILTIN_OBJ(lang_tableinstance_type),\
    /* table */\
    BUILTIN_OBJ(lang_table_construct_),\
    /* mount_subscription */\
    BUILTIN_OBJ(vstore_mount_subscription_query),\
    BUILTIN_OBJ(vstore_mount_subscription_mountCount),\
    BUILTIN_OBJ(vstore_mount_subscription_subscriberCount),\
    BUILTIN_OBJ(vstore_mount_subscription_mountCtx),\
    BUILTIN_OBJ(vstore_mount_subscription_subscriberCtx),\
    /* query */\
    BUILTIN_OBJ(vstore_query_select),\
    BUILTIN_OBJ(vstore_query_from),\
    BUILTIN_OBJ(vstore_query_type),\
    BUILTIN_OBJ(vstore_query_instanceof),\
    BUILTIN_OBJ(vstore_query_member),\
    BUILTIN_OBJ(vstore_query_where),\
    BUILTIN_OBJ(vstore_query_offset),\
    BUILTIN_OBJ(vstore_query_limit),\
    BUILTIN_OBJ(vstore_query_soffset),\
    BUILTIN_OBJ(vstore_query_slimit),\
    BUILTIN_OBJ(vstore_query_frame_begin),\
    BUILTIN_OBJ(vstore_query_frame_end),\
    BUILTIN_OBJ(vstore_query_content),\
    BUILTIN_OBJ(vstore_query_yield_unknown),\
    BUILTIN_OBJ(vstore_query_cardinality_),\
    BUILTIN_OBJ(vstore_query_match_),\
    /* subscriber */\
    BUILTIN_OBJ(vstore_subscriber_query),\
    BUILTIN_OBJ(vstore_subscriber_format),\
    BUILTIN_OBJ(vstore_subscriber_instance),\
    BUILTIN_OBJ(vstore_subscriber_dispatcher),\
    BUILTIN_OBJ(vstore_subscriber_enabled),\
    BUILTIN_OBJ(vstore_subscriber_fmt_handle),\
    BUILTIN_OBJ(vstore_subscriber_idmatch),\
    BUILTIN_OBJ(vstore_subscriber_isAligning),\
    BUILTIN_OBJ(vstore_subscriber_alignMutex),\
    BUILTIN_OBJ(vstore_subscriber_alignQueue),\
    BUILTIN_OBJ(vstore_subscriber_init_),\
    BUILTIN_OBJ(vstore_subscriber_deinit_),\
    BUILTIN_OBJ(vstore_subscriber_construct_),\
    BUILTIN_OBJ(vstore_subscriber_define_),\
    BUILTIN_OBJ(vstore_subscriber_destruct_),\
    BUILTIN_OBJ(vstore_subscriber_subscribe_),\
    BUILTIN_OBJ(vstore_subscriber_unsubscribe_),\
    /* router */\
    BUILTIN_OBJ(vstore_router_init_),\
    BUILTIN_OBJ(vstore_router_construct_),\
    BUILTIN_OBJ(vstore_router_match),\
    BUILTIN_OBJ(vstore_router_return_type),\
    BUILTIN_OBJ(vstore_router_param_type),\
    BUILTIN_OBJ(vstore_router_param_name),\
    BUILTIN_OBJ(vstore_router_router_data_type),\
    BUILTIN_OBJ(vstore_router_router_data_name),\
    BUILTIN_OBJ(vstore_router_element_separator),\
    /* routerimpl */\
    BUILTIN_OBJ(vstore_routerimpl_construct_),\
    BUILTIN_OBJ(vstore_routerimpl_destruct_),\
    BUILTIN_OBJ(vstore_routerimpl_maxArgs),\
    BUILTIN_OBJ(vstore_routerimpl_matched),\
    BUILTIN_OBJ(vstore_routerimpl_match_route_),\
    BUILTIN_OBJ(vstore_routerimpl_find_route_),\
    /* mount */\
    BUILTIN_OBJ(vstore_mount_attr),\
    BUILTIN_OBJ(vstore_mount_ownership),\
    BUILTIN_OBJ(vstore_mount_callbacks),\
    BUILTIN_OBJ(vstore_mount_sample_rate),\
    BUILTIN_OBJ(vstore_mount_queue_max),\
    BUILTIN_OBJ(vstore_mount_expiry_time),\
    BUILTIN_OBJ(vstore_mount_filter_results),\
    BUILTIN_OBJ(vstore_mount_subscriptions),\
    BUILTIN_OBJ(vstore_mount_events),\
    BUILTIN_OBJ(vstore_mount_historicalEvents),\
    BUILTIN_OBJ(vstore_mount_lastPoll),\
    BUILTIN_OBJ(vstore_mount_lastPost),\
    BUILTIN_OBJ(vstore_mount_lastSleep),\
    BUILTIN_OBJ(vstore_mount_dueSleep),\
    BUILTIN_OBJ(vstore_mount_lastQueueSize),\
    BUILTIN_OBJ(vstore_mount_passThrough),\
    BUILTIN_OBJ(vstore_mount_explicitResume),\
    BUILTIN_OBJ(vstore_mount_thread),\
    BUILTIN_OBJ(vstore_mount_quit),\
    BUILTIN_OBJ(vstore_mount_formatOut),\
    BUILTIN_OBJ(vstore_mount_formatOutHandle),\
    BUILTIN_OBJ(vstore_mount_init_),\
    BUILTIN_OBJ(vstore_mount_construct_),\
    BUILTIN_OBJ(vstore_mount_destruct_),\
    BUILTIN_OBJ(vstore_mount_invoke_),\
    BUILTIN_OBJ(vstore_mount_id_),\
    BUILTIN_OBJ(vstore_mount_query_),\
    BUILTIN_OBJ(vstore_mount_historyQuery_),\
    BUILTIN_OBJ(vstore_mount_resume_),\
    BUILTIN_OBJ(vstore_mount_subscribe_),\
    BUILTIN_OBJ(vstore_mount_unsubscribe_),\
    BUILTIN_OBJ(vstore_mount_set_format_),\
    BUILTIN_OBJ(vstore_mount_set_formatIn_),\
    BUILTIN_OBJ(vstore_mount_set_formatOut_),\
    BUILTIN_OBJ(vstore_mount_return_),\
    BUILTIN_OBJ(vstore_mount_publish_),\
    BUILTIN_OBJ(vstore_mount_post_),\
    BUILTIN_OBJ(vstore_mount_onPoll_),\
    BUILTIN_OBJ(vstore_mount_on_notify_),\
    BUILTIN_OBJ(vstore_mount_on_batch_notify_),\
    BUILTIN_OBJ(vstore_mount_on_history_batch_notify_),\
    BUILTIN_OBJ(vstore_mount_on_invoke_),\
    BUILTIN_OBJ(vstore_mount_on_id_),\
    BUILTIN_OBJ(vstore_mount_on_query_),\
    BUILTIN_OBJ(vstore_mount_on_history_query_),\
    BUILTIN_OBJ(vstore_mount_on_resume_),\
    BUILTIN_OBJ(vstore_mount_on_subscribe_),\
    BUILTIN_OBJ(vstore_mount_on_unsubscribe_),\
    BUILTIN_OBJ(vstore_mount_on_mount_),\
    BUILTIN_OBJ(vstore_mount_on_unmount_),\
    BUILTIN_OBJ(vstore_mount_on_transaction_begin_),\
    BUILTIN_OBJ(vstore_mount_on_transaction_end_),\
    /* loader */\
    BUILTIN_OBJ(vstore_loader_autoLoad),\
    BUILTIN_OBJ(vstore_loader_construct_),\
    BUILTIN_OBJ(vstore_loader_destruct_),\
    BUILTIN_OBJ(vstore_loader_on_query_),\
    BUILTIN_OBJ(vstore_loader_on_resume_),\
    /* delegatedata */\
    BUILTIN_OBJ(lang_delegatedata_instance),\
    BUILTIN_OBJ(lang_delegatedata_procedure),\
    /* delegate */\
    BUILTIN_OBJ(lang_delegate_return_type),\
    BUILTIN_OBJ(lang_delegate_is_reference),\
    BUILTIN_OBJ(lang_delegate_parameters),\
    BUILTIN_OBJ(lang_delegate_init_),\
    BUILTIN_OBJ(lang_delegate_construct_),\
    BUILTIN_OBJ(lang_delegate_compatible_),\
    BUILTIN_OBJ(lang_delegate_castable_),\
    BUILTIN_OBJ(lang_delegate_instanceof_),\
    BUILTIN_OBJ(lang_delegate_bind),\
    /* target */\
    BUILTIN_OBJ(lang_target_type),\
    BUILTIN_OBJ(lang_target_construct_),\
    /* quantity */\
    BUILTIN_OBJ(lang_quantity_base_unit),\
    /* tag */\
    /* unit */\
    BUILTIN_OBJ(lang_unit_quantity),\
    BUILTIN_OBJ(lang_unit_symbol),\
    BUILTIN_OBJ(lang_unit_conversion),\
    BUILTIN_OBJ(lang_unit_type),\
    BUILTIN_OBJ(lang_unit_toQuantity),\
    BUILTIN_OBJ(lang_unit_fromQuantity),\
    BUILTIN_OBJ(lang_unit_init_),\
    BUILTIN_OBJ(lang_unit_construct_),\
    /* array */\
    BUILTIN_OBJ(lang_array_element_type),\
    BUILTIN_OBJ(lang_array_init_),\
    BUILTIN_OBJ(lang_array_construct_),\
    BUILTIN_OBJ(lang_array_destruct_),\
    /* sequence */\
    BUILTIN_OBJ(lang_sequence_init_),\
    BUILTIN_OBJ(lang_sequence_construct_),\
    /* list */\
    BUILTIN_OBJ(lang_list_init_),\
    BUILTIN_OBJ(lang_list_construct_),\
    /* map */\
    BUILTIN_OBJ(lang_map_key_type),\
    BUILTIN_OBJ(lang_map_element_type),\
    BUILTIN_OBJ(lang_map_max),\
    BUILTIN_OBJ(lang_map_init_),\
    BUILTIN_OBJ(lang_map_construct_),\
    /* member */\
    BUILTIN_OBJ(lang_member_type),\
    BUILTIN_OBJ(lang_member_modifiers),\
    BUILTIN_OBJ(lang_member_default),\
    BUILTIN_OBJ(lang_member_unit),\
    BUILTIN_OBJ(lang_member_tags),\
    BUILTIN_OBJ(lang_member_state),\
    BUILTIN_OBJ(lang_member_stateCondExpr),\
    BUILTIN_OBJ(lang_member_id),\
    BUILTIN_OBJ(lang_member_offset),\
    BUILTIN_OBJ(lang_member_init_),\
    BUILTIN_OBJ(lang_member_construct_),\
    /* alias */\
    BUILTIN_OBJ(lang_alias_member),\
    BUILTIN_OBJ(lang_alias_construct_),\
    /* case */\
    BUILTIN_OBJ(lang_case_discriminator),\
    BUILTIN_OBJ(lang_case_type),\
    BUILTIN_OBJ(lang_case_modifiers),\
    /* default */\
    BUILTIN_OBJ(lang_default_type),\
    /* parameter */\
    BUILTIN_OBJ(lang_parameter_name),\
    BUILTIN_OBJ(lang_parameter_type),\
    BUILTIN_OBJ(lang_parameter_inout),\
    BUILTIN_OBJ(lang_parameter_is_reference),\
    /* sample */\
    BUILTIN_OBJ(vstore_sample_timestamp),\
    BUILTIN_OBJ(vstore_sample_value),\
    /* result */\
    BUILTIN_OBJ(vstore_result_id),\
    BUILTIN_OBJ(vstore_result_name),\
    BUILTIN_OBJ(vstore_result_parent),\
    BUILTIN_OBJ(vstore_result_type),\
    BUILTIN_OBJ(vstore_result_value),\
    BUILTIN_OBJ(vstore_result_flags),\
    BUILTIN_OBJ(vstore_result_object),\
    BUILTIN_OBJ(vstore_result_history),\
    BUILTIN_OBJ(vstore_result_owner),\
    BUILTIN_OBJ(vstore_result_get_text_),\
    BUILTIN_OBJ(vstore_result_fromcontent_),\
    BUILTIN_OBJ(vstore_result_contentof_),\
    /* package */\
    BUILTIN_OBJ(lang_package_description),\
    BUILTIN_OBJ(lang_package_version),\
    BUILTIN_OBJ(lang_package_author),\
    BUILTIN_OBJ(lang_package_organization),\
    BUILTIN_OBJ(lang_package_url),\
    BUILTIN_OBJ(lang_package_repository),\
    BUILTIN_OBJ(lang_package_license),\
    BUILTIN_OBJ(lang_package_icon),\
    BUILTIN_OBJ(lang_package_use),\
    BUILTIN_OBJ(lang_package_public),\
    BUILTIN_OBJ(lang_package_managed),\
    BUILTIN_OBJ(lang_package_init_),\
    BUILTIN_OBJ(lang_package_define_),\
    /* time */\
    BUILTIN_OBJ(vstore_time_sec),\
    BUILTIN_OBJ(vstore_time_nanosec),\
    /* frame */\
    BUILTIN_OBJ(vstore_frame_kind),\
    BUILTIN_OBJ(vstore_frame_value),\
    BUILTIN_OBJ(vstore_frame_getTime_),\
    /* native/type */\
    BUILTIN_OBJ(native_type_name),\
    BUILTIN_OBJ(native_type_init_),\
    /* secure/key */\
    BUILTIN_OBJ(secure_key_enabled),\
    BUILTIN_OBJ(secure_key_construct_),\
    BUILTIN_OBJ(secure_key_destruct_),\
    BUILTIN_OBJ(secure_key_login_),\
    BUILTIN_OBJ(secure_key_logout_),\
    /* secure/lock */\
    BUILTIN_OBJ(secure_lock_query),\
    BUILTIN_OBJ(secure_lock_priority),\
    BUILTIN_OBJ(secure_lock_construct_),\
    BUILTIN_OBJ(secure_lock_destruct_),\
    BUILTIN_OBJ(secure_lock_authorize_)\


typedef struct corto_bootstrapElement {
    corto_object o;
    size_t size;
} corto_bootstrapElement;

corto_bootstrapElement types[] = {
    BUILTIN_TYPE(),
    {NULL, 0}
};

corto_bootstrapElement objects[] = {
    BUILTIN_OBJECT(),
    {NULL, 0}
};

/* Initialization of objects */
static
void corto_init_builtin_object(
    corto_object o)
{
    corto_init_builtin(o);
    corto_walk_opt s = corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_walk(&s, o, NULL);
    corto_type t = corto_typeof(o);
    corto_invoke_preDelegate(&t->init, t, o);
}

/* Define object */
static
void corto_define_builtin(
    corto_object o)
{
    if (corto_define(o)) {
        corto_throw("failed to define builtin-object '%s'", corto_idof(o));
    }
}

/* Define type (same as define_builtin, but with additional size check) */
static
void corto_define_builtin_type(
    corto_object o,
    corto_uint32 size)
{
    corto_define_builtin(o);

    if (corto_type(o)->size != size) {
        corto_error(
          "size validation failed for type '%s' - metatype = %d, c-type = %d.",
          corto_fullpath(NULL, o), corto_type(o)->size, size);
    }
}

static
void corto_genericTlsFree(
    void *o)
{
    free(o);
}

/* Sequences are types that are allocated on the heap, and are therefore not
 * created statically. This function manually creates the necessary sequences
 * for builtin objects. */
static
void corto_init_sequences(void) {
    /* Mount implements dispatcher */
    corto_mount_o->implements.length = 1;
    corto_mount_o->implements.buffer = corto_alloc(sizeof(corto_object));
    corto_mount_o->implements.buffer[0] = corto_dispatcher_o;

    /* Add parameter to handleAction */
    corto_handleAction_o->parameters.length = 1;
    corto_handleAction_o->parameters.buffer = corto_calloc(sizeof(corto_parameter));
    corto_parameter *p = &corto_handleAction_o->parameters.buffer[0];
    p->type = (corto_type)corto_event_o;
    p->name = "event";
}

/* Manually free the sequences in builtin objects */
static
void corto_deinit_sequences(void) {
    /* Mount implements dispatcher */
    free (corto_mount_o->implements.buffer);
    corto_mount_o->implements.length = 0;

    free (corto_handleAction_o->parameters.buffer);
    corto_handleAction_o->parameters.length = 0;
}

/* Initialize mandatory corto environment variables if they are not set */
static
void corto_environment_init(void)
{
/* Only set environment variables if library is installed as corto package */

    /* If there is no home directory, default to /usr/local. This should be
     * avoided in development environments. */
    if (!corto_getenv("HOME") || !strlen(corto_getenv("HOME"))) {
        corto_setenv("HOME", "/usr/local");
    }

    /* BAKE_VERSION points to the current major-minor version */
    if (!corto_getenv("BAKE_VERSION")) {
        corto_setenv("BAKE_VERSION", VERSION_MAJOR "." VERSION_MINOR);
    }

    if (!corto_getenv("BAKE_HOME")) {
        corto_setenv("BAKE_HOME", ".");
    }

    if (!corto_getenv("BAKE_TARGET")) {
        corto_setenv("BAKE_TARGET", ".");
    }

    corto_string enableBacktrace = corto_getenv("CORTO_LOG_BACKTRACE");
    if (enableBacktrace) {
        CORTO_LOG_BACKTRACE = !strcmp(enableBacktrace, "true");
    }

    corto_string errfmt = corto_getenv("CORTO_LOG_FORMAT");
    if (errfmt && errfmt[0]) {
        corto_log_fmt(errfmt);
    }
}

/* Function for automatically loading all configuration files in a path that is
 * specified in the $CORTO_CONFIG environment variable. This function is
 * typically called from the gen/_project.c file in managed corto projects. */
int corto_load_config(void)
{
    int result = 0;
    corto_debug("load configuration");
    corto_log_push("config");
    char *cfg = corto_getenv("CORTO_CONFIG");
    if (cfg) {
        if (corto_isdir(cfg)) {
            corto_trace("loading configuration");
            corto_ll cfgfiles = corto_opendir(cfg);
            corto_iter it = corto_ll_iter(cfgfiles);
            while (corto_iter_hasNext(&it)) {
                char *file = corto_iter_next(&it);
                char *full_path = corto_asprintf("%s/%s", cfg, file);
                if (corto_use(full_path, 0, NULL)) {
                    corto_raise();
                    result = -1;
                    /* Don't break, report all errors */
                } else {
                    corto_ok("successfuly loaded '%s'", file);
                }
                free(full_path);
            }
            corto_closedir(cfgfiles);
        } else if (corto_file_test(cfg)) {
            if (corto_use(cfg, 0, NULL)) {
                result = -1;
            }
        } else {
            corto_trace(
                "$CORTO_CONFIG ('%s') does not point to an accessible "
                "path or file",
                cfg);
        }
    }
    corto_log_pop();

    return result;
}

/* Bootstrapping corto. Must be called before doing anything else and must only
 * be called once. */
int corto_start(
    char *appName)
{
    CORTO_APP_STATUS = 1; /* Initializing */

    corto_appName = appName;
    if ((appName[0] == '.') && (appName[1] == '/')) {
        corto_appName += 2;
    }

    /* Initialize platform abstraction layer */
    corto_platform_init(appName);

    /* Initialize TLS keys */
    corto_tls_new(&CORTO_KEY_OBSERVER_ADMIN, corto_observerAdminFree);
    corto_tls_new(&CORTO_KEY_DECLARED_ADMIN, corto_declaredByMeFree);
    corto_tls_new(&CORTO_KEY_LISTEN_ADMIN, NULL);
    corto_tls_new(&CORTO_KEY_OWNER, NULL);
    corto_tls_new(&CORTO_KEY_ATTR, corto_genericTlsFree);
    corto_tls_new(&CORTO_KEY_FLUENT, NULL);
    corto_tls_new(&CORTO_KEY_MOUNT_RESULT, NULL);
    corto_tls_new(&CORTO_KEY_CONSTRUCTOR_TYPE, NULL);
    corto_tls_new(&corto_subscriber_admin.key, corto_entityAdmin_free);
    corto_tls_new(&corto_mount_admin.key, corto_entityAdmin_free);

    /* If BAKE_HOME is not set to a public package repository, default to
     * standalone mode */
    char *BAKE_HOME = corto_getenv("BAKE_HOME");
    bool standalone = !BAKE_HOME || !BAKE_HOME[0];

    /* Initialize operating system environment */
    corto_environment_init();

#ifndef NDEBUG
    corto_ok("using corto #[yellow]debug#[normal] runtime, use a release build for better performance");
#else
    corto_ok("using corto #[green]release#[normal] runtime, use a debug build to enable runtime sanity checks");
#endif

    /* Push init component for logging */
    corto_log_push("init");

    corto_trace("initializing...");

    /* Initialize loader */
    corto_load_init(
        corto_getenv("BAKE_TARGET"),
        corto_getenv("BAKE_HOME"),
        corto_getenv("BAKE_VERSION"),
        corto_get_build(),
        standalone);

    if (standalone) {
        corto_trace("standalone mode enabled");
    }

    /* Initialize security */
    corto_debug("init security");
    corto_secure_init();

    /* Register CDECL as first binding */
    corto_debug("init C binding");
    if (corto_invoke_register(corto_cdeclInit, corto_cdeclDeinit) != CORTO_PROCEDURE_CDECL) {
        /* Sanity check */
        corto_critical("CDECL binding did not register with id 1");
    }

    corto_debug("init global administration");

    /* Init admin-lock */
    corto_mutex_new(&corto_adminLock);
    corto_rwmutex_new(&corto_subscriberLock);

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
    corto_o->version = (char*)VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
    corto_lang_o->version = (char*)VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
    corto_vstore_o->version = (char*)VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
    corto_secure_o->version = (char*)VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;
    corto_native_o->version = (char*)VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH;

    /* Initialize builtin scopes */
    corto_debug("init builtin packages");
    corto_init_builtin_object(root_o);
    corto_init_builtin_object(corto_o);
    corto_init_builtin_object(corto_lang_o);
    corto_init_builtin_object(corto_vstore_o);
    corto_init_builtin_object(corto_native_o);
    corto_init_builtin_object(corto_secure_o);

    /* Define builtin scopes */
    corto_define_builtin(root_o);
    corto_define_builtin(corto_o);
    corto_define_builtin(corto_lang_o);
    corto_define_builtin(corto_vstore_o);
    corto_define_builtin(corto_native_o);
    corto_define_builtin(corto_secure_o);

    /* Because at this point the construct/destruct & init/deinit delegates are
     * not yet propagated from base classes to sub classes, type construction
     * can't begin yet. First, delegates need to be properly initialized for
     * all types. This only affects types that support inheritance, so all
     * types that inherit from interface. */

    corto_debug("init delegates");
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
                if (corto_interface_pullDelegate(o, &lang_class_define__o.v)) {
                    ((corto_type)o)->flags |= CORTO_TYPE_HAS_DEFINE;
                }
                if (corto_interface_pullDelegate(o, &lang_class_destruct__o.v)) {
                    ((corto_type)o)->flags |= CORTO_TYPE_HAS_DESTRUCT;
                }

                /* Other delegates are not relevant for construction of types */
            }
        }
    }

    /* Init objects */
    corto_debug("init builtin objects");
    for (i = 0; (o = types[i].o); i++) corto_init_builtin_object(o);
    for (i = 0; (o = objects[i].o); i++) corto_init_builtin_object(o);

    /* Patch sequences- these aren't set statically since sequences are
     * allocated on the heap */
    corto_init_sequences();

    /* Mark the tableinstance type as a container. Even though it does not
     * inherit from the container base class, object management should treat it
     * as one (automatically defining / declaring child objects) */
    ((corto_type)corto_tableinstance_o)->flags |= CORTO_TYPE_IS_CONTAINER;

    /* Manually assign two function objects that are used as delegate callbacks */
    corto_observer_event_handle_o = &vstore_observer_event_handle__o.v;
    corto_subscriber_event_handle_o = &vstore_subscriber_event_handle__o.v;

    /* Construct objects */
    for (i = 0; (o = objects[i].o); i++) corto_define_builtin(o);
    for (i = 0; (o = types[i].o); i++) corto_define_builtin_type(o, types[i].size);

    /* Initialize conversions and operators */
    corto_ptr_castInit();
    corto_ptr_operatorInit();

    /* Register exit-handler */
    void corto_loaderOnExit(void* ctx);
    corto_atexit(corto_loaderOnExit, NULL);

    /* Register library-binding */
    corto_debug("init builtin file extensions");

    int corto_load_libraryAction(corto_string file, int argc, char* argv[], void *data);
    corto_load_register("so", corto_load_libraryAction, NULL);

    int corto_file_loader(corto_string file, int argc, char* argv[], void *data);
    corto_load_register("", corto_file_loader, NULL);

    /* Randomize seed by default (application can easily override by calling
     * srand again) */
    srand (time(NULL));

    CORTO_APP_STATUS = 0; /* Running */

    /* Create builtin root scopes */
    corto_debug("init root scopes");

    config_o = corto(CORTO_DECLARE|CORTO_DEFINE|CORTO_FORCE_TYPE,
        {.parent = root_o, .id = "config", .type = corto_void_o});

    data_o = corto(CORTO_DECLARE|CORTO_DEFINE|CORTO_FORCE_TYPE,
        {.parent = root_o, .id = "data", .type = corto_void_o});

    home_o = corto(CORTO_DECLARE|CORTO_DEFINE|CORTO_FORCE_TYPE,
        {.parent = root_o, .id = "home", .type = corto_void_o});

/* Only create package mount for non-redistributable version of corto, where
 * packages are installed in a common location */
    corto_debug("init package loader");

    corto_loaderInstance = corto(CORTO_DECLARE|CORTO_DEFINE|CORTO_FORCE_TYPE,
        {.parent = config_o, .id = "loader", .type = corto_loader_o});

    if (corto_loaderInstance) {
        corto_loaderInstance->autoLoad = TRUE;
    } else {
        corto_raise();
        corto_trace("autoloading of packages disabled");
    }

    /* Pop init log component */
    corto_log_pop();

    return 0;
}

/* Register exithandler */
void corto_atexit(
    void(*handler)(void*),
    void* userData)
{
    struct corto_exitHandler* h;

    h = corto_alloc(sizeof(struct corto_exitHandler));
    h->handler = handler;
    h->userData = userData;

    corto_mutex_lock(&corto_adminLock);
    if (!corto_exitHandlers) {
        corto_exitHandlers = corto_ll_new();
    }
    corto_ll_insert(corto_exitHandlers, h);
    corto_mutex_unlock(&corto_adminLock);
}

/* Shutdown corto. After this corto will occupy no more resources. Calling corto
 * functions after corto_stop has been called causes undefined behavior. */
int corto_stop(void)
{
    corto_log_push("fini");

    corto_trace("shutting down...");

    /* If an application modified the source of the mainthread but has not reset
     * this value, it may interfere with cleaning up resources so abort */
    if (corto_get_source()) {
        corto_error("owner has not been reset to NULL before shutting down");
        abort();
    }

    if (corto_loaderInstance) {
        corto_debug("cleanup package loader");
        //corto_release(corto_loaderInstance);
    }

    /* Drop the rootscope. This will not actually result
     * in removing the rootscope itself, but it will result in the
     * removal of all non-builtin objects. */
    corto_debug("cleanup objects");

    if (CORTO_TRACE_MEM) corto_log_push("SHUTDOWN_COLLECT");
    corto_collect(root_o, CORTO_COLLECT_CYCLES);
    if (CORTO_TRACE_MEM) corto_log_pop();

    corto_int32 i;
    corto_object o;

    /* From here things get funky, because we're going to deinitialize builtin
     * structures. Signal that corto is shutting down */
    CORTO_APP_STATUS = 2;

    /* Destruct objects */
    corto_debug("cleanup builtin objects");

    uint32_t types_count = 0;
    for (i = 0; (o = types[i].o); i++) {
        corto_destruct(o, false, true);
        types_count ++;
    }

    uint32_t objects_count = 0;
    for (i = 0; (o = objects[i].o); i++) {
        corto_destruct(o, false, true);
        objects_count ++;
    }

    /* Deinitialize objects in reverse order, as deinitialization cleans up the
     * typecaches required for cleaning up */
    for (i = objects_count - 1; i >= 0; i--) {
        corto_deinit_builtin(objects[i].o);
    }
    for (i = types_count - 1; i >= 0; i--) {
        corto_deinit_builtin(types[i].o);
    }

    if (corto_deinit_builtin(corto_native_o)) goto error;
    if (corto_deinit_builtin(corto_secure_o)) goto error;
    if (corto_deinit_builtin(corto_vstore_o)) goto error;
    if (corto_deinit_builtin(corto_lang_o)) goto error;
    if (corto_deinit_builtin(corto_o)) goto error;
    if (corto_deinit_builtin(root_o)) goto error;

    /* Free manually initialized sequences */
    corto_deinit_sequences();

    /* Free global entity administrations */
    corto_entityAdmin_free_contents(&corto_subscriber_admin, true);
    corto_entityAdmin_free_contents(&corto_mount_admin, true);

    /* Deinit adminLock */
    corto_debug("cleanup global administration");
    corto_mutex_free(&corto_adminLock);
    corto_rwmutex_free(&corto_subscriberLock);

    corto_log_pop();
    corto_fmt_deinit();
    corto_platform_deinit();

    /* Call exithandlers. Do after corto_platform_deinit as this will unload any
     * loaded libraries, which may have routines to cleanup TLS data. */
    struct corto_exitHandler* h;

    if (corto_exitHandlers) {
        while((h = corto_ll_takeFirst(corto_exitHandlers))) {
            h->handler(h->userData);
            corto_dealloc(h);
        }
        corto_ll_free(corto_exitHandlers);
        corto_exitHandlers = NULL;
    }

    /* Corto is now shut down */
    CORTO_APP_STATUS = 3;

    /* Cleanup any TLS data in the mainthread not created through corto. Don't
     * enable this by default as it will exit the process with exit status 0,
     * which prevents the application from specifying a custom exit code. */
    if (CORTO_COLLECT_TLS) {
        pthread_exit(0);
    }

    return 0;
error:
    return -1;
}

/* Get current build. Used to check if packages link with correct corto lib */
corto_string corto_get_build(void) {
    return CORTO_BUILD;
}

/* Enable or disable autoloading of packages when a package object is created */
bool corto_autoload(bool autoload)
{
    bool prev = false;

    if (corto_loaderInstance) {
        prev = corto_loaderInstance->autoLoad;
        corto_loaderInstance->autoLoad = autoload;
    }

    return prev;
}

/* Enable or disable package loader mount. */
corto_bool corto_enable_load(corto_bool enable)
{
    corto_bool prev = FALSE;
    if (!enable) {
        if (corto_loaderInstance) {
            corto_delete(corto_loaderInstance);
            corto_loaderInstance = NULL;
            prev = TRUE;
        }
    } else {
        if (!corto_loaderInstance) {
            corto_loaderInstance = corto_create(
                root_o, "config/loader", corto_loader_o);
        } else {
            prev = TRUE;
        }
    }

    return prev;
}

/* Assert object is of specified type. Used in generated type macro's. */
corto_object _corto_assert_type(
    corto_type type,
    corto_object o)
{
    corto_assert_object(type);
    corto_assert_object(o);

    if (o && (corto_typeof(o) != type)) {
        if (!_corto_instanceof(type, o)) {
            corto_error("object '%s' is not an instance of '%s'\n   type = %s",
                corto_fullpath(NULL, o),
                corto_fullpath(NULL, type),
                corto_fullpath(NULL, corto_typeof(o)));
            corto_backtrace(stdout);
            abort();
        }
    }
    return o;
}

/* Assert object is valid. Only enabled in debug builds */
#ifndef NDEBUG
void _corto_assert_object(char const *file, unsigned int line, corto_object o) {
    if (o) {
        corto__object *_o = corto_hdr(o);
        if (_o->magic != CORTO_MAGIC) {
            if (_o->magic == CORTO_MAGIC_DESTRUCT) {
                corto_critical_fl(
                    file,
                    line,
                    "address <%p> points to an object that is already deleted",
                    o);
            } else {
                corto_critical_fl(
                    file,
                    line,
                    "address <%p> does not point to an object", o);
            }
        }
    }
}
#endif
