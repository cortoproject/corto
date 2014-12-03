/*
 * db_serializer.h
 *
 *  Created on: Aug 22, 2012
 *      Author: sander
 */

#ifndef DB_SERIALIZER_H_
#define DB_SERIALIZER_H_

#include "db__type.h"
#include "db_value.h"

#ifdef __cplusplus
extern "C" {
#endif

DB_CLASS(db_serializer);

typedef db_int16(*db_serializerCallback)(db_serializer _this, db_value *v, void* userData);
typedef db_int16(*db_serializerConstruct)(db_serializer _this, db_value *v, void* userData);
typedef db_int16(*db_serializerDestruct)(db_serializer _this, void* userData);

typedef enum db_serializerTraceKind {
    DB_SERIALIZER_TRACE_ALWAYS,
    DB_SERIALIZER_TRACE_ON_FAIL,
    DB_SERIALIZER_TRACE_NEVER
}db_serializerTraceKind;

DB_CLASS_DEF(db_serializer) {
    db_bool initialized;
    db_bool constructed;
    db_modifier access;
    db_operatorKind accessKind; /* OR, XOR, NOT */
    db_serializerTraceKind traceKind;
    db_serializerConstruct construct;
    db_serializerDestruct destruct;
    db_serializerCallback program[DB_COLLECTION+1];
    db_serializerCallback metaprogram[DB_CONSTANT+1];
    db_serializerCallback reference;
};

db_int16 db_serialize(db_serializer _this, db_object o, void* userData);
void db_serializerInit(db_serializer _this);
db_int16 db_serializeDestruct(db_serializer _this, void* userData);
db_int16 db_serializeAny(db_serializer _this, db_value* info, void* userData);
db_int16 db_serializeMembers(db_serializer _this, db_value* info, void* userData);
db_int16 db_serializeElements(db_serializer _this, db_value* info, void* userData);
db_int16 db_serializeValue(db_serializer _this, db_value* info, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_SERIALIZER_H_ */
