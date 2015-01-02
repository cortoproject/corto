/*
 * cx_metawalk.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef CX_METAWALK_H_
#define CX_METAWALK_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 cx_metaWalk(cx_serializer s, cx_type type, void* userData);
cx_int16 cx_serializeConstants(cx_serializer s, cx_value* v, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CX_METAWALK_H_ */
