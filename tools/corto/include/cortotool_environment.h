
#ifndef CORTO_ENVIRONMENT_H
#define CORTO_ENVIRONMENT_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

char* cortotool_environmentPath(char* name);
corto_int16 cortotool_activate(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif
#endif

