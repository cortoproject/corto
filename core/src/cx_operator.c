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
#include "cx.h"

#ifdef CX_OPERATORS

typedef void (*cx__unaryOperator)(void* operand, void* result);
typedef void (*cx__binaryOperator)(void* operand1, void* operand2, void* result);

static cx__unaryOperator cx_unaryOps[CX_PRIMITIVE_MAX_CONVERTID+1][CX_SHIFT_RIGHT+1];
static cx__binaryOperator cx_binaryOps[CX_PRIMITIVE_MAX_CONVERTID+1][CX_SHIFT_RIGHT+1];

#define CX_NAME_UNARYOP(type, name) __cx_##type##_##name##_unaryOp
#define CX_NAME_BINARYOP(type, name) __cx_##type##_##name##_binaryOp

#define CX_NUMERIC_UNARY_OP(type, _op, name)\
void CX_NAME_UNARYOP(type,name)(void* op, void* result) {\
        *(cx_##type*)result = _op *(cx_##type*)op;\
}

#define CX_NUMERIC_BINARY_OP(type, op, name)\
static void CX_NAME_BINARYOP(type,name)(void* op1, void* op2, void* result) {\
    *(cx_##type*)result = *(cx_##type*)op1 op *(cx_##type*)op2;\
}

#define CX_NUMERIC_COND_UNARY_OP(type, op, name)\
static void CX_NAME_UNARYOP(type,name)(void* op, void* result) {\
    *(cx_bool*)result = op *(cx_##type*)op;\
}

#define CX_NUMERIC_COND_BINARY_OP(type, op, name)\
static void CX_NAME_BINARYOP(type,name)(void* op1, void* op2, void* result) {\
    *(cx_bool*)result = *(cx_##type*)op1 op *(cx_##type*)op2;\
}

static void CX_NAME_BINARYOP(string,cond_eq)(void* op1, void* op2, void* result) {
    *(cx_bool*)result = !strcmp(*(cx_string*)op1, *(cx_string*)op2);
}
static void CX_NAME_BINARYOP(string,cond_neq)(void* op1, void* op2, void* result) {
    *(cx_bool*)result = strcmp(*(cx_string*)op1, *(cx_string*)op2) != 0;
}
static void CX_NAME_BINARYOP(string,add)(void* op1, void* op2, void* result) {
    cx_uint32 len = strlen(*(cx_string*)op1) + strlen(*(cx_string*)op2);
    if (*(cx_string*)result) {
        cx_dealloc(*(cx_string*)result);
    }
    *(cx_string*)result = cx_alloc(len + 1);
    sprintf(*(cx_string*)result, "%s%s", *(cx_string*)op1, *(cx_string*)op2);
}


#define CX_INTEGER_UNARY_OPS(type) \
CX_NUMERIC_UNARY_OP(type, ++, inc)\
CX_NUMERIC_UNARY_OP(type, --, dec)\
CX_NUMERIC_UNARY_OP(type, -, sign)\
CX_NUMERIC_UNARY_OP(type, ~, not)\
CX_NUMERIC_UNARY_OP(type, !, cond_not)

#define CX_FLOAT_UNARY_OPS(type) \
CX_NUMERIC_UNARY_OP(type, ++, inc)\
CX_NUMERIC_UNARY_OP(type, --, dec)\
CX_NUMERIC_UNARY_OP(type, -, sign)\
CX_NUMERIC_UNARY_OP(type, !, cond_not)\

#define CX_INTEGER_BINARY_OPS(type) \
CX_NUMERIC_BINARY_OP(type, =, assign)\
CX_NUMERIC_BINARY_OP(type, +=, assign_add)\
CX_NUMERIC_BINARY_OP(type, -=, assign_sub)\
CX_NUMERIC_BINARY_OP(type, *=, assign_mul)\
CX_NUMERIC_BINARY_OP(type, /=, assign_div)\
CX_NUMERIC_BINARY_OP(type, %=, assign_mod)\
CX_NUMERIC_BINARY_OP(type, |=, assign_or)\
CX_NUMERIC_BINARY_OP(type, ^=, assign_xor)\
CX_NUMERIC_BINARY_OP(type, &=, assign_and)\
CX_NUMERIC_BINARY_OP(type, +, add)\
CX_NUMERIC_BINARY_OP(type, -, sub)\
CX_NUMERIC_BINARY_OP(type, *, mul)\
CX_NUMERIC_BINARY_OP(type, /, div)\
CX_NUMERIC_BINARY_OP(type, %, mod)\
CX_NUMERIC_BINARY_OP(type, |, or)\
CX_NUMERIC_BINARY_OP(type, ^, xor)\
CX_NUMERIC_BINARY_OP(type, &, and)\
CX_NUMERIC_BINARY_OP(type, ^, not)\
CX_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
CX_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
CX_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
CX_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
CX_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
CX_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
CX_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
CX_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define CX_FLOAT_BINARY_OPS(type) \
CX_NUMERIC_BINARY_OP(type, =, assign)\
CX_NUMERIC_BINARY_OP(type, +=, assign_add)\
CX_NUMERIC_BINARY_OP(type, -=, assign_sub)\
CX_NUMERIC_BINARY_OP(type, *=, assign_mul)\
CX_NUMERIC_BINARY_OP(type, /=, assign_div)\
CX_NUMERIC_BINARY_OP(type, +, add)\
CX_NUMERIC_BINARY_OP(type, -, sub)\
CX_NUMERIC_BINARY_OP(type, *, mul)\
CX_NUMERIC_BINARY_OP(type, /, div)\
CX_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
CX_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
CX_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
CX_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
CX_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
CX_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
CX_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
CX_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define CX_INTEGER_OPS(type) \
CX_INTEGER_UNARY_OPS(type) \
CX_INTEGER_BINARY_OPS(type)

#define CX_FLOAT_OPS(type)\
CX_FLOAT_UNARY_OPS(type)\
CX_FLOAT_BINARY_OPS(type)

/* Boolean operator implementation */
CX_NUMERIC_UNARY_OP(bool, !, cond_not)
CX_NUMERIC_BINARY_OP(bool, ==, cond_eq)
CX_NUMERIC_BINARY_OP(bool, !=, cond_neq)
CX_NUMERIC_BINARY_OP(bool, ||, cond_or)
CX_NUMERIC_BINARY_OP(bool, &&, cond_and)

/* Integer operator implementations */
CX_INTEGER_OPS(octet)
CX_INTEGER_OPS(word)
CX_INTEGER_OPS(int8)
CX_INTEGER_OPS(int16)
CX_INTEGER_OPS(int32)
CX_INTEGER_OPS(int64)
CX_INTEGER_OPS(uint8)
CX_INTEGER_OPS(uint16)
CX_INTEGER_OPS(uint32)
CX_INTEGER_OPS(uint64)

/* Float operator implementations */
CX_FLOAT_OPS(float32)
CX_FLOAT_OPS(float64)

#define CX_UNARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
        cx_unaryOps[cx__primitive_convertId(typeKind, typeWidth)][operatorKind] = CX_NAME_UNARYOP(type, name);

#define CX_BINARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
    cx_binaryOps[cx__primitive_convertId(typeKind, typeWidth)][operatorKind] = CX_NAME_BINARYOP(type, name);

#define CX_STRING_OP_INIT(operatorKind, name)\
    cx_binaryOps[cx__primitive_convertId(CX_TEXT, CX_WIDTH_WORD)][operatorKind] = CX_NAME_BINARYOP(string, name);

#define CX_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_INC, type, inc)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_DEC, type, dec)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_SUB, type, sign)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_NOT, type, not)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_COND_NOT, type, cond_not)

#define CX_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN, type, assign)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_ADD, type, assign_add)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_SUB, type, assign_sub)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_MUL, type, assign_mul)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_DIV, type, assign_div)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_MOD, type, assign_mod)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_OR, type, assign_or)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_XOR, type, assign_xor)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_AND, type, assign_and)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ADD, type, add)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_SUB, type, sub)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_MUL, type, mul)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_DIV, type, div)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_MOD, type, mod)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_OR, type, or)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_XOR, type, xor)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_AND, type, and)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_NOT, type, not)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_EQ, type, cond_eq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_NEQ, type, cond_neq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_LT, type, cond_lt)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_GT, type, cond_gt)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_LTEQ, type, cond_lteq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_GTEQ, type, cond_gteq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_AND, type, cond_and)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_OR, type, cond_or)

#define CX_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_INC, type, inc)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_DEC, type, dec)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_SUB, type, sign)\
CX_UNARY_OP_INIT(typeKind, typeWidth, CX_COND_NOT, type, cond_not)

#define CX_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN, type, assign)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_ADD, type, assign_add)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_SUB, type, assign_sub)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_MUL, type, assign_mul)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ASSIGN_DIV, type, assign_div)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_ADD, type, add)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_SUB, type, sub)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_MUL, type, mul)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_DIV, type, div)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_EQ, type, cond_eq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_NEQ, type, cond_neq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_LT, type, cond_lt)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_GT, type, cond_gt)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_LTEQ, type, cond_lteq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_GTEQ, type, cond_gteq)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_AND, type, cond_and)\
CX_BINARY_OP_INIT(typeKind, typeWidth, CX_COND_OR, type, cond_or)

#define CX_INTEGER_OPS_INIT(typeKind, typeWidth, type) \
CX_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CX_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define CX_FLOAT_OPS_INIT(typeKind, typeWidth, type) \
CX_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CX_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define CX_STRING_OPS_INIT()\
CX_STRING_OP_INIT(CX_COND_EQ, cond_eq)\
CX_STRING_OP_INIT(CX_COND_NEQ, cond_neq)\
CX_STRING_OP_INIT(CX_ADD, add)


void cx_operatorInit(void) {
    CX_UNARY_OP_INIT(CX_BOOLEAN, CX_WIDTH_8, CX_COND_NOT, bool, cond_not);
    CX_BINARY_OP_INIT(CX_BOOLEAN, CX_WIDTH_8, CX_COND_EQ, bool, cond_eq);
    CX_BINARY_OP_INIT(CX_BOOLEAN, CX_WIDTH_8, CX_COND_NEQ, bool, cond_neq);
    CX_BINARY_OP_INIT(CX_BOOLEAN, CX_WIDTH_8, CX_COND_OR, bool, cond_or);
    CX_BINARY_OP_INIT(CX_BOOLEAN, CX_WIDTH_8, CX_COND_AND, bool, cond_and);

    CX_INTEGER_OPS_INIT(CX_BINARY, CX_WIDTH_8, octet);
    CX_INTEGER_OPS_INIT(CX_BINARY, CX_WIDTH_WORD, word);

    CX_INTEGER_OPS_INIT(CX_INTEGER, CX_WIDTH_8, int8);
    CX_INTEGER_OPS_INIT(CX_INTEGER, CX_WIDTH_16, int16);
    CX_INTEGER_OPS_INIT(CX_INTEGER, CX_WIDTH_32, int32);
    CX_INTEGER_OPS_INIT(CX_INTEGER, CX_WIDTH_64, int64);

    CX_INTEGER_OPS_INIT(CX_UINTEGER, CX_WIDTH_8, uint8);
    CX_INTEGER_OPS_INIT(CX_UINTEGER, CX_WIDTH_16, uint16);
    CX_INTEGER_OPS_INIT(CX_UINTEGER, CX_WIDTH_32, uint32);
    CX_INTEGER_OPS_INIT(CX_UINTEGER, CX_WIDTH_64, uint64);

    CX_INTEGER_OPS_INIT(CX_ENUM, CX_WIDTH_32, int32);
    CX_INTEGER_OPS_INIT(CX_BITMASK, CX_WIDTH_32, int32);

    CX_FLOAT_OPS_INIT(CX_FLOAT, CX_WIDTH_32, float32);
    CX_FLOAT_OPS_INIT(CX_FLOAT, CX_WIDTH_64, float64);

    CX_STRING_OPS_INIT();
}

cx_int16 cx_unaryOperator(cx_type type, cx_operatorKind operator, void* operand, void* result) {
    if (type->kind == CX_PRIMITIVE) {
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
    if (type->kind == CX_PRIMITIVE) {
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

#endif
