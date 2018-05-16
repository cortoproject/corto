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

#ifndef CORTO_EXPR_H
#define CORTO_EXPR_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Is operator an assigment operator.
 */
CORTO_EXPORT
bool corto_operator_is_assignment(
    corto_operatorKind _operator);

/** Is operator a conditional operator.
 */
CORTO_EXPORT
bool corto_operator_is_conditional(
     corto_operatorKind _operator);

/** Get type expressiveness score.
 * This function is used to determine which type in a binary expression is more
 * expressive, which will be used to determine the type of the binary
 * expression.
 */
CORTO_EXPORT
uint8_t corto_expr_type_score(
    corto_primitive t);

/** Determine type of expression in assignment.
 * When an expression is assigned to another expression, its type is determined
 * in certain circumstances by the type of the lvalue. This function accepts the
 * type of the expression (src) and the type of the target expression (dst) and
 * returns the correct type.
 *
 * This function is necessary to handle null values, as the null literal by
 * itself does not have a type.
 *
 * The dst_is_ref parameter allows handling expressions where the target
 * expression holds a reference to an object of a non-reference type.
 *
 * @param src Type of the expression to assign. When NULL, function assumes that
 *            source is a null literal.
 * @param dst Type of the target expression.
 * @param dst_is_ref Is the target expression a reference.
 */
CORTO_EXPORT
int16_t corto_expr_typeof(
    corto_type src,
    corto_type dst,
    bool src_is_ref,
    bool dst_is_ref,
    corto_type *type_out);

/** Determine type of a binary expression.
 * The type of a binary expression is determined by the types of its operands
 * and the operator.
 *
 * - Assignment expressions always assume the type of the lvalue.
 * - Conditional expressions always return a boolean value.
 * - Division expressions always return a floating point value.
 *
 * When operand types are not equal but are compatible, the most expressive
 * type will be selected. This is determined by a type score, as is returned
 * by the corto_expr_type_score function. If the type score of both operands is
 * equal but the types are not, the type with the largest storage size (width)
 * will be selected. If both sizes are equal, the left type is selected.
 *
 * @param left_type Type of left operand.
 * @param left_is_ref Is left operand a reference.
 * @param rigth_type Type of right operand.
 * @param right_is_ref Is right operand a reference.
 * @param _operator Operator of binary expression.
 * @param operand_type [out] Cast operands to this before applying operator.
 * @param expr_type [out] Type of the expression.
 */
CORTO_EXPORT
int16_t corto_expr_binary_typeof(
    corto_type left_type,
    corto_bool left_is_ref,
    corto_type right_type,
    corto_bool right_is_ref,
    corto_operatorKind _operator,
    corto_type *operand_type,
    corto_type *expr_type);


CORTO_EXPORT
int16_t corto_expr_is_ref(
    corto_value_kind kind,
    corto_value_ref_kind ref_kind,
    corto_type type,
    bool *result);

#ifdef __cplusplus
}
#endif

#endif
