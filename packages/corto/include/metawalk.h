/*
 * corto_metawalk.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef CORTO_METAWALK_H_
#define CORTO_METAWALK_H_

#include "corto/serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_int16 _corto_metaWalk(corto_serializer s, corto_type type, void* userData);
CORTO_EXPORT corto_int16 corto_serializeConstants(corto_serializer s, corto_value *v, void* userData);
CORTO_EXPORT corto_int16 corto_serializeCases(corto_serializer s, corto_value *v, void *userData);

#define corto_metaWalk(s, t, d) _corto_metaWalk(s, corto_type(t), d)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_METAWALK_H_ */
