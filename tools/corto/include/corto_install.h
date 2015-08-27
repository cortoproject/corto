
#ifndef CORTO_INSTALL_H
#define CORTO_INSTALL_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 corto_install(int argc, char *argv[]);
cx_int16 corto_uninstall(int argc, char *argv[]);
cx_int16 corto_locate(int argc, char* argv[]);
cx_int16 corto_tar(int argc, char* argv[]);
cx_int16 corto_untar(int argc, char* argv[]);

#ifdef __cplusplus
}
#endif
#endif


