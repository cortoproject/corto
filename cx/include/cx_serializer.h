/*
 * cx_serializer.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef DB_SERIALIZER_H_
#define DB_SERIALIZER_H_

#include "cx__type.h"
#include "cx_value.h"

#ifdef __cplusplus
extern "C" {
#endif

DB_CLASS(cx_serializer);

typedef cx_int16(*cx_serializerCallback)(cx_serializer _this, cx_value *v, void* userData);
typedef cx_int16(*cx_serializerConstruct)(cx_serializer _this, cx_value *v, void* userData);
typedef cx_int16(*cx_serializerDestruct)(cx_serializer _this, void* userData);

typedef enum cx_serializerTraceKind {
    DB_SERIALIZER_TRACE_ALWAYS,
    DB_SERIALIZER_TRACE_ON_FAIL,
    DB_SERIALIZER_TRACE_NEVER
}cx_serializerTraceKind;

DB_CLASS_DEF(cx_serializer) {
    cx_bool initialized;
    cx_bool constructed;
    cx_modifier access;
    cx_operatorKind accessKind; /* OR, XOR, NOT */
    cx_serializerTraceKind traceKind;
    cx_serializerConstruct construct;
    cx_serializerDestruct destruct;
    cx_serializerCallback program[DB_COLLECTION+1];
    cx_serializerCallback metaprogram[DB_CONSTANT+1];
    cx_serializerCallback reference;
};

cx_int16 cx_serialize(cx_serializer _this, cx_object o, void* userData);
void cx_serializerInit(cx_serializer _this);
cx_int16 cx_serializeDestruct(cx_serializer _this, void* userData);
cx_int16 cx_serializeAny(cx_serializer _this, cx_value* info, void* userData);
cx_int16 cx_serializeMembers(cx_serializer _this, cx_value* info, void* userData);
cx_int16 cx_serializeElements(cx_serializer _this, cx_value* info, void* userData);
cx_int16 cx_serializeValue(cx_serializer _this, cx_value* info, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_SERIALIZER_H_ */
