/*
 * db_def.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_DEF_H_
#define DB_DEF_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL (0x0)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#define DB_NULL_STRING ("null")

/* Builtin collection-implementation definitions */
typedef struct db_rbtree_s* db_rbtree;
typedef struct db_ll_s* db_ll;

/* Configuration parameters */
#define DB_MAX_SCOPE_DEPTH (256)
#define DB_MAX_TYPE_DEPTH (32)
#define DB_MAX_INHERITANCE_DEPTH (32)
#define DB_MAX_BINDINGS (256)
#define DB_MAX_THREADS (512)
#define DB_MAX_NOTIFY_DEPTH (32)
#define DB_MAX_STRING_LITERAL_LENGTH (512)
#define DB_MAX_WAIT_FOR_OBJECTS (256)

/* Debugging flags */
/* #define DB_TRACE_NOTIFICATIONS */
/* #define DB_LEAKCHECK */
/* #define DB_SERIALIZER_TRACING */
#define DB_IC_TRACING
#define DB_VM_DEBUG
#define DB_VM_BOUNDSCHECK

#define DB_PROCEDURE_STUB (0)
#define DB_PROCEDURE_CDECL (1)
#define DB_PROCEDURE_VM    (2)
#define _(txt)

#define DB_STRUCT(type) typedef struct type type
#define DB_INTERFACE(type) typedef void* type
#define DB_CLASS(type) typedef struct type##_s* type
#define DB_PROCEDURE(type) typedef struct type##_s* type
#define DB_BITMASK(type) typedef uint32_t type

/* The _() prevents expansion by class casting-macro's */
#define DB_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define DB_SEQUENCE_ANONYMOUS(subtype, postexpr) struct {uint32_t length; subtype _()(*buffer) postexpr;}

#define DB_LIST(type) typedef db_ll type

#define DB_STRUCT_DEF(type) struct type
#define DB_CLASS_DEF(type) struct type##_s
#define DB_PROCEDURE_DEF(type) struct type##_s

#define DB_EXTEND(type) struct type##_s _parent

#define DB_ANY(__type) typedef struct __type {db_type type; void* value; db_bool owner;} __type

#ifdef __cplusplus
}
#endif

#endif /* DB_DEF_H_ */


