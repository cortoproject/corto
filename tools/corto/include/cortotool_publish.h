
#ifndef CORTO_PUBLISH_H
#define CORTO_PUBLISH_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_publish(int argc, char* argv[]);
void cortotool_publishHelp(void);

#ifdef __cplusplus
}
#endif
#endif
