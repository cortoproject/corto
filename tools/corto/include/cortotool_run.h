
#ifndef CORTO_RUN_H
#define CORTO_RUN_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_run(int argc, char* argv[]);
corto_int16 cortotool_debug(int argc, char* argv[]);
void cortotool_runHelp(void);

#ifdef __cplusplus
}
#endif
#endif
