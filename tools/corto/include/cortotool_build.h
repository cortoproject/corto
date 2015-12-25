
#ifndef CORTO_BUILD_H
#define CORTO_BUILD_H

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_build(int argc, char *argv[]);
corto_int16 cortotool_rebuild(int argc, char *argv[]);
corto_int16 cortotool_clean(int argc, char *argv[]);
void cortotool_buildHelp(void);
void cortotool_rebuildHelp(void);
void cortotool_cleanHelp(void);

#ifdef __cplusplus
}
#endif
#endif
