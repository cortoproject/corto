/*
 * corto_metawalk.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef CORTO_METAWALK_H_
#define CORTO_METAWALK_H_

#include "corto_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 corto_metaWalk(corto_serializer s, corto_type type, void* userData);
corto_int16 corto_serializeConstants(corto_serializer s, corto_value* v, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_METAWALK_H_ */
