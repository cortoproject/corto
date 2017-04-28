
#ifndef CORTO_CDECLHANDLER_H_
#define CORTO_CDECLHANDLER_H_

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 corto_cdeclInit(corto_function this);
void corto_cdeclDeinit(corto_function this);

#ifdef __cplusplus
}
#endif

#endif
