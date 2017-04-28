/*
 * corto_operator.h
 *
 *  Created on: Aug 8, 2013
 *      Author: sander
 */

#ifndef CORTO_PTR_H_
#define CORTO_PTR_H_

#include "corto/lang/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

void corto_operatorInit(void);
CORTO_EXPORT void corto_ptr_castInit(void);

CORTO_EXPORT int16_t corto_ptr_unaryOp(corto_type type, corto_operatorKind _operator, void* operand, void* result);
CORTO_EXPORT int16_t corto_ptr_binaryOp(corto_type type, corto_operatorKind _operator, void *operand1, void *operand2, void *result);
CORTO_EXPORT int16_t _corto_ptr_cast(corto_type fromType, void *from, corto_type toType, void *to);

#define corto_ptr_cast(fromType, from, toType, to) _corto_ptr_cast(corto_type(fromType), from, corto_type(toType), to)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_PTR_H_ */
