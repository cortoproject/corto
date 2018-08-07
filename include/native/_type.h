/* _type.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_NATIVE_TYPE_H
#define CORTO_NATIVE_TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -- Type definitions -- */

/* class corto/native/type */
typedef struct corto_native_type_s {
    struct corto_binary_s super;
    corto_string name;
    bool is_ptr;
} *corto_native_type;


#ifdef __cplusplus
}
#endif
#endif

