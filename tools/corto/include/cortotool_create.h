
#ifndef CORTO_PROJECT_H
#define CORTO_PROJECT_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_PACKAGE ("package")
#define CORTO_COMPONENT ("component")
#define CORTO_APPLICATION ("app")
#define CORTO_ENVIRONMENT ("env")

corto_int16 cortotool_create(int argc, char* argv[]);
corto_int16 cortotool_delete(int argc, char* argv[]);

void cortotool_createHelp(void);

#ifdef __cplusplus
}
#endif
#endif

