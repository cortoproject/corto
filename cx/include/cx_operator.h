/*
 * cx_operator.h
 *
 *  Created on: Aug 8, 2013
 *      Author: sander
 */

#ifndef DB_OPERATOR_H_
#define DB_OPERATOR_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

void cx_operatorInit(void);
cx_int16 cx_unaryOperator(cx_type type, cx_operatorKind operator, void* operand, void* result);
cx_int16 cx_binaryOperator(cx_type type, cx_operatorKind operator, void *operand1, void *operand2, void *result);

#ifdef __cplusplus
}
#endif

#endif /* DB_OPERATOR_H_ */
