/*
 * db_vm.h
 *
 *  Created on: Aug 14, 2013
 *      Author: sander
 */

#ifndef DB_IC_H_
#define DB_IC_H_

#include "db_type.h"
#include "db_value.h"
#include "db_vm.h"
#include "db_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum db_icOpKind {
	/* Set (assign) */
	DB_IC_SET,

	/* Cast */
	DB_IC_CAST,

	/* String concatenation */
	DB_IC_STRCAT,
	DB_IC_STRCPY,

	/* Memory management */
	DB_IC_NEW,
	DB_IC_DEFINE,
	DB_IC_FREE,
	DB_IC_KEEP,

	/* Notifications */
	DB_IC_UPDATE,
	DB_IC_UPDATEBEGIN,
	DB_IC_UPDATEEND,
	DB_IC_UPDATECANCEL,

	/* Waiting */
	DB_IC_WAITFOR,
	DB_IC_WAIT,

	/* Operators */
	DB_IC_ADD,
	DB_IC_SUB,
	DB_IC_MUL,
	DB_IC_DIV,
	DB_IC_MOD,
	DB_IC_INC,
	DB_IC_DEC,
	DB_IC_XOR,
	DB_IC_OR,
	DB_IC_AND,
	DB_IC_NOT,
	DB_IC_SHIFT_LEFT,
	DB_IC_SHIFT_RIGHT,
	DB_IC_STAGE1,
	DB_IC_STAGE2,
	DB_IC_COND_OR,
	DB_IC_COND_AND,
	DB_IC_COND_NOT,
	DB_IC_COND_EQ,
	DB_IC_COND_NEQ,
	DB_IC_COND_GT,
	DB_IC_COND_LT,
	DB_IC_COND_GTEQ,
	DB_IC_COND_LTEQ,

	/* Program control */
	DB_IC_JUMP,
	DB_IC_JEQ,
	DB_IC_JNEQ,
	DB_IC_STOP,

	/* Function calls */
	DB_IC_PUSH,
	DB_IC_CALL,
	DB_IC_RET
}db_icOpKind;

/* Intermediate structures */
typedef enum db_icKind {
	DB_IC_STORAGE,
	DB_IC_LITERAL,
	DB_IC_LABEL,
	DB_IC_FUNCTION,
	DB_IC_OP,
	DB_IC_SCOPE
}db_icKind;

typedef enum db_icStorageKind {
	DB_STORAGE_OBJECT,
	DB_STORAGE_LOCAL,
	DB_STORAGE_ACCUMULATOR,
	DB_STORAGE_MEMBER,
	DB_STORAGE_ELEMENT
}db_icStorageKind;

typedef struct db_ic_s *db_ic;
typedef struct db_icValue_s *db_icValue;
typedef struct db_icStorage_s *db_icStorage;
typedef struct db_icObject_s *db_icObject;
typedef struct db_icLocal_s *db_icLocal;
typedef struct db_icMember_s *db_icMember;
typedef struct db_icElement_s *db_icElement;
typedef struct db_icAccumulator_s *db_icAccumulator;
typedef struct db_icLiteral_s *db_icLiteral;
typedef struct db_icLabel_s *db_icLabel;
typedef struct db_icFunction_s *db_icFunction;
typedef struct db_icOp_s *db_icOp;
typedef struct db_icScope_s *db_icScope;
typedef struct db_icProgram_s *db_icProgram;

typedef struct db_ic_s {
	db_icKind kind;
	db_icProgram program;
	db_uint32 line;
}db_ic_s;

typedef struct db_icValue_s {
	db_ic_s _parent;
}db_icValue_s;

typedef enum db_icDerefMode {
    DB_IC_DEREF_VALUE = 0,
    DB_IC_DEREF_ADDRESS,
    DB_IC_DEREF_PUSH
}db_icDerefMode;

typedef struct db_icStorage_s {
	db_icValue_s _parent;
	db_icStorageKind kind;
	db_string name;
	db_type type;
	db_bool isReference; /* Is the storage a reference */
    db_uint32 used; /* Count how many times value is used in program */
    db_bool holdsReturn; /* If accumulator holds returnvalue, it potentially holds resources */
}db_icStorage_s;

typedef struct db_icObject_s {
    db_icStorage_s _parent;
    db_object ptr;
}db_icObject_s;

typedef struct db_icLocal_s {
    db_icStorage_s _parent;
    db_bool isParameter;
    db_bool isReturn; /* Return locals are special in that resources are not free'd when leaving scope */
}db_icLocal_s;

typedef struct db_icMember_s {
    db_icStorage_s _parent;
    db_icStorage base;
    db_member member;
}db_icMember_s;

typedef struct db_icElement_s {
    db_icStorage_s _parent;
    db_icStorage base;
    db_icValue index;
    db_collection collectionType;
    db_bool dynamic; /* If TRUE, index-expression is not a literal and element needs to be calculated at runtime */
}db_icElement_s;

typedef struct db_icAccumulator_s {
    db_icStorage_s _parent;
    db_uint32 accumulatorId;
}db_icAccumulator_s;

typedef struct db_icLiteral_s {
	db_icValue_s _parent;
	db_value value;
	db_type type;
}db_icLiteral_s;

typedef struct db_icLabel_s {
	db_icValue_s _parent;
	db_uint32 id;
}db_icLabel_s;

typedef struct db_icFunction_s {
    db_icValue_s _parent;
    db_function function;
}db_icFunction_s;

typedef struct db_icOp_s {
	db_ic_s _parent;
	db_icOpKind kind;
	db_icValue s1;
	db_icValue s2;
	db_icValue s3;
	/* If VALUE, storage will be interpreted as value. PVALUE will interpret value of storage. PPVALUE will interpret value of address in storage. */
	db_icDerefMode s1Deref;
	db_icDerefMode s2Deref;
	db_icDerefMode s3Deref;
	/* If s1Any, treat s1 as an any-value */
	db_bool s1Any;
}db_icOp_s;

typedef struct db_icScope_s {
	db_ic_s _parent;
	db_icScope parent;
	db_ll storages; /* Stores accumulators and local variables */
	db_ll program;
	db_bool isFunction;
}db_icScope_s;

typedef struct db_icProgram_s {
	db_ll storages; /* Stores objects */
	db_ll scopes;
	db_ll labels;
	db_ll functions;
	db_ll literals;
	db_ll ops;
	db_string filename;
	db_uint32 labelCount;
	db_uint32 accumulatorId;
	db_icAccumulator accumulatorStack[256];
	db_icScope scope;
    db_int32 errors;
}db_icProgram_s;

/* Intermediate program */
db_icProgram db_icProgram__create(db_string filename);
void db_icProgram__free(db_icProgram program);
void db_icProgram_addIc(db_icProgram program, db_ic ic);
db_icAccumulator db_icProgram_accumulatorPush(db_icProgram _this, db_uint32 line, db_type type, db_bool isReference);
void db_icProgram_accumulatorPop(db_icProgram _this, db_uint32 line);
db_icScope db_icProgram_scopePush(db_icProgram _this, db_uint32 line);
db_icScope db_icProgram_functionPush(db_icProgram _this, db_uint32 line, db_function function);
void db_icProgram_scopePop(db_icProgram _this, db_uint32 line);
db_string db_icProgram_toString(db_icProgram program);
db_vmProgram db_icProgram_toVm(db_icProgram program);

/* Storages */
void db_icStorage_init(
		db_icStorage storage,
		db_icProgram program,
		db_uint32 line,
		db_icStorageKind kind,
		db_string name,
		db_type type);
db_icObject db_icObject__create(db_icProgram program, db_uint32 line, db_object object);
db_icLocal db_icLocal__create(db_icProgram program, db_uint32 line, db_string name, db_type type, db_bool isParameter, db_bool isReturn, db_bool declare);
db_icAccumulator db_icAccumulator__create(db_icProgram program, db_uint32 line, db_type type, db_uint32 accumulatorId);
db_icMember db_icMember__create(db_icProgram program, db_uint32 line, db_icStorage base, db_member member);
db_icElement db_icElement__create(db_icProgram program, db_uint32 line, db_type type, db_icStorage base, db_icValue index);

/* Values */
db_icLiteral db_icLiteral__create(db_icProgram program, db_uint32 line, db_value value, db_type type);
db_icLabel db_icLabel__create(db_icProgram program, db_uint32 line);
db_icFunction db_icFunction__create(db_icProgram program, db_uint32 line, db_function function);

/* Scopes */
db_icScope db_icScope__create(db_icProgram program, db_uint32 line, db_icScope parent, db_bool isFunction);
void db_icScope_addIc(db_icScope scope, db_ic ic);
db_icStorage db_icScope_lookupStorage(db_icScope scope, db_string name, db_bool recursive);

/* Create operation */
db_icOp db_icOp__create(db_icProgram program, db_uint32 line, db_icOpKind kind, db_icValue s1, db_icValue s2, db_icValue s3);

/* Utility */
db_icOpKind db_icOpKindFromOperator(db_operatorKind operator);

#ifdef __cplusplus
}
#endif

#endif /* DB_IC_H_ */
