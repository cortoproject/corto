
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

void corto_installHelp(void);
void corto_uninstallHelp(void);
void corto_tarHelp(void);
void corto_untarHelp(void);

#ifdef __cplusplus
}
#endif
#endif


