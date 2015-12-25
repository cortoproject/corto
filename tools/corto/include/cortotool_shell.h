
#ifndef CORTO_SHELL_H
#define CORTO_SHELL_H

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_shell(int argc, char* argv[]);
void cortotool_shellHelp(void);

#ifdef __cplusplus
}
#endif
#endif
