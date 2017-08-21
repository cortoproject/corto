/* _type.h
 *
 * This file contains generated C type definitions.
 * You should not manually modify the contents of this file.
 */

#ifndef CORTO_CORE__TYPE_H
#define CORTO_CORE__TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_package(o) ((corto_package)corto_assertType((corto_type)corto_package_o, o))
#define corto_application(o) ((corto_application)corto_assertType((corto_type)corto_application_o, o))
#define corto_dispatcher(o) ((corto_dispatcher)corto_assertType((corto_type)corto_dispatcher_o, o))
#define corto_handleAction(o) ((corto_handleAction*)corto_assertType((corto_type)corto_handleAction_o, o))
#define corto_event(o) ((corto_event*)corto_assertType((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask*)corto_assertType((corto_type)corto_eventMask_o, o))
#define corto_frameKind(o) ((corto_frameKind*)corto_assertType((corto_type)corto_frameKind_o, o))
#define corto_frame(o) ((corto_frame*)corto_assertType((corto_type)corto_frame_o, o))
#define corto_observer(o) ((corto_observer)corto_assertType((corto_type)corto_observer_o, o))
#define corto_query(o) ((corto_query*)corto_assertType((corto_type)corto_query_o, o))
#define corto_subscriber(o) ((corto_subscriber)corto_assertType((corto_type)corto_subscriber_o, o))
#define corto_ownership(o) ((corto_ownership*)corto_assertType((corto_type)corto_ownership_o, o))
#define corto_mountMask(o) ((corto_mountMask*)corto_assertType((corto_type)corto_mountMask_o, o))
#define corto_mountPolicy(o) ((corto_mountPolicy*)corto_assertType((corto_type)corto_mountPolicy_o, o))
#define corto_mountStats(o) ((corto_mountStats*)corto_assertType((corto_type)corto_mountStats_o, o))
#define corto_mountSubscription(o) ((corto_mountSubscription*)corto_assertType((corto_type)corto_mountSubscription_o, o))
#define corto_mountSubscriptionList(o) ((corto_mountSubscriptionList*)corto_assertType((corto_type)corto_mountSubscriptionList_o, o))
#define corto_mount(o) ((corto_mount)corto_assertType((corto_type)corto_mount_o, o))
#define corto_invokeEvent(o) ((corto_invokeEvent)corto_assertType((corto_type)corto_invokeEvent_o, o))
#define corto_loader(o) ((corto_loader)corto_assertType((corto_type)corto_loader_o, o))
#define corto_objectIter(o) ((corto_objectIter*)corto_assertType((corto_type)corto_objectIter_o, o))
#define corto_observerEvent(o) ((corto_observerEvent*)corto_assertType((corto_type)corto_observerEvent_o, o))
#define corto_operatorKind(o) ((corto_operatorKind*)corto_assertType((corto_type)corto_operatorKind_o, o))
#define corto_position(o) ((corto_position*)corto_assertType((corto_type)corto_position_o, o))
#define corto_remote(o) ((corto_remote)corto_assertType((corto_type)corto_remote_o, o))
#define corto_resultMask(o) ((corto_resultMask*)corto_assertType((corto_type)corto_resultMask_o, o))
#define corto_time(o) ((corto_time*)corto_assertType((corto_type)corto_time_o, o))
#define corto_sample(o) ((corto_sample*)corto_assertType((corto_type)corto_sample_o, o))
#define corto_sampleIter(o) ((corto_sampleIter*)corto_assertType((corto_type)corto_sampleIter_o, o))
#define corto_result(o) ((corto_result*)corto_assertType((corto_type)corto_result_o, o))
#define corto_resultIter(o) ((corto_resultIter*)corto_assertType((corto_type)corto_resultIter_o, o))
#define corto_resultList(o) ((corto_resultList*)corto_assertType((corto_type)corto_resultList_o, o))
#define corto_route(o) ((corto_route)corto_assertType((corto_type)corto_route_o, o))
#define corto_router(o) ((corto_router)corto_assertType((corto_type)corto_router_o, o))
#define corto_routerimpl(o) ((corto_routerimpl)corto_assertType((corto_type)corto_routerimpl_o, o))
#define corto_stager(o) ((corto_stager)corto_assertType((corto_type)corto_stager_o, o))
#define corto_subscriberEvent(o) ((corto_subscriberEvent*)corto_assertType((corto_type)corto_subscriberEvent_o, o))
#define corto_subscriberEventIter(o) ((corto_subscriberEventIter*)corto_assertType((corto_type)corto_subscriberEventIter_o, o))
#define corto_tool(o) ((corto_tool)corto_assertType((corto_type)corto_tool_o, o))

/* Native types */
#ifndef CORTO_CORE_H
#endif

/* Type definitions */
/*  /corto/core/package */
typedef struct corto_package_s *corto_package;

struct corto_package_s {
    corto_string url;
    corto_string version;
    corto_string author;
    corto_string description;
    corto_string env;
    corto_string language;
    bool managed;
    bool noapi;
    corto_stringlist cflags;
    corto_stringlist cxxflags;
    corto_stringlist dependencies;
    corto_stringlist definitions;
    corto_string prefix;
    corto_stringlist cortoVersion;
    bool local;
    corto_stringlist lib;
    corto_stringlist libpath;
    corto_stringlist include;
    corto_stringlist link;
    bool coverage;
};

/*  /corto/core/application */
typedef struct corto_application_s *corto_application;

struct corto_application_s {
    struct corto_package_s super;
};

/*  /corto/core/dispatcher */
typedef void *corto_dispatcher;


/*  /corto/core/handleAction */
typedef struct corto_handleAction corto_handleAction;

struct corto_handleAction {
    corto_delegatedata super;
};

/*  /corto/core/event */
typedef struct corto_event corto_event;

struct corto_event {
    uint16_t kind;
    bool handled;
    corto_handleAction handleAction;
};

/* /corto/core/eventMask */
typedef uint32_t corto_eventMask;
    #define CORTO_ON_DECLARE (0x1)
    #define CORTO_ON_DEFINE (0x2)
    #define CORTO_ON_DELETE (0x4)
    #define CORTO_ON_INVALIDATE (0x8)
    #define CORTO_ON_UPDATE (0x10)
    #define CORTO_ON_RESUME (0x20)
    #define CORTO_ON_SUSPEND (0x40)
    #define CORTO_ON_SELF (0x80)
    #define CORTO_ON_SCOPE (0x100)
    #define CORTO_ON_TREE (0x200)
    #define CORTO_ON_VALUE (0x400)
    #define CORTO_ON_METAVALUE (0x800)
    #define CORTO_ON_ANY (0xffff)

/* /corto/core/frameKind */
typedef enum corto_frameKind {
    CORTO_FRAME_NOW = 0,
    CORTO_FRAME_TIME = 1,
    CORTO_FRAME_DURATION = 2,
    CORTO_FRAME_SAMPLE = 3,
    CORTO_FRAME_DEPTH = 4
} corto_frameKind;

/*  /corto/core/frame */
typedef struct corto_frame corto_frame;

struct corto_frame {
    corto_frameKind kind;
    int64_t value;
};

/*  /corto/core/observer */
typedef struct corto_observer_s *corto_observer;

struct corto_observer_s {
    struct corto_function_s super;
    corto_eventMask mask;
    corto_object observable;
    corto_object instance;
    corto_dispatcher dispatcher;
    corto_type type;
    bool enabled;
    uint32_t active;
};

/*  /corto/core/query */
typedef struct corto_query corto_query;

struct corto_query {
    corto_string select;
    corto_string from;
    corto_string type;
    corto_string member;
    corto_string where;
    uint64_t offset;
    uint64_t limit;
    corto_frame timeBegin;
    corto_frame timeEnd;
    bool content;
};

/*  /corto/core/subscriber */
typedef struct corto_subscriber_s *corto_subscriber;

struct corto_subscriber_s {
    struct corto_observer_s super;
    corto_query query;
    corto_string contentType;
    uintptr_t contentTypeHandle;
    uintptr_t idmatch;
};

/* /corto/core/ownership */
typedef enum corto_ownership {
    CORTO_REMOTE_OWNER = 0,
    CORTO_LOCAL_OWNER = 1,
    CORTO_CACHE_OWNER = 2
} corto_ownership;

/* /corto/core/mountMask */
typedef uint32_t corto_mountMask;
    #define CORTO_QUERY (0x1)
    #define CORTO_HISTORY_QUERY (0x2)
    #define CORTO_NOTIFY (0x4)
    #define CORTO_BATCH_NOTIFY (0x8)
    #define CORTO_SUBSCRIBE (0x10)
    #define CORTO_MOUNT (0x20)
    #define CORTO_RESUME (0x40)
    #define CORTO_INVOKE (0x80)

/*  /corto/core/mountPolicy */
typedef struct corto_mountPolicy corto_mountPolicy;

struct corto_mountPolicy {
    corto_ownership ownership;
    corto_mountMask mask;
    double sampleRate;
    uint64_t expiryTime;
};

/*  /corto/core/mountStats */
typedef struct corto_mountStats corto_mountStats;

struct corto_mountStats {
    uint64_t declares;
    uint64_t updates;
    uint64_t deletes;
};

/*  /corto/core/mountSubscription */
typedef struct corto_mountSubscription corto_mountSubscription;

struct corto_mountSubscription {
    corto_query query;
    uint32_t mountCount;
    uint32_t subscriberCount;
    uintptr_t mountCtx;
    uintptr_t subscriberCtx;
};

#ifndef corto_mountSubscriptionList_DEFINED
#define corto_mountSubscriptionList_DEFINED
typedef corto_ll corto_mountSubscriptionList;
#endif

/*  /corto/core/mount */
typedef struct corto_mount_s *corto_mount;

struct corto_mount_s {
    struct corto_subscriber_s super;
    corto_mountPolicy policy;
    corto_object mount;
    corto_attr attr;
    corto_mountStats sent;
    corto_mountStats received;
    corto_mountStats sentDiscarded;
    corto_mountSubscriptionList subscriptions;
    corto_objectlist events;
    bool passThrough;
    bool explicitResume;
    uintptr_t thread;
    bool quit;
    corto_string contentTypeOut;
    uintptr_t contentTypeOutHandle;
};

/*  /corto/core/invokeEvent */
typedef struct corto_invokeEvent_s *corto_invokeEvent;

struct corto_invokeEvent_s {
    corto_event super;
    corto_mount mount;
    corto_object instance;
    corto_function function;
    uintptr_t args;
};

/*  /corto/core/loader */
typedef struct corto_loader_s *corto_loader;

struct corto_loader_s {
    struct corto_mount_s super;
    bool autoLoad;
};

typedef corto_iter corto_objectIter;

/*  /corto/core/observerEvent */
typedef struct corto_observerEvent corto_observerEvent;

struct corto_observerEvent {
    corto_event super;
    corto_observer observer;
    corto_object instance;
    corto_object source;
    corto_eventMask event;
    corto_object data;
    uintptr_t thread;
};

/* /corto/core/operatorKind */
typedef enum corto_operatorKind {
    CORTO_ASSIGN = 0,
    CORTO_ASSIGN_ADD = 1,
    CORTO_ASSIGN_SUB = 2,
    CORTO_ASSIGN_MUL = 3,
    CORTO_ASSIGN_DIV = 4,
    CORTO_ASSIGN_MOD = 5,
    CORTO_ASSIGN_XOR = 6,
    CORTO_ASSIGN_OR = 7,
    CORTO_ASSIGN_AND = 8,
    CORTO_ASSIGN_UPDATE = 9,
    CORTO_ADD = 10,
    CORTO_SUB = 11,
    CORTO_MUL = 12,
    CORTO_DIV = 13,
    CORTO_MOD = 14,
    CORTO_INC = 15,
    CORTO_DEC = 16,
    CORTO_XOR = 17,
    CORTO_OR = 18,
    CORTO_AND = 19,
    CORTO_NOT = 20,
    CORTO_COND_OR = 21,
    CORTO_COND_AND = 22,
    CORTO_COND_NOT = 23,
    CORTO_COND_EQ = 24,
    CORTO_COND_NEQ = 25,
    CORTO_COND_GT = 26,
    CORTO_COND_LT = 27,
    CORTO_COND_GTEQ = 28,
    CORTO_COND_LTEQ = 29,
    CORTO_SHIFT_LEFT = 30,
    CORTO_SHIFT_RIGHT = 31,
    CORTO_REF = 32
} corto_operatorKind;

/*  /corto/core/position */
typedef struct corto_position corto_position;

struct corto_position {
    double latitude;
    double longitude;
};

/*  /corto/core/remote */
typedef struct corto_remote_s *corto_remote;

struct corto_remote_s {
    struct corto_method_s super;
};

/* /corto/core/resultMask */
typedef uint32_t corto_resultMask;
    #define CORTO_RESULT_LEAF (0x1)
    #define CORTO_RESULT_HIDDEN (0x2)

/*  /corto/core/time */
typedef struct corto_time corto_time;

struct corto_time {
    int32_t sec;
    uint32_t nanosec;
};

/*  /corto/core/sample */
typedef struct corto_sample corto_sample;

struct corto_sample {
    corto_time timestamp;
    uintptr_t value;
};

typedef corto_iter corto_sampleIter;

/*  /corto/core/result */
typedef struct corto_result corto_result;

struct corto_result {
    corto_string id;
    corto_string name;
    corto_string parent;
    corto_string type;
    uintptr_t value;
    corto_resultMask flags;
    corto_object object;
    corto_sampleIter history;
    corto_object owner;
};

typedef corto_iter corto_resultIter;

#ifndef corto_resultList_DEFINED
#define corto_resultList_DEFINED
typedef corto_ll corto_resultList;
#endif

/*  /corto/core/route */
typedef struct corto_route_s *corto_route;

struct corto_route_s {
    struct corto_method_s super;
    corto_string pattern;
    corto_stringseq elements;
};

/*  /corto/core/router */
typedef struct corto_router_s *corto_router;

struct corto_router_s {
    struct corto_class_s super;
    corto_type returnType;
    corto_type paramType;
    corto_string paramName;
    corto_type routerDataType;
    corto_string routerDataName;
    corto_string elementSeparator;
};

/*  /corto/core/routerimpl */
typedef struct corto_routerimpl_s *corto_routerimpl;

struct corto_routerimpl_s {
    struct corto_class_s super;
    uint16_t maxArgs;
    corto_route matched;
};

/*  /corto/core/stager */
typedef struct corto_stager_s *corto_stager;

struct corto_stager_s {
    uintptr_t resolver;
};

/*  /corto/core/subscriberEvent */
typedef struct corto_subscriberEvent corto_subscriberEvent;

struct corto_subscriberEvent {
    corto_event super;
    corto_subscriber subscriber;
    corto_object instance;
    corto_object source;
    corto_eventMask event;
    corto_result data;
    uintptr_t contentTypeHandle;
};

typedef corto_iter corto_subscriberEventIter;

/*  /corto/core/tool */
typedef struct corto_tool_s *corto_tool;

struct corto_tool_s {
    struct corto_package_s super;
};

#ifdef __cplusplus
}
#endif
#endif

