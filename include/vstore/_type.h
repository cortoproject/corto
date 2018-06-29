/* _type.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_VSTORE_TYPE_H
#define CORTO_VSTORE_TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -- Native types -- */
#ifndef CORTO_VSTORE_H
#endif


/* -- Type definitions -- */

/* interface corto/vstore/dispatcher */
typedef void *corto_dispatcher;

/* delegate corto/vstore/handleAction */
typedef struct corto_handleAction {
    corto_delegatedata super;
} corto_handleAction;

/* struct corto/vstore/event */
typedef struct corto_event {
    corto_handleAction handleAction;
} corto_event;

/* bitmask corto/vstore/eventMask */
typedef uint32_t corto_eventMask;
    #define CORTO_DECLARE (0x1)
    #define CORTO_DEFINE (0x2)
    #define CORTO_DELETE (0x4)
    #define CORTO_INVALIDATE (0x8)
    #define CORTO_UPDATE (0x10)
    #define CORTO_RESUME (0x20)
    #define CORTO_SUSPEND (0x40)
    #define CORTO_ON_SELF (0x80)
    #define CORTO_ON_SCOPE (0x100)
    #define CORTO_ON_TREE (0x200)
    #define CORTO_ON_VALUE (0x400)
    #define CORTO_ON_METAVALUE (0x800)
    #define CORTO_ON_ANY (0xffff)

/* struct corto/vstore/fmt_data */
typedef struct corto_fmt_data {
    uintptr_t ptr;
    uintptr_t handle;
    uintptr_t shared_count;
} corto_fmt_data;

/* enum corto/vstore/frameKind */
typedef enum corto_frameKind {
    CORTO_FRAME_NOW = 0,
    CORTO_FRAME_TIME = 1,
    CORTO_FRAME_DURATION = 2
} corto_frameKind;

/* struct corto/vstore/frame */
typedef struct corto_frame {
    corto_frameKind kind;
    int64_t value;
} corto_frame;

/* procedure corto/vstore/observer */
typedef struct corto_observer_s {
    struct corto_function_s super;
    corto_eventMask mask;
    corto_object observable;
    corto_object instance;
    corto_dispatcher dispatcher;
    corto_type type;
    bool enabled;
    uint32_t active;
} *corto_observer;

/* struct corto/vstore/query */
typedef struct corto_query {
    corto_string select;
    corto_string from;
    corto_string type;
    corto_string instanceof;
    corto_string member;
    corto_string where;
    uint64_t offset;
    uint64_t limit;
    uint64_t soffset;
    uint64_t slimit;
    corto_frame frame_begin;
    corto_frame frame_end;
    bool content;
    bool yield_unknown;
} corto_query;

/* procedure corto/vstore/subscriber */
typedef struct corto_subscriber_s {
    struct corto_observer_s super;
    corto_query query;
    corto_string format;
    uintptr_t fmt_handle;
    uintptr_t idmatch;
    bool isAligning;
    uintptr_t alignMutex;
    corto_objectlist alignQueue;
} *corto_subscriber;

/* enum corto/vstore/ownership */
typedef enum corto_ownership {
    CORTO_REMOTE_SOURCE = 0,
    CORTO_LOCAL_SOURCE = 1,
    CORTO_CACHE_OWNER = 2
} corto_ownership;

/* bitmask corto/vstore/mountCallbackMask */
typedef uint32_t corto_mountCallbackMask;
    #define CORTO_MOUNT_QUERY (0x1)
    #define CORTO_MOUNT_HISTORY_QUERY (0x2)
    #define CORTO_MOUNT_NOTIFY (0x4)
    #define CORTO_MOUNT_HISTORY_BATCH_NOTIFY (0x8)
    #define CORTO_MOUNT_BATCH_NOTIFY (0x10)
    #define CORTO_MOUNT_SUBSCRIBE (0x20)
    #define CORTO_MOUNT_MOUNT (0x40)
    #define CORTO_MOUNT_RESUME (0x80)
    #define CORTO_MOUNT_INVOKE (0x100)
    #define CORTO_MOUNT_ID (0x200)

/* struct corto/vstore/mount_subscription */
typedef struct corto_mount_subscription {
    corto_query query;
    uint32_t mountCount;
    uint32_t subscriberCount;
    uintptr_t mountCtx;
    uintptr_t subscriberCtx;
} corto_mount_subscription;

#ifndef corto_mount_subscriptionList_DEFINED
#define corto_mount_subscriptionList_DEFINED
typedef corto_ll corto_mount_subscriptionList;
#endif

/* struct corto/vstore/time */
typedef struct corto_time {
    int32_t sec;
    uint32_t nanosec;
} corto_time;

/* class corto/vstore/mount */
typedef struct corto_mount_s {
    struct corto_subscriber_s super;
    corto_attr attr;
    corto_ownership ownership;
    corto_mountCallbackMask callbacks;
    double sample_rate;
    uint32_t queue_max;
    uint64_t expiry_time;
    bool filter_results;
    corto_mount_subscriptionList subscriptions;
    corto_objectlist events;
    corto_objectlist historicalEvents;
    corto_time lastPoll;
    corto_time lastPost;
    corto_time lastSleep;
    corto_time dueSleep;
    uint32_t lastQueueSize;
    bool passThrough;
    bool explicitResume;
    uintptr_t thread;
    bool quit;
    corto_string formatOut;
    uintptr_t formatOutHandle;
} *corto_mount;

/* struct corto/vstore/invoke_event */
typedef struct corto_invoke_event {
    corto_event super;
    corto_mount mount;
    corto_object instance;
    corto_function function;
    uintptr_t args;
} corto_invoke_event;

/* class corto/vstore/loader */
typedef struct corto_loader_s {
    struct corto_mount_s super;
    bool autoLoad;
} *corto_loader;

typedef corto_iter corto_objectIter;

/* struct corto/vstore/observer_event */
typedef struct corto_observer_event {
    corto_event super;
    corto_observer observer;
    corto_object instance;
    corto_object source;
    corto_eventMask event;
    corto_object data;
    uintptr_t thread;
} corto_observer_event;

/* enum corto/vstore/operatorKind */
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
    CORTO_ASSIGN_SHIFT_LEFT = 9,
    CORTO_ASSIGN_SHIFT_RIGHT = 10,
    CORTO_ASSIGN_UPDATE = 11,
    CORTO_ADD = 12,
    CORTO_SUB = 13,
    CORTO_MUL = 14,
    CORTO_DIV = 15,
    CORTO_MOD = 16,
    CORTO_INC = 17,
    CORTO_DEC = 18,
    CORTO_XOR = 19,
    CORTO_OR = 20,
    CORTO_AND = 21,
    CORTO_NOT = 22,
    CORTO_COND_OR = 23,
    CORTO_COND_AND = 24,
    CORTO_COND_NOT = 25,
    CORTO_COND_EQ = 26,
    CORTO_COND_NEQ = 27,
    CORTO_COND_GT = 28,
    CORTO_COND_LT = 29,
    CORTO_COND_GTEQ = 30,
    CORTO_COND_LTEQ = 31,
    CORTO_SHIFT_LEFT = 32,
    CORTO_SHIFT_RIGHT = 33,
    CORTO_REF = 34
} corto_operatorKind;

/* procedure corto/vstore/remote */
typedef struct corto_remote_s {
    struct corto_method_s super;
} *corto_remote;

/* bitmask corto/vstore/resultMask */
typedef uint32_t corto_resultMask;
    #define CORTO_RESULT_LEAF (0x1)
    #define CORTO_RESULT_HIDDEN (0x2)

/* struct corto/vstore/sample */
typedef struct corto_sample {
    corto_time timestamp;
    uintptr_t value;
} corto_sample;

typedef corto_iter corto_sampleIter;

/* struct corto/vstore/result */
typedef struct corto_result {
    corto_string id;
    corto_string name;
    corto_string parent;
    corto_string type;
    uintptr_t value;
    corto_resultMask flags;
    corto_object object;
    corto_sampleIter history;
    corto_object owner;
} corto_result;

typedef corto_iter corto_resultIter;

#ifndef corto_resultlist_DEFINED
#define corto_resultlist_DEFINED
typedef corto_ll corto_resultlist;
#endif

/* procedure corto/vstore/route */
typedef struct corto_route_s {
    struct corto_method_s super;
    corto_string pattern;
    corto_stringseq elements;
} *corto_route;

/* class corto/vstore/router */
typedef struct corto_router_s {
    struct corto_class_s super;
    corto_type return_type;
    corto_type param_type;
    corto_string param_name;
    corto_type router_data_type;
    corto_string router_data_name;
    corto_string element_separator;
} *corto_router;

/* class corto/vstore/routerimpl */
typedef struct corto_routerimpl_s {
    struct corto_class_s super;
    uint16_t maxArgs;
    corto_route matched;
} *corto_routerimpl;

/* struct corto/vstore/subscriber_event */
typedef struct corto_subscriber_event {
    corto_event super;
    corto_subscriber subscriber;
    corto_object instance;
    corto_object source;
    corto_eventMask event;
    corto_result data;
    corto_fmt_data fmt;
} corto_subscriber_event;

typedef corto_iter corto_subscriber_eventIter;


#ifdef __cplusplus
}
#endif
#endif

