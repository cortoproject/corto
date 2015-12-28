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

#ifdef __cplusplus
}
#endif

#endif /* CORTO_OPERATOR_H_ */
