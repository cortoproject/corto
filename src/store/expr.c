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

/* Rate types based on expressibility */
uint8_t corto_expr_type_score(
    corto_primitive t)
{
    uint8_t result = 0;

    switch(t->kind) {
    case CORTO_ENUM:
    case CORTO_BITMASK:
        result = 1;
        break;
    case CORTO_BOOLEAN:
    case CORTO_BINARY:
    case CORTO_INTEGER:
    case CORTO_UINTEGER:
        result = 2;
        break;
    case CORTO_CHARACTER:
        result = 3;
        break;
    case CORTO_FLOAT:
        result = 4;
        break;
    case CORTO_TEXT:
        result = 5;
        break;
    }

    return result;
}

bool corto_operator_is_assignment(
    corto_operatorKind _operator)
{
    corto_bool result;
    switch(_operator) {
    case CORTO_ASSIGN:
    case CORTO_ASSIGN_ADD:
    case CORTO_ASSIGN_SUB:
    case CORTO_ASSIGN_DIV:
    case CORTO_ASSIGN_MUL:
    case CORTO_ASSIGN_MOD:
    case CORTO_ASSIGN_OR:
    case CORTO_ASSIGN_AND:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

bool corto_operator_is_conditional(
     corto_operatorKind _operator)
{
    corto_bool result;
    switch(_operator) {
    case CORTO_COND_EQ:
    case CORTO_COND_NEQ:
    case CORTO_COND_LT:
    case CORTO_COND_LTEQ:
    case CORTO_COND_GT:
    case CORTO_COND_GTEQ:
    case CORTO_COND_AND:
    case CORTO_COND_OR:
    case CORTO_COND_NOT:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
}

int16_t corto_expr_typeof(
    corto_type src,
    corto_type dst,
    bool src_is_ref,
    bool dst_is_ref,
    corto_type *type_out)
{
    corto_type result = src;

    if (!src && !dst) {
        /* Valid scenario: null && null */
        *type_out = NULL;
        return 0;
    }

    if (!src) {
        /* If this is a null-expression, type is derived from the dst */
        if (dst) {
            bool primitive_target = dst->kind == CORTO_PRIMITIVE;
            if (dst->reference || dst_is_ref) {
                /* If dst is a reference, interpret as type of dst */
                result = dst;

                /* The purpose of the dst_is_ref parameter is to support
                 * references of which the type is not a reference. An
                 * example:
                 *  var int32& ref = my_int
                 */
            } else if (primitive_target) {
                corto_primitiveKind kind = corto_primitive(dst)->kind;
                if (kind == CORTO_TEXT) {
                    /* If dst is a string, interpret null as string */
                    result = corto_type(corto_string_o);
                } else if (kind == CORTO_BOOLEAN) {
                    /* If dst is a bool, interpret null as an string */
                    result = corto_type(corto_string_o);
                } else {
                    /* Can't assign null to other kinds of primitives */
                    corto_throw("cannot assign null to value of type '%s'",
                        corto_fullpath(NULL, dst));
                    goto error;
                }
            } else if (dst->kind == CORTO_COLLECTION &&
                (corto_collection(dst)->kind == CORTO_LIST ||
                corto_collection(dst)->kind == CORTO_MAP))
            {
                result = dst;
            } else {
                /* Can't assign null to other values */
                corto_throw("cannot assign null to value of type '%s'",
                    corto_fullpath(NULL, dst));
                goto error;
            }
        } else {
            /* This and dst don't have a type. Don't know what to do */
            corto_throw("cannot derive type, source and target are 'null'");
            goto error;
        }

    } else if ((dst && (dst->kind == CORTO_VOID) && dst->reference)) {
        if (src_is_ref || (src && src->reference)) {
            result = corto_object_o;
        } else {
            corto_throw(
                "cannot assign non-reference value to '%s'",
                    corto_fullpath(NULL, dst));
            goto error;
        }
    }

    *type_out = result;

    return 0;
error:
    return -1;
}

int16_t corto_expr_binary_typeof(
    corto_type left_type,
    corto_bool left_is_ref,
    corto_type right_type,
    corto_bool right_is_ref,
    corto_operatorKind _operator,
    corto_type *operand_type,
    corto_type *expr_type)
{
    corto_type castType = NULL;
    corto_bool equal = FALSE;

    corto_assert(
        operand_type != NULL, "NULL provided for out-parameter operandType");
    corto_assert(
        expr_type != NULL, "NULL provided for out-parameter expr_type");

    if (corto_operator_is_conditional(_operator)) {
        *expr_type = corto_type(corto_bool_o);
    } else {
        *expr_type = NULL;
    }

    corto_try (corto_expr_typeof(
        left_type, NULL, left_is_ref, FALSE, &left_type), NULL);

    corto_catch();

    corto_try (corto_expr_typeof(
        right_type, left_type, right_is_ref, left_is_ref, &right_type), NULL);


    if (!left_type) {
        left_type = right_type;
    }

    /* NULL input, NULL output */
    if (!right_type) {
        *operand_type = NULL;
        return 0;
    }

    /* If types are not scoped, verify whether they're equal */
    if (!corto_check_attr(left_type, CORTO_ATTR_NAMED) &&
        !corto_check_attr(right_type, CORTO_ATTR_NAMED))
    {
        if (corto_compare(left_type, right_type) == CORTO_EQ) {
            equal = TRUE;
        }
    } else {
        equal = left_type == right_type;
    }

    if (_operator == CORTO_DIV) {
        castType = corto_type(corto_float64_o);

    } else if (!equal) {
        /* Can only cast between primitive types */
        if ((left_type->kind == CORTO_PRIMITIVE ) &&
            (right_type->kind == CORTO_PRIMITIVE))
        {
            corto_primitive
                ltype = corto_primitive(left_type),
                rtype = corto_primitive(right_type);

            int8_t lscore = corto_expr_type_score(ltype);
            int8_t rscore = corto_expr_type_score(rtype);

            /* If expression is an assignment, always take type of lvalue.
             * Otherwise determine based on expressibility score which type to
             * cast to. */
            if (corto_operator_is_assignment(_operator)) {
                if (ltype->width != rtype->width) {
                    castType = left_type;
                }
            } else {
                if (lscore == rscore) {
                    if (ltype->width == rtype->width) {
                        /* If width and kind are equal, no conversion is
                         * required. */
                        *operand_type = left_type;
                    } else if (ltype->width >= rtype->width) {
                        castType = left_type;
                    } else {
                        castType = right_type;
                    }
                } else if (lscore >= rscore) {
                    castType = left_type;
                } else {
                    castType = right_type;
                }
            }
        } else if (left_type->reference && right_type->reference) {
            castType = NULL;
            /* Check if types are compatible */

        } else if ((right_type->reference ||
                   (right_is_ref)) &&
                   !left_type->reference)
        {
            if (corto_type_castable(left_type, corto_object_o)) {
                castType = left_type;
            }
        } else {
            corto_throw("cannot cast from '%s' to '%s'",
                corto_fullpath(NULL, left_type),
                corto_fullpath(NULL, right_type));
            goto error;
        }
    } else if ((right_type->reference ||
                (right_is_ref)) &&
                !left_type->reference)
    {
        if (corto_type_castable(left_type, corto_object_o)) {
            castType = left_type;
        }
    }

    if (!castType) {
        castType = left_type;
    }
    if (castType) {
        *operand_type = castType;
    }
    if (!*expr_type) {
        *expr_type = *operand_type;
    }

    return 0;
error:
    return -1;
}

int16_t corto_expr_is_ref(
    corto_value_kind kind,
    corto_value_ref_kind ref_kind,
    corto_type type,
    bool *result)
{
    if (ref_kind == CORTO_BY_REFERENCE) {
        if (kind == CORTO_OBJECT) {
            *result = true;
        } else if (type && type->reference) {
            *result = true;
        } else if (!type && kind == CORTO_LITERAL) {
            *result = true; /* null literal */
        } else {
            corto_throw(
            "cannot take reference of non-reference expression of type '%s'",
                corto_fullpath(NULL, type));
            goto error;
        }
    } else if (ref_kind == CORTO_BY_TYPE) {
        if (type && type->reference) {
            *result = true;
        } else if (type && type->kind == CORTO_VOID) {
            *result = true; /* void values can't be used by value */
        } else {
            *result = false;
        }
    } else if (ref_kind == CORTO_BY_VALUE) {
        if (type && type->kind == CORTO_VOID && !type->reference) {
            corto_throw("cannot take value of void value");
            goto error;
        } else {
            *result = false;
        }
    }

    return 0;
error:
    return -1;
}
