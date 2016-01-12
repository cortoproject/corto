/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE__TYPE_H
#define CORTO_CORE__TYPE_H

#include "corto/lang/_type.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define corto_attr(o) ((corto_attr *)corto_assertType((corto_type)corto_attr_o, o))
#define corto_dispatcher(o) ((corto_dispatcher)corto_assertType((corto_type)corto_dispatcher_o, o))
#define corto_equalityKind(o) ((corto_equalityKind *)corto_assertType((corto_type)corto_equalityKind_o, o))
#define corto_event(o) ((corto_event)corto_assertType((corto_type)corto_event_o, o))
#define corto_eventMask(o) ((corto_eventMask *)corto_assertType((corto_type)corto_eventMask_o, o))
#define corto_invokeEvent(o) ((corto_invokeEvent)corto_assertType((corto_type)corto_invokeEvent_o, o))
#define corto_notifyAction(o) ((corto_notifyAction *)corto_assertType((corto_type)corto_notifyAction_o, o))
#define corto_observableEvent(o) ((corto_observableEvent)corto_assertType((corto_type)corto_observableEvent_o, o))
#define corto_observer(o) ((corto_observer)corto_assertType((corto_type)corto_observer_o, o))
#define corto_observerseq(o) ((corto_observerseq *)corto_assertType((corto_type)corto_observerseq_o, o))
#define corto_operatorKind(o) ((corto_operatorKind *)corto_assertType((corto_type)corto_operatorKind_o, o))
#define corto_package(o) ((corto_package)corto_assertType((corto_type)corto_package_o, o))
#define corto_query(o) ((corto_query)corto_assertType((corto_type)corto_query_o, o))
#define corto_replicator(o) ((corto_replicator)corto_assertType((corto_type)corto_replicator_o, o))
#define corto_result(o) ((corto_result *)corto_assertType((corto_type)corto_result_o, o))
#define corto_resultIter(o) ((corto_resultIter *)corto_assertType((corto_type)corto_resultIter_o, o))
#define corto_resultList(o) ((corto_resultList *)corto_assertType((corto_type)corto_resultList_o, o))

/* Type definitions */
/* /corto/core/attr */
CORTO_BITMASK(corto_attr);
    #define CORTO_ATTR_SCOPED (0x1)
    #define CORTO_ATTR_WRITABLE (0x2)
    #define CORTO_ATTR_OBSERVABLE (0x4)
    #define CORTO_ATTR_PERSISTENT (0x8)
    #define CORTO_ATTR_DEFAULT (0x10)

/*  /corto/core/dispatcher */
CORTO_INTERFACE(corto_dispatcher);


/* /corto/core/equalityKind */
typedef enum corto_equalityKind {
    CORTO_EQ = 0,
    CORTO_LT = -1,
    CORTO_GT = 1,
    CORTO_NEQ = 2
} corto_equalityKind;

/*  /corto/core/event */
CORTO_CLASS(corto_event);

CORTO_CLASS_DEF(corto_event) {
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
    #define CORTO_ON_SELF (0x20)
    #define CORTO_ON_SCOPE (0x40)
    #define CORTO_ON_TREE (0x80)
    #define CORTO_ON_VALUE (0x100)
    #define CORTO_ON_METAVALUE (0x200)

/*  /corto/core/query */
CORTO_CLASS(corto_query);

CORTO_CLASS_DEF(corto_query) {
    corto_object from;
    corto_eventMask mask;
};

/*  /corto/core/replicator */
CORTO_CLASS(corto_replicator);

CORTO_CLASS_DEF(corto_replicator) {
    corto_object mount;
    corto_query query;
    corto_string contentType;
};

/*  /corto/core/invokeEvent */
CORTO_CLASS(corto_invokeEvent);

CORTO_CLASS_DEF(corto_invokeEvent) {
    CORTO_EXTEND(corto_event);
    corto_replicator replicator;
    corto_object instance;
    corto_function function;
    corto_octetseq args;
};

/*  /corto/core/notifyAction */
typedef struct corto_notifyAction corto_notifyAction;

struct corto_notifyAction {
    corto_delegatedata _parent;
};

/*  /corto/core/observer */
CORTO_CLASS(corto_observer);

CORTO_CLASS_DEF(corto_observer) {
    CORTO_EXTEND(corto_function);
    corto_eventMask mask;
    corto_object observable;
    corto_object me;
    corto_dispatcher dispatcher;
    corto_uint32 _template;
};

/*  /corto/core/observableEvent */
CORTO_CLASS(corto_observableEvent);

CORTO_CLASS_DEF(corto_observableEvent) {
    CORTO_EXTEND(corto_event);
    corto_observer observer;
    corto_object me;
    corto_object source;
    corto_object observable;
    corto_eventMask mask;
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
CORTO_CLASS(corto_package);

CORTO_CLASS_DEF(corto_package) {
    corto_string url;
};

/*  /corto/core/result */
typedef struct corto_result corto_result;

struct corto_result {
    corto_string name;
    corto_string parent;
    corto_string type;
    corto_word value;
};

CORTO_ITERATOR(corto_resultIter);

CORTO_LIST(corto_resultList);

#ifdef __cplusplus
}
#endif
#endif

