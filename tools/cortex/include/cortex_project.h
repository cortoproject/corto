
#ifndef CORTEX_PROJECT_H
#define CORTEX_PROJECT_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTEX_PACKAGE ("package")
#define CORTEX_COMPONENT ("component")
#define CORTEX_APPLICATION ("application")

cx_int16 cortex_project(int argc, char* argv[]);

#ifdef __cplusplus
}
#endif
#endif

