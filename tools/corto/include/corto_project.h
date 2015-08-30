
#ifndef CORTO_PROJECT_H
#define CORTO_PROJECT_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_PACKAGE ("package")
#define CORTO_COMPONENT ("component")
#define CORTO_APPLICATION ("application")

cx_int16 corto_project(int argc, char* argv[]);

void corto_createHelp(void);

#ifdef __cplusplus
}
#endif
#endif

