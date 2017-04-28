/*
 * corto_walk_opt*.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef CORTO_WALK_H_
#define CORTO_WALK_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"
#include "corto/value.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_walk_opt corto_walk_opt;

typedef int16_t ___ (*corto_walk_cb)(corto_walk_opt* _this, corto_value *v, void* userData);
typedef int16_t ___ (*corto_walk_init_cb)(corto_walk_opt* _this, corto_value *v, void* userData);
typedef int16_t ___ (*corto_walk_deinit_cb)(corto_walk_opt* _this, void* userData);

typedef enum corto_walk_traceKind {
    CORTO_WALK_TRACE_ALWAYS,
    CORTO_WALK_TRACE_ON_FAIL,
    CORTO_WALK_TRACE_NEVER
} corto_walk_traceKind;

typedef enum corto_aliasActionKind {
    CORTO_WALK_ALIAS_FOLLOW,
    CORTO_WALK_ALIAS_IGNORE,
    CORTO_WALK_ALIAS_PASSTHROUGH
} corto_aliasActionKind;

typedef enum corto_optionalActionKind {
    CORTO_WALK_OPTIONAL_IF_SET,
    CORTO_WALK_OPTIONAL_ALWAYS,
} corto_optionalActionKind;

struct corto_walk_opt {
    bool initialized;
    bool constructed;
    corto_modifier access;
    corto_operatorKind accessKind; /* OR, XOR, NOT */
    corto_aliasActionKind aliasAction;
    corto_optionalActionKind optionalAction;
    bool visitAllCases; /* If TRUE, serializer will visit all union cases */
    corto_objectseq members; /* Only serialize specified members */
    corto_walk_traceKind traceKind;
    corto_walk_init_cb construct;
    corto_walk_deinit_cb destruct;
    corto_walk_cb program[CORTO_ITERATOR+1];
    corto_walk_cb metaprogram[CORTO_CONSTANT+1];
    corto_walk_cb reference;
};

CORTO_EXPORT int16_t corto_walk(corto_walk_opt* _this, corto_object o, void* userData);
CORTO_EXPORT int16_t corto_value_walk(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_any_walk(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_walk_members(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_walk_elements(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT void corto_walk_init(corto_walk_opt* _this);
CORTO_EXPORT int16_t corto_walk_deinit(corto_walk_opt* _this, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_WALK_H_ */
