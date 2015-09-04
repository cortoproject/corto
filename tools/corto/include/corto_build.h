
#ifndef CORTO_BUILD_H
#define CORTO_BUILD_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 corto_build(int argc, char *argv[]);
cx_int16 corto_rebuild(int argc, char *argv[]);
cx_int16 corto_clean(int argc, char *argv[]);
void corto_buildHelp(void);
void corto_rebuildHelp(void);
void corto_cleanHelp(void);

#ifdef __cplusplus
}
#endif
#endif

