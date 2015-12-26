/*
 * corto__primitive.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef CORTO__PRIMITIVE_H_
#define CORTO__PRIMITIVE_H_

#include "corto/lang/primitive.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_PRIMITIVE_MAX_CONVERTID (24)

corto_uint8 corto__primitive_convertId(corto_primitiveKind kind, corto_width width);

corto_int16 corto__bitmask_bindConstant(corto_bitmask _this, corto_constant* c);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__PRIMITIVE_H_ */
