/*
 * corto_shellEngine.h
 *
 *  Created on: 28 jul. 2010
 *      Author: Sander Mertens
 */

#ifndef CORTO_SHELLENGINE_H_
#define CORTO_SHELLENGINE_H_

#include "corto.h"

typedef int (*corto_commandCallback) (int argc, const char* argv[], char *cmd);
typedef corto_ll (*corto_expandCallback)(char *arg);

void corto_shellEngine_prompt (const char* fmt, ...);
int corto_shellEngine_readInput(corto_commandCallback cmd, corto_expandCallback expand);

#endif /* CORTO_SHELLENGINE_H_ */
