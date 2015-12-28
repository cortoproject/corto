/*
 * corto_serializer.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef CORTO_SERIALIZER_H_
#define CORTO_SERIALIZER_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"
#include "corto/value.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_CLASS(corto_serializer);

typedef corto_int16 ___ (*corto_serializerCallback)(corto_serializer _this, corto_value *v, void* userData);
typedef corto_int16 ___ (*corto_serializerConstruct)(corto_serializer _this, corto_value *v, void* userData);
typedef corto_int16 ___ (*corto_serializerDestruct)(corto_serializer _this, void* userData);

typedef enum corto_serializerTraceKind {
    CORTO_SERIALIZER_TRACE_ALWAYS,
    CORTO_SERIALIZER_TRACE_ON_FAIL,
    CORTO_SERIALIZER_TRACE_NEVER
} corto_serializerTraceKind;

typedef enum corto_aliasActionKind {
    CORTO_SERIALIZER_ALIAS_FOLLOW,
    CORTO_SERIALIZER_ALIAS_IGNORE,
    CORTO_SERIALIZER_ALIAS_PASSTHROUGH
} corto_aliasActionKind;

CORTO_CLASS_DEF(corto_serializer) {
    corto_bool initialized;
    corto_bool constructed;
    corto_modifier access;
    corto_operatorKind accessKind; /* OR, XOR, NOT */
    corto_aliasActionKind aliasAction;
    corto_serializerTraceKind traceKind;
    corto_serializerConstruct construct;
    corto_serializerDestruct destruct;
    corto_serializerCallback program[CORTO_ITERATOR+1];
    corto_serializerCallback metaprogram[CORTO_CONSTANT+1];
    corto_serializerCallback reference;
};

corto_int16 corto_serialize(corto_serializer _this, corto_object o, void* userData);
void corto_serializerInit(corto_serializer _this);
corto_int16 corto_serializeDestruct(corto_serializer _this, void* userData);
corto_int16 corto_serializeAny(corto_serializer _this, corto_value* info, void* userData);
corto_int16 corto_serializeMembers(corto_serializer _this, corto_value* info, void* userData);
corto_int16 corto_serializeElements(corto_serializer _this, corto_value* info, void* userData);
corto_int16 corto_serializeValue(corto_serializer _this, corto_value* info, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_SERIALIZER_H_ */
