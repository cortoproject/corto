/*
 * cx_convert.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 *
 *      The database can perform implicit type-conversions between all primitive types. This is not the same as type transformations, which
 *      are more flexible, not limited to primitive types, but also more heavy-weight.
 */

#ifndef CX_CONVERT_H_
#define CX_CONVERT_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

void cx_convertInit(void);
cx_int16 cx_convert(cx_primitive fromType, void *from, cx_primitive toType, void *to);

#ifdef __cplusplus
}
#endif

#endif /* CX_CONVERT_H_ */
