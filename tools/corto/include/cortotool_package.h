
#ifndef CORTOTOOL_PACKAGE_H
#define CORTOTOOL_PACKAGE_H

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_add(int argc, char* argv[]);
corto_int16 cortotool_remove(int argc, char* argv[]);
corto_int16 cortotool_list(int argc, char* argv[]);

void cortotool_addHelp(void);
void cortotool_removeHelp(void);
void cortotool_listHelp(void);

#ifdef __cplusplus
}
#endif
#endif
