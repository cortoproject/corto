
#ifndef CORTO_INSTALL_H
#define CORTO_INSTALL_H

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_install(int argc, char *argv[]);
corto_int16 cortotool_uninstall(int argc, char *argv[]);
corto_int16 cortotool_locate(int argc, char* argv[]);
corto_int16 cortotool_tar(int argc, char* argv[]);
corto_int16 cortotool_untar(int argc, char* argv[]);
corto_int16 cortotool_update(int argc, char* argv[]);

void cortotool_toLibPath(char *location);

void cortotool_installHelp(void);
void cortotool_uninstallHelp(void);
void cortotool_tarHelp(void);
void cortotool_untarHelp(void);
void cortotool_updateHelp(void);
void cortotool_locateHelp(void);

#ifdef __cplusplus
}
#endif
#endif
