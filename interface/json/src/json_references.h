#ifndef json_primitives_H
#define json_primitives_H

#include "parson.h"

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_bool json_deserReference(void* p, cx_type t, JSON_Value* v);

#ifdef __cplusplus
}
#endif
#endif
