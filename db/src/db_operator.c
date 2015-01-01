/*
 * cx_operator.c
 *
 *  Created on: Aug 7, 2013
 *      Author: sander
 */

#include "cx_object.h"
#include "cx_err.h"
#include "cx__meta.h"
#include "cx__primitive.h"
#include "db.h"

typedef void (*cx__unaryOperator)(void* operand, void* result);
typedef void (*cx__binaryOperator)(void* operand1, void* operand2, void* result);

static cx__unaryOperator cx_unaryOps[DB_PRIMITIVE_MAX_CONVERTID+1][DB_SHIFT_RIGHT+1];
static cx__binaryOperator cx_binaryOps[DB_PRIMITIVE_MAX_CONVERTID+1][DB_SHIFT_RIGHT+1];

#define DB_NAME_UNARYOP(type, name) __cx_##type##_##name##_unaryOp
#define DB_NAME_BINARYOP(type, name) __cx_##type##_##name##_binaryOp

#define DB_NUMERIC_UNARY_OP(type, _op, name)\
void DB_NAME_UNARYOP(type,name)(void* op, void* result) {\
		*(cx_##type*)result = _op *(cx_##type*)op;\
}

#define DB_NUMERIC_BINARY_OP(type, op, name)\
static void DB_NAME_BINARYOP(type,name)(void* op1, void* op2, void* result) {\
	*(cx_##type*)result = *(cx_##type*)op1 op *(cx_##type*)op2;\
}

#define DB_NUMERIC_COND_UNARY_OP(type, op, name)\
static void DB_NAME_UNARYOP(type,name)(void* op, void* result) {\
	*(cx_bool*)result = op *(cx_##type*)op;\
}

#define DB_NUMERIC_COND_BINARY_OP(type, op, name)\
static void DB_NAME_BINARYOP(type,name)(void* op1, void* op2, void* result) {\
	*(cx_bool*)result = *(cx_##type*)op1 op *(cx_##type*)op2;\
}

static void DB_NAME_BINARYOP(string,cond_eq)(void* op1, void* op2, void* result) {
	*(cx_bool*)result = !strcmp((cx_string)op1, (cx_string)op2);
}
static void DB_NAME_BINARYOP(string,cond_neq)(void* op1, void* op2, void* result) {
	*(cx_bool*)result = strcmp((cx_string)op1, (cx_string)op2);
}

#define DB_INTEGER_UNARY_OPS(type) \
DB_NUMERIC_UNARY_OP(type, ++, inc)\
DB_NUMERIC_UNARY_OP(type, --, dec)\
DB_NUMERIC_UNARY_OP(type, -, sign)\
DB_NUMERIC_UNARY_OP(type, ~, not)\
DB_NUMERIC_UNARY_OP(type, !, cond_not)

#define DB_FLOAT_UNARY_OPS(type) \
DB_NUMERIC_UNARY_OP(type, ++, inc)\
DB_NUMERIC_UNARY_OP(type, --, dec)\
DB_NUMERIC_UNARY_OP(type, -, sign)\
DB_NUMERIC_UNARY_OP(type, !, cond_not)\

#define DB_INTEGER_BINARY_OPS(type) \
DB_NUMERIC_BINARY_OP(type, =, assign)\
DB_NUMERIC_BINARY_OP(type, +=, assign_add)\
DB_NUMERIC_BINARY_OP(type, -=, assign_sub)\
DB_NUMERIC_BINARY_OP(type, *=, assign_mul)\
DB_NUMERIC_BINARY_OP(type, /=, assign_div)\
DB_NUMERIC_BINARY_OP(type, %=, assign_mod)\
DB_NUMERIC_BINARY_OP(type, |=, assign_or)\
DB_NUMERIC_BINARY_OP(type, ^=, assign_xor)\
DB_NUMERIC_BINARY_OP(type, &=, assign_and)\
DB_NUMERIC_BINARY_OP(type, +, add)\
DB_NUMERIC_BINARY_OP(type, -, sub)\
DB_NUMERIC_BINARY_OP(type, *, mul)\
DB_NUMERIC_BINARY_OP(type, /, div)\
DB_NUMERIC_BINARY_OP(type, %, mod)\
DB_NUMERIC_BINARY_OP(type, |, or)\
DB_NUMERIC_BINARY_OP(type, ^, xor)\
DB_NUMERIC_BINARY_OP(type, &, and)\
DB_NUMERIC_BINARY_OP(type, ^, not)\
DB_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
DB_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
DB_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
DB_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
DB_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
DB_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
DB_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
DB_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define DB_FLOAT_BINARY_OPS(type) \
DB_NUMERIC_BINARY_OP(type, =, assign)\
DB_NUMERIC_BINARY_OP(type, +=, assign_add)\
DB_NUMERIC_BINARY_OP(type, -=, assign_sub)\
DB_NUMERIC_BINARY_OP(type, *=, assign_mul)\
DB_NUMERIC_BINARY_OP(type, /=, assign_div)\
DB_NUMERIC_BINARY_OP(type, +, add)\
DB_NUMERIC_BINARY_OP(type, -, sub)\
DB_NUMERIC_BINARY_OP(type, *, mul)\
DB_NUMERIC_BINARY_OP(type, /, div)\
DB_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
DB_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
DB_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
DB_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
DB_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
DB_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
DB_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
DB_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define DB_INTEGER_OPS(type) \
DB_INTEGER_UNARY_OPS(type) \
DB_INTEGER_BINARY_OPS(type)

#define DB_FLOAT_OPS(type)\
DB_FLOAT_UNARY_OPS(type)\
DB_FLOAT_BINARY_OPS(type)

/* Boolean operator implementation */
DB_NUMERIC_UNARY_OP(bool, !, cond_not)
DB_NUMERIC_BINARY_OP(bool, ==, cond_eq)
DB_NUMERIC_BINARY_OP(bool, !=, cond_neq)
DB_NUMERIC_BINARY_OP(bool, ||, cond_or)
DB_NUMERIC_BINARY_OP(bool, &&, cond_and)

/* Integer operator implementations */
DB_INTEGER_OPS(octet)
DB_INTEGER_OPS(word)
DB_INTEGER_OPS(int8)
DB_INTEGER_OPS(int16)
DB_INTEGER_OPS(int32)
DB_INTEGER_OPS(int64)
DB_INTEGER_OPS(uint8)
DB_INTEGER_OPS(uint16)
DB_INTEGER_OPS(uint32)
DB_INTEGER_OPS(uint64)

/* Float operator implementations */
DB_FLOAT_OPS(float32)
DB_FLOAT_OPS(float64)

#define DB_UNARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
		cx_unaryOps[cx__primitive_convertId(typeKind, typeWidth)][operatorKind] = DB_NAME_UNARYOP(type, name);

#define DB_BINARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
	cx_binaryOps[cx__primitive_convertId(typeKind, typeWidth)][operatorKind] = DB_NAME_BINARYOP(type, name);

#define DB_STRING_OP_INIT(operatorKind, name)\
	cx_binaryOps[cx__primitive_convertId(DB_TEXT, DB_WIDTH_WORD)][operatorKind] = DB_NAME_BINARYOP(string, name);

#define DB_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_INC, type, inc)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_DEC, type, dec)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_SUB, type, sign)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_NOT, type, not)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_COND_NOT, type, cond_not)

#define DB_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN, type, assign)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_ADD, type, assign_add)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_SUB, type, assign_sub)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_MUL, type, assign_mul)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_DIV, type, assign_div)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_MOD, type, assign_mod)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_OR, type, assign_or)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_XOR, type, assign_xor)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_AND, type, assign_and)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ADD, type, add)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_SUB, type, sub)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_MUL, type, mul)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_DIV, type, div)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_MOD, type, mod)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_OR, type, or)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_XOR, type, xor)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_AND, type, and)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_NOT, type, not)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_EQ, type, cond_eq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_NEQ, type, cond_neq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_LT, type, cond_lt)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_GT, type, cond_gt)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_LTEQ, type, cond_lteq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_GTEQ, type, cond_gteq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_AND, type, cond_and)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_OR, type, cond_or)

#define DB_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_INC, type, inc)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_DEC, type, dec)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_SUB, type, sign)\
DB_UNARY_OP_INIT(typeKind, typeWidth, DB_COND_NOT, type, cond_not)

#define DB_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN, type, assign)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_ADD, type, assign_add)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_SUB, type, assign_sub)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_MUL, type, assign_mul)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ASSIGN_DIV, type, assign_div)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_ADD, type, add)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_SUB, type, sub)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_MUL, type, mul)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_DIV, type, div)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_EQ, type, cond_eq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_NEQ, type, cond_neq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_LT, type, cond_lt)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_GT, type, cond_gt)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_LTEQ, type, cond_lteq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_GTEQ, type, cond_gteq)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_AND, type, cond_and)\
DB_BINARY_OP_INIT(typeKind, typeWidth, DB_COND_OR, type, cond_or)

#define DB_INTEGER_OPS_INIT(typeKind, typeWidth, type) \
DB_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
DB_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define DB_FLOAT_OPS_INIT(typeKind, typeWidth, type) \
DB_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
DB_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define DB_STRING_OPS_INIT()\
DB_STRING_OP_INIT(DB_COND_EQ, cond_eq)\
DB_STRING_OP_INIT(DB_COND_NEQ, cond_neq)\

void cx_operatorInit(void) {
	DB_UNARY_OP_INIT(DB_BOOLEAN, DB_WIDTH_8, DB_COND_NOT, bool, cond_not);
	DB_BINARY_OP_INIT(DB_BOOLEAN, DB_WIDTH_8, DB_COND_EQ, bool, cond_eq);
	DB_BINARY_OP_INIT(DB_BOOLEAN, DB_WIDTH_8, DB_COND_NEQ, bool, cond_neq);
	DB_BINARY_OP_INIT(DB_BOOLEAN, DB_WIDTH_8, DB_COND_OR, bool, cond_or);
	DB_BINARY_OP_INIT(DB_BOOLEAN, DB_WIDTH_8, DB_COND_AND, bool, cond_and);

	DB_INTEGER_OPS_INIT(DB_BINARY, DB_WIDTH_8, octet);
	DB_INTEGER_OPS_INIT(DB_BINARY, DB_WIDTH_WORD, word);

	DB_INTEGER_OPS_INIT(DB_INTEGER, DB_WIDTH_8, int8);
	DB_INTEGER_OPS_INIT(DB_INTEGER, DB_WIDTH_16, int16);
	DB_INTEGER_OPS_INIT(DB_INTEGER, DB_WIDTH_32, int32);
	DB_INTEGER_OPS_INIT(DB_INTEGER, DB_WIDTH_64, int64);

	DB_INTEGER_OPS_INIT(DB_UINTEGER, DB_WIDTH_8, uint8);
	DB_INTEGER_OPS_INIT(DB_UINTEGER, DB_WIDTH_16, uint16);
	DB_INTEGER_OPS_INIT(DB_UINTEGER, DB_WIDTH_32, uint32);
	DB_INTEGER_OPS_INIT(DB_UINTEGER, DB_WIDTH_64, uint64);

	DB_INTEGER_OPS_INIT(DB_ENUM, DB_WIDTH_32, int32);
	DB_INTEGER_OPS_INIT(DB_BITMASK, DB_WIDTH_32, int32);

	DB_FLOAT_OPS_INIT(DB_FLOAT, DB_WIDTH_32, float32);
	DB_FLOAT_OPS_INIT(DB_FLOAT, DB_WIDTH_64, float64);

	DB_STRING_OPS_INIT();
}

cx_int16 cx_unaryOperator(cx_type type, cx_operatorKind operator, void* operand, void* result) {
	if (type->kind == DB_PRIMITIVE) {
		cx__unaryOperator impl = cx_unaryOps[cx_primitive(type)->convertId][operator];
		if (impl) {
			impl(operand, result);
		} else {
			cx_id id;
			cx_error("unary operator '%s' is not implemented for type '%s'", cx_nameof(cx_enum_constant(cx_operatorKind_o, operator)), cx_fullname(type, id));
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

cx_int16 cx_binaryOperator(cx_type type, cx_operatorKind operator, void *operand1, void *operand2, void *result) {
	if (type->kind == DB_PRIMITIVE) {
		cx__binaryOperator impl = cx_binaryOps[cx_primitive(type)->convertId][operator];
		if (impl) {
			impl(operand1, operand2, result);
		} else {
			cx_id id;
			cx_error("binary operator '%s' is not implemented for type '%s'", cx_nameof(cx_enum_constant(cx_operatorKind_o, operator)), cx_fullname(type, id));
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

