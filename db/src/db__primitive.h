/*
 * cx__primitive.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef DB__PRIMITIVE_H_
#define DB__PRIMITIVE_H_

#include "cx_primitive.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_PRIMITIVE_MAX_CONVERTID (24)

cx_uint8 cx__primitive_convertId(cx_primitiveKind kind, cx_width width);

cx_int16 cx__bitmask_bindConstant(cx_bitmask _this, cx_constant* c);

#ifdef __cplusplus
}
#endif

#endif /* DB__PRIMITIVE_H_ */
