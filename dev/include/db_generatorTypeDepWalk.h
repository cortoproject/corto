/*
 * cx_generatorDepWalk.h
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#ifndef DB_GENERATORDEPWALK_H_
#define DB_GENERATORDEPWALK_H_

#include "cx_generator.h"

#ifdef __cplusplus
extern "C" {
#endif

int cx_genTypeDepWalk(cx_generator g, g_walkAction onDeclare, g_walkAction onDefine, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_GENERATORDEPWALK_H_ */
