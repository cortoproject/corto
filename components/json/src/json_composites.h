#ifndef json_composites_H
#define json_composites_H

#include "parson.h"

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_bool json_deserComposite(void* p, cx_type t, JSON_Value* v);

#ifdef __cplusplus
}
#endif
#endif
