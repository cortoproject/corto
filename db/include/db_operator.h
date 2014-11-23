/*
 * db_operator.h
 *
 *  Created on: Aug 8, 2013
 *      Author: sander
 */

#ifndef DB_OPERATOR_H_
#define DB_OPERATOR_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

void db_operatorInit(void);
db_int16 db_unaryOperator(db_type type, db_operatorKind operator, void* operand, void* result);
db_int16 db_binaryOperator(db_type type, db_operatorKind operator, void *operand1, void *operand2, void *result);

#ifdef __cplusplus
}
#endif

#endif /* DB_OPERATOR_H_ */
