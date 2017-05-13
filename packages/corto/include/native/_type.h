/* _type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_NATIVE__TYPE_H
#define CORTO_NATIVE__TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's */
#define corto_native_type(o) ((corto_native_type)corto_assertType((corto_type)corto_native_type_o, o))

/* Native types */
#ifndef CORTO_NATIVE_H
#endif

/* Type definitions */
/*  /corto/native/type */
typedef struct corto_native_type_s *corto_native_type;

struct corto_native_type_s {
    struct corto_binary_s super;
    corto_string name;
};

#ifdef __cplusplus
}
#endif
#endif

