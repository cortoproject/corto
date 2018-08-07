/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>
#include "src/lang/primitive.h"
#include "object.h"

typedef void (*corto__unaryOperator)(void* operand, void* result);
typedef void (*corto__binaryOperator)(void* operand1, void* operand2, void* result);

static corto__unaryOperator corto_unaryOps[CORTO_PRIMITIVE_MAX_CONVERTID+1][CORTO_SHIFT_RIGHT+1];
static corto__binaryOperator corto_binaryOps[CORTO_PRIMITIVE_MAX_CONVERTID+1][CORTO_SHIFT_RIGHT+1];

#define CORTO_NAME_UNARYOP(type, name) __corto_##type##_##name##_unaryOp
#define CORTO_NAME_BINARYOP(type, name) __corto_##type##_##name##_binaryOp

#define CORTO_NUMERIC_UNARY_OP(type, _op, name)\
void CORTO_NAME_UNARYOP(type,name)(void* op, void* result) {\
        *(corto_##type*)result = _op *(corto_##type*)op;\
}

#define CORTO_NUMERIC_BINARY_OP(type, op, name)\
static \
void CORTO_NAME_BINARYOP(type,name)(\
    void* op1,\
    void* op2,\
    void* result)\
{\
    *(corto_##type*)result = *(corto_##type*)op1 op *(corto_##type*)op2;\
}

#define CORTO_NUMERIC_COND_UNARY_OP(type, op, name)\
static \
void CORTO_NAME_UNARYOP(type,name)(\
    void* op,\
    void* result)\
{\
    *(corto_bool*)result = op *(corto_##type*)op;\
}

#define CORTO_NUMERIC_COND_BINARY_OP(type, op, name)\
static \
void CORTO_NAME_BINARYOP(type,name)(\
    void* op1,\
    void* op2,\
    void* result)\
{\
    *(corto_bool*)result = *(corto_##type*)op1 op *(corto_##type*)op2;\
}

static
void CORTO_NAME_BINARYOP(string, cond_eq)(
    void* op1,
    void* op2,
    void* result)
{
    char *str1 = *(char**)op1, *str2 = *(char**)op2;
    if (!str1 || !str2) {
        if (str1 == str2) {
            *(bool*)result = true;
        } else {
            *(bool*)result = false;
        }
    } else {
        *(bool*)result = !strcmp(str1, str2);
    }
}

static
void CORTO_NAME_BINARYOP(string, cond_neq)(
    void* op1,
    void* op2,
    void* result)
{
    CORTO_NAME_BINARYOP(string,cond_eq)(op1, op2, result);
    *(bool*)result = !*(bool*)result;
}

static
void CORTO_NAME_BINARYOP(string, cond_and)(
    void* op1,
    void* op2,
    void* result)
{
    if (!*(char**)op1 || !*(char**)op2) {
        *(bool*)result = false;
    } else {
        *(bool*)result = true;
    }
}

static
void CORTO_NAME_BINARYOP(string, cond_or)(
    void* op1,
    void* op2,
    void* result)
{
    if (*(char**)op1 || *(char**)op2) {
        *(bool*)result = true;
    } else {
        *(bool*)result = false;
    }
}

static
void CORTO_NAME_UNARYOP(string, cond_not)(
    void* op,
    void* result)
{
    if (op && *(char**)op) {
        *(bool*)result = false;
    } else {
        *(bool*)result = true;
    }
}

static
void CORTO_NAME_BINARYOP(string, add)(
    void* op1,
    void* op2,
    void* result)
{
    char *str1 = *(char**)op1;
    char *str2 = *(char**)op2;
    uint32_t len = 0;

    if (str1) len += strlen(str1);
    if (str2) len += strlen(str2);

    if (*(corto_string*)result) {
        corto_dealloc(*(corto_string*)result);
    }

    if (str1 || str2) {
        *(char**)result = corto_alloc(len + 1);
        if (str1 && str2) {
            sprintf(*(char**)result, "%s%s", str1, str2);
        } else if (str1) {
            strcpy(*(char**)result, str1);
        } else {
            strcpy(*(char**)result, str2);
        }
    } else {
        *(char**)result = NULL;
    }
}

static
void CORTO_NAME_BINARYOP(string, assign)(
    void* op1,
    void* op2,
    void* result)
{
    if (result) {
        if (op2) {
            corto_set_str((corto_string*)result, *(corto_string*)op2);
        } else {
            corto_set_str((corto_string*)result, NULL);
        }
    }
    if (op1) {
        if (op2) {
            corto_set_str((corto_string*)op1, *(corto_string*)op2);
        } else {
            corto_set_str((corto_string*)op1, NULL);
        }
    }
}


#define CORTO_INTEGER_UNARY_OPS(type) \
CORTO_NUMERIC_UNARY_OP(type, ++, inc)\
CORTO_NUMERIC_UNARY_OP(type, --, dec)\
CORTO_NUMERIC_UNARY_OP(type, -, sign)\
CORTO_NUMERIC_UNARY_OP(type, ~, not)\
CORTO_NUMERIC_UNARY_OP(type, !, cond_not)

#define CORTO_FLOAT_UNARY_OPS(type) \
CORTO_NUMERIC_UNARY_OP(type, ++, inc)\
CORTO_NUMERIC_UNARY_OP(type, --, dec)\
CORTO_NUMERIC_UNARY_OP(type, -, sign)\
CORTO_NUMERIC_UNARY_OP(type, !, cond_not)\

#define CORTO_INTEGER_BINARY_OPS(type) \
CORTO_NUMERIC_BINARY_OP(type, =, assign)\
CORTO_NUMERIC_BINARY_OP(type, +=, assign_add)\
CORTO_NUMERIC_BINARY_OP(type, -=, assign_sub)\
CORTO_NUMERIC_BINARY_OP(type, *=, assign_mul)\
CORTO_NUMERIC_BINARY_OP(type, /=, assign_div)\
CORTO_NUMERIC_BINARY_OP(type, %=, assign_mod)\
CORTO_NUMERIC_BINARY_OP(type, |=, assign_or)\
CORTO_NUMERIC_BINARY_OP(type, ^=, assign_xor)\
CORTO_NUMERIC_BINARY_OP(type, &=, assign_and)\
CORTO_NUMERIC_BINARY_OP(type, +, add)\
CORTO_NUMERIC_BINARY_OP(type, -, sub)\
CORTO_NUMERIC_BINARY_OP(type, *, mul)\
CORTO_NUMERIC_BINARY_OP(type, /, div)\
CORTO_NUMERIC_BINARY_OP(type, %, mod)\
CORTO_NUMERIC_BINARY_OP(type, |, or)\
CORTO_NUMERIC_BINARY_OP(type, ^, xor)\
CORTO_NUMERIC_BINARY_OP(type, &, and)\
CORTO_NUMERIC_BINARY_OP(type, ^, not)\
CORTO_NUMERIC_BINARY_OP(type, >>, shift_right)\
CORTO_NUMERIC_BINARY_OP(type, <<, shift_left)\
CORTO_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
CORTO_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
CORTO_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
CORTO_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
CORTO_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
CORTO_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
CORTO_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
CORTO_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define CORTO_FLOAT_BINARY_OPS(type) \
CORTO_NUMERIC_BINARY_OP(type, =, assign)\
CORTO_NUMERIC_BINARY_OP(type, +=, assign_add)\
CORTO_NUMERIC_BINARY_OP(type, -=, assign_sub)\
CORTO_NUMERIC_BINARY_OP(type, *=, assign_mul)\
CORTO_NUMERIC_BINARY_OP(type, /=, assign_div)\
CORTO_NUMERIC_BINARY_OP(type, +, add)\
CORTO_NUMERIC_BINARY_OP(type, -, sub)\
CORTO_NUMERIC_BINARY_OP(type, *, mul)\
CORTO_NUMERIC_BINARY_OP(type, /, div)\
CORTO_NUMERIC_COND_BINARY_OP(type, ==, cond_eq)\
CORTO_NUMERIC_COND_BINARY_OP(type, !=, cond_neq)\
CORTO_NUMERIC_COND_BINARY_OP(type, <, cond_lt)\
CORTO_NUMERIC_COND_BINARY_OP(type, >, cond_gt)\
CORTO_NUMERIC_COND_BINARY_OP(type, <=, cond_lteq)\
CORTO_NUMERIC_COND_BINARY_OP(type, >=, cond_gteq)\
CORTO_NUMERIC_COND_BINARY_OP(type, &&, cond_and)\
CORTO_NUMERIC_COND_BINARY_OP(type, ||, cond_or)

#define CORTO_INTEGER_OPS(type) \
CORTO_INTEGER_UNARY_OPS(type) \
CORTO_INTEGER_BINARY_OPS(type)

#define CORTO_FLOAT_OPS(type)\
CORTO_FLOAT_UNARY_OPS(type)\
CORTO_FLOAT_BINARY_OPS(type)

/* Boolean operator implementation */
CORTO_NUMERIC_UNARY_OP(bool, !, cond_not)
CORTO_NUMERIC_BINARY_OP(bool, ==, cond_eq)
CORTO_NUMERIC_BINARY_OP(bool, !=, cond_neq)
CORTO_NUMERIC_BINARY_OP(bool, ||, cond_or)
CORTO_NUMERIC_BINARY_OP(bool, &&, cond_and)
CORTO_NUMERIC_BINARY_OP(bool, =, assign)
CORTO_NUMERIC_BINARY_OP(bool, &, and)
CORTO_NUMERIC_BINARY_OP(bool, |, or)
CORTO_NUMERIC_BINARY_OP(bool, ^, xor)

/* Integer operator implementations */
CORTO_INTEGER_OPS(octet)
CORTO_INTEGER_OPS(word)
CORTO_INTEGER_OPS(int8)
CORTO_INTEGER_OPS(int16)
CORTO_INTEGER_OPS(int32)
CORTO_INTEGER_OPS(int64)
CORTO_INTEGER_OPS(uint8)
CORTO_INTEGER_OPS(uint16)
CORTO_INTEGER_OPS(uint32)
CORTO_INTEGER_OPS(uint64)

/* Float operator implementations */
CORTO_FLOAT_OPS(float32)
CORTO_FLOAT_OPS(float64)

#define CORTO_UNARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
        corto_unaryOps[corto__primitive_convert_id(typeKind, typeWidth)][operatorKind] = CORTO_NAME_UNARYOP(type, name);

#define CORTO_BINARY_OP_INIT(typeKind, typeWidth, operatorKind, type, name)\
    corto_binaryOps[corto__primitive_convert_id(typeKind, typeWidth)][operatorKind] = CORTO_NAME_BINARYOP(type, name);

#define CORTO_STRING_OP_INIT(operatorKind, name)\
    corto_binaryOps[corto__primitive_convert_id(CORTO_TEXT, CORTO_WIDTH_WORD)][operatorKind] = CORTO_NAME_BINARYOP(string, name);

#define CORTO_STRING_UNARY_OP_INIT(operatorKind, name)\
    corto_unaryOps[corto__primitive_convert_id(CORTO_TEXT, CORTO_WIDTH_WORD)][operatorKind] = CORTO_NAME_UNARYOP(string, name);


#define CORTO_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_INC, type, inc)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_DEC, type, dec)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_SUB, type, sign)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_NOT, type, not)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_COND_NOT, type, cond_not)

#define CORTO_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN, type, assign)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_ADD, type, assign_add)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_SUB, type, assign_sub)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_MUL, type, assign_mul)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_DIV, type, assign_div)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_MOD, type, assign_mod)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_OR, type, assign_or)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_XOR, type, assign_xor)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_AND, type, assign_and)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ADD, type, add)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_SUB, type, sub)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_MUL, type, mul)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_DIV, type, div)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_MOD, type, mod)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_OR, type, or)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_XOR, type, xor)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_AND, type, and)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_NOT, type, not)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_SHIFT_RIGHT, type, shift_right)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_SHIFT_LEFT, type, shift_left)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_EQ, type, cond_eq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_NEQ, type, cond_neq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_LT, type, cond_lt)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_GT, type, cond_gt)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_LTEQ, type, cond_lteq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_GTEQ, type, cond_gteq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_AND, type, cond_and)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_OR, type, cond_or)

#define CORTO_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_INC, type, inc)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_DEC, type, dec)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_SUB, type, sign)\
CORTO_UNARY_OP_INIT(typeKind, typeWidth, CORTO_COND_NOT, type, cond_not)

#define CORTO_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN, type, assign)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_ADD, type, assign_add)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_SUB, type, assign_sub)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_MUL, type, assign_mul)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ASSIGN_DIV, type, assign_div)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_ADD, type, add)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_SUB, type, sub)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_MUL, type, mul)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_DIV, type, div)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_EQ, type, cond_eq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_NEQ, type, cond_neq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_LT, type, cond_lt)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_GT, type, cond_gt)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_LTEQ, type, cond_lteq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_GTEQ, type, cond_gteq)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_AND, type, cond_and)\
CORTO_BINARY_OP_INIT(typeKind, typeWidth, CORTO_COND_OR, type, cond_or)

#define CORTO_INTEGER_OPS_INIT(typeKind, typeWidth, type) \
CORTO_INTEGER_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_INTEGER_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define CORTO_FLOAT_OPS_INIT(typeKind, typeWidth, type) \
CORTO_FLOAT_UNARY_OPS_INIT(typeKind, typeWidth, type)\
CORTO_FLOAT_BINARY_OPS_INIT(typeKind, typeWidth, type)

#define CORTO_STRING_OPS_INIT()\
CORTO_STRING_OP_INIT(CORTO_COND_EQ, cond_eq)\
CORTO_STRING_OP_INIT(CORTO_COND_NEQ, cond_neq)\
CORTO_STRING_OP_INIT(CORTO_COND_AND, cond_and)\
CORTO_STRING_OP_INIT(CORTO_COND_OR, cond_or)\
CORTO_STRING_UNARY_OP_INIT(CORTO_COND_NOT, cond_not)\
CORTO_STRING_OP_INIT(CORTO_ASSIGN, assign)\
CORTO_STRING_OP_INIT(CORTO_ADD, add)

void corto_ptr_operatorInit(void) {
    CORTO_UNARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_COND_NOT, bool, cond_not);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_COND_EQ, bool, cond_eq);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_COND_NEQ, bool, cond_neq);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_COND_OR, bool, cond_or);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_COND_AND, bool, cond_and);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_ASSIGN, bool, assign);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_AND, bool, and);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_OR, bool, or);
    CORTO_BINARY_OP_INIT(CORTO_BOOLEAN, CORTO_WIDTH_8, CORTO_XOR, bool, xor);

    CORTO_BINARY_OP_INIT(CORTO_CHARACTER, CORTO_WIDTH_8, CORTO_ASSIGN, char, assign);

    CORTO_INTEGER_OPS_INIT(CORTO_BINARY, CORTO_WIDTH_8, octet);
    CORTO_INTEGER_OPS_INIT(CORTO_BINARY, CORTO_WIDTH_WORD, word);

    CORTO_INTEGER_OPS_INIT(CORTO_INTEGER, CORTO_WIDTH_8, int8);
    CORTO_INTEGER_OPS_INIT(CORTO_INTEGER, CORTO_WIDTH_16, int16);
    CORTO_INTEGER_OPS_INIT(CORTO_INTEGER, CORTO_WIDTH_32, int32);
    CORTO_INTEGER_OPS_INIT(CORTO_INTEGER, CORTO_WIDTH_64, int64);

    CORTO_INTEGER_OPS_INIT(CORTO_UINTEGER, CORTO_WIDTH_8, uint8);
    CORTO_INTEGER_OPS_INIT(CORTO_UINTEGER, CORTO_WIDTH_16, uint16);
    CORTO_INTEGER_OPS_INIT(CORTO_UINTEGER, CORTO_WIDTH_32, uint32);
    CORTO_INTEGER_OPS_INIT(CORTO_UINTEGER, CORTO_WIDTH_64, uint64);

    CORTO_INTEGER_OPS_INIT(CORTO_ENUM, CORTO_WIDTH_32, int32);
    CORTO_INTEGER_OPS_INIT(CORTO_BITMASK, CORTO_WIDTH_32, int32);

    CORTO_FLOAT_OPS_INIT(CORTO_FLOAT, CORTO_WIDTH_32, float32);
    CORTO_FLOAT_OPS_INIT(CORTO_FLOAT, CORTO_WIDTH_64, float64);

    CORTO_STRING_OPS_INIT();
}

int16_t corto_ptr_unaryOp(
    corto_type type,
    corto_operatorKind operator,
    void* operand,
    void* result)
{
    void *nullptr = NULL;
    if (!operand) {
        operand = &nullptr;
    }

    if (!type && !*(char**)operand) {
        /* operand is a 'null' */
        type = (corto_type)corto_string_o;
    }

    if (type->kind == CORTO_PRIMITIVE) {
        corto__unaryOperator impl = corto_unaryOps[corto_primitive(type)->convert_id][operator];
        if (impl) {
            impl(operand, result);
        } else {
            corto_throw(
              "unary operator '%s' is not implemented for type '%s'",
              corto_idof(corto_enum_constant_from_value(corto_operatorKind_o, operator)),
              corto_fullpath(NULL, type));
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

static
int16_t corto_intern_binaryOp(
    corto_type type,
    corto_operatorKind operator,
    void *operand1,
    void *operand2,
    void *result,
    bool always_copy)
{
    /* Convenience: allow passing NULL to binaryOp for null values */
    void *nullptr = NULL;
    if (!operand1) {
        operand1 = &nullptr;
    }
    if (!operand2) {
        operand2 = &nullptr;
    }

    if (!type && !*(char**)operand1 && !*(char**)operand2) {
        /* both operands are 'null' */
        type = (corto_type)corto_string_o;
    }

    if (type->kind == CORTO_PRIMITIVE) {
        corto__binaryOperator impl =
            corto_binaryOps[corto_primitive(type)->convert_id][operator];
        if (impl) {
            impl(operand1, operand2, result);
        } else {
            corto_throw("binary operator '%s' is not implemented for type '%s'",
              corto_idof(corto_enum_constant_from_value(corto_operatorKind_o, operator)),
              corto_fullpath(NULL, type));
            goto error;
        }

    } else if (operator == CORTO_ASSIGN) {
        if (!always_copy && type->reference) {
            corto_set_ref(operand1, *(corto_object*)operand2);
            if (result && result != operand1) {
                *(corto_object*)result = *(corto_object*)operand1;
            }
        } else {
            corto_walk_opt s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
            corto_copy_ser_t data;
            data.value = corto_value_mem(operand1, type);
            corto_value src = corto_value_mem(operand2, type);
            corto_walk_value(&s, &src, &data);

            if (result && result != operand1) {
                data.value = corto_value_mem(result, type);
                corto_value src = corto_value_mem(operand2, type);
                corto_walk_value(&s, &src, &data);
            }
        }
    } else {
        corto_throw("invalid operator for non-primitive type");
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_ptr_binaryOp(
    corto_type type,
    corto_operatorKind operator,
    void *operand1,
    void *operand2,
    void *result)
{
    return corto_intern_binaryOp(
        type, operator, operand1, operand2, result, false);
}

int16_t corto_mem_binaryOp(
    corto_type type,
    corto_operatorKind operator,
    void *operand1,
    void *operand2,
    void *result)
{
    return corto_intern_binaryOp(
        type, operator, operand1, operand2, result, true);
}
