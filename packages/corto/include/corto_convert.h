/*
 * corto_convert.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 *
 *      The database can perform implicit type-conversions between all primitive types. This is not the same as type transformations, which
 *      are more flexible, not limited to primitive types, but also more heavy-weight.
 */

#ifndef CORTO_CONVERT_H_
#define CORTO_CONVERT_H_

#include "corto/lang/lang.h"

#ifdef __cplusplus
extern "C" {
#endif

void corto_convertInit(void);
corto_int16 corto_convert(corto_primitive fromType, void *from, corto_primitive toType, void *to);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CONVERT_H_ */
