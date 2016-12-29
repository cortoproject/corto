/*
 * g_generatorDepWalk.h
 *
 *  Created on: Sep 25, 2012
 *      Author: sander
 */

#ifndef CORTO_GENERATORDEPWALK_H_
#define CORTO_GENERATORDEPWALK_H_

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT int corto_genDepWalk(g_generator g, corto_depresolver_action onDeclare, corto_depresolver_action onDefine, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_GENERATORDEPWALK_H_ */
