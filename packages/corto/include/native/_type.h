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

/* Type definitions */
/*  /corto/native/type */
CORTO_CLASS(corto_native_type);

CORTO_CLASS_DEF(corto_native_type) {
    CORTO_EXTEND(corto_binary);
    corto_string name;
};

#ifdef __cplusplus
}
#endif
#endif

