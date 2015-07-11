#ifndef json_composites_H
#define json_composites_H

#include "parson.h"

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_bool json_deserComposite(void* o, JSON_Value *value);

#ifdef __cplusplus
}
#endif
#endif
