/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE__TYPE_H
#define CORTO_CORE__TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_augmentData(o) ((corto_augmentData*)corto_assertType((corto_type)corto_augmentData_o, o))
#define corto_augmentseq(o) ((corto_augmentseq*)corto_assertType((corto_type)corto_augmentseq_o, o))
#define corto_dispatcher(o) ((corto_dispatcher)corto_assertType((corto_type)corto_dispatcher_o, o))
#define corto_event(o) ((corto_event)corto_assertType((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask*)corto_assertType((corto_type)corto_eventMask_o, o))
#define corto_frameKind(o) ((corto_frameKind*)corto_assertType((corto_type)corto_frameKind_o, o))
#define corto_frame(o) ((corto_frame*)corto_assertType((corto_type)corto_frame_o, o))
#define corto_observer(o) ((corto_observer)corto_assertType((corto_type)corto_observer_o, o))
#define corto_subscriber(o) ((corto_subscriber)corto_assertType((corto_type)corto_subscriber_o, o))
#define corto_mountKind(o) ((corto_mountKind*)corto_assertType((corto_type)corto_mountKind_o, o))
#define corto_mountStats(o) ((corto_mountStats*)corto_assertType((corto_type)corto_mountStats_o, o))
#define corto_mountPolicy(o) ((corto_mountPolicy*)corto_assertType((corto_type)corto_mountPolicy_o, o))
#define corto_mountSubscription(o) ((corto_mountSubscription*)corto_assertType((corto_type)corto_mountSubscription_o, o))
#define corto_mountSubscriptionList(o) ((corto_mountSubscriptionList*)corto_assertType((corto_type)corto_mountSubscriptionList_o, o))
#define corto_mount(o) ((corto_mount)corto_assertType((corto_type)corto_mount_o, o))
#define corto_invokeEvent(o) ((corto_invokeEvent)corto_assertType((corto_type)corto_invokeEvent_o, o))
#define corto_loader(o) ((corto_loader)corto_assertType((corto_type)corto_loader_o, o))
#define corto_notifyAction(o) ((corto_notifyAction*)corto_assertType((corto_type)corto_notifyAction_o, o))
#define corto_observableEvent(o) ((corto_observableEvent)corto_assertType((corto_type)corto_observableEvent_o, o))
#define corto_observerseq(o) ((corto_observerseq*)corto_assertType((corto_type)corto_observerseq_o, o))
#define corto_operatorKind(o) ((corto_operatorKind*)corto_assertType((corto_type)corto_operatorKind_o, o))
#define corto_package(o) ((corto_package)corto_assertType((corto_type)corto_package_o, o))
#define corto_position(o) ((corto_position*)corto_assertType((corto_type)corto_position_o, o))
#define corto_remote(o) ((corto_remote)corto_assertType((corto_type)corto_remote_o, o))
#define corto_request(o) ((corto_request*)corto_assertType((corto_type)corto_request_o, o))
#define corto_result(o) ((corto_result*)corto_assertType((corto_type)corto_result_o, o))
#define corto_resultIter(o) ((corto_resultIter*)corto_assertType((corto_type)corto_resultIter_o, o))
#define corto_resultList(o) ((corto_resultList*)corto_assertType((corto_type)corto_resultList_o, o))
#define corto_route(o) ((corto_route)corto_assertType((corto_type)corto_route_o, o))
#define corto_router(o) ((corto_router)corto_assertType((corto_type)corto_router_o, o))
#define corto_routerimpl(o) ((corto_routerimpl)corto_assertType((corto_type)corto_routerimpl_o, o))
#define corto_stager(o) ((corto_stager)corto_assertType((corto_type)corto_stager_o, o))
#define corto_subscriberEvent(o) ((corto_subscriberEvent)corto_assertType((corto_type)corto_subscriberEvent_o, o))
#define corto_time(o) ((corto_time*)corto_assertType((corto_type)corto_time_o, o))

/* Type definitions */
/*  /corto/core/augmentData */
typedef struct corto_augmentData corto_augmentData;

struct corto_augmentData {
    corto_string id;
    corto_word data;
};

CORTO_SEQUENCE(corto_augmentseq, corto_augmentData,);

/*  /corto/core/dispatcher */
CORTO_INTERFACE(corto_dispatcher);


/*  /corto/core/event */
typedef struct corto_event_s *corto_event;

struct corto_event_s {
    corto_uint16 kind;
    corto_bool handled;
};

/* /corto/core/eventMask */
CORTO_BITMASK(corto_eventMask);
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
    corto_int64 value;
};

/*  /corto/core/observer */
typedef struct corto_observer_s *corto_observer;

struct corto_observer_s {
    struct corto_function_s _parent;
    corto_eventMask mask;
    corto_object observable;
    corto_object instance;
    corto_dispatcher dispatcher;
    corto_string type;
    corto_bool enabled;
    corto_uint32 active;
    corto_type typeReference;
};

/*  /corto/core/subscriber */
typedef struct corto_subscriber_s *corto_subscriber;

struct corto_subscriber_s {
    struct corto_observer_s _parent;
    corto_string parent;
    corto_string expr;
    corto_string contentType;
    corto_word contentTypeHandle;
    corto_word matchProgram;
};

/* /corto/core/mountKind */
typedef enum corto_mountKind {
    CORTO_SOURCE = 0,
    CORTO_SINK = 1,
    CORTO_CACHE = 2,
    CORTO_HISTORIAN = 3
} corto_mountKind;

/*  /corto/core/mountStats */
typedef struct corto_mountStats corto_mountStats;

struct corto_mountStats {
    corto_uint64 declares;
    corto_uint64 updates;
    corto_uint64 deletes;
};

/*  /corto/core/mountPolicy */
typedef struct corto_mountPolicy corto_mountPolicy;

struct corto_mountPolicy {
    corto_float64 sampleRate;
};

/*  /corto/core/mountSubscription */
typedef struct corto_mountSubscription corto_mountSubscription;

struct corto_mountSubscription {
    corto_string parent;
    corto_string expr;
    corto_eventMask mask;
    corto_uint32 count;
    corto_word userData;
};

CORTO_LIST(corto_mountSubscriptionList);

/*  /corto/core/mount */
typedef struct corto_mount_s *corto_mount;

struct corto_mount_s {
    struct corto_subscriber_s _parent;
    corto_mountKind kind;
    corto_string policy;
    corto_object mount;
    corto_eventMask mask;
    corto_attr attr;
    corto_mountStats sent;
    corto_mountStats received;
    corto_mountStats sentDiscarded;
    corto_mountPolicy policies;
    corto_mountSubscriptionList subscriptions;
    corto_objectlist events;
    corto_bool passThrough;
    corto_word thread;
    corto_bool quit;
    corto_bool hasNotify;
    corto_bool hasResume;
    corto_string contentTypeOut;
    corto_word contentTypeOutHandle;
};

/*  /corto/core/invokeEvent */
typedef struct corto_invokeEvent_s *corto_invokeEvent;

struct corto_invokeEvent_s {
    struct corto_event_s _parent;
    corto_mount mount;
    corto_object instance;
    corto_function function;
    corto_word args;
};

/*  /corto/core/loader */
typedef struct corto_loader_s *corto_loader;

struct corto_loader_s {
    struct corto_mount_s _parent;
};

/*  /corto/core/notifyAction */
typedef struct corto_notifyAction corto_notifyAction;

struct corto_notifyAction {
    corto_delegatedata _parent;
};

/*  /corto/core/observableEvent */
typedef struct corto_observableEvent_s *corto_observableEvent;

struct corto_observableEvent_s {
    struct corto_event_s _parent;
    corto_function observer;
    corto_object me;
    corto_object source;
    corto_object observable;
    corto_eventMask mask;
    corto_word thread;
};

CORTO_SEQUENCE(corto_observerseq, corto_observer,);

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

/*  /corto/core/package */
typedef struct corto_package_s *corto_package;

struct corto_package_s {
    corto_string url;
    corto_string version;
    corto_string author;
    corto_string description;
    corto_string env;
    corto_bool nocorto;
    corto_stringlist cflags;
    corto_stringlist dependencies;
    corto_string prefix;
    corto_stringlist cortoVersion;
    corto_bool local;
    corto_stringlist lib;
    corto_stringlist libpath;
    corto_stringlist include;
    corto_stringlist link;
};

/*  /corto/core/position */
typedef struct corto_position corto_position;

struct corto_position {
    corto_float64 latitude;
    corto_float64 longitude;
};

/*  /corto/core/remote */
typedef struct corto_remote_s *corto_remote;

struct corto_remote_s {
    struct corto_method_s _parent;
};

/*  /corto/core/request */
typedef struct corto_request corto_request;

struct corto_request {
    corto_string parent;
    corto_string expr;
    corto_string type;
    corto_uint64 offset;
    corto_uint64 limit;
    corto_bool content;
    corto_frame from;
    corto_frame to;
};

/*  /corto/core/result */
typedef struct corto_result corto_result;

struct corto_result {
    corto_string id;
    corto_string name;
    corto_string parent;
    corto_string type;
    corto_word value;
    corto_bool leaf;
    corto_object object;
    corto_wordseq history;
    corto_augmentseq augments;
    corto_object mount;
};

CORTO_ITERATOR(corto_resultIter);

CORTO_LIST(corto_resultList);

/*  /corto/core/route */
typedef struct corto_route_s *corto_route;

struct corto_route_s {
    struct corto_method_s _parent;
    corto_string pattern;
    corto_stringseq elements;
};

/*  /corto/core/router */
typedef struct corto_router_s *corto_router;

struct corto_router_s {
    struct corto_class_s _parent;
    corto_type returnType;
    corto_type paramType;
    corto_string paramName;
};

/*  /corto/core/routerimpl */
typedef struct corto_routerimpl_s *corto_routerimpl;

struct corto_routerimpl_s {
    struct corto_class_s _parent;
    corto_uint16 maxArgs;
};

/*  /corto/core/stager */
typedef struct corto_stager_s *corto_stager;

struct corto_stager_s {
    corto_word resolver;
};

/*  /corto/core/subscriberEvent */
typedef struct corto_subscriberEvent_s *corto_subscriberEvent;

struct corto_subscriberEvent_s {
    struct corto_observableEvent_s _parent;
    corto_result result;
    corto_word contentTypeHandle;
};

/*  /corto/core/time */
typedef struct corto_time corto_time;

struct corto_time {
    corto_int32 sec;
    corto_uint32 nanosec;
};

#ifdef __cplusplus
}
#endif
#endif

