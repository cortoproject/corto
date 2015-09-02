
#ifndef CORTO_PACKAGE_H
#define CORTO_PACKAGE_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 corto_add(int argc, char* argv[]);
cx_int16 corto_remove(int argc, char* argv[]);
cx_int16 corto_list(int argc, char* argv[]);

void corto_addHelp(void);
void corto_removeHelp(void);
void corto_listHelp(void);

#ifdef __cplusplus
}
#endif
#endif

