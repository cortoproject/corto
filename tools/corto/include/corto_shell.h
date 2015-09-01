
#ifndef CORTO_SHELL_H
#define CORTO_SHELL_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 corto_shell(int argc, char* argv[]);
void corto_shellHelp(void);

#ifdef __cplusplus
}
#endif
#endif
