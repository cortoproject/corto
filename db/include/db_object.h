/*
 * db_object.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_OBJECT_H_
#define DB_OBJECT_H_

#include "db__type.h"
#include "db_ll.h"
#include "db_value.h"
#include "db_rbtree.h"
#include "db_async.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Used to hold the fully scoped name of an object */
typedef char db_id[512];

/* Action-signature for scopeWalk */
typedef int (*db_scopeWalkAction)(db_object o, void* userData);

/* Object attribute flags */
#define DB_ATTR_SCOPED      (1)
#define DB_ATTR_WRITABLE    (2)
#define DB_ATTR_OBSERVABLE  (4)

/* Object state flags */
#define DB_VALID      (1)
#define DB_DECLARED   (2)
#define DB_DEFINED    (4)
#define DB_DESTRUCTED (8)

/* Object event flags */
#define DB_ON_DECLARE  			(1)
#define DB_ON_DEFINE 	(2)
#define DB_ON_DESTRUCT 		(4)
#define DB_ON_INVALIDATE 	(8)
#define DB_ON_UPDATE 		(16)
#define DB_ON_SELF 			(32)
#define DB_ON_SCOPE 		(64)
#define DB_ON_VALUE         (128)
#define DB_ON_METAVALUE     (256)

/* Event-kinds */
#define DB_EVENT_NONE		(0)
#define DB_EVENT_OBSERVABLE (1)

/* Object lifecycle */
db_object db_new(db_typedef type);
db_object db_new_ext(db_object src, db_typedef type, db_uint8 attrs, db_string context);
db_object db_declare(db_object parent, db_string name, db_typedef type);
db_int16 db_define(db_object o);
void db_destruct(db_object o);
void db_attach(db_object parent, db_object child); /* Attach lifecycle of unscoped object to scoped object */
void db_detach(db_object parent, db_object child); /* Detach lifecycle of unscoped object from scoped object */
void db_invalidate(db_object o);

/* Object-data */
db_typedef db_typeof(db_object o);
db_int32 db_countof(db_object o);
db_bool db_checkState(db_object o, db_int8 state);
db_bool db_checkAttr(db_object o, db_int8 attr);
db_bool db_instanceof(db_typedef type, db_object o);

/* Scoped object-data */
db_string db_nameof(db_object o);
db_object db_parentof(db_object o);
db_rbtree db_scopeof(db_object o); /* Dangerous function, because it's not protected by locks */
db_uint32 db_scopeSize(db_object o); /* Returns number of objects (non-recursive) in scope */
db_ll db_scopeClaim(db_object o); /* Safe way to access scope contents */
void db_scopeRelease(db_ll scope);
db_int32 db_scopeWalk(db_object o, db_scopeWalkAction action, void* userData); /* Safe object-walk */
db_string db_fullname(db_object o, db_id buffer);
db_string db_relname(db_object from, db_object o, db_id buffer);

/* Resource management */
db_int32 db_keep(db_object o);
db_int32 db_free(db_object o);
db_int32 db_free_ext(db_object src, db_object o, db_string context);
db_int32 db_keep_ext(db_object src, db_object o, db_string context);
void db_drop(db_object o); /* Free all non-orphaned objects in scope. Object self is not free'd. */

/* Lookup objects either using names or fully qualified names. */
db_object db_lookup(db_object scope, db_string name);
db_object db_lookup_ext(db_object src, db_object scope, db_string name, db_string context);
db_function db_lookupFunction(db_object scope, db_string requested, db_bool allowCastableOverloading, db_int32 *d);
db_function db_lookupFunction_ext(db_object src, db_object scope, db_string requested, db_bool allowCastableOverloading, db_int32 *d, db_string context);
db_object db_resolve(db_object scope, db_string expr);
db_object db_resolve_ext(db_object src, db_object scope, db_string expr, db_bool allowCastableOverloading, db_string context);

/* Notifications */
db_int32 db_listen(db_object observable, db_observer observer, db_object _this);
db_int32 db_silence(db_object observable, db_observer observer, db_object _this);
db_bool db_listening(db_object observable, db_observer, db_object _this);
db_int32 db_update(db_object observable);
db_int32 db_updateFrom(db_object observable, db_object _this);
db_int32 db_updateBegin(db_object observable);
db_int32 db_updateTry(db_object observable);
db_int32 db_updateEnd(db_object observable);
db_int32 db_updateEndFrom(db_object observable, db_object _this);
db_int32 db_updateCancel(db_object observable);

/* Waiting */
db_int32 db_waitfor(db_object observable);
db_object db_wait(db_int32 timeout_sec, db_int32 timeout_nanosec);

/* Thread-safe reading (polling) */
db_int32 db_readBegin(db_object object);
db_int32 db_readEnd(db_object object);

/* Set reference field */
void db_set(void* ptr, db_object value);
void db_set_ext(db_object source, void* ptr, db_object value, db_string context);

/* Measure to what extend a function meets requested signature */
db_int16 db_overload(db_function object, db_string name, db_int32* distance, db_bool allowCastable);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */
db_int32 db_signatureName(db_string signature, db_id buffer);
db_int32 db_signatureParamCount(db_string signature);
db_int32 db_signatureParamName(db_string signature, db_uint32 id, db_id buffer);
db_int32 db_signatureParamType(db_string signature, db_uint32 id, db_id buffer, db_bool* reference);

/* Create request signature */
db_string db_signatureOpen(db_string name);
db_string db_signatureAdd(db_string sig, db_typedef type, db_bool isReference);
db_string db_signatureAddWildcard(db_string sig, db_bool isReference);
db_string db_signatureClose(db_string sig);

/* Parse member expression */
db_value* db_parseExpr(db_object o, db_string expr, db_valueStack stack, db_uint32 *count);

/* Serialize object to string */
db_string db_toString(db_object object, db_uint32 maxLength);

/* Deserialize object from string */
db_object db_fromString(db_string string);

/* Convert value to string */
db_string db_valueToString(db_value* v, db_uint32 maxLength);

/* Deserialize value from string */
void *db_valueFromString(db_string string, void* out, db_typedef type);

/* Compare objects */
db_equalityKind db_compare(db_object o1, db_object o2);

/* Compare value */
db_equalityKind db_valueCompare(db_value *value1, db_value *value2);
    
/* Init object */
db_int16 db_init(db_object o);
    
/* Init value */
db_int16 db_initValue(db_value *v);
    
/* Deinit object */
db_int16 db_deinit(db_object o);
    
/* Deinit value */
db_int16 db_deinitValue(db_value *v);
    
/* Copy object */
db_int16 db_copy(db_object from, db_object to);
 
/* Copy value */
db_int16 db_valueCopy(db_value *from, db_value *to);

#ifdef __cplusplus
}
#endif

#endif /* DB_OBJECT_H_ */
