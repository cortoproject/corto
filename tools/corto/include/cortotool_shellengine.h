/*
 * corto_shellEngine.h
 *
 *  Created on: 28 jul. 2010
 *      Author: Sander Mertens
 */

#ifndef CORTO_SHELLENGINE_H_
#define CORTO_SHELLENGINE_H_

#include "corto.h"

typedef void (*corto_printCallback) (const char *cmd);
typedef int (*corto_commandCallback) (int argc, const char* argv[], char *cmd);
typedef corto_ll (*corto_expandCallback)(int argc, const char *argv[], char *cmd);

void corto_shellEngine_prompt (const char* fmt, ...);
int corto_shellEngine_readInput(
  corto_printCallback print,
  corto_commandCallback cmd,
  corto_expandCallback expand);

#endif /* CORTO_SHELLENGINE_H_ */
