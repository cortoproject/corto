
#ifndef CORTEX_INSTALL_H
#define CORTEX_INSTALL_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 cortex_install(int argc, char *argv[]);
cx_int16 cortex_uninstall(int argc, char *argv[]);
cx_int16 cortex_locate(int argc, char* argv[]);

#ifdef __cplusplus
}
#endif
#endif


