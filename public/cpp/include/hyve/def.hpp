/*
 * db_def.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef DB_DEF_H_
#define DB_DEF_H_

#include "stdint.h"

#ifndef NULL
#define NULL (0x0)
#endif

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

/* Configuration parameters */
#define DB_MAX_SCOPE_DEPTH (256)
#define DB_MAX_TYPE_DEPTH (32)
#define DB_MAX_BINDINGS (256)
#define DB_PROCEDURE_STUB (0)
#define DB_PROCEDURE_CDECL (1)
#define _(txt)

#define DB_STRUCT(type) typedef struct type type
#define DB_INTERFACE(type) typedef hyve::lang::object type
#define DB_CLASS(type) typedef struct type##_s* type
#define DB_PROCEDURE(type) typedef struct type##_s* type
#define DB_BITMASK(type) typedef uint32_t type

/* The _() prevents expansion by class casting-macro's */
#define DB_SEQUENCE(type, subtype, postexpr) typedef struct type {uint32_t length; subtype _()(*buffer) postexpr;} type
#define DB_SEQUENCE_ANONYMOUS(subtype, postexpr) struct {uint32_t length; subtype _()(*buffer) postexpr;}

#define DB_STRUCT_DEF(type) struct type
#define DB_CLASS_DEF(type) struct type##_s
#define DB_PROCEDURE_DEF(type) struct type##_s

#define DB_EXTEND(type) struct type##_s _parent

#endif /* DB_DEF_H_ */


