/*
 * g_generatorDepWalk.h
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#ifndef CORTO_GENERATORTYPEDEPWALK_H_
#define CORTO_GENERATORTYPEDEPWALK_H_

#include "corto/generator.h"

#ifdef __cplusplus
extern "C" {
#endif

int corto_genTypeDepWalk(g_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_GENERATORDEPWALK_H_ */
