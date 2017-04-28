/*
 * corto_metawalk.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef CORTO_METAWALK_H_
#define CORTO_METAWALK_H_

#include "corto/walk.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT int16_t _corto_metawalk(corto_walk_opt* s, corto_type type, void* userData);
CORTO_EXPORT int16_t corto_walk_constants(corto_walk_opt* s, corto_value *v, void* userData);
CORTO_EXPORT int16_t corto_walk_cases(corto_walk_opt* s, corto_value *v, void *userData);

#define corto_metawalk(s, t, d) _corto_metawalk(s, corto_type(t), d)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_METAWALK_H_ */
