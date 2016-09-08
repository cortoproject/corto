/*
 * corto_operator.h
 *
 *  Created on: Aug 8, 2013
 *      Author: sander
 */

#ifndef CORTO_OPERATOR_H_
#define CORTO_OPERATOR_H_

#include "corto/lang/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

void corto_operatorInit(void);
corto_int16 corto_unaryOperator(corto_type type, corto_operatorKind _operator, void* operand, void* result);
corto_int16 corto_binaryOperator(corto_type type, corto_operatorKind _operator, void *operand1, void *operand2, void *result);

corto_int16 corto_value_unaryOperator(corto_operatorKind _operator, corto_value *value, corto_value *result);
corto_int16 corto_value_binaryOperator(corto_operatorKind _operator, corto_value *operand1, corto_value *operand2, corto_value *result);

corto_type corto_binaryOperator_getType(corto_type t1, corto_type t2, corto_operatorKind _operator);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_OPERATOR_H_ */
